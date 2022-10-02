#pragma once
#include <fstream>
#include <string>

//MyFile
class MyFile {
private:
	std::fstream ofile;
	std::ifstream ifile;

public:
	void OpenFileToWrite();
	void WriteInfo(std::string& arg1, std::string& arg2, std::string& arg3,
		std::string& arg4, std::string& arg5);
	void OpenFileToRead();
};