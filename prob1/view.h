#pragma once

class MainMenu {
	
public:
	int nextView;
	void PrintView();
	int GetNextView();
	~MainMenu();
};

class InsertionView {
public:
	void PrintView();
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
