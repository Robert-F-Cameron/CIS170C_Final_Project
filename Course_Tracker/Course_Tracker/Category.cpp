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
	categoryWeight = weight;
	numAssignments = assignments;
}
Category::Category(string name, float weight, double weightedGrade, double grade, int assignments, vector<double> submittedAssignments) {
	categoryName = name;
	categoryGrade = grade;
	categoryWeightedGrade = weightedGrade;
	categoryWeight = weight;
	numAssignments = assignments;
	assignmentGrades = submittedAssignments;
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
		if (grade > 100) {
			cout << "Grade cannot be over 100!" << endl;
			setAddAssignmentGrade();
		}
		else {
			assignmentGrades.push_back(grade);
		};
	}
	else {
		cout << "All Assignments Submitted!" << endl;
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
};
vector<double> Category::getSubmittedAssignmentGrades() {
	return assignmentGrades;
};
//Category Menu
void Category::categoryMenuTable() {
	TextTable t('-', '|', '+');
	t.add("Category Name");
	t.add("Category Weight");
	t.add("Category Grade");
	t.add("Number of category assignments");
	t.add("Number of assignments submitted");
	t.endOfRow();
	t.add(getCategoryName());
	t.add(to_string(getCategoryWeight()));
	t.add(to_string(getCategoryGrade()));
	t.add(to_string(getNumAssignments()));
	t.add(to_string(getNumAssignmentsSubmitted()));
	t.endOfRow();
	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
};
void Category::categoryMenu() {
	bool categoryMenu = true;
	categoryMenuTable();
	do {
		int categoryInput{}, number{};
		float weight{};
		string name{};
		cout << getCategoryName() << " Menu:" << endl;
		cout << "1) Add assignment grade" << endl
			<< "2) Update category name" << endl
			<< "3) Update category weight" << endl
			<< "4) Update category number of category assignments" << endl
			<< "5) Return to course menu" << endl;
		cout << "Selection: ";
		cin >> categoryInput;
		cin.clear();
		cin.ignore(1024, '\n');
		switch (categoryInput) {
		case 1:
			setAddAssignmentGrade();
			calculateCategoryGrade();
			calculateCategoryWeightedGrade();
			categoryMenuTable();
			break;
		case 2:
			cout << "Input updated category name: ";
			getline(cin, name);
			setCategoryName(name);
			categoryMenuTable();
			break;
		case 3:
			cout << "Input updated category name: ";
			cin >> weight;
			cin.clear();
			cin.ignore(1024, '\n');
			setCategoryWeight(weight);
			categoryMenuTable();
			break;
		case 4:
			cout << "Input updated category name: ";
			cin >> number;
			cin.clear();
			cin.ignore(1024, '\n');
			setNumAssignments(number);
			categoryMenuTable();
			break;
		case 5:
			cout << "Returning to course menu..." << endl << endl;
			categoryMenu = false;
			break;
		default:
			cout << "Not a valid input." << endl;
			break;
		};
	} while (categoryMenu);
};