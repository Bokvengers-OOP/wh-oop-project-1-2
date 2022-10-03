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

//Control SearchView
int SelectSerchMode();

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
	insertionView.PrintView();
	insertionView.PutInformation();
	insertionView.DispenseString(arg1, arg2, arg3, arg4, arg5);
}

void WriteInfo(std::string arg1, std::string arg2, std::string arg3,
	std::string arg4, std::string arg5) {
	MyFile myFile;
	myFile.OpenFileToWrite();
	myFile.WriteInfo(arg1, arg2, arg3, arg4, arg5);
	myFile.CloseFile();
}

int SelectSerchMode() {
	SearchView searchView;
	searchView.PrintView();
	return searchView.GetNextView();
}


void MoveMainToNext(int& sortMode) {
	// selectPage can be int 1~4 if it were not, that would be error occured!
	int selectPage = GetNextPageNum();
	ClearView();

	//open file to read
	std::vector<std::string> sortedNameList;
	std::vector<std::string> idList;
	std::vector<std::string> birthYearList;
	std::vector<std::string> departmentList;
	std::vector<std::string> telList;

	MyFile myFileToRead;
	myFileToRead.OpenFileToRead(selectPage);

	switch (selectPage)
	{
	case 1: {
		//insert에서는 읽기 모드 파일 close
		myFileToRead.CloseFile();

		//buffer
		std::string stringBuffer1;
		std::string stringBuffer2;
		std::string stringBuffer3;
		std::string stringBuffer4;
		std::string stringBuffer5;

		//model doesn't know view, vice versa
		//if these function returned, objects related with funtions will be destroyed
		InputInfo(stringBuffer1, stringBuffer2,
			stringBuffer3, stringBuffer4, stringBuffer5);
		ClearView();
		WriteInfo(stringBuffer1, stringBuffer2,
			stringBuffer3, stringBuffer4, stringBuffer5);
		break; //return 으로 control 가능!
	}

	case 2: {

		int SearchMode = SelectSerchMode();
		ClearView();
		switch (SearchMode)
		{
		case 1: {

			break;
		}
		case 2: {

			break;
		}
		case 3: {

			break;
		}
		case 4: {

			break;
		}
		case 5: {
			//buffer to sort



			break;
		}
		default: {
			break;
		}

		}

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
	case 5: {
		break;
	}

	default: {
		std::cout << "unpredictable error occured!! X_X";
		break;
	}

	}
}

int main() {
	int sortMode = 1;
	while (1) MoveMainToNext(sortMode);

	return 0;
}

