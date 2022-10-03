#include <cstdlib>
#include <iostream>
#include "view.h"
#include <string>

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
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::getline(std::cin, name);
	if (name.capacity() > 15) name.erase(15); //예외 처리 지점 길이!


	std::cout << "Student ID (10 digits) :: ";
	std::getline(std::cin, studentId);

	std::cout << "Birth Year (4 digits) :: ";
	std::getline(std::cin, birthYear);

	std::cout << "Department :: ";
	std::getline(std::cin, department);

	std::cout << "Tel :: ";
	std::getline(std::cin, tel);
}

void InsertionView::DispenseString(
	std::string &arg1, std::string &arg2, std::string &arg3,
	std::string &arg4, std::string &arg5) {
	
	arg1 = name;
	arg2 = studentId;
	arg3 = birthYear;
	arg4 = department;
	arg5 = tel;

}


//SearchView
void SearchView::PrintView() {
	std::cout << "- Search -\n";
	std::cout << "1. Search by name\n";
	std::cout << "2. Search by student ID (10 numbers)\n";
	std::cout << "3. Search by admission year (4 numbers)\n";
	std::cout << "4. Search by department name\n";
	std::cout << "5. List All\n";
}

int SearchView::GetNextView() {
	nextView = 0;
	while (1) {
		std::cout << "> ";
		std::cin >> nextView;

		if (nextView == 1 || nextView == 2 || nextView == 3 ||
			nextView == 4 || nextView == 5) {
			return nextView;
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			nextView = 0;
			std::cout << "> WARNING!! input 1 or 2 or 3 or 4 or 5 correctly again\n";
		}
	}
}


//SortionOptionView
void SortingOptionView::PrintView() {
	std::cout << "3. Sorting Option\n";
}

//ExitView
void ExitView::PrintView() {
	std::cout << "4. Exit\n";
}

