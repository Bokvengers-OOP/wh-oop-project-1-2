#pragma once
#include <fstream>
#include <string>
#include <vector>

//MyFile
class MyFile {
private:
	std::fstream ofile;
	std::ifstream ifile;

	std::vector<std::string> nameList;
	std::vector<std::string> idList;
	std::vector<std::string> birthYearList;
	std::vector<std::string> departmentList;
	std::vector<std::string> telList;

	int fileCheck;

public:
	void OpenFileToWrite();
	void WriteInfo(std::string& arg1, std::string& arg2, std::string& arg3,
		std::string& arg4, std::string& arg5);
	int OpenFileToRead(int& selectPage);
	void CloseFile();
	void setFileChek(int num);
};