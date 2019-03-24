#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class Transform
{
public:
	Transform(Mat one);
	Transform();
	~Transform();
	
	void showImage();
private:
	Mat self;
	CvPoint p;
};

Transform::Transform(Mat one)
{
	self = one.clone();
	p = cvPoint(one.rows / 2, one.cols / 2);
}
Transform::Transform()
{
	cout << "´´½¨Ê§°Ü\n";
}

Transform::~Transform()
{
	self.~Mat();
}
void Transform::showImage()
{
	double scale = -3;
	if (self.empty())
	{
		cout << "¶ÁÈëÍ¼ÏñÊ§°Ü\n";
	}
	else {
	for (int i = 0; i<self.rows; i++)
	{
		for (int j = 0; j<self.cols; j++)
		{
			double dx = (double)(j - p.x) / p.x;
			double dy = (double)(i - p.y) / p.y;
			double weight = exp((dx*dx + dy*dy)*scale);
			Vec3b &ptr = self.at<Vec3b>(i, j);
			ptr[0] = saturate_cast<uchar>(ptr[0] * weight);
			ptr[1] = saturate_cast<uchar>(ptr[1] * weight);
			ptr[2] = saturate_cast<uchar>(ptr[2] * weight);
		}
	}
	imshow("±ä»»ºó", self);
	}
}