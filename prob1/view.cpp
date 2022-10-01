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
	std::cout << "> ";
	std::cin >> nextView;

	return nextView;

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

