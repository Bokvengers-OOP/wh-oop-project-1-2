#include "view.h"
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
	case 1:
		InsertionView insertionView;
		ClearView();
		insertionView.PrintView();
		break;
	case 2:
		SearchView searchView;
		ClearView();
		searchView.PrintView();
		break;
	case 3:
		SortingOptionView sortingOptionView;
		ClearView();
		sortingOptionView.PrintView();
		break;
	case 4:
		ExitView exitView;
		ClearView();
		exitView.PrintView();
		break;
	default:
		std::cout << "Unknown";
		break;
	}
}

void main() {
	MoveMainToNext();
}