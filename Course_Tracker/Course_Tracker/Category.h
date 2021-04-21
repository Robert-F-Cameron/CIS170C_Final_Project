#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include<array>
#include "TextTable.h"

using namespace std;

class Category {
private:
	string categoryName;
	double categoryWeight, categoryGrade, categoryWeightedGrade;
	int numAssignments;
	vector<double> assignmentGrades;
public:
	//Constructors
	Category();
	Category(string name, float categoryWeight, int numAssignments);
	Category(string name, float categoryWeight, double weightedGrade, double grade, int numAssignments);
	Category(string name, float categoryWeight, double weightedGrade, double grade, int numAssignments, vector<double> assignments);
	//Setters
	void setCategoryName(string name);
	void setCategoryWeight(float weight);
	void setCategoryWeightedGrade(double grade);
	void calculateCategoryWeightedGrade();
	void setCategoryGrade(double grade);
	void calculateCategoryGrade();
	void setNumAssignments(int numAssignments);
	void setAddAssignmentGrade();
	//Getters
	string getCategoryName();
	double getCategoryWeight();
	double getCategoryGrade();
	double getCategoryWeightedGrade();
	int getNumAssignments();
	void getAssignmentGrades();
	int getNumAssignmentsSubmitted();
	vector<double> getSubmittedAssignmentGrades();
	//Category Menu
	void categoryMenuTable();
	void categoryMenu();
};