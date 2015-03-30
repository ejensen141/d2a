#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cmath>
#include "t2sformat.h"
using namespace std;



int main(int argc, char* argv[] )
{
string inputfile;
string outputfile;



if(argc==1)
{

cout<<"Converts time including data in the format    Time Data to just DATA \n";



}
if(argc>1)
{
inputfile = argv[1];
outputfile = argv[2];


Format(inputfile,outputfile);

}



return 0;
}







