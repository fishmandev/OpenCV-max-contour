#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
    Mat src, dst;
    vector<vector<Point> > contours;
    char src_filename[] = "../images/src.png";
    char dst_filename[] = "../images/dst.png";
    int max_index = 0;
    double max_area_value = 0;

    src = imread(src_filename, CV_LOAD_IMAGE_COLOR);

    if (!src.data) {
        printf("Could not open the image file '%s'", src_filename);
        return -1;
    }

    cvtColor(src, dst, CV_RGB2GRAY);
    threshold(dst, dst, 250, 255, CV_THRESH_BINARY);
    bitwise_not(dst, dst);
    findContours(dst.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    Mat contourImage(src.size(), CV_8UC3, Scalar(255,255,255));

    for (size_t idx = 0; idx < contours.size(); idx++) {
        if (max_area_value < contourArea(contours[idx])) {
            max_area_value = contourArea(contours[idx]);
            max_index = idx;
        }
    }

    drawContours(contourImage, contours, max_index, Scalar(0, 0, 0));
    imwrite(dst_filename, contourImage);

    return 0;
}