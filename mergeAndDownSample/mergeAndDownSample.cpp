#include "pch.h"
#include "mergeAndDownsample.h"
#define even 2

bool mergeAndDownsample2x2Images(const std::string& vImage00, const std::string& vImage01, const std::string& vImage10, const std::string& vImage11, const std::string& vOutputImage)
{
	_ASSERTE(!vImage00.empty() && !vImage01.empty() && !vImage10.empty() && !vImage11.empty());

	cv::Mat Image00 = cv::imread(vImage00);
	cv::Mat Image01 = cv::imread(vImage01);
	cv::Mat Image10 = cv::imread(vImage10);
	cv::Mat Image11 = cv::imread(vImage11);

	if (Image00.empty() || Image01.empty() || Image10.empty() || Image11.empty())
	{
		std::cerr << "Error: One or more images could not be loaded" << std::endl;
		return false;
	}

	if (Image00.size() != Image01.size() || Image00.size() != Image10.size() || Image00.size() != Image11.size())
	{
		std::cerr << "Error : Images have differrnt sizes" << std::endl;
		return false;
	}

	if (Image00.cols % even != 0 || Image00.rows % even != 0)
	{
		std::cerr << "Error : Images are not qualified !" << std::endl;
		return false;
	}

	int Width = Image00.cols * even;
	int Height = Image00.rows * even;

	cv::Mat CombinedImage = cv::Mat(Height, Width, CV_8UC3, cv::Scalar::all(0));
	Image00.copyTo(CombinedImage(cv::Rect(0, 0, Image00.cols, Image00.rows)));
	Image01.copyTo(CombinedImage(cv::Rect(Image00.cols, 0, Image00.cols, Image00.rows)));
	Image10.copyTo(CombinedImage(cv::Rect(0, Image00.rows, Image00.cols, Image00.rows)));
	Image11.copyTo(CombinedImage(cv::Rect(Image00.cols, Image00.rows, Image00.cols, Image00.rows)));

	cv::Mat downsampleImage;
	cv::pyrDown(CombinedImage, downsampleImage, Image00.size());
	cv::Mat OutputImage;
	cv::resize(downsampleImage, OutputImage, Image00.size());

	if (!cv::imwrite(vOutputImage, downsampleImage))
	{
		std::cerr << "Erroe: Unable to write the output image" << std::endl;
		return false;
	}
	return true;
}