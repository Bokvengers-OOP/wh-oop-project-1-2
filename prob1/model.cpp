#include "model.h"
#include <fstream>


void MyFile::OpenFile() {
	file.open("file1.txt");
	if (file.fail()) {
		//����
	}
}

void MyFile::WriteInfo() {
	file << "�۾���";
}