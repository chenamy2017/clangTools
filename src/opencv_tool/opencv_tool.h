//
// Created by caesar kekxv on 2020/2/26.
//

#ifndef TOOLS_OPENCV_TOOL_H
#define TOOLS_OPENCV_TOOL_H
#ifdef ENABLE_OPENCV

#include <string>
#include <opencv2/opencv.hpp>

#ifdef ENABLE_GTK3

#include <gdk/gdk.h>

#endif

class opencv_tool {
public:
    static opencv_tool *instance();

    explicit opencv_tool(std::string faceXml = "");

    int init(const std::string &filename = "");

    ~opencv_tool();

    bool findMaxFace(const cv::Mat &inMat, std::vector<cv::Rect> &faces);

    cv::Mat findMaxFace(const cv::Mat &inMat);

    inline bool isLoad() {
        return !faceCascade.empty();
    }

public:

    static cv::Mat CreateQrCode(const std::string& data,int size = 2);

    static void create2dArray(cv::Mat *input, uint8_t ***outputPtr);

    static void ImgDithering(const cv::Mat &dithImg, std::vector<std::vector<unsigned char>> &outputPtr);

    // static bool putText(cv::Mat &img, const std::string &text, cv::Point org,
    //                     int fontFace, double fontScale, cv::Scalar color,
    //                     int thickness = 1, int lineType = cv::LINE_8,
    //                     bool bottomLeftOrigin = false, const std::string file_path = "");

    template<typename T>
    static std::vector<int> argsort(const std::vector<T> &array);

// 实现argsort功能
    template<typename T>
    static std::vector<int> argsort(const std::vector<T> &array, const std::vector<T> &array2);

    /**
     * NMS 方法（Non Maximum Suppression，非极大值抑制）
     * @param boxes
     * @param overlapThresh
     * @return
     */
    static int
    nms(std::vector<cv::RotatedRect> &results, std::vector<cv::RotatedRect> boxes, float overlapThresh = 0.5);

    /**
     * 检测文本区域
     * @param srcImage
     * @return
     */
    static std::vector<cv::RotatedRect> FindLine_mserGetPlate(const cv::Mat &srcImage);

    static std::vector<cv::RotatedRect> FindLine_Gray(const cv::Mat &srcImage);

    /**
     * 检测文本区域
     * @param srcImage
     * @return
     */
    static int
    FindLine(const cv::Mat &srcImage, std::vector<cv::RotatedRect> &texts, std::vector<cv::RotatedRect> &faces,
             bool useMserGetPlate = false);

    static int WarpAffine(const cv::Mat &srcImage, std::vector<cv::Mat> &outImage, cv::RotatedRect box);

#ifdef ENABLE_GTK3

    static GdkPixbuf *MatToGdkPixbuf(const cv::Mat& inMat);

#endif
private:
    std::string faceXml = "./haarcascades/haarcascade_frontalface_alt2.xml";
    // string faceXml = "./haarcascades/haarcascade_frontalface_default.xml";
    cv::CascadeClassifier faceCascade;

    static uint8_t saturated_add(uint8_t val1, int8_t val2);

public:
    static void rotate180(cv::OutputArray &inMat);
};


#endif //ENABLE_OpenCV
#endif //TOOLS_OPENCV_TOOL_H
