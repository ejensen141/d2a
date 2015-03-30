#ifndef T2Sformat_H
#define T2Sformat_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cmath>



using namespace std;

void Format(string infile, string outfile)
{

	ifstream  myfile(infile.c_str());   // setup input file
	ofstream stream(outfile.c_str());    // setup output file

	string line;	             // declare the input file string line
	

if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {	string::size_type pos;
	pos=line.find(' ',0);
	stream<<line.substr(pos+1)<<endl;
    }
    myfile.close();
  }
else if(!myfile.is_open())
{

cout<<"OOPS File not Open"<<endl;
}

}





#endif
