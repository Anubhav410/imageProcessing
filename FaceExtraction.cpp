/**
 * @file objectDetection.cpp
 * @author A. Huaman ( based in the classic facedetect.cpp in samples/c )
 * @brief A simplified version of facedetect.cpp, show how to load a cascade classifier and how to find objects (Face + eyes) in a video stream
 */
#include "myHeader.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay( Mat frame );

/** Global variables */
int kk = 0;
//-- Note, either copy these two files from opencv/data/haarscascades to your current folder, or change these locations
String face_cascade_name = "E:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
//E:\opencv\data\haarcascades
String eyes_cascade_name = "E:\\opencv\\data\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "Capture - Face detection";
RNG rng(12345);

/**
 * @function main
 */
int main( int argc, const char** argv )
{
  CvCapture* capture;
  Mat frame;

  //-- 1. Load the cascades
  if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
  if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
  int jj = 0;
  for(jj=1;jj<=7;jj++)
  {
	  string ss = "C:\\Users\\phantom\\Desktop\\test\\arpan\\a";
	  std::stringstream sstm;
	  sstm << ss << jj<<".jpg";
	  ss = sstm.str();
	  Mat input = imread(ss);
	  detectAndDisplay(input);
  }
  cout<<"Extraction Complete....\n";
  getchar();
  return 0;
}

/**
 * @function detectAndDisplay
 */
void detectAndDisplay( Mat frame )
{
   std::vector<Rect> faces;
   Mat frame_gray;

   cvtColor( frame, frame_gray, CV_BGR2GRAY );
   equalizeHist( frame_gray, frame_gray );
   //-- Detect faces
   face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
   FILE* outF= fopen("C:\\anubhav\\outputImages.txt","w");
   int i;
   for(i = 0;i<faces.size();i++)
   {
	   Mat faceROI = frame_gray( faces[i] );
	   string s = "C:\\anubhav\\toBeRecognized\\a";
	  std::stringstream sstm;
//	  sstm << s << i<<".jpg";
	  sstm << s << kk<<".jpg";
	  kk++;
	  s = sstm.str();
	  Mat dst;
	Size sz( 100, 100);
	resize( faceROI, dst, sz , 0, 0, CV_INTER_AREA );
	  imwrite(s,dst);//faceROI);
	  sstm<<";"<<i<<"\n";
	  s = sstm.str();
	 const char* ss;
	 ss = s.c_str();
	fprintf(outF,"%s",ss);	
   }

  fclose(outF);
  const char* outFolder = "C:\\anubhav\\outFolder";
  const char*  CVSFile = "C:\\anubhav\\fn_csv.txt";
  const char*  inputCVS = "C:\\anubhav\\outputImages.txt";
  int inputSize = i;
 // fisherFaces(outFolder,CVSFile,2,inputCVS);
}