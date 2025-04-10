import PatchMatchStereo as pms  # Assuming the module is named PatchMatchStereo
import cv2
import numpy as np

class PMSOptions:
    def __init__(self):
        self.max_iterations = 5
        self.disparity_range = (0, 64)  # Min and max disparity
        self.window_size = 5
        self.smoothing = True
        self.smoothness_weight = 0.1

def main():
    # Example parameters for PatchMatchStereo
    left_image_path = "/home/qinglin/workspace/generalprompt/codes/PatchMatchStereo/Data/Cone/im2.png"
    right_image_path = "/home/qinglin/workspace/generalprompt/codes/PatchMatchStereo/Data/Cone/im6.png"
    disparity_range = (0, 64)  # Min and max disparity

    # Load images (assuming the function requires paths)
    left_image = cv2.imread(left_image_path, cv2.IMREAD_COLOR)
    right_image = cv2.imread(right_image_path, cv2.IMREAD_COLOR)

    height, width = left_image.shape[:2]
    pms_option = pms.PMSOptions()
    pms_class = pms.PatchMatchStereo(height, width, pms_option)
    disparity = np.zeros((height, width), dtype=np.float32)
    # Initialize PatchMatchStereo
    pms_class.Match(left_image, right_image, disparity)


    # Compute disparity map
    # disparity_map = stereo.compute(left_image, right_image)

    # Save or display the disparity map
    # pms.save_disparity_map("disparity_map.png", disparity_map)

if __name__ == "__main__":
    main()