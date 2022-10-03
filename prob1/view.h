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
	std::string department;
	std::string tel;
public:
	void PrintView();
	void PutInformation();
	void DispenseString(std::string& arg1, std::string& arg2, std::string& arg3,
		std::string& arg4, std::string& arg5);
};

//SearchView
class SearchView {
private:
	int nextView;
public:
	void PrintView();
	int GetNextView();

	//after select search mode
	void PirntSearchByName();
	void PrintSearchByID();
	void PrintSearchByAdmissionYear();
	void PrintSearchByDepartment();
	void PrintListAll(int sortMode);
};

//SortingOptionView
class SortingOptionView {
private:
	int sortMode;
public:
	void PrintView();
	int GetSortMode();
};

//Exit
class ExitView {
public:
	void PrintView();
};