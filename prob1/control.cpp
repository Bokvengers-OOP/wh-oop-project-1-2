#include "view.h"
#include "model.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>


//Declaration part

//Start controler
int StartControler(int& sortMode);

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
std::string GetSearchKeyword(int searchMode);
void PrintByKeyword(int n, std::string& keyword,
	std::vector<std::vector<std::string>>& students);

//Control SortingOptionView
int SelectSortMode();
bool compareName(std::vector<std::string> a, std::vector<std::string> b);
bool compareID(std::vector<std::string> a, std::vector<std::string> b);
bool compareAdmissionYear(std::vector<std::string> a, std::vector<std::string> b);
bool compareDepartmentName(std::vector<std::string> a, std::vector<std::string> b);

//Control ExitView
void Exit();

//Used basically
void ClearView();

//Definition part
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

std::string GetSearchKeyword(int searchMode) {
	SearchView searchView(searchMode);
	return searchView.PrintSearchModeView();
}

void PrintByKeyword(int n, std::string& keyword,
	std::vector<std::vector<std::string>>& students) {
	switch (n)
	{
	case 1: {
		SearchView().PrintSearchByKeyword(0, keyword, students);
		break;
	}
	case 2: {
		SearchView().PrintSearchByKeyword(1, keyword, students);
		break;
	}
	case 3: {
		SearchView().PrintSearchByKeyword(5, keyword, students);
		break;
	}
	case 4: {
		SearchView().PrintSearchByKeyword(3, keyword, students);
		break;
	}
	case 5: {
		SearchView().PrintSearchByKeyword(students);
	}
	default:
		break;
	}

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

//function for sortin option
bool compareName(std::vector<std::string> a, std::vector<std::string> b) {
	std::string str1 = a[0];
	std::string str2 = b[0];
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	return str1 < str2;
}

bool compareID(std::vector<std::string> a, std::vector<std::string> b) {
	return a[1] < b[1];
}

bool compareAdmissionYear(std::vector<std::string> a, std::vector<std::string> b) {
	return a[5] < b[5];
}

bool compareDepartmentName(std::vector<std::string> a, std::vector<std::string> b) {
	std::string str1 = a[3];
	std::string str2 = b[3];
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	return str1 < str2;
}

int StartControler(int& sortMode) {

	// selectPage can be int 1~4 if it were not, that would be error occured!
	int selectPage = GetNextPageNum();
	ClearView();
	int checkFile;

	std::vector<std::vector<std::string>> students;

	std::vector<std::string> nameList;			//index 0
	std::vector<std::string> idList;			//index 1
	std::vector<std::string> birthYearList;		//index 2
	std::vector<std::string> departmentList;	//index 3
	std::vector<std::string> telList;			//index 4
	std::vector<std::string> admisstionYear;	//index 5


	//open file to read
	//store the information gotten from file in variables in control secttion to control
	MyFile myFileToRead;
	checkFile = myFileToRead.OpenFileToRead(selectPage);
	myFileToRead.GetList(
		nameList, idList, birthYearList, departmentList, telList
	);

	for (int i = 0, end = idList.size(); i < end; i++) {
		admisstionYear.push_back(idList[i].substr(0, 4));
	}

	for (int i = 0, end = nameList.size(); i < end; i++) {
		std::vector<std::string> temp;
		temp.push_back(nameList[i]);
		temp.push_back(idList[i]);
		temp.push_back(birthYearList[i]);
		temp.push_back(departmentList[i]);
		temp.push_back(telList[i]);
		temp.push_back(admisstionYear[i]);
		students.push_back(temp);
		temp.clear();
	}

	//sort with number(var sortmode)
	switch (sortMode)
	{
	case 1: {
		std::sort(students.begin(), students.end(), compareName);
		break;
	}
	case 2: {
		std::sort(students.begin(), students.end(), compareID);
		break;
	}
	case 3: {
		std::sort(students.begin(), students.end(), compareAdmissionYear);
		break;
	}
	case 4: {
		std::sort(students.begin(), students.end(), compareDepartmentName);
		break;
	}
	default:
		break;
	}

	switch (selectPage)
	{
	case 1: {
		// close read mode stream
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
		int searchMode = SelectSerchMode();
		ClearView();

		std::vector<std::string>::iterator it;
		std::string keyword;
		std::vector<int> resultIndex;
		std::cout << std::left;
		switch (searchMode)
		{
		case 1: {	//search by name
			keyword = GetSearchKeyword(searchMode);
			PrintByKeyword(searchMode, keyword, students);

			break;
		}
		case 2: {	//search by student id
			keyword = GetSearchKeyword(searchMode);
			PrintByKeyword(searchMode, keyword, students);
			break;
		}
		case 3: {	//search by admisstion year
			keyword = GetSearchKeyword(searchMode);
			PrintByKeyword(searchMode, keyword, students);
			break;
		}
		case 4: {	//search by department name
			keyword = GetSearchKeyword(searchMode);
			PrintByKeyword(searchMode, keyword, students);
			break;
		}
		case 5: {
			std::string pin = "N";
			PrintByKeyword(searchMode, keyword, students);
			while (pin != "Y") {
				std::cout << "[Plese enter 'Y' to go Main back]\n";
				std::cin >> pin;
			}
			ClearView();
			break;
		}
		default: {
			break;
		}

		}
		return 1;
	}
	case 3: {	//sortmode
		sortMode = SelectSortMode();
		ClearView();
		return 1;
	}
	case 4: {	//exit
		Exit();
		return 0;
	}
	case 5: {	//there is no file t read
		return 1;
	}
	default: {
		std::cout << "unpredictable error occured!! X_X";
		return 0;
	}

	}
}

int main() {
	int sortMode = 1;
	while (StartControler(sortMode));
	return 0;
}