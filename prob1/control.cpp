#include "view.h"
#include "model.h"
#include <iostream>
#include <cstdlib>

//Control Mainview
int GetNextPageNum();
void MoveMainToNext();

//Control InsertionView
void InputInfo(std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5);
void WriteInfo(std::string arg1, std::string arg2, std::string arg3,
	std::string arg4, std::string arg5);

//Used basically
void ClearView();

int GetNextPageNum() {
	MainMenu mainMenu;
	mainMenu.PrintView();
	return mainMenu.GetNextView();
}

//Used basically
void ClearView() {
	try {
		if (system("clear")) {	//success case : 0, flase case : -1
			std::cout << "error\n";
			throw 0;
		}
	}
	catch (...) {
		system("cls");
	}
}

void InputInfo(std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5) {
	InsertionView insertionView;
	ClearView();
	insertionView.PrintView();
	insertionView.PutInformation();
	insertionView.DispenseString(arg1, arg2, arg3, arg4, arg5);
}

void WriteInfo(std::string arg1, std::string arg2, std::string arg3,
	std::string arg4, std::string arg5) {
	MyFile myFile;
	myFile.OpenFileToWrite();
	myFile.WriteInfo(arg1, arg2, arg3, arg4, arg5);
}


void MoveMainToNext() {
	int selectPage = GetNextPageNum();
	 
	switch (selectPage)
	{
	case 1: {
		//buffer
		std::string stringBuffer1;
		std::string stringBuffer2;
		std::string stringBuffer3;
		std::string stringBuffer4;
		std::string stringBuffer5;

		//이부분 함수로 묶으면 좋을지도? 객체 소멸해서
		InputInfo(stringBuffer1, stringBuffer2,
			stringBuffer3, stringBuffer4, stringBuffer5);
		WriteInfo(stringBuffer1, stringBuffer2,
			stringBuffer3, stringBuffer4, stringBuffer5);


		//입력 정보들을 가지고 있다.,
		

		break; //return  이 되어야 할것같음
	}
	case 2: {
		SearchView searchView;
		ClearView();
		searchView.PrintView();
		break;
	}
	case 3: {
		SortingOptionView sortingOptionView;
		ClearView();
		sortingOptionView.PrintView();
		break;
	}
	case 4: {
		ExitView exitView;
		ClearView();
		exitView.PrintView();
		break;
	}
	default: {
		std::cout << "Unknown";
		break;
	}

	}
}

void main() {
	MoveMainToNext();
}