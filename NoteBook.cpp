#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void addItemInNoteBook(const string& filename, const vector<string>& lines) {
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		for (const auto& line : lines) {
			file << line << endl;
		}
	}
	file.close();
}

void viewNoteBook(string filename) {
	ifstream file(filename);

	string line;
	int lineNumber = -1;

	if (file.is_open()) {
		while (getline(file, line)) {
			lineNumber++;
			cout << lineNumber << " - " << line << endl;
		}
	}
	file.close();
}

string reading() {
	string input;
	getline(cin, input);
	return input;
}

int getPosition() {
	int num;
	cout << "Enter item position:" << endl;
	cin >> num;
	return num;
}

void deleteItem(string filename, int lineNumber) {
	ifstream file(filename);
	vector<string> lines;
	string line;

	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();

	if (lineNumber >= 0 && lineNumber < lines.size()) {
		lines.erase(lines.begin() + lineNumber);
	}

	ofstream outFile(filename);
	for (const auto& l : lines) {
		outFile << l << endl;
	}
	outFile.close();
;}

void clearNoteBook(string filename) {
	ofstream file(filename);
	file.close();
}

void notebook(string file) {
func:
	int numOfPosItem;
	vector<string> line;
	cout << "Enter the command: " << endl;
	cout << "1 - View your notebook" << endl;
	cout << "2 - Add items to the notebook" << endl;
	cout << "3 - Delete item from notebook" << endl;
	cout << "4 - Clear notebook" << endl;
	cout << "q - Exiting the programme" << endl;

	char input = _getch();

	switch (input) {
	case '1':
		viewNoteBook(file);
		break;
	case '2':
		cout << "Enter information:" << endl;
		line = { reading() };
		addItemInNoteBook(file, line);
		system("CLS");
		break;
	case '3':
		numOfPosItem = getPosition();
		deleteItem(file, numOfPosItem);
		break;
	case '4':
		char input;
		cout << "Confirm the clearing of the notepad (y/n): ";
replay:
		cin >> input;
		if (input == 'y') {
			clearNoteBook(file);
			cout << endl;
			cout << "Notebook will be cleaning" << endl;
			cout << endl;
			goto func;
		}
		else if (input == 'n') {
			goto func;
		}
		else {
			cout << "Enter 'y' or 'n': ";
			goto replay;
		}
	case 'q':
		exit(0);
	}

}

int main() {

	string file = "NoteBook.txt";

	while (true) {
		notebook(file);
	}
}
