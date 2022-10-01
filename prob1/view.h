#pragma once
#include <string>

//MainMenu
class MainMenu {
private:
	int nextView;
public:
	void PrintView();
	int GetNextView();
	~MainMenu();
};

//InsertionView
class InsertionView {
private:
	std::string name;
	std::string studentId;
	std::string birthYear;
	std::string Department;
	std::string tel;
public:
	void PrintView();
	void PutInformation();
};



class SearchView {
public:
	void PrintView();
};

class SortingOptionView {
public:
	void PrintView();
};

class ExitView {
public:
	void PrintView();
};
