#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Course.h"
#include "Category.h"
#include "TextTable.h"

using namespace std;

void createCourse();
void viewCourses();
void writeToFile();
void readFile();
void courseListTable();
vector<Course> courses;
Course selectedCourse;

int main() {
	int input;
	cout << "\x1B[33mWelcome to your Course Tracker\033[0m" << endl;
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
			cout << "\x1B[31mNot a valid input!\033[0m" << endl;
		}
	} while (input != 'q');
}
//Creates a course to track
void createCourse() {
	string name;
	double courseWeight;
	cout << "Course name: ";
	getline(cin, name);
	selectedCourse = Course(name);
	do {
		cout << "\x1B[36mAdd grading category.\033[0m" << endl;
		selectedCourse.addCategory();
		courseWeight = selectedCourse.getTotalCategoryWeight();
	} while (courseWeight < 1);
	courses.push_back(selectedCourse);
	cout << selectedCourse.getCourseName() << " added!" << endl;
	return;
};
//Outputs the course list as a table
void courseListTable() {
	TextTable t('-', '|', '+');
	t.add("Selection");
	t.add("Course Name");
	t.add("Course Grade");
	t.add("Weighted Course Grade");
	t.add("Number of Course Categories");
	t.endOfRow();
	for (unsigned int i{}; i < courses.size(); i++) {
		t.add(to_string(i + 1));
		t.add(courses[i].getCourseName());
		t.add(to_string(courses[i].getCourseGrade()));
		t.add(to_string(courses[i].getCourseWeightedGrade()));
		t.add(to_string(courses[i].getCategoriesSize()));
		t.endOfRow();
	};
	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
};
//Allows the user to select a course to view
void viewCourses() {
	bool courseList = true;
	char selection, input;
	courseListTable();
	do {
		cout << "Select a course to view" << endl;
		cout << "or 'q' to return to main menu:";
		cin >> input;
		cin.clear();
		cin.ignore(1024, '\n');
		int num = (input - 49);
		int numCourses = courses.size();
		if (input == 'q') {
			selection = 'q';
		}
		else if (num <= numCourses) {
			selection = '1';
		}
		else {
			selection = input;
		}
		switch (selection) {
		case '1':
			courses[num].courseMenu();
			courses[num].setCourseGrade();
			courses[num].setCourseWeightedGrade();
			courseListTable();
			break;
		case 'q':
			courseList = false;
			break;
		default:
			cout << "\x1B[31mNot a valid input!\033[0m" << endl;
		}
	} while (courseList);
};
//Writes the courses and their grading categories to a CSV file
//TODO: write the course category grades to the file
void writeToFile() {
	ofstream course_data;
	course_data.open("courses.csv");
	if (course_data.is_open()) {
		for (unsigned int i{}; i < courses.size(); i++) {
			vector<Category> categories = courses[i].getCategoriesVector();
			course_data << "course" << ",";
			course_data << courses[i].getCourseName() << endl;
			for (unsigned int i{}; i < categories.size(); i++) {
				vector<double> submittedGrades = categories[i].getSubmittedAssignmentGrades();
				course_data << "category" << ",";
				course_data << categories[i].getCategoryName() << ",";
				course_data << categories[i].getCategoryWeight() << ",";
				course_data << categories[i].getCategoryWeightedGrade() << ",";
				course_data << categories[i].getCategoryGrade() << ",";
				course_data << categories[i].getNumAssignments() << endl;
//				for (unsigned int i{}; 1 < submittedGrades.size(); i++) {
//					course_data << "assignments" << ",";
//					if (i != submittedGrades.size()) {
//						cout << "in submittedGrades";
//						course_data << submittedGrades[i] << ",";
//					}
//					else {
//						course_data << submittedGrades[i] << endl;
//					}
//				}
			};
		};
	};
	course_data.close();
};
//Reads the CSV file and creates the courses and their associated categories
//TODO: read category assignemnt grades 
void readFile() {
	string type, courseName, categoryName, numAssignments, categoryWeight, categoryWeightedGrade, categoryGrade;
	ifstream input_data("courses.csv");
	if (input_data.is_open()) {
		cout << "open";
		while (getline(input_data, type, ',')) {
			if (type == "course") {
				getline(input_data, courseName, '\n');
				Course newCourse(courseName);
				courses.push_back(newCourse);
			}
			else if (type == "category") {
				getline(input_data, categoryName, ',');
				getline(input_data, categoryWeight, ',');
				getline(input_data, categoryWeightedGrade, ',');
				getline(input_data, categoryGrade, ',');
				getline(input_data, numAssignments, '\n');
				double cWeight, cWeightedGrade, cGrade;
				int cAssignments;
				cWeight = stod(categoryWeight);
				cWeightedGrade = stod(categoryWeightedGrade);
				cGrade = stod(categoryGrade);
				cAssignments = stoi(numAssignments);
				Category courseCategory(categoryName, cWeight, cWeightedGrade, cGrade, cAssignments);
				courses[courses.size() - 1].addCategoryObj(courseCategory);
			}
		};
	};
	input_data.close();
};