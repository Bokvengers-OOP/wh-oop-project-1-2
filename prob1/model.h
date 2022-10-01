#pragma once
#include <fstream>
#include <string>

//MyFile
class MyFile {
private:
	std::fstream file;

public:
	void OpenFile();
	void WriteInfo();
};