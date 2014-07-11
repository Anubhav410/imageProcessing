/*
 * Copyright (c) 2011. Philipp Wagner <bytefish[at]gmx[dot]de>.
 * Released to public domain under terms of the BSD Simplified license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the organization nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *   See <http://www.opensource.org/licenses/bsd-license>
 */
#include "myheader.h"


static Mat norm_0_255(InputArray _src) {
    Mat src = _src.getMat();
    // Create and return normalized image:
    Mat dst;
    switch(src.channels()) {
    case 1:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
        break;
    case 3:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
        break;
    default:
        src.copyTo(dst);
        break;
    }
    return dst;
}


 
void fisherFaces()
{ 
   	 string output_folder;
     string initialCSV = "D:\\Visual Studio Projects\\ImageProcessing\\ImageProcessing\\initialCSV.csv";	//trainer set CSV
	 string inputCSV = "D:\\Visual Studio Projects\\ImageProcessing\\ImageProcessing\\inputCSV.csv";	//the images to be tested

	 vector<Mat> testSample;	//this vector will store all the images to be tested/recognized
     vector<int> testLabels;	//labels for images to be tested

     vector<myImage> images; //this vector will store all the images to be used for training
    // vector<int> labels; //labels for the input trainer set
     
     Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer(0);//250.0);	//	 Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();
	 
	 myTrainer(modelFisher,images,labels,initialCSV);    
     read_csv(inputCSV, testSample, testLabels,';');	//reading the input images and labels
      
	 myRecognizer(modelFisher, testSample , testLabels);

#if 0
     Ptr<FaceRecognizer> modelLBPH = createLBPHFaceRecognizer();//250.0);	//	 Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();
	 
	 myTrainer(modelLBPH,images,labels,initialCSV);    
     read_csv(inputCSV, testSample, testLabels,';');	//reading the input images and labels
      
	 myRecognizer(modelLBPH, testSample , testLabels);

     Ptr<FaceRecognizer> modelEigen = createEigenFaceRecognizer(0);//250.0);	//	 Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();
	 
	 myTrainer(modelEigen,images,labels,initialCSV);    
     read_csv(inputCSV, testSample, testLabels,';');	//reading the input images and labels
      
	 myRecognizer(modelEigen, testSample , testLabels);

#endif 
}
int main()
{
// 	createCSV("D:/Visual Studio Projects/ImageProcessing/ImageProcessing/Below_Thresh/" , "D:/Visual Studio Projects/ImageProcessing/ImageProcessing/inputCSV.csv");
//	getchar();
	fisherFaces();
//	getchar();
}