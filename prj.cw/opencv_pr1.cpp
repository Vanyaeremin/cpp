#include <opencv2/highgui/highgui.hpp> 
#include <iostream>

int main() {
    cv::Mat img = cv::imread("C:/Users/vanyu/Desktop/1dd.jpg"); // Получение имени изображения
    cv::namedWindow("DisplayPicture", cv::WINDOW_AUTOSIZE);  // Создание окна
    cv::imshow("DisplayPicture", img); // Показ изображения
    cv::waitKey(0); // Освобождение памяти из под изображения
    cv::destroyAllWindows();
}

    