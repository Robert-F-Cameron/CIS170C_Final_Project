#include <iostream>
#include <fstream>
#include <vector>
#include "Course.h"
#include "Category.h"

using namespace std;

void createCourse();
void viewCourse();
void writeToFile();
vector<Course> courses;
Course selectedCourse;

int main() {
	int input;
	cout << "Welcome to your Course Tracker" << endl;
	do {
		cout << endl << "Main Menu" << endl
			<< "1) Add Course" << endl
			<< "2) View Course" << endl
			<< "3) Write to file" << endl
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
			viewCourse();
			break;
		case 3:
			writeToFile();
			break;
		default:
			cout << "Not a valid input!" << endl;
		}
	} while (input != 4);
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

void viewCourse() {
	for (unsigned int i{}; i < courses.size(); i++) {
		cout << courses[i].getCourseName() << endl;
		selectedCourse = courses[i];
		vector<Category> courseCategories = selectedCourse.getCategoriesVector();
		for (unsigned int i{}; i < courseCategories.size(); i++) {
			cout << courseCategories[i].getCategoryName() << endl;
		}
	};
};

void writeToFile() {
	ofstream course_data;
	course_data.open("courses.csv");
	if (course_data.is_open()) {
		for (unsigned int i{}; i < courses.size(); i++) {
			vector<Category> categories = courses[i].getCategoriesVector();
			course_data << "course,";
			course_data << courses[i].getCourseName() << endl;
			for (unsigned int i{}; i < categories.size(); i++) {
				cout << "In second for loop";
				course_data << "category,";
				course_data << categories[i].getCategoryName() << ",";
				course_data << categories[i].getCategoryWeight() << ",";
				course_data << categories[i].getNumAssignments() << endl;
			};
		};
	};
};