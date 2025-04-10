import PatchMatchStereo as pms  # Assuming the module is named PatchMatchStereo

def main():
    # Example parameters for PatchMatchStereo
    left_image_path = "left_image.png"
    right_image_path = "right_image.png"
    disparity_range = (0, 64)  # Min and max disparity

    # Load images (assuming the function requires paths)
    left_image = pms.load_image(left_image_path)
    right_image = pms.load_image(right_image_path)

    # Initialize PatchMatchStereo
    stereo = pms.PatchMatchStereo(disparity_range[0], disparity_range[1])

    # Compute disparity map
    disparity_map = stereo.compute(left_image, right_image)

    # Save or display the disparity map
    pms.save_disparity_map("disparity_map.png", disparity_map)

if __name__ == "__main__":
    main()