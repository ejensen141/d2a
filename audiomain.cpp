#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cmath>
#include "d2a.h"

using namespace std;

void printUsage()
{

std::cout<<"\n Data2Audio Usage: \n";
std::cout<<"\n Type d2a datafile_name audiofile_name \n \n";

std::cout<<"\n d2a datafile_name audiofile_name sampleRate multiplier time(s)";
std::cout<<"\n -----> \n this is an avalible format as well \n \n";

std::cout<<"\n Thank you... goodbye :) \n";


}

int main(int argc, char* argv[])
{
//printUsage();
int sampleRate= 250;
float multiplier = 536870912;
int N = 1e8;
int time = 10;  // time in seconds 
float *databuffer = new float[N];
string line;
string datafile_name;
string audiofile_name;



if(argc<2)    
{printUsage();

return 0;
}
if(argc==3)
{
datafile_name = argv[1];
audiofile_name = argv[2];
}
if(argc==4)
{
datafile_name = argv[1];
audiofile_name = argv[2];
sampleRate = atoi(argv[3]);

}
if(argc==5)
{
datafile_name = argv[1];
audiofile_name = argv[2];
sampleRate = atoi(argv[3]);
multiplier= atof(argv[4]);

}
if(argc==6)
{
datafile_name = argv[1];
audiofile_name = argv[2];
sampleRate = atoi(argv[3]);
multiplier= atof(argv[4]);
time = atoi(argv[5]);

}


N = time*sampleRate;



ifstream  myfile (datafile_name.c_str());

//*********write the header in RIFF format **************//
writeWAVHeader(audiofile_name.c_str(), databuffer, N*sizeof(databuffer[0]), sampleRate, 1); 


int i =0;
if (myfile.is_open())
  {
    
    
    while (getline(myfile,line) && i<N)
    {
     databuffer[i] = atof(line.c_str())/multiplier;
	i++;
	
    }
	
appendWAVData(audiofile_name.c_str(), databuffer, N*sizeof(databuffer[0]));

    
	
    myfile.close();
  }
else if(!myfile.is_open())
{

cout<<"Error: File "<<datafile_name<<" not Open. Please check that the file exists."<<endl;
}


delete databuffer;

return 0;
}
