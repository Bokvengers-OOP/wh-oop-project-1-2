#include <cstdlib>
#include <iostream>
#include "view.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector> 


//MainMenu
MainMenu::~MainMenu() {
	std::cout << "destroyed..\n";
}

void MainMenu::PrintView() {
	std::cout << "- Main -\n";
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

		if (nextView == 1 || nextView == 2 || nextView == 3 || nextView == 4) {
			return nextView;
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			nextView = 0;
			std::cout << "> WARNING!! input 1 or 2 or 3or 4 correctly again\n";
		}
	}
}

//InsertionView
void InsertionView::PrintView() {
	std::cout << "- Insertion -\n";
	std::cout << "Name ?\n";
	std::cout << "Student ID (10 digits) ?\n";
	std::cout << "Birth Year (4 digits) ?\n";
	std::cout << "Department ?\n";
	std::cout << "Tel ?\n";

}

void InsertionView::PutInformation() {
	std::cin.clear();
	std::cin.ignore(256, '\n');
	while (name.size() < 1 || name.size() > 15) {

		std::cout << "Name (up to 15 eng characters) :: ";
		std::getline(std::cin, name);
		if (name.size() > 15 || name.size() < 1) {
			std::cout << "!!write again!!\n";
		}
	}

	bool numberFlag = 1;
	while (this->studentId.size() < 10 || this->studentId.size() > 10 || numberFlag) {//거짓이면 탈출

		std::cout << "Student ID (exactly 10 digits) :: ";
		std::cin.clear();
		std::getline(std::cin, studentId);

		numberFlag = 0;
		for (int i = 0; i < studentId.size(); i++) {
			if (isdigit(studentId[i]) == 0) {	//문자가 하나라도 있으면 플레그 1
				numberFlag = 1;
				break;
			}
		}
		if (studentId.size() == 0) numberFlag = 1;
		if (studentId.size() > 10 || studentId.size() < 10 || numberFlag) {
			std::cout << "!!write again!!\n";
		}
	}

	numberFlag = 1;
	while (birthYear.size() < 4 || birthYear.size() > 4 || numberFlag) {//거짓이면 탈출

		std::cout << "Birth Year (exactly 4 digits) :: ";
		std::cin.clear();
		std::getline(std::cin, birthYear);

		numberFlag = 0;
		for (int i = 0; i < birthYear.size(); i++) {
			if (isdigit(birthYear[i]) == 0) {	//문자가 하나라도 있으면 플레그 1
				numberFlag = 1;
				break;
			}
		}
		if (birthYear.size() == 0) numberFlag = 1;
		if (birthYear.size() > 4 || birthYear.size() < 4 || numberFlag) {
			std::cout << "!!write again!!\n";
		}
	}

	std::cout << "Department :: ";
	std::getline(std::cin, department);

	numberFlag = 1;
	while (tel.size() < 1 || tel.size() > 12 || numberFlag) {//거짓이면 탈출

		std::cout << "Tel :: (up to 12 digits) ";
		std::cin.clear();
		std::getline(std::cin, tel);

		numberFlag = 0;
		for (int i = 0; i < tel.size(); i++) {
			if (isdigit(tel[i]) == 0) {	//문자가 하나라도 있으면 플레그 1
				numberFlag = 1;
				break;
			}
		}
		if (tel.size() == 0) numberFlag = 1;
		if (tel.size() > 12 || tel.size() < 1 || numberFlag) {
			std::cout << "!!write again!!\n";
		}
	}
}

void InsertionView::DispenseString(
	std::string& arg1, std::string& arg2, std::string& arg3,
	std::string& arg4, std::string& arg5) {

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

SearchView::SearchView() { nextView = 0; };
SearchView::SearchView(int searchView) {
	nextView = searchView;
}

std::string SearchView::PrintSearchModeView() {
	std::string keyword;
	switch (this->nextView)
	{
	case 1: {
		PirntSearchByName();
		break;
	}
	case 2: {
		PrintSearchByID();
		break;
	}
	case 3: {
		PrintSearchByAdmissionYear();
		break;
	}
	case 4: {
		PrintSearchByDepartment();
		break;
	}
	default:
		std::cout << "error ouccer in SearchView::PrintSearchModeView";
		break;
	}

	std::cin >> keyword;
	return keyword;
}

void SearchView::PirntSearchByName() {
	std::cout << "Name keyword? :";
}
void SearchView::PrintSearchByID() {
	std::cout << "sutdent ID (10numbers) keyword? :";
}
void SearchView::PrintSearchByAdmissionYear() {
	std::cout << "admisstion year (4 numbers) keyword? :";
}
void SearchView::PrintSearchByDepartment() {
	std::cout << "Department name keyword? :";
}

void SearchView::PrintSearchByKeyword(int n, std::string& keyword,
	std::vector<std::vector<std::string>>& students) {

	int deptNumber = students[0][3].size();;
	for (int i = 1; i < students.size(); i++) {
		if (deptNumber < students[i][3].size()) {
			deptNumber = students[i][3].size();
		}
	}
	deptNumber += 2;
	std::cout << "\n";
	std::cout << std::setw(16) << "Name" << std::setw(11) << "StudentID" << std::setw(deptNumber)
		<< "Dept" << std::setw(12) << "Birth Year" << std::setw(11) << "Tel" << "\n";

	for (int i = 0; i < students.size(); i++) {
		if (students[i][n] == keyword) {
			std::cout << std::setw(16) << students[i][0] << std::setw(11) << students[i][1] << std::setw(deptNumber)
				<< students[i][3] << std::setw(12) << students[i][2] << std::setw(11) << students[i][4] << "\n";
			std::cout.clear();
		}
	}
	std::cout << "\nall items showed...!\n\n";
}

void SearchView::PrintSearchByKeyword(std::vector<std::vector<std::string>>& students) {
	int deptNumber = students[0][3].size();;
	for (int i = 1; i < students.size(); i++) {
		if (deptNumber < students[i][3].size()) {
			deptNumber = students[i][3].size();
		}
	}
	deptNumber += 2;
	std::cout << std::setw(16) << "Name" << std::setw(11) << "StudentID" << std::setw(deptNumber)
		<< "Dept" << std::setw(12) << "Birth Year" << std::setw(11) << "Tel" << "\n";

	for (int i = 0; i < students.size(); i++) {
		std::cout << std::setw(16) << students[i][0] << std::setw(11) << students[i][1] << std::setw(deptNumber)
			<< students[i][3] << std::setw(12) << students[i][2] << std::setw(11) << students[i][4] << "\n";
		std::cout.clear();
	}
	std::cout << "\nall items showed...!\n\n";
}


//SortionOptionView
void SortingOptionView::PrintView() {
	std::cout << "- Sorting Option -\n";
	std::cout << "1. Sort by Name\n";
	std::cout << "2. Sort by Student ID\n";
	std::cout << "3. Sort by Admission Year\n";
	std::cout << "4. Sort by Department name\n";
}

int SortingOptionView::GetSortMode() {
	sortMode = 0;
	while (1) {
		std::cout << "> ";
		std::cin >> sortMode;

		if (sortMode == 1 || sortMode == 2 || sortMode == 3 || sortMode == 4) {
			return sortMode;
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			sortMode = 0;
			std::cout << "> WARNING!! input 1 or 2 or 3or 4 correctly again\n";
		}
	}
}

//ExitView
void ExitView::PrintView() {
	std::cout << "- Exit Program -\n";
}