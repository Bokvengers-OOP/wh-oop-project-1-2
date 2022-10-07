#include "view.h"
#include "model.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

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

//Control ExitView
void Exit();

//Used basically
void ClearView();

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
		SearchView KeywordView;
		KeywordView.PrintSearchByKeyword(0, keyword, students);
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
		SearchView KeywordView;
		KeywordView.PrintSearchByKeyword(3, keyword, students);
		break;
	}
	case 5: {
		std::cout << std::setw(16) << "Name" << std::setw(11) << "StudentID" << std::setw(20)
			<< "Dept" << std::setw(12) << "Birth Year" << std::setw(11) << "Tel" << "\n";
		for (int i = 0; i < students.size(); i++) {
			std::cout << std::setw(16) << students[i][0] << std::setw(11) << students[i][1] << std::setw(20)
				<< students[i][3] << std::setw(12) << students[i][2] << std::setw(11) << students[i][4] << "\n";
			std::cout.clear();
		}
		std::cout << "\nall items showed...!\n\n";
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
	return a[0] < b[0];
}

bool compareID(std::vector<std::string> a, std::vector<std::string> b) {
	return a[1] < b[1];
}

bool compareAdmissionYear(std::vector<std::string> a, std::vector<std::string> b) {
	return a[5] < b[5];
}

bool compareDepartmentName(std::vector<std::string> a, std::vector<std::string> b) {
	return a[3] < b[3];
}



int MoveMainToNext(int& sortMode) {

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
	//파일에서 읽어온 정보들을 control 단에서 통제하기 위한 변수에 저장
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

	//sort mode에 따라 정렬!
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
		switch (searchMode)	//TODO!! SearchMode에 따라 Search 구현하기
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
	case 3: {
		sortMode = SelectSortMode();
		ClearView();
		//TODO!! sortMode 에따라 vector 정렬시키기
		return 1;
	}
	case 4: {
		Exit();
		return 0;
	}
	case 5: {
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
	while (MoveMainToNext(sortMode));
	system("pause");
	return 0;
}