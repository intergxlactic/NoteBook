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
	int lineNumber = 0;

	if (file.is_open()) {
		while (getline(file, line)) {
			lineNumber++;
			cout << lineNumber << " " << line << endl;
		}
	}
	file.close();
}

string reading() {
	string line;
	cin >> line;
	return line;
}

int getPosition() {
    int num;
    cout << "Enter item position:" << endl;
    cin >> num;
    return num;
} 

void deleteItem(string filename, int lineNumber) {
    
}

void notebook(string file) {
func:
    int numOfPosItem;
    vector<string> line;
	cout << "Enter the command (1,2): " << endl;
	cout << "1 - View your notebook" << endl;
	cout << "2 - Add items to the notebook" << endl;
    cout << "3 - Delete item from notebook" << endl;
	cout << "q - Exiting the programme" << endl;

	char input = _getch();

	switch (input) {
	case '1':
		viewNoteBook(file);
		goto func;
	case '2':
		cout << "Enter information:" << endl;
		line = { reading() };
		addItemInNoteBook(file, line);
		system("CLS");
		goto func;
    case '3':
        numOfPosItem = getPosition(); 
        deleteItem(file, numOfPosItem);
        goto func;
	case 'q':
		exit(0);
	}
	
}

int main() {

	string file = "NoteBook.txt";

	notebook(file);
}
 // добавить функцию удаления задачи из блокнота