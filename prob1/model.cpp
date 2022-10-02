#include "model.h"
#include <fstream>
#include <iostream>


void MyFile::OpenFileToWrite() {
	ofile.open("file1.txt", std::ios::out | std::ios::app);
}

void MyFile::OpenFileToRead() {
	ifile.open("file1.txt");

	if (ofile.fail()) {
		std::cout << "파일 못열었어요";
	}
}

void MyFile::WriteInfo(std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5) {

	ofile << arg1 << "\n";
	ofile << arg2 << "\n";
	ofile << arg3 << "\n";
	ofile << arg4 << "\n";
	ofile << arg5 << "\n";
}

