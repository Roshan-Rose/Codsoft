#include <iostream>
using namespace std;

// Display menu
void displayMenu() {
    cout << "\n==== Image Processing Tool ====\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Resize Image\n";
    cout << "4. Crop Image\n";
    cout << "5. Apply Grayscale Filter\n";
    cout << "6. Apply Blur Filter\n";
    cout << "7. Apply Sharpen Filter\n";
    cout << "8. Adjust Brightness & Contrast\n";
    cout << "9. Save Image\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

void resizeImage(Mat& image) {
    int width, height;
    cout << "Enter new width: ";
    cin >> width;
    cout << "Enter new height: ";
    cin >> height;
    resize(image, image, Size(width, height));
    cout << "Image resized.\n";
}

void cropImage(Mat& image) {
    int x, y, w, h;
    cout << "Enter top-left x: "; cin >> x;
    cout << "Enter top-left y: "; cin >> y;
    cout << "Enter width: "; cin >> w;
    cout << "Enter height: "; cin >> h;

    Rect roi(x, y, w, h);
    if (x + w <= image.cols && y + h <= image.rows) {
        image = image(roi);
        cout << "Image cropped.\n";
    } else {
        cout << "Invalid crop dimensions.\n";
    }
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
    cvtColor(image, image, COLOR_GRAY2BGR); // Convert back to 3 channels
    cout << "Grayscale filter applied.\n";
}

void applyBlur(Mat& image) {
    int kernelSize;
    cout << "Enter kernel size (odd number): ";
