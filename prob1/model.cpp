#include "model.h"
#include <fstream>


void MyFile::OpenFile() {
	file.open("file1.txt");
	if (file.fail()) {
		//오류
	}
}

void MyFile::WriteInfo() {
	file << "글쓰기";
}