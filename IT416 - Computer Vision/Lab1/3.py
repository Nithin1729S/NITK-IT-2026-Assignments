import tkinter as tk
from tkinter import filedialog, messagebox
import cv2
import numpy as np
from PIL import Image, ImageTk
import os

class FaceDetector:
    def __init__(self, root):
        self.root = root
        self.root.title("Face Detection and Counting System")
        self.root.geometry("1000x800")
        self.root.configure(bg='white')

        self.current_file = None
        self.cap = None
        self.running = False
        self.is_video = False
        self.load_face_detector()
        
        self.setup_ui()

    def load_face_detector(self):
        try:
            self.face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load face detection model: {str(e)}")

    def setup_ui(self):
        control_frame = tk.Frame(self.root, bg='white', relief=tk.RAISED, bd=1)
        control_frame.pack(fill=tk.X, padx=5, pady=5)
        file_frame = tk.Frame(control_frame, bg='white')
        file_frame.pack(side=tk.LEFT, padx=5)
        tk.Button(file_frame, text="Load Image", bg="#4CAF50", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.load_image).pack(side=tk.LEFT, padx=2)
        tk.Button(file_frame, text="Load Video", bg="#2196F3", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.load_video).pack(side=tk.LEFT, padx=2)
        tk.Button(file_frame, text="Use Webcam", bg="#FF9800", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.use_webcam).pack(side=tk.LEFT, padx=2)
        detection_frame = tk.Frame(control_frame, bg='white')
        detection_frame.pack(side=tk.LEFT, padx=20)
        tk.Button(detection_frame, text="Detect Faces", bg="#9C27B0", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.detect_faces).pack(side=tk.LEFT, padx=5)
        video_frame = tk.Frame(control_frame, bg='white')
        video_frame.pack(side=tk.LEFT, padx=20)
        tk.Button(video_frame, text="Start Video", bg="#4CAF50", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.start_video_detection).pack(side=tk.LEFT, padx=2)
        tk.Button(video_frame, text="Stop", bg="#F44336", fg="white",
                  font=("Arial", 10, "bold"), relief=tk.FLAT, padx=15, pady=5,
                  command=self.stop_detection).pack(side=tk.LEFT, padx=2)
        status_frame = tk.Frame(self.root, bg='white')
        status_frame.pack(fill=tk.X, padx=5, pady=2)
        self.status_label = tk.Label(status_frame, text="Load an image or video to start face detection", 
                                   bg='white', font=("Arial", 10), fg='blue')
        self.status_label.pack(side=tk.LEFT)
        self.face_count_label = tk.Label(status_frame, text="Faces: 0", 
                                       bg='white', font=("Arial", 12, "bold"), fg='red')
        self.face_count_label.pack(side=tk.RIGHT, padx=20)
        self.canvas = tk.Canvas(self.root, bg='black', relief=tk.SUNKEN, bd=2)
        self.canvas.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        self.canvas.bind('<Configure>', self.on_canvas_resize)

    def on_canvas_resize(self, event):
        if hasattr(self, 'current_image') and self.current_image is not None and not self.running:
            self.display_image(self.current_image)

    def load_image(self):
        file_types = [
            ("Image files", "*.jpg *.jpeg *.png *.bmp *.tiff *.gif"),
            ("JPEG files", "*.jpg *.jpeg"),
            ("PNG files", "*.png"),
            ("All files", "*.*")
        ]
        
        file_path = filedialog.askopenfilename(
            title="Select Image File",
            filetypes=file_types,
            initialdir=os.path.join(os.path.expanduser("~"), "Downloads")
        )
        
        if file_path:
            try:
                self.current_file = file_path
                self.is_video = False
                image = cv2.imread(file_path)
                if image is None:
                    raise ValueError("Could not load image")
                
                self.current_image = image.copy()
                self.display_image(image)
                self.status_label.config(text=f"Loaded: {os.path.basename(file_path)}")
                self.face_count_label.config(text="Faces: 0")
                
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load image: {str(e)}")

    def load_video(self):
        file_types = [
            ("Video files", "*.mp4 *.avi *.mov *.mkv *.wmv *.flv"),
            ("MP4 files", "*.mp4"),
            ("AVI files", "*.avi"),
            ("All files", "*.*")
        ]
        
        file_path = filedialog.askopenfilename(
            title="Select Video File",
            filetypes=file_types,
            initialdir=os.path.join(os.path.expanduser("~"), "Downloads")
        )
        
        if file_path:
            try:
                if self.cap:
                    self.cap.release()
                
                self.cap = cv2.VideoCapture(file_path)
                if not self.cap.isOpened():
                    raise ValueError("Could not open video")
                
                self.current_file = file_path
                self.is_video = True
                self.status_label.config(text=f"Loaded: {os.path.basename(file_path)}")
                self.face_count_label.config(text="Faces: 0")
                
                ret, frame = self.cap.read()
                if ret:
                    self.current_image = frame.copy()
                    self.display_image(frame)
                    self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
                
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load video: {str(e)}")

    def use_webcam(self):
        try:
            if self.cap:
                self.cap.release()
            
            self.cap = cv2.VideoCapture(0)
            if not self.cap.isOpened():
                raise ValueError("Could not access webcam")
            
            self.current_file = "Webcam"
            self.is_video = True
            self.status_label.config(text="Webcam ready")
            self.face_count_label.config(text="Faces: 0")
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to access webcam: {str(e)}")

    def detect_faces_in_frame(self, frame):
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = self.face_cascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(80, 80),
            flags=cv2.CASCADE_SCALE_IMAGE
        )
        
        return faces

    def detect_faces(self):
        if not hasattr(self, 'current_image') or self.current_image is None:
            messagebox.showwarning("Warning", "Please load an image first!")
            return
        
        try:
            frame = self.current_image.copy()
            faces = self.detect_faces_in_frame(frame)
            for i, (x, y, w, h) in enumerate(faces):
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
                cv2.putText(frame, f'Face {i+1}', (x, y - 10),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
            cv2.putText(frame, f'Total Faces: {len(faces)}', (10, 30),
                       cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            self.display_image(frame)
            self.face_count_label.config(text=f"Faces: {len(faces)}")
            self.status_label.config(text=f"Detection complete - Found {len(faces)} face(s)")
            
        except Exception as e:
            messagebox.showerror("Error", f"Face detection failed: {str(e)}")

    def start_video_detection(self):
        if not self.cap:
            messagebox.showwarning("Warning", "Please load a video or start webcam first!")
            return
        
        self.running = True
        self.status_label.config(text="Running face detection...")
        self.process_video_frame()

    def stop_detection(self):
        self.running = False
        self.status_label.config(text="Detection stopped")

    def process_video_frame(self):
        if not self.running or not self.cap:
            return
        
        ret, frame = self.cap.read()
        if not ret:
            if self.current_file != "Webcam":
                self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
                ret, frame = self.cap.read()
            
            if not ret:
                self.running = False
                self.status_label.config(text="Video ended or webcam disconnected")
                return
        
        try:
            faces = self.detect_faces_in_frame(frame)
            for i, (x, y, w, h) in enumerate(faces):
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
                cv2.putText(frame, f'Face {i+1}', (x, y - 10),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
            cv2.putText(frame, f'Faces: {len(faces)}', (10, 30),
                       cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            self.display_image(frame)
            self.face_count_label.config(text=f"Faces: {len(faces)}")
            
        except Exception as e:
            print(f"Error processing frame: {str(e)}")
        
        # Schedule next frame
        if self.running:
            self.root.after(30, self.process_video_frame)

    def resize_image_to_canvas(self, image):
        """Resize image to fit canvas while maintaining aspect ratio"""
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
        
        if canvas_width <= 1 or canvas_height <= 1:
            return image
        
        img_height, img_width = image.shape[:2]
        
        # Calculate scaling factor
        scale_w = canvas_width / img_width
        scale_h = canvas_height / img_height
        scale = min(scale_w, scale_h)
        
        # Calculate new dimensions
        new_width = int(img_width * scale)
        new_height = int(img_height * scale)
        
        # Resize image
        resized_image = cv2.resize(image, (new_width, new_height))
        return resized_image

    def display_image(self, image):
        """Display image on canvas"""
        try:
            # Resize image to fit canvas
            display_image = self.resize_image_to_canvas(image)
            
            # Convert BGR to RGB
            image_rgb = cv2.cvtColor(display_image, cv2.COLOR_BGR2RGB)
            
            # Convert to PIL Image and then to PhotoImage
            pil_image = Image.fromarray(image_rgb)
            photo = ImageTk.PhotoImage(pil_image)
            
            # Clear canvas and display image
            self.canvas.delete("all")
            
            # Center image on canvas
            canvas_width = self.canvas.winfo_width()
            canvas_height = self.canvas.winfo_height()
            x_offset = (canvas_width - pil_image.width) // 2
            y_offset = (canvas_height - pil_image.height) // 2
            
            self.canvas.create_image(max(0, x_offset), max(0, y_offset), 
                                   anchor=tk.NW, image=photo)
            self.canvas.image = photo  # Keep a reference
            
        except Exception as e:
            print(f"Error displaying image: {str(e)}")

    def __del__(self):
        """Cleanup resources"""
        if self.cap:
            self.cap.release()

def main():
    root = tk.Tk()
    app = FaceDetector(root)
    root.mainloop()

if __name__ == "__main__":
    main()