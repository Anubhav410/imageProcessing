#ifndef myHEADER
#define myHEADER
#include "myHeader.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include<stdio.h>
#include<dirent.h>

using namespace cv;
using namespace std;

class myImage
{
	Mat img;
	int label;
	char* path;
};

int fisherFaces(const char *outFolder,const char* CVSFile,int inputSize,const char* inputCVS);
void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator);
void myTrainer(Ptr<FaceRecognizer>& model, vector<Mat>& images,vector<int>& labels , string initialCSV);
bool myRecognizer(Ptr<FaceRecognizer>& model,  vector<Mat> testSample ,vector<int> testLabels);
void createCSV(const char* readFolder, const char* );
#endif