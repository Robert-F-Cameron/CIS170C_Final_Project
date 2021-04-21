#include "Category.h"
#include "Course.h"

using namespace std;
//Constructors
Course::Course() {
	courseName = "Default Course";
	courseGrade = 0;
	courseWeightedGrade = 0;
};
Course::Course(string name) {
	courseName = name;
	courseGrade = 0;
	courseWeightedGrade = 0;
};
//Setters
void Course::addCategory() {
	string name;
	float categoryWeight;
	int numAssignments;
	if (totalCategoryWeight < 1) {
		cout << "Category Name: ";
		getline(cin, name);
		cout << "Category Grading Weight: ";
		cin >> categoryWeight;
		if (((categoryWeight * 0.01) + totalCategoryWeight) > 1) {
			do {
				cout << "Invalid Category Grading Weight" << endl;
				if (totalCategoryWeight > 0) {
					cout << "Only " << (100 - (totalCategoryWeight * 100)) << "% remaining!" << endl;
				}
				else {
					cout << "Grading weight cannot be greater than 100%" << endl;
				}
				cout << "Category Grading Weight: ";
				cin >> categoryWeight;
			} while (((categoryWeight * 0.01) + totalCategoryWeight) > 1);
		}
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Number of Category Assignments: ";
		cin >> numAssignments;
		cin.clear();
		cin.ignore(1024, '\n');
		Category newCategory = Category(name, categoryWeight, numAssignments);
		categories.push_back(newCategory);
		setTotalCategoryWeight();
		if (totalCategoryWeight < 1) {
			cout << categories[categories.size() - 1].getCategoryName() << " added!" << ((1 - totalCategoryWeight) * 100) << "% grade weight remaining." << endl;
		}
		else if (totalCategoryWeight == 1) {
			cout << name << " added!" << "100% grade weight allocated." << endl;
		}
	}
};
void Course::setCourseName(string name) {
	courseName = name;
};
void Course::setCourseGrade() {
	double grade{}, gradedCategories{};
	for (unsigned int i{}; i < categories.size(); i++) {
		vector<double> submittedGrades = categories[i].getSubmittedAssignmentGrades();
		if (submittedGrades.size() > 0) {
			grade += categories[i].getCategoryGrade();
			gradedCategories++;
		};
	};
	courseGrade = grade / gradedCategories;
};
void Course::setCourseWeightedGrade() {
	double grade{}, gradedCategories{};
	for (unsigned int i{}; i < categories.size(); i++) {
		vector<double> submittedGrades = categories[i].getSubmittedAssignmentGrades();
		if (submittedGrades.size() > 0) {
			grade += categories[i].getCategoryWeightedGrade();
			gradedCategories++;
		};
	};
	courseWeightedGrade = grade / gradedCategories;
};
void Course::setTotalCategoryWeight() {
	double categoryWeight{};
	for (unsigned int i{}; i < categories.size(); i++) {
		categoryWeight += categories[i].getCategoryWeight();
	}
	totalCategoryWeight = categoryWeight;
};
void Course::addCategoryObj(Category category) {
	categories.push_back(category);
};
//Getters
string Course::getCourseName() {
	return courseName;
};
double Course::getCourseGrade() {
	return courseGrade;
};
double Course::getCourseWeightedGrade() {
	return courseWeightedGrade;
};
double Course::getTotalCategoryWeight() {
	return totalCategoryWeight;
};
int Course::getCategoriesSize() {
	return categories.size();
};
vector<Category> Course::getCategoriesVector() {
	return categories;
};
//menu
void Course::courseMenuTable() {
	TextTable t('-', '|', '+');
	t.add("Selection");
	t.add("Category Name");
	t.add("Category Weight");
	t.add("Category Grade");
	t.add("Number of Assignments");
	t.add("Assignments submitted");
	t.endOfRow();
	for (unsigned int i{}; i < categories.size(); i++) {
		t.add(to_string(i + 1));
		t.add(categories[i].getCategoryName());
		t.add(to_string(categories[i].getCategoryWeight()));
		t.add(to_string(categories[i].getCategoryGrade()));
		t.add(to_string(categories[i].getNumAssignments()));
		t.add(to_string(categories[i].getNumAssignmentsSubmitted()));
		t.endOfRow();
	}
	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
};
void Course::courseMenu() {
	bool courseMenu = true;
	char selection, input;
	int categorySelection = 0;
	do {
		courseMenuTable();
		cout << "Select a category to view" << endl;
		cout << "or 'q' to return to Course List:";
		cin >> input;
		cin.clear();
		cin.ignore(1024, '\n');
		int num = input - 49;
		int numCategories = categories.size();
		if (input == 'q') {
			selection = 'q';
		}
		else if (num > numCategories) {
			selection = input;
		}
		else if (num <= numCategories) {
			selection = '1';
		}
		switch (selection) {
		case '1':
			categories[num].categoryMenu();
			getCourseWeightedGrade();
			getCourseGrade();
			break;
		case 'q':
			cout << "Retruning to course list..." << endl << endl;
			courseMenu = false;
			break;
		default:
			cout << num;
			cout << "Not a valid input";
		}
	} while (courseMenu);
};