#include <iostream>
#include <fstream>
#include <vector>
#include "Course.h"
#include "Category.h"
#include "TextTable.h"

using namespace std;

void createCourse();
void viewCourses();
void writeToFile();
void readFile();
vector<Course> courses;
Course selectedCourse;

int main() {
	int input;
	cout << "Welcome to your Course Tracker" << endl;
	do {
		cout << endl << "Main Menu" << endl
			<< "1) Add Course" << endl
			<< "2) View Course List" << endl
			<< "3) Write to file" << endl
			<< "4) Read from file" << endl
			<< "5) Exit Application" << endl
			<< "Selection: ";
		cin >> input;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
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
			readFile();
			break;
		case 5:
			cout << "Goodbye!";
			system("pause");
			break;
		default:
			cout << "Not a valid input!" << endl;
		}
	} while (input != 5);
}

void createCourse() {
	string name;
	double courseWeight;
	cout << "Course name: ";
	getline(cin, name);
	selectedCourse = Course(name);
	do {
		cout << "Add grading category." << endl;
		selectedCourse.addCategory();
		courseWeight = selectedCourse.getTotalCategoryWeight();
	} while (courseWeight < 1);
	courses.push_back(selectedCourse);
	cout << selectedCourse.getCourseName() << " added!" << endl;
	return;
};

void viewCourses() {
	TextTable t('-', '|', '+');
	bool courseList = true;
	char selection, input;
	int courseSelection;
	t.add("Selection");
	t.add("Course Name");
	t.add("Course Grade");
	t.add("Number of Course Categories");
	t.endOfRow();
	for (unsigned int i{}; i < courses.size(); i++) {
		t.add(to_string(i + 1));
		t.add(courses[i].getCourseName());
		t.add(to_string(courses[i].getCourseGrade()));
		t.add(to_string(courses[i].getCategoriesSize()));
		t.endOfRow();
	};
	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
	do {
		cout << "Select a course to view" << endl;
		cout << "or 'q' to return to main menu:";
		cin >> input;
		int num = input - 49;
		courseSelection = (num - 1);
		int numCourses = courses.size();
		if (input == 'q') {
			selection = 'q';
		}
		else if (num <= numCourses) {
			selection = 1;
		}
		else {
			selection = input;
		}
		switch (selection) {
		case '1':
			courses[courseSelection].getCourseName();
			break;
		case 'q':
			courseList = false;
			break;
		default:
			cout << num;
			cout << "Not a valid input";
		}
	} while (courseList);
};

void writeToFile() {
	ofstream course_data;
	course_data.open("courses.csv");
	if (course_data.is_open()) {
		for (unsigned int i{}; i < courses.size(); i++) {
			string type = "course";
			vector<Category> categories = courses[i].getCategoriesVector();
			course_data << type << ",";
			course_data << courses[i].getCourseName() << endl;
			for (unsigned int i{}; i < categories.size(); i++) {
				string type = "category";
				course_data << type << ",";
				course_data << categories[i].getCategoryName() << ",";
				course_data << categories[i].getCategoryWeight() << ",";
				course_data << categories[i].getNumAssignments() << endl;
			};
		};
	};
	course_data.close();
};
void readFile() {
	string type, courseName, categoryName;
	int numAssignments;
	float categoryWeight;
	string ADDRESS_FILE_NAME = "courses.csv";
	ifstream input_data(ADDRESS_FILE_NAME);
	input_data.open("courses.csv");
	if (input_data.is_open()) {
		while (getline(input_data, type, ',')) {
			if (type == "course") {
				getline(input_data, courseName, '\n');
				Course newCourse(courseName);
				courses.push_back(newCourse);
			}
			else if (type == "category") {
				getline(input_data, categoryName, ',');
				input_data >> categoryWeight;
				input_data >> numAssignments;
				Category courseCategory(categoryName, categoryWeight, numAssignments);
				courses[courses.size() - 1].addCategoryObj(courseCategory);
			}
		};
	};
	input_data.close();
};