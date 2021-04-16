#include "Category.h"
#include "Course.h"

using namespace std;

//Default Constructor
Course::Course() {
	courseName = "Default Course";
	courseGrade = 0;
}
//Constructor
Course::Course(string name) {
	courseName = name;
}
//Setters
void Course::setCourseName(string name) {
	courseName = name;
}
void Course::setCourseGrade() {
	double grade;
		for (unsigned int i; i < categories.size(); i++) {
			grade += categories[i]->getCategoryGrade();
		};
		courseGrade = grade;
}
void Course::setAddCategory() {
	string name;
	double categoryWeight;
	int numAssignments;
	if(getTotalCategoryWeight() < 1){
		cout << "Category Name: ";
		getline(cin, name);
		cout << endl;
		cout << "Category Grading Weight: ";
		cin >> categoryWeight;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << "Number of Category Assignments: ";
		cin >> numAssignments;
		cout << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		categories.push_back(new Category(name, categoryWeight, numAssignments));
		cout << ((1 - getTotalCategoryWeight()) * 100) << "% grade weight remaining." << endl;
	}
}
//Getters
string Course::getCourseName() {
	return courseName;
}
double Course::getCourseGrade() {
	return courseGrade;
}
double Course::getTotalCategoryWeight() {
	double categoryWeight;
	for (unsigned int i; i < categories.size(); i++) {
		categoryWeight += categories[i]->getCategoryWeight();
	}
	return categoryWeight;
}