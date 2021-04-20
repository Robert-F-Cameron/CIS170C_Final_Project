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
Category::Category(string name, float weight, int assignments) {
	categoryName = name;
	categoryGrade = 0;
	categoryWeight = weight * 0.01;
	numAssignments = assignments;
}
//Setters
void Category::setCategoryName(string name) {
	categoryName = name;
};
void Category::setCategoryWeight(float weight) {
	categoryWeight = weight * 0.01;
};
void Category::setCategoryWeightedGrade(double grade) {
	categoryWeightedGrade = grade;
};
void Category::setCategoryGrade(double grade) {
	categoryGrade = grade;
};
void Category::calculateCategoryWeightedGrade() {
	double grade{};
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		grade += assignmentGrades[i];
	};
	categoryWeightedGrade = grade * categoryWeight;
};
void Category::calculateCategoryGrade() {
	double grade{};
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		grade += assignmentGrades[i];
	};
	categoryGrade = grade;
};
void Category::setNumAssignments(int assignments) {
	numAssignments = assignments;
};
void Category::setAddAssignmentGrade() {
	double grade{};
	if (assignmentGrades.size() < numAssignments) {
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