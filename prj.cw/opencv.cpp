//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <string>
//#include <vector>
//
//
//cv::Mat prepare(const cv::Mat& img) {
//    cv::Mat gray;
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); 
//
//    cv::Mat enhancedImage;
//    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
//    clahe->setClipLimit(80);
//    clahe->apply(gray, enhancedImage);
//
//    cv::Mat thresh;
//    cv::threshold(enhancedImage, thresh, 120, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
//
//    cv::Mat img_erode;
//    cv::erode(thresh, img_erode, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9)), cv::Point(-1, -1), 1);
//
//    return img_erode;
//}
//
//cv::Mat prepare1(const cv::Mat& img) {
//
//    cv::Mat gray;
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
//
//    cv::Mat thresh;
//    cv::threshold(gray, thresh, 120, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
//
//    cv::Mat img_erode;
//    cv::erode(thresh, img_erode, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9)), cv::Point(-1, -1), 1);
//
//    return img_erode;
//}
//
//void result(const cv::Mat& img, cv::Mat& output) {
//    std::vector<std::vector<cv::Point>> contours; 
//    std::vector<cv::Vec4i> hierarchy; 
//    cv::findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE); 
//
//    for (std::size_t idx = 0; idx < contours.size(); idx++) { 
//        cv::Rect rect = cv::boundingRect(contours[idx]); 
//        if (hierarchy[idx][3] == 0) {
//            cv::rectangle(output, rect, cv::Scalar(0, 255, 0), 1);
//        }
//    }
//}
//
//int main()
//{
//
//    //OPENFILENAME ofn;       // common dialog box structure
//    //wchar_t szFile[260];       // buffer for file name
//
//    //ZeroMemory(&ofn, sizeof(ofn));
//    //ofn.lStructSize = sizeof(ofn);
//    //ofn.hwndOwner = NULL;
//    //ofn.lpstrFile = szFile;
//    //ofn.lpstrFile[0] = '\0';
//    //ofn.nMaxFile = sizeof(szFile);
//    //ofn.lpstrFilter = L"Image Files (*.jpg, *.png, *.bmp)\0*.jpg;*.png;*.bmp";
//    //ofn.nFilterIndex = 1;
//    //ofn.lpstrFileTitle = NULL;
//    //ofn.nMaxFileTitle = 0;
//    //ofn.lpstrInitialDir = NULL;
//    //ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//
//    //GetOpenFileName(&ofn);
//    //    cv::Mat image = cv::imread(szFile);
//    //}
//   
//    cv::Mat img = cv::imread("C:/Users/vanyu/Desktop/final_test.png");
//    cv::Mat output = img.clone();
//    cv::Mat prepareim = prepare(img);
//    result(prepareim, output);
//    cv::Mat prepareim1 = prepare1(img);
//    result(prepareim1, output);
//    cv::bitwise_not(img, img);
//    cv::Mat prepareim2 = prepare(img);
//    result(prepareim2, output);
//    cv::Mat prepareim3 = prepare1(img);
//    result(prepareim3, output);
//
//    cv::Mat resized_image;
//    cv::resize(output, resized_image, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);
//    std::string windowName = "PetProject";
//    cv::namedWindow(windowName);
//    cv::imshow(windowName, resized_image);
//    cv::waitKey(0);
//    cv::destroyAllWindows();
//
//}
//
