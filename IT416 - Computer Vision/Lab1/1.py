import os
import tkinter as tk
from tkinter import filedialog, messagebox
import cv2
import numpy as np
from PIL import Image, ImageTk

class MinimalCannyDetector:
    def __init__(self, root):
        self.root = root
        self.root.title("Canny Edge Detection")
        self.root.geometry("900x700")
        self.root.configure(bg='white')

        self.original_image = None
        self.processed_image = None
        self.filter_applied = False
        self.low_threshold = tk.IntVar(value=50)
        self.high_threshold = tk.IntVar(value=150)

        self.setup_ui()

    def setup_ui(self):
        main_frame = tk.Frame(self.root, bg='white')
        main_frame.pack(fill=tk.BOTH, expand=True, padx=20, pady=20)

        self.control_frame = tk.Frame(main_frame, bg='white')
        self.control_frame.pack(pady=(0, 20))

        self.load_btn = tk.Button(self.control_frame, text="Load Image",
                                  command=self.load_image,
                                  font=('Arial', 11),
                                  bg='#4A90E2', fg='white',
                                  relief=tk.FLAT, padx=20, pady=8)
        self.load_btn.pack(pady=5)

        self.apply_btn = tk.Button(self.control_frame, text="Apply Canny Filter",
                                   command=self.apply_filter,
                                   font=('Arial', 11),
                                   bg='#7ED321', fg='white',
                                   relief=tk.FLAT, padx=20, pady=8)

        self.threshold_frame = tk.Frame(main_frame, bg='white')

        low_frame = tk.Frame(self.threshold_frame, bg='white')
        low_frame.pack(pady=5)
        tk.Label(low_frame, text="Low", font=('Arial', 10), bg='white', fg='#666').pack(side=tk.LEFT)
        self.low_scale = tk.Scale(low_frame, from_=0, to=255,
                                  variable=self.low_threshold, orient=tk.HORIZONTAL,
                                  command=self.update_filter,
                                  bg='white', fg='#333', highlightthickness=0,
                                  troughcolor='#E8E8E8', activebackground='#4A90E2',
                                  length=200, showvalue=0)
        self.low_scale.pack(side=tk.LEFT, padx=10)
        self.low_label = tk.Label(low_frame, text="50", font=('Arial', 10, 'bold'),
                                  bg='white', fg='#333', width=3)
        self.low_label.pack(side=tk.LEFT)

        high_frame = tk.Frame(self.threshold_frame, bg='white')
        high_frame.pack(pady=5)
        tk.Label(high_frame, text="High", font=('Arial', 10), bg='white', fg='#666').pack(side=tk.LEFT)
        self.high_scale = tk.Scale(high_frame, from_=0, to=255,
                                   variable=self.high_threshold, orient=tk.HORIZONTAL,
                                   command=self.update_filter,
                                   bg='white', fg='#333', highlightthickness=0,
                                   troughcolor='#E8E8E8', activebackground='#4A90E2',
                                   length=200, showvalue=0)
        self.high_scale.pack(side=tk.LEFT, padx=10)
        self.high_label = tk.Label(high_frame, text="150", font=('Arial', 10, 'bold'),
                                   bg='white', fg='#333', width=3)
        self.high_label.pack(side=tk.LEFT)

        self.action_frame = tk.Frame(main_frame, bg='white')

        self.reset_btn = tk.Button(self.action_frame, text="Reset",
                                   command=self.reset_values,
                                   font=('Arial', 9),
                                   bg='#F5A623', fg='white',
                                   relief=tk.FLAT, padx=15, pady=5)
        self.reset_btn.pack(side=tk.LEFT, padx=(0, 10))

        self.save_btn = tk.Button(self.action_frame, text="Save",
                                  command=self.save_image,
                                  font=('Arial', 9),
                                  bg='#50E3C2', fg='white',
                                  relief=tk.FLAT, padx=15, pady=5)
        self.save_btn.pack(side=tk.LEFT)

        self.image_frame = tk.Frame(main_frame, bg='#F8F8F8', relief=tk.SUNKEN, bd=1)
        self.image_frame.pack(fill=tk.BOTH, expand=True)

        self.canvas = tk.Canvas(self.image_frame, bg='white', highlightthickness=0)
        self.canvas.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        self.status_label = tk.Label(main_frame, text="Load an image to begin",
                                     font=('Arial', 9), fg='#999', bg='white')
        self.status_label.pack(pady=(10, 0))

    def load_image(self):
        downloads_path = os.path.join(os.path.expanduser("~"), "Downloads")
        file_path = filedialog.askopenfilename(
            initialdir=downloads_path,
            title="Select Image",
            filetypes=[("Images", "*.jpg *.jpeg *.png *.bmp *.tiff")]
        )
        if file_path:
            try:
                self.original_image = cv2.imread(file_path)
                if self.original_image is None:
                    raise ValueError("Could not load image")
                self.original_rgb = cv2.cvtColor(self.original_image, cv2.COLOR_BGR2RGB)
                self.filter_applied = False
                self.processed_image = None
                self.threshold_frame.pack_forget()
                self.action_frame.pack_forget()
                self.apply_btn.pack(pady=5)
                self.display_image(self.original_rgb)
                filename = file_path.split('/')[-1]
                self.status_label.config(text=f"{filename} loaded")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load image: {str(e)}")
                self.status_label.config(text="Error loading image")

    def apply_filter(self):
        if self.original_image is None:
            return
        self.apply_btn.pack_forget()
        self.threshold_frame.pack(pady=(0, 15))
        self.action_frame.pack(pady=(0, 15))
        self.filter_applied = True
        self.update_filter()
        self.status_label.config(text="Adjust thresholds to fine-tune edges")

    def update_filter(self, event=None):
        if not self.filter_applied or self.original_image is None:
            return
        low_val = self.low_threshold.get()
        high_val = self.high_threshold.get()
        self.low_label.config(text=str(low_val))
        self.high_label.config(text=str(high_val))
        if low_val >= high_val:
            if event and event.widget == self.low_scale:
                self.high_threshold.set(min(255, low_val + 1))
            else:
                self.low_threshold.set(max(0, high_val - 1))
            return
        try:
            gray = cv2.cvtColor(self.original_image, cv2.COLOR_BGR2GRAY)
            blurred = cv2.GaussianBlur(gray, (5, 5), 0)
            edges = cv2.Canny(blurred, low_val, high_val)
            self.processed_image = edges
            self.display_image(edges)
        except Exception as e:
            messagebox.showerror("Error", f"Processing failed: {str(e)}")

    def display_image(self, image):
        if image is None:
            return
        self.canvas.update_idletasks()
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
        if canvas_width < 50 or canvas_height < 50:
            canvas_width, canvas_height = 600, 400
        if len(image.shape) == 3:
            h, w = image.shape[:2]
        else:
            h, w = image.shape
        scale = min((canvas_width-20)/w, (canvas_height-20)/h, 1.0)
        if scale < 1.0:
            new_w, new_h = int(w * scale), int(h * scale)
            display_img = cv2.resize(image, (new_w, new_h))
        else:
            display_img = image.copy()
        if len(display_img.shape) == 3:
            pil_img = Image.fromarray(display_img)
        else:
            pil_img = Image.fromarray(display_img, mode='L')
        self.photo = ImageTk.PhotoImage(pil_img)
        self.canvas.delete("all")
        x = (canvas_width - pil_img.width) // 2
        y = (canvas_height - pil_img.height) // 2
        self.canvas.create_image(x, y, anchor=tk.NW, image=self.photo)

    def reset_values(self):
        self.low_threshold.set(50)
        self.high_threshold.set(150)
        self.update_filter()

    def save_image(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No processed image to save")
            return
        file_path = filedialog.asksaveasfilename(
            title="Save Image",
            defaultextension=".png",
            filetypes=[("PNG", "*.png"), ("JPEG", "*.jpg")]
        )
        if file_path:
            try:
                cv2.imwrite(file_path, self.processed_image)
                messagebox.showinfo("Success", "Image saved!")
                self.status_label.config(text="Image saved successfully")
            except Exception as e:
                messagebox.showerror("Error", f"Save failed: {str(e)}")

def main():
    root = tk.Tk()
    app = MinimalCannyDetector(root)
    root.mainloop()

if __name__ == "__main__":
    main()
