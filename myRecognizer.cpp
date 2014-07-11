#include"myHeader.h"

bool myRecognizer(Ptr<FaceRecognizer>& model,vector<Mat> testSample ,vector<int> testLabels, int mythreshold)
{
	cout<<"***********************************************************\n";
	int len = testSample.size();
    bool continueLearning = false;

		for(int ii = 0 ;ii < len ; ii++)
		{
          int predictedLabel = -1;
          double confidence = 0.5;
          model->predict(testSample[ii], predictedLabel, confidence);
		  string result_message = format("Predicted class = %d .......Actual Class %d.....Confidence = %f\n", predictedLabel, testLabels[ii], confidence);
		  if(confidence <= mythreshold)
		  {
//  CopyFile();
//			  continueLearning = true;
		  }


		  cout << result_message << endl;
		  getchar();
		}

		return continueLearning;
}
