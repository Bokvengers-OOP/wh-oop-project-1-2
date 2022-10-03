#pragma once
#include <fstream>
#include <string>
#include <vector>

//MyFile
class MyFile {
private:
	//stream for fie connect
	std::fstream ofile;
	std::ifstream ifile;

	//
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
	void SetFileChek(int num);
	void GetList(std::vector<std::string>& list1, std::vector<std::string>& list2,
		std::vector<std::string>& list3, std::vector<std::string>& list4,
		std::vector<std::string>& list5);
};