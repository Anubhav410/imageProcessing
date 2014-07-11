#include "myHeader.h"


void createCSV(const char* readFolder , const char* destCSV)	//creates a csv file from the files present in the argument folder name
{
	DIR *dir;
	struct dirent *ent;
	//FILE* inputCSV = fopen(destCSV,"w");//("D:/Visual Studio Projects/ImageProcessing/ImageProcessing/inputCSV.csv","w");
	//const char* readFolder = "D:/Visual Studio Projects/ImageProcessing/ImageProcessing/Below_Thresh/";
	
	  ofstream myfile;
	  myfile.open (destCSV);
	  //myfile << "Writing this to a file.\n";
	 
	if ((dir = opendir (readFolder)) != NULL) 
	{
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) 
	  {
 		 string str = ent->d_name;
  		 if(S_ISDIR(ent->d_type))	//trying not to image recognize the current directory or the parent directory
		 {
			 cout<<"Its a directory\n";
			continue;
		 }
 		 myfile <<readFolder<< str<<";0\n";
	   }
	  closedir (dir);
	  myfile.close();	
	}
	else 
	{
	  /* could not open directory */
	  perror ("lol,,,,its not opening!!!");
	  getchar();
	  return exit(200);
	}

}