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
	categoryWeightedGrade = 0;
	categoryWeight = weight * 0.01;
	numAssignments = assignments;
}
Category::Category(string name, float weight, double weightedGrade, double grade, int assignments) {
	categoryName = name;
	categoryGrade = grade;
	categoryWeightedGrade = weightedGrade;
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

	categoryWeightedGrade = ((grade / assignmentGrades.size()) * categoryWeight);
};
void Category::calculateCategoryGrade() {
	double grade{};
	for (unsigned int i{}; i < assignmentGrades.size(); i++) {
		grade += assignmentGrades[i];
	};
	categoryGrade = grade / assignmentGrades.size();
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
	else {
		cout << "All Assignments Submitted!";
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
double Category::getCategoryWeightedGrade() {
	return categoryWeightedGrade;
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
int Category::getNumAssignmentsSubmitted() {
	return assignmentGrades.size();
}
//Category Menu
void Category::categoryMenu() {
	bool categoryMenu = true;
		cout << getCategoryName() << " Menu:" << endl;
		cout << "1) Add assignment grade" << endl
			<< "2) Update category name" << endl
			<< "3) Update category weight" << endl
			<< "4) Update category number of category assignments" << endl
			<< "5) Return to course menu" << endl;
	do {
		int categoryInput{}, number{};
		float weight{};
		string name{};
			cout << "Selection: ";
		cin >> categoryInput;
		cin.clear();
		cin.ignore(1024, '\n');
		switch (categoryInput) {
		case 1:
			setAddAssignmentGrade();
			calculateCategoryGrade();
			calculateCategoryWeightedGrade();
			break;
		case 2:
			cout << "Input updated category name: ";
			cin >> name;
			cin.clear();
			cin.ignore(1024, '\n');
			setCategoryName(name);
			break;
		case 3:
			cout << "Input updated category name: ";
			cin >> weight;
			cin.clear();
			cin.ignore(1024, '\n');
			setCategoryWeight(weight);
			break;
		case 4:
			cout << "Input updated category name: ";
			cin >> number;
			cin.clear();
			cin.ignore(1024, '\n');
			setNumAssignments(number);
			break;
		case 5:
			categoryMenu = false;
			break;
		default:
			cout << "Not a valid input." << endl;
			break;
		};
	} while (categoryMenu);
};