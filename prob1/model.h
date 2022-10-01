#pragma once
#include <fstream>
#include <string>

//MyFile
class MyFile {
private:
	std::ofstream ofile;
	std::ifstream ifile;

public:
	void OpenFileToWrite();
	void WriteInfo();
	void OpenFileToRead();
};