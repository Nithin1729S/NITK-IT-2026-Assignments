import tkinter as tk
from tkinter import filedialog, colorchooser, messagebox
import cv2
import numpy as np
from PIL import Image, ImageTk
import os

class ColorObjectDetector:
    def __init__(self, root):
        self.root = root
        self.root.title("Color Object Detector")
        self.root.geometry("900x700")
        self.root.configure(bg='white')

        self.video_path = None
        self.cap = None
        self.color_lower = None
        self.color_upper = None
        self.running = False
        self.selected_color = None

        self.setup_ui()

    def setup_ui(self):
        control_frame = tk.Frame(self.root, bg='white')
        control_frame.pack(pady=10)

        tk.Button(control_frame, text="Load Video", bg="#5F7FA5", fg="white",
                  font=("Arial", 11), relief=tk.FLAT, padx=20, pady=8,
                  command=self.load_video).pack(side=tk.LEFT, padx=5)

        tk.Button(control_frame, text="Choose Color", bg="#7ED321", fg="white",
                  font=("Arial", 11), relief=tk.FLAT, padx=20, pady=8,
                  command=self.choose_color).pack(side=tk.LEFT, padx=5)

        tk.Button(control_frame, text="Start Detection", bg="#F5A623", fg="white",
                  font=("Arial", 11), relief=tk.FLAT, padx=20, pady=8,
                  command=self.start_detection).pack(side=tk.LEFT, padx=5)

        tk.Button(control_frame, text="Stop", bg="#D0021B", fg="white",
                  font=("Arial", 11), relief=tk.FLAT, padx=20, pady=8,
                  command=self.stop_detection).pack(side=tk.LEFT, padx=5)

        self.status_label = tk.Label(self.root, text="Load a video and choose a color to start", 
                                   bg='white', font=("Arial", 10))
        self.status_label.pack(pady=5)

        self.canvas = tk.Canvas(self.root, bg='black')
        self.canvas.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

    def load_video(self):
        downloads_path = os.path.join(os.path.expanduser("~"), "Downloads")
        path = filedialog.askopenfilename(initialdir=downloads_path,
                                          title="Select Video",
                                          filetypes=[("Video files", "*.mp4 *.avi *.mov *.mkv")])
        if path:
            self.video_path = path
            if self.cap:
                self.cap.release()
            self.cap = cv2.VideoCapture(path)
            self.status_label.config(text=f"Loaded: {os.path.basename(path)}")
            messagebox.showinfo("Video Loaded", f"Loaded: {os.path.basename(path)}")

    def choose_color(self):
        color_code = colorchooser.askcolor(title="Choose Target Color")
        if color_code and color_code[0]:
            r, g, b = color_code[0]
            self.selected_color = (int(r), int(g), int(b))
            self.set_color_range(r, g, b)
            self.status_label.config(text=f"Color selected: R:{int(r)}, G:{int(g)}, B:{int(b)}")
            messagebox.showinfo("Color Selected", f"R:{int(r)}, G:{int(g)}, B:{int(b)}")

    def set_color_range(self, r, g, b):
        bgr_color = np.uint8([[[b, g, r]]])
        hsv_color = cv2.cvtColor(bgr_color, cv2.COLOR_BGR2HSV)[0][0]
        hue, sat, val = hsv_color
        
        if hue < 10 or hue > 170: 
            if hue < 10:
                self.color_lower = np.array([0, 50, 50])
                self.color_upper = np.array([10, 255, 255])
                self.color_lower2 = np.array([170, 50, 50])
                self.color_upper2 = np.array([179, 255, 255])
            else:
                self.color_lower = np.array([170, 50, 50])
                self.color_upper = np.array([179, 255, 255])
                self.color_lower2 = np.array([0, 50, 50])
                self.color_upper2 = np.array([10, 255, 255])
        else:
            hue_tolerance = 15 
            self.color_lower = np.array([max(0, hue - hue_tolerance), 50, 50])
            self.color_upper = np.array([min(179, hue + hue_tolerance), 255, 255])
            self.color_lower2 = None
            self.color_upper2 = None

    def start_detection(self):
        if not self.cap or self.color_lower is None:
            messagebox.showerror("Error", "Please load a video and choose a color first!")
            return
        self.running = True
        self.status_label.config(text="Detection running...")
        self.process_frame()

    def stop_detection(self):
        self.running = False
        self.status_label.config(text="Detection stopped")

    def create_mask(self, hsv):
        mask = cv2.inRange(hsv, self.color_lower, self.color_upper)
        
        if hasattr(self, 'color_lower2') and self.color_lower2 is not None:
            mask2 = cv2.inRange(hsv, self.color_lower2, self.color_upper2)
            mask = cv2.bitwise_or(mask, mask2)
        
        kernel = np.ones((5, 5), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        
        return mask

    def resize_frame_to_canvas(self, frame):
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
        
        if canvas_width <= 1 or canvas_height <= 1:
            return frame
        
        frame_height, frame_width = frame.shape[:2]
        
        scale_w = canvas_width / frame_width
        scale_h = canvas_height / frame_height
        scale = min(scale_w, scale_h)
        
        new_width = int(frame_width * scale)
        new_height = int(frame_height * scale)
        
        resized_frame = cv2.resize(frame, (new_width, new_height))
        return resized_frame

    def process_frame(self):
        if not self.running or not self.cap:
            return
            
        ret, frame = self.cap.read()
        if not ret:
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
            ret, frame = self.cap.read()
            if not ret:
                self.running = False
                self.status_label.config(text="Error reading video")
                return

        frame = self.resize_frame_to_canvas(frame)
        
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        mask = self.create_mask(hsv)
        
        result = cv2.bitwise_and(frame, frame, mask=mask)
        
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        object_count = 0
        
        for cnt in contours:
            area = cv2.contourArea(cnt)
            if area > 300: 
                object_count += 1
                x, y, w, h = cv2.boundingRect(cnt)
                cv2.rectangle(result, (x, y), (x + w, y + h), (0, 255, 0), 2)
                cv2.putText(result, f'Area: {int(area)}', (x, y-10), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)

        cv2.putText(result, f'Objects detected: {object_count}', (10, 30), 
                   cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

        frame_rgb = cv2.cvtColor(result, cv2.COLOR_BGR2RGB)
        img_pil = Image.fromarray(frame_rgb)
        img_tk = ImageTk.PhotoImage(image=img_pil)

        self.canvas.delete("all")
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
        
        x_offset = (canvas_width - img_pil.width) // 2
        y_offset = (canvas_height - img_pil.height) // 2
        
        self.canvas.create_image(max(0, x_offset), max(0, y_offset), anchor=tk.NW, image=img_tk)
        self.canvas.image = img_tk 

        if self.running:
            self.root.after(30, self.process_frame) 

    def __del__(self):
        if self.cap:
            self.cap.release()

def main():
    root = tk.Tk()
    app = ColorObjectDetector(root)
    root.mainloop()

if __name__ == "__main__":
    main()