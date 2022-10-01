#include <cstdlib>
#include <iostream>
#include "view.h"

MainMenu::~MainMenu() {
	std::cout << "¼Ò¸ê´ï..\n";
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

void InsertionView::PrintView() {
	std::cout << "1. Insertion\n";
}

void SearchView::PrintView() {
	std::cout << "2. Search\n";
}

void SortingOptionView::PrintView() {
	std::cout << "3. Sorting Option\n";
}

void ExitView::PrintView() {
	std::cout << "4. Exit\n";
}

