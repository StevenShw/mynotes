
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv) {
  // 读取视频
  cv::VideoCapture cap("video.mp4");
  if (!cap.isOpened()) {
    std::cerr << "Failed to open video file!" << std::endl;
    return -1;
  }

  // 读取第一帧图像
  cv::Mat frame, template_image, gray_template;
  cap >> frame;
  cv::Rect roi = cv::selectROI(frame);
  template_image = frame(roi).clone();
  cv::cvtColor(template_image, gray_template, cv::COLOR_BGR2GRAY);

  // 创建相关性滤波器
  cv::Mat correlation;
  cv::Mat hann_window = cv::createHanningWindow(gray_template.size(), CV_32F);
  cv::dft(gray_template, gray_template, cv::DFT_COMPLEX_OUTPUT);
  cv::mulSpectrums(gray_template, gray_template, gray_template, 0, true);
  cv::idft(gray_template, correlation, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT);

  // 定义阈值
  double threshold = 0.8;

  // 进行目标追踪
  while (cap.read(frame)) {
    cv::Mat gray_frame;
    cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);

    // 进行相关性滤波
    cv::Mat image;
    gray_frame.convertTo(image, CV_32F);
    cv::dft(image, image, cv::DFT_COMPLEX_OUTPUT);
    cv::mulSpectrums(image, gray_template, image, 0, true);
    cv::idft(image, image, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT);

    // 查找最大相关值
    double min_val, max_val;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(image, &min_val, &max_val, &min_loc, &max_loc);

    // 绘制矩形框
    cv::Rect bbox(max_loc.x, max_loc.y, gray_template.cols, gray_template.rows);
    cv::rectangle(frame, bbox, cv::Scalar(0, 255, 0), 2);

    // 更新模板
    if (max_val >= threshold) {
      roi.x = max_loc.x;
      roi.y = max_loc.y;
      template_image = frame(roi).clone();
      cv::cvtColor(template_image, gray_template, cv::COLOR_BGR2GRAY);
      cv::dft(gray_template, gray_template, cv::DFT_COMPLEX_OUTPUT);
      cv::mulSpectrums(gray_template, gray_template, gray_template, 0, true);
      cv::idft(gray_template, correlation, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT);
    }

    // 显示图像
    cv::imshow("Frame", frame);

    if (cv::waitKey(1) == 27) break;
  }

  return 0;
}
