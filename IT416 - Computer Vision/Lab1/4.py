import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from PIL import Image, ImageTk, ImageFilter, ImageEnhance
import numpy as np
from scipy import ndimage
import os

class ImageProcessor:
    def __init__(self, root):
        self.root = root
        self.root.title("Image Processing Tool")
        self.root.geometry("1600x1000") 
        
        self.original_image = None
        self.processed_image = None
        self.display_image = None
        
        self.setup_ui()
        
    def setup_ui(self):
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=6)  
        main_frame.rowconfigure(0, weight=1)  
        
        control_frame = ttk.LabelFrame(main_frame, text="Controls", padding="8", width=280)
        control_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S), padx=(0, 8))
        control_frame.grid_propagate(False) 
        
        file_frame = ttk.LabelFrame(control_frame, text="File Operations", padding="5")
        file_frame.pack(fill="x", pady=(0, 10))
        
        ttk.Button(file_frame, text="Load Image", command=self.load_image).pack(fill="x", pady=2)
        ttk.Button(file_frame, text="Save Image", command=self.save_image).pack(fill="x", pady=2)
        ttk.Button(file_frame, text="Reset to Original", command=self.reset_image).pack(fill="x", pady=2)
        
        resize_frame = ttk.LabelFrame(control_frame, text="Resize", padding="5")
        resize_frame.pack(fill="x", pady=(0, 10))
        
        ttk.Label(resize_frame, text="Width:").pack(anchor="w")
        self.width_var = tk.StringVar(value="400")
        ttk.Entry(resize_frame, textvariable=self.width_var, width=10).pack(fill="x", pady=2)
        
        ttk.Label(resize_frame, text="Height:").pack(anchor="w")
        self.height_var = tk.StringVar(value="300")
        ttk.Entry(resize_frame, textvariable=self.height_var, width=10).pack(fill="x", pady=2)
        
        self.maintain_aspect = tk.BooleanVar(value=True)
        ttk.Checkbutton(resize_frame, text="Maintain Aspect Ratio", 
                       variable=self.maintain_aspect).pack(anchor="w", pady=2)
        
        ttk.Button(resize_frame, text="Resize Image", command=self.resize_image).pack(fill="x", pady=2)
        
        rotate_frame = ttk.LabelFrame(control_frame, text="Rotation", padding="5")
        rotate_frame.pack(fill="x", pady=(0, 10))
        
        ttk.Label(rotate_frame, text="Angle (degrees):").pack(anchor="w")
        self.angle_var = tk.StringVar(value="0")
        ttk.Entry(rotate_frame, textvariable=self.angle_var, width=10).pack(fill="x", pady=2)
        
        angle_buttons_frame = ttk.Frame(rotate_frame)
        angle_buttons_frame.pack(fill="x", pady=2)
        
        ttk.Button(angle_buttons_frame, text="90°", width=5,
                  command=lambda: self.set_angle(90)).pack(side="left", padx=1)
        ttk.Button(angle_buttons_frame, text="180°", width=5,
                  command=lambda: self.set_angle(180)).pack(side="left", padx=1)
        ttk.Button(angle_buttons_frame, text="270°", width=5,
                  command=lambda: self.set_angle(270)).pack(side="left", padx=1)
        
        ttk.Button(rotate_frame, text="Rotate Image", command=self.rotate_image).pack(fill="x", pady=2)
        
        blur_frame = ttk.LabelFrame(control_frame, text="Blur", padding="5")
        blur_frame.pack(fill="x", pady=(0, 10))
        
        ttk.Label(blur_frame, text="Blur Type:").pack(anchor="w")
        self.blur_type = tk.StringVar(value="Gaussian")
        blur_combo = ttk.Combobox(blur_frame, textvariable=self.blur_type, 
                                 values=["Gaussian", "Box", "Motion"], state="readonly")
        blur_combo.pack(fill="x", pady=2)
        
        ttk.Label(blur_frame, text="Intensity:").pack(anchor="w")
        self.blur_intensity = tk.DoubleVar(value=2.0)
        blur_scale = ttk.Scale(blur_frame, from_=0.1, to=10.0, 
                              variable=self.blur_intensity, orient="horizontal")
        blur_scale.pack(fill="x", pady=2)
        
        self.blur_label = ttk.Label(blur_frame, text="2.0")
        self.blur_label.pack(anchor="w")
        blur_scale.configure(command=self.update_blur_label)
        
        ttk.Button(blur_frame, text="Apply Blur", command=self.blur_image).pack(fill="x", pady=2)
        display_frame = ttk.LabelFrame(main_frame, text="Image Display", padding="5")
        display_frame.grid(row=0, column=1, sticky=(tk.W, tk.E, tk.N, tk.S))
        display_frame.columnconfigure(0, weight=1)
        display_frame.rowconfigure(0, weight=1)
        
        self.canvas = tk.Canvas(display_frame, bg="white", relief="sunken", bd=1, 
                               highlightthickness=0)
        self.canvas.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        v_scrollbar = ttk.Scrollbar(display_frame, orient="vertical", command=self.canvas.yview)
        v_scrollbar.grid(row=0, column=1, sticky=(tk.N, tk.S))
        self.canvas.configure(yscrollcommand=v_scrollbar.set)
        
        h_scrollbar = ttk.Scrollbar(display_frame, orient="horizontal", command=self.canvas.xview)
        h_scrollbar.grid(row=1, column=0, sticky=(tk.W, tk.E))
        self.canvas.configure(xscrollcommand=h_scrollbar.set)
        
        self.status_var = tk.StringVar(value="Ready - Please load an image")
        status_bar = ttk.Label(main_frame, textvariable=self.status_var, relief="sunken")
        status_bar.grid(row=1, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=(10, 0))
    
    def update_filter_intensity_label(self, value):
        self.filter_intensity_label.config(text=f"{float(value):.1f}")
    
    def on_filter_select(self, event=None):
        if self.filter_type.get() == "Custom":
            self.custom_kernel_frame.pack(fill="x", pady=(5, 0))
        else:
            self.custom_kernel_frame.pack_forget()
    
    def get_predefined_kernel(self, filter_name):
        kernels = {
            "Sharpen": np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]]),
            "Edge Detection": np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]]),
            "Emboss": np.array([[-2, -1, 0], [-1, 1, 1], [0, 1, 2]]),
            "High Pass": np.array([[-1, -1, -1], [-1, 9, -1], [-1, -1, -1]]),
            "Gaussian Sharpen": np.array([[0, -1, 0], [-1, 6, -1], [0, -1, 0]]) / 2,
            "Unsharp Mask": np.array([[-1, -4, -1], [-4, 20, -4], [-1, -4, -1]]) / 8
        }
        return kernels.get(filter_name)
    
    def apply_filter(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        filter_name = self.filter_type.get()
        
        if filter_name == "None":
            return
        elif filter_name == "Custom":
            self.apply_custom_kernel()
            return
        
        try:
            kernel = self.get_predefined_kernel(filter_name)
            if kernel is None:
                messagebox.showerror("Error", f"Unknown filter: {filter_name}")
                return
            
            intensity = self.filter_intensity.get()
            if filter_name in ["Sharpen", "Gaussian Sharpen", "High Pass"]:
                center = kernel.shape[0] // 2
                original_center = kernel[center, center]
                kernel = kernel.copy()
                kernel[center, center] = (original_center - 1) * intensity + 1
            elif filter_name == "Unsharp Mask":
                kernel = kernel * intensity
            
            img_array = np.array(self.processed_image)
            
            if len(img_array.shape) == 3:
                for i in range(img_array.shape[2]):
                    img_array[:, :, i] = ndimage.convolve(img_array[:, :, i], kernel, mode='reflect')
            else:
                img_array = ndimage.convolve(img_array, kernel, mode='reflect')
            
            img_array = np.clip(img_array, 0, 255)
            
            self.processed_image = Image.fromarray(np.uint8(img_array))
            self.display_image_on_canvas()
            self.status_var.set(f"Applied {filter_name} filter (intensity: {intensity:.1f})")
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to apply filter: {str(e)}")
    
    def set_angle(self, angle):
        self.angle_var.set(str(angle))
    
    def load_image(self):
        file_path = filedialog.askopenfilename(
            title="Select Image",
            filetypes=[
                ("Image files", "*.jpg *.jpeg *.png *.bmp *.gif *.tiff"),
                ("All files", "*.*")
            ]
        )
        
        if file_path:
            try:
                self.original_image = Image.open(file_path)
                self.processed_image = self.original_image.copy()
                self.display_image_on_canvas()
                
                # Update size fields with current image size
                self.width_var.set(str(self.original_image.width))
                self.height_var.set(str(self.original_image.height))
                
                self.status_var.set(f"Loaded: {os.path.basename(file_path)} "
                                  f"({self.original_image.width}x{self.original_image.height})")
                
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load image: {str(e)}")
    
    def save_image(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image to save")
            return
        
        file_path = filedialog.asksaveasfilename(
            title="Save Image",
            defaultextension=".png",
            filetypes=[
                ("PNG files", "*.png"),
                ("JPEG files", "*.jpg"),
                ("All files", "*.*")
            ]
        )
        
        if file_path:
            try:
                self.processed_image.save(file_path)
                self.status_var.set(f"Saved: {os.path.basename(file_path)}")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to save image: {str(e)}")
    
    def reset_image(self):
        if self.original_image is None:
            messagebox.showwarning("Warning", "No original image loaded")
            return
        
        self.processed_image = self.original_image.copy()
        self.display_image_on_canvas()
        self.status_var.set("Image reset to original")
    
    def display_image_on_canvas(self):
        if self.processed_image is None:
            return
        
        self.display_image = ImageTk.PhotoImage(self.processed_image)
        
        self.canvas.delete("all")
        self.canvas.create_image(0, 0, anchor="nw", image=self.display_image)
        
        self.canvas.configure(scrollregion=self.canvas.bbox("all"))
    
    def resize_image(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        try:
            width = int(self.width_var.get())
            height = int(self.height_var.get())
            
            if width <= 0 or height <= 0:
                raise ValueError("Width and height must be positive")
            
            if self.maintain_aspect.get():
                original_ratio = self.processed_image.width / self.processed_image.height
                new_ratio = width / height
                
                if new_ratio > original_ratio:
                    width = int(height * original_ratio)
                else:
                    height = int(width / original_ratio)
                
                self.width_var.set(str(width))
                self.height_var.set(str(height))
            
            self.processed_image = self.processed_image.resize((width, height), Image.Resampling.LANCZOS)
            self.display_image_on_canvas()
            self.status_var.set(f"Resized to {width}x{height}")
            
        except ValueError as e:
            messagebox.showerror("Error", f"Invalid size values: {str(e)}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to resize image: {str(e)}")
    
    def rotate_image(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        try:
            angle = float(self.angle_var.get())
            self.processed_image = self.processed_image.rotate(angle, expand=True, fillcolor='white')
            self.display_image_on_canvas()
            self.status_var.set(f"Rotated by {angle} degrees")
            
        except ValueError:
            messagebox.showerror("Error", "Invalid angle value")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to rotate image: {str(e)}")
    
    def blur_image(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        try:
            blur_type = self.blur_type.get()
            intensity = self.blur_intensity.get()
            
            if blur_type == "Gaussian":
                self.processed_image = self.processed_image.filter(ImageFilter.GaussianBlur(radius=intensity))
            elif blur_type == "Box":
                self.processed_image = self.processed_image.filter(ImageFilter.BoxBlur(radius=intensity))
            elif blur_type == "Motion":
                kernel_size = int(intensity * 2) + 1
                kernel = np.zeros((kernel_size, kernel_size))
                kernel[kernel_size//2, :] = 1.0
                kernel = kernel / kernel.sum()
                
                img_array = np.array(self.processed_image)
                
                if len(img_array.shape) == 3:
                    for i in range(img_array.shape[2]):
                        img_array[:, :, i] = ndimage.convolve(img_array[:, :, i], kernel, mode='reflect')
                else:
                    img_array = ndimage.convolve(img_array, kernel, mode='reflect')
                
                self.processed_image = Image.fromarray(np.uint8(img_array))
            
            self.display_image_on_canvas()
            self.status_var.set(f"Applied {blur_type} blur (intensity: {intensity:.1f})")
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to apply blur: {str(e)}")
    
    def update_blur_label(self, value):
        self.blur_label.config(text=f"{float(value):.1f}")
    
    def update_filter_intensity_label(self, value):
        self.filter_intensity_label.config(text=f"{float(value):.1f}")
    
    def on_filter_select(self, event=None):
        if self.filter_type.get() == "Custom":
            self.custom_kernel_frame.pack(fill="x", pady=(5, 0))
        else:
            self.custom_kernel_frame.pack_forget()
    
    def get_predefined_kernel(self, filter_name):
        kernels = {
            "Sharpen": np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]]),
            "Edge Detection": np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]]),
            "Emboss": np.array([[-2, -1, 0], [-1, 1, 1], [0, 1, 2]]),
            "High Pass": np.array([[-1, -1, -1], [-1, 9, -1], [-1, -1, -1]]),
            "Gaussian Sharpen": np.array([[0, -1, 0], [-1, 6, -1], [0, -1, 0]]) / 2,
            "Unsharp Mask": np.array([[-1, -4, -1], [-4, 20, -4], [-1, -4, -1]]) / 8
        }
        return kernels.get(filter_name)
    
    def apply_filter(self):
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        filter_name = self.filter_type.get()
        
        if filter_name == "None":
            return
        elif filter_name == "Custom":
            self.apply_custom_kernel()
            return
        
        try:
            kernel = self.get_predefined_kernel(filter_name)
            if kernel is None:
                messagebox.showerror("Error", f"Unknown filter: {filter_name}")
                return
            
            intensity = self.filter_intensity.get()
            if filter_name in ["Sharpen", "Gaussian Sharpen", "High Pass"]:
                center = kernel.shape[0] // 2
                original_center = kernel[center, center]
                kernel = kernel.copy()
                kernel[center, center] = (original_center - 1) * intensity + 1
            elif filter_name == "Unsharp Mask":
                kernel = kernel * intensity
            
            img_array = np.array(self.processed_image)
            
            if len(img_array.shape) == 3:
                for i in range(img_array.shape[2]):
                    img_array[:, :, i] = ndimage.convolve(img_array[:, :, i], kernel, mode='reflect')
            else:
                img_array = ndimage.convolve(img_array, kernel, mode='reflect')
            
            img_array = np.clip(img_array, 0, 255)
            
            self.processed_image = Image.fromarray(np.uint8(img_array))
            self.display_image_on_canvas()
            self.status_var.set(f"Applied {filter_name} filter (intensity: {intensity:.1f})")
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to apply filter: {str(e)}")
        if self.processed_image is None:
            messagebox.showwarning("Warning", "No image loaded")
            return
        
        try:
            kernel_text = self.kernel_text.get("1.0", tk.END).strip()
            lines = kernel_text.split('\n')
            
            kernel = []
            for line in lines:
                if line.strip():
                    row = [float(x) for x in line.split()]
                    kernel.append(row)
            
            kernel = np.array(kernel)
            
            if kernel.shape[0] != kernel.shape[1]:
                raise ValueError("Kernel must be square")
            
            if kernel.shape[0] % 2 == 0:
                raise ValueError("Kernel size must be odd")
            
            img_array = np.array(self.processed_image)
            
            if len(img_array.shape) == 3:
                for i in range(img_array.shape[2]):
                    img_array[:, :, i] = ndimage.convolve(img_array[:, :, i], kernel, mode='reflect')
            else:
                img_array = ndimage.convolve(img_array, kernel, mode='reflect')
            
            img_array = np.clip(img_array, 0, 255)
            
            self.processed_image = Image.fromarray(np.uint8(img_array))
            self.display_image_on_canvas()
            self.status_var.set(f"Applied custom kernel ({kernel.shape[0]}x{kernel.shape[1]})")
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to apply custom kernel: {str(e)}")

def main():
    root = tk.Tk()
    app = ImageProcessor(root)
    root.mainloop()

if __name__ == "__main__":
    main()