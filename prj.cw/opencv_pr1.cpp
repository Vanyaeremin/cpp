#include <opencv2/highgui/highgui.hpp> 
#include <iostream>

int main() {
    cv::Mat img = cv::imread("C:/Users/vanyu/Desktop/1dd.jpg"); // ��������� ����� �����������
    cv::namedWindow("DisplayPicture", cv::WINDOW_AUTOSIZE);  // �������� ����
    cv::imshow("DisplayPicture", img); // ����� �����������
    cv::waitKey(0); // ������������ ������ �� ��� �����������
    cv::destroyAllWindows();
}

    