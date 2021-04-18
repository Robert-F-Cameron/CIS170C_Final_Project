#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Course.h"
#include "Category.h"

using namespace std;

void createCourse();
void viewCourses();
void writeToFile();
void mainMenu();

vector<Course> courses;
Course selectedCourse;

int main() {
	cout << "Welcome to your Course Tracker" << endl << endl;
	mainMenu();
}

void mainMenu() {
	int input;
	cout << "1) Enter a new Course" << endl
		<< "2) View Course List" << endl
		<< "3) Save Course Data" << endl
		<< "4) Exit Application" << endl
		<< "Selection: ";
	cin >> input;
	cin.clear();
	cin.ignore(1024, '\n');
	switch (input) {
	case 1:
		createCourse();
		break;
	case 2:
		viewCourses();
		break;
	case 3:
		writeToFile();
		break;
	case 4:
		cout << "Goodbye!" << endl;
		system("pause");
	default:
		cout << "Not a Valid Input";
	}
}

void createCourse() {
	string name; 
	char input{};
	bool quit = false;
	cout << "Course name: ";
	getline(cin, name);
	courses.push_back(Course(name));
	selectedCourse = courses[courses.size() - 1];
	cout << selectedCourse.getCourseName() << " added!" << endl << endl;
	if (selectedCourse.getTotalCategoryWeight() < 100) {
		do {
			if (selectedCourse.getTotalCategoryWeight() < 1) {
				cout << "Would you like to add grading categories to " << selectedCourse.getCourseName() << "? (Y/N): ";
				cin >> input;
				input = tolower(input);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				quit = true;
			}
			switch (input) {
			case 'y':
				selectedCourse.addCategory();
				selectedCourse.getCategoriesSize();
				break;
			case 'n':
				quit = true;
				cout << endl;
				break;
			default:
				cout << "Not a Valid Input" << endl;
			}
		} while (!quit);
	}
	mainMenu();
}

void viewCourses() {
	int input{};
	cout << "Select course to view:" << endl;
	for (unsigned int i{}; i < courses.size(); i++) {
		cout << (i + 1) << ") " << courses[i].getCourseName()<<"\t";
	}
	cout << endl << "Selection: ";
	cin >> input;
	input = input - 1;
	if (input < 0 || input > courses.size()) {
		cout << "Not a valid selection! " << typeid(input).name() << " - " << input << " - " << courses.size();
	}
	selectedCourse = courses[input];
	cout << selectedCourse.getCourseName();
}

void writeToFile() {
	ofstream course_data;
	course_data.open("courses.csv");
	if (course_data.is_open()) {
		for (unsigned int i{}; i < courses.size(); i++) {
			vector<Category> categories = courses[i].getCategoriesVector();
			course_data << "course,";
			course_data << courses[i].getCourseName() << endl;
			cout << categories.size();
			cout << courses[i].getCategoriesVector().size();
			for (unsigned int i{}; i < categories.size(); i++){
				cout << "In second for loop";
				course_data << "category,";
				course_data << categories[i].getCategoryName() << ",";
				course_data << categories[i].getCategoryWeight() << ",";
				course_data << categories[i].getNumAssignments() << endl;
			}

		}
	}
}