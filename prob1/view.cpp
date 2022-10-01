#include <cstdlib>
#include <iostream>
#include "view.h"

//MainMenu
MainMenu::~MainMenu() {
	std::cout << "destroyed..\n";
}

void MainMenu::PrintView() {
	std::cout << "1. Insertion\n";
	std::cout << "2. Search\n";
	std::cout << "3. Sorting Option\n";
	std::cout << "4. Exit\n";
}

int MainMenu::GetNextView() {
	nextView = 0;
	while (1) {
		std::cout << "> ";
		std::cin >> nextView;

		if (nextView == 1 || nextView == 2 || nextView == 3 || nextView == 4 ) {
			return nextView;
		}
		else {
			std::cin.clear();
			std::cin.ignore(256,'\n');
			nextView = 0;
			std::cout << "> WARNING!! input 1 or 2 or 3or 4 correctly again\n";
		}
		
	}
}


//InsertionView
void InsertionView::PrintView() {
	std::cout << "1. Insertion\n";
	std::cout << "Name ?\n";
	std::cout << "Student ID (10 digits) ?\n";
	std::cout << "Birth Year (4 digits) ?\n";
	std::cout << "Department ?\n";
	std::cout << "Tel ?\n";

}

void InsertionView::PutInformation() {
	std::cout << "Name :: ";
	std::cin >> name;

	std::cin >> studentId;
	std::cout << "Student ID (10 digits) :: ";

	std::cin >> birthYear;
	std::cout << "Birth Year (4 digits) :: ";

	std::cin >> Department;
	std::cout << "Department :: ";

	std::cin >> tel;
	std::cout << "Tel :: ";

}


//SearchView
void SearchView::PrintView() {
	std::cout << "2. Search\n";
}


//SortionOptionView
void SortingOptionView::PrintView() {
	std::cout << "3. Sorting Option\n";
}

//ExitView
void ExitView::PrintView() {
	std::cout << "4. Exit\n";
}

