#include "model.h"
#include <fstream>
#include <iostream>


void MyFile::OpenFileToWrite() {
	ofile.open("file1.txt");

}

void MyFile::OpenFileToRead() {
	ifile.open("file1.txt");

}

void MyFile::WriteInfo() {
	ofile << "±Û¾²±â";
}