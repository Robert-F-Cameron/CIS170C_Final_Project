#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include<array>

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
	Category(string name, double categoryWeight, int numAssignments);
	//Setters
	void setCategoryName(string name);
	void setCategoryWeight(double weight);
	void setCategoryWeightedGrade();
	void setCategoryGrade();
	void setNumAssignments(int numAssignments);
	void setAddAssignmentGrade();
	//Getters
	string getCategoryName();
	double getCategoryWeight();
	double getCategoryGrade();
	int getNumAssignments();
	void getAssignmentGrades();
};