#include "view.h"
#include "model.h"
#include <iostream>
#include <cstdlib>

//Control Mainview
int GetNextPageNum();
int MoveMainToNext();

//Control InsertionView
void InputInfo(
	std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5
);
void WriteInfo(
	std::string arg1, std::string arg2, std::string arg3,
	std::string arg4, std::string arg5, int checkFile
);

//Control SearchView
int SelectSerchMode();

//Control SortingOptionView
int SelectSortMode();

//Control ExitView
void Exit();

//Used basically
void ClearView();

int GetNextPageNum() {
	MainMenu mainMenu;
	mainMenu.PrintView();
	return mainMenu.GetNextView();
}



void InputInfo(std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5) {
	InsertionView insertionView;
	insertionView.PrintView();
	insertionView.PutInformation();
	insertionView.DispenseString(arg1, arg2, arg3, arg4, arg5);
}

void WriteInfo(std::string arg1, std::string arg2, std::string arg3,
	std::string arg4, std::string arg5, int checkFile) {
	MyFile myFile;
	myFile.SetFileChek(checkFile);
	myFile.OpenFileToWrite();
	myFile.WriteInfo(arg1, arg2, arg3, arg4, arg5);
	myFile.CloseFile();
}

int SelectSerchMode() {
	SearchView searchView;
	searchView.PrintView();
	return searchView.GetNextView();
}

int SelectSortMode() {
	SortingOptionView sortingOptionView;
	sortingOptionView.PrintView();
	return sortingOptionView.GetSortMode();
}

void Exit() {
	ExitView exitView;
	exitView.PrintView();
}

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

int MoveMainToNext(int& sortMode) {
	ClearView();

	// selectPage can be int 1~4 if it were not, that would be error occured!
	int selectPage = GetNextPageNum();
	ClearView();
	int checkFile;
	

	std::vector<std::string> nameList;
	std::vector<std::string> idList;
	std::vector<std::string> birthYearList;
	std::vector<std::string> departmentList;
	std::vector<std::string> telList;


	//open file to read
	MyFile myFileToRead;
	checkFile = myFileToRead.OpenFileToRead(selectPage);
	myFileToRead.GetList(
		nameList, idList, birthYearList, departmentList, telList
	);


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
		InputInfo(
			stringBuffer1, stringBuffer2, stringBuffer3, stringBuffer4, stringBuffer5
		);
		ClearView();
		WriteInfo(
			stringBuffer1, stringBuffer2, stringBuffer3,
			stringBuffer4, stringBuffer5, checkFile
		);
		return 1;
	}

	case 2: {

		int SearchMode = SelectSerchMode();
		ClearView();
		switch (SearchMode)	//TODO!! SearchMode에 따라 Search 구현하기
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
			int end = nameList.size();
			std::cout << end;
			for (int i = 0; i < end; i++) {
				std::cout << nameList[i] << " ";
				std::cout << idList[i] << " ";
				std::cout << birthYearList[i] << " ";
				std::cout << departmentList[i] << " ";
				std::cout << telList[i] << "\n";
			}
			std::cout << "\nall items showed...!\n";
			char pin = 'N';
			while (pin != 'Y') {
				std::cout << "[Plese enter 'Y' to go Main back]\n";
				std::cin >> pin;
			}

			break;
		}
		default: {
			break;
		}

		}

		return 1;
	}

	case 3: {
		sortMode = SelectSortMode();

		//TODO!! sortMode 에따라 vector 정렬시키기
		return 1;
	}

	case 4: {
		Exit();
		return 0;
	}

	default: {
		std::cout << "unpredictable error occured!! X_X";
		return 0;
	}

	}
}

int main() {
	int sortMode = 1;
	while (MoveMainToNext(sortMode)) ;

	return 0;
}