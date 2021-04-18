#include "Category.h"

using namespace std;

//Default Constructor
Category::Category() {
	categoryName = "Default Category";
	categoryWeightedGrade = 0;
	categoryWeight = 0;
	numAssignments = 0;
}
//Constructor
Category::Category(string name, double weight, int assignments) {
	categoryName = name;
	categoryGrade = 0;
	categoryWeight = weight*0.01;
	numAssignments = assignments;
}
//Setters
void Category::setCategoryName(string name) {
	categoryName = name;
};
void Category::setCategoryWeight(double weight) {
	categoryWeight = weight*0.01;
};
void Category::setCategoryWeightedGrade() {
	double grade{};
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		grade += assignmentGrades[i];
	}
	categoryWeightedGrade = grade * categoryWeight;
};void Category::setCategoryGrade() {
	double grade{};
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		grade += assignmentGrades[i];
	}
	categoryWeightedGrade = grade;
};
void Category::setNumAssignments(int numAssignments) {
};
void Category::setAddAssignmentGrade() {
	double grade;
	if(assignmentGrades.size() < numAssignments){
	cout << "Enter Assignment Grade: ";
	cin >> grade;
	cin.clear();
	cin.ignore(1024, '\n');
	assignmentGrades.push_back(grade);
	}
};
//Getters
string Category::getCategoryName() {
	return categoryName;
};
double Category::getCategoryWeight() {
	return categoryWeight;
};
double Category::getCategoryGrade() {
	return categoryGrade;
};
int Category::getNumAssignments() {
	return numAssignments;
};
void Category::getAssignmentGrades() {
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		cout << "Assignment " << i << ": " << assignmentGrades[i] << " | ";
	}
	cout << endl;
};