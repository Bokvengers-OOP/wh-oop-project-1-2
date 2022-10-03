#include "model.h"
#include <fstream>
#include <iostream>


void MyFile::OpenFileToWrite() {
	ofile.open("file1.txt", std::ios::out | std::ios::app);
}

void MyFile::setFileChek(int num) {
	fileCheck = num;
}

int MyFile::OpenFileToRead(int& selectPage) {
	ifile.open("file1.txt");
	std::string buffer;

	if (ifile.fail()) {
		if (selectPage != 1) {
			selectPage = 5;
			std::cout << "there is no file plse create or choose insert mode \"file1.txt\"\n";			
		}
		return 0;
	}
	else {
		while (!ifile.eof()) {
			getline(ifile, buffer);
			nameList.push_back(buffer);
			std::cout << buffer << "\n";
			buffer = "";
			getline(ifile, buffer);
			idList.push_back(buffer);
			std::cout << buffer << "\n";
			buffer = "";
			getline(ifile, buffer);
			birthYearList.push_back(buffer);
			std::cout << buffer << "\n";
			buffer = "";
			getline(ifile, buffer);
			departmentList.push_back(buffer);
			std::cout << buffer << "\n";
			buffer = "";
			getline(ifile, buffer);
			telList.push_back(buffer);
			std::cout << buffer << "\n";
			buffer = "";
		}
		return 1;
	}
}

void MyFile::CloseFile() {
	ofile.close();
	ifile.close();
}

void MyFile::WriteInfo(std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5) {
	
	if (fileCheck == 1) {
		ofile << "\n";
		ofile << arg1 << "\n";
		ofile << arg2 << "\n";
		ofile << arg3 << "\n";
		ofile << arg4 << "\n";
		ofile << arg5;
	}
	else if (fileCheck == 0) {
		ofile << arg1 << "\n";
		ofile << arg2 << "\n";
		ofile << arg3 << "\n";
		ofile << arg4 << "\n";
		ofile << arg5;
	}

}

