#include "open.hpp"

cv::Mat prepare(const cv::Mat& img) {
    cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
    cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
    dilate(imgCanny, imgDil, kernel);
    cv::bitwise_not(imgDil, imgDil);
    return imgDil;
}

void result(const cv::Mat& img, cv::Mat& output) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    for (std::size_t idx = 0; idx < contours.size(); idx++) {
        int area = cv::contourArea(contours[idx]);
        if (area > 500)
        {
            cv::Rect rect = cv::boundingRect(contours[idx]);
            if (hierarchy[idx][3] == 0) {
                cv::rectangle(output, rect, cv::Scalar(0, 255, 0), 3);
            }
        }
    }


}