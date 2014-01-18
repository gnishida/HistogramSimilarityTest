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
	if (argc < 2) {
		return 1;
	}

	RoadGraph r;
	GraphUtil::loadRoads(r, argv[1]);

	cv::MatND hist[6];
	for (int i = 0; i < 6; i++) {
		int x = -1500 + i * 500;
		RoadGraph patch;
		BBox box(QVector2D(x, 0));
		box.addPoint(QVector2D(x + 500, 500));
		GraphUtil::copyRoads(r, patch);
		GraphUtil::extractRoads(patch, box, false);
		hist[i] = GraphUtil::computeEdgeLengthHistogram(patch, 10);
		std::cout << "hist" << i << ": " << hist[i] << std::endl;
	}

	for (int i = 0; i < 6; i++) {
		std::cout << i << ": ";
		for (int j = 0; j < i; j++) {
			std::cout << cv::compareHist(hist[i], hist[j], 0) << ", ";
		}
		std::cout << std::endl;
	}

}