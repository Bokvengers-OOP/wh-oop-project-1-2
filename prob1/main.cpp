#include "view.h"
#include "model.h"
#include <iostream>
#include <cstdlib>

int GetNextPageNum() {
	MainMenu mainMenu;
	mainMenu.PrintView();
	return mainMenu.GetNextView();
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

void MoveMainToNext() {
	int selectPage = GetNextPageNum();
	 
	switch (selectPage)
	{
	case 1: {
		//이부분 함수로 묶으면 좋을지도? 객체 소멸해서
		InsertionView insertionView;
		ClearView();
		insertionView.PrintView();
		insertionView.PutInformation();
		//입력 정보들을 가지고 있다.,
		MyFile myFile;
		myFile.OpenFile();
		myFile.WriteInfo();

		
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