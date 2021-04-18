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
	double grade{};
	for (unsigned int i{}; i < categories.size(); i++) {
			grade += categories[i].getCategoryGrade();
		};
		courseGrade = grade;
}
void Course::setTotalCategoryWeight() {
	double categoryWeight{};
	for (unsigned int i{}; i < categories.size(); i++) {
		categoryWeight += categories[i].getCategoryWeight();
	}
	totalCategoryWeight = categoryWeight;
}
void Course::addCategory() {
	//variables
	string name;
	double categoryWeight;
	int numAssignments;
	//logic
	if(totalCategoryWeight < 1){
		cout << "Category Name: ";
		getline(cin, name);
		cout << "Category Grading Weight: ";
		cin >> categoryWeight;
		if (((categoryWeight * 0.01) + totalCategoryWeight) > 1) {
			do {
				cout << "Invalid Category Grading Weight" << endl;
				if (totalCategoryWeight > 0) {
				cout << "Only " << totalCategoryWeight * 100 << "% remaining!" << endl;
				}
				else {
				cout << "Grading weight cannot be greater than 100%" << endl;
				}
				cout << "Category Grading Weight: ";
				cin >> categoryWeight;
			} while (((categoryWeight * 0.01) + totalCategoryWeight)>1);
		}
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Number of Category Assignments: ";
		cin >> numAssignments;
		cin.clear();
		cin.ignore(1024, '\n');
		categories.push_back(Category(name, categoryWeight, numAssignments));
		this->setTotalCategoryWeight();
		if (totalCategoryWeight < 1) {
			cout << categories[categories.size() - 1].getCategoryName() << " added!" << ((1 - totalCategoryWeight) * 100) << "% grade weight remaining." << endl;
		}
		else if (totalCategoryWeight == 1) {
			cout << name << " added!" << "100% grade weight allocated." << endl;
		}
		cout << endl;
	}
	cout << "Categories Size: " << categories.size();
}
//Getters
string Course::getCourseName() {
	return courseName;
}
double Course::getCourseGrade() {
	return courseGrade;
}
double Course::getTotalCategoryWeight() {
	return totalCategoryWeight;
}
int Course::getCategoriesSize() {
	return categories.size();
}
vector<Category> Course::getCategoriesVector(){
	vector<Category> courseCategories = categories;
	return courseCategories;
}