#include "myHeader.h"
void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator) 
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
	{
        string error_message = "No valid input file was given, please check the given filename.";
//        CV_Error(CV_StsBadArg, error_message);
		 cerr << "Error opening file \"" << filename << "\". Reason: "<<error_message <<endl; 
		exit(1);	
	}
    string line, path, classlabel;
    while (getline(file, line)) 
	{
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) 
		{
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}
