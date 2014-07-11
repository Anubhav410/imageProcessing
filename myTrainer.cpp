#include "myHeader.h"

void myTrainer(Ptr<FaceRecognizer>& model, vector<Mat>& images,vector<int>& labels , string trainerCSV)
{
	 
	 read_csv(trainerCSV , images, labels,';');
	 if(images.size() <= 1) 
	 {
        string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
        CV_Error(CV_StsError, error_message);
     }
//training the model with the particualr set of images....
	model->train(images,labels);
}