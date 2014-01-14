/**
 * ヒストグラム間の類似度に関する実験
 *
 * @author Gen Nishida
 * @version 1.0
 */

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QVector2D>
#include <QHash>
#include "GraphUtil.h"
#include "BBox.h"

int main(int argc, char *argv[]) {
	int size = 10;
	float range[] = { 0, 300 };
	const float* ranges = { range };

	// create a histogram
	cv::Mat data1 = (cv::Mat_<double>(1, 10) << 20, 30, 30, 40, 80, 90, 120, 120, 130, 150);
	cv::MatND hist1;
	cv::calcHist(&data1, 1, 0, cv::Mat(), hist1, 1, &size, &ranges, true, false);

	// create a histogram
	cv::Mat data2 = (cv::Mat_<double>(1, 10) << 30, 33, 40, 70, 90, 100, 130, 135, 140, 154);
	cv::MatND hist2;
	cv::calcHist(&data2, 1, 0, cv::Mat(), hist2, 1, &size, &ranges, true, false);

	// compute the similarity
	float similarity = cv::compareHist(hist1, hist2, 0);
	printf("%lf\n", similarity);

	// Display
	/*
	cv::flip(result, result, 1);
	cv::namedWindow("segmentation", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("segmentation", result * 64);
	*/

	cv::waitKey(0);
}