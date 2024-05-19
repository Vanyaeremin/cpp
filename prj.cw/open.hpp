#pragma once
#ifndef OPEN_HPP
#define OPEN_HPP

#include <cstddef>
#include <vector>
#include <opencv2/opencv.hpp>

cv::Mat prepare(const cv::Mat& img);
void result(const cv::Mat& img, cv::Mat& output);

#endif


