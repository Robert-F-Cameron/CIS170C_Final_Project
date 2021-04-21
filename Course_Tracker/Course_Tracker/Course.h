#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Category.h"
#include "TextTable.h"

using namespace std;

class Course {
private:
	string courseName;
	double courseGrade, courseWeightedGrade, totalCategoryWeight;
	vector<Category> categories;
public:
	//Constructors
	Course();
	Course(string name);
	//Setters
	void setCourseName(string name);
	void setCourseGrade();
	void setCourseWeightedGrade();
	void setTotalCategoryWeight();
	void addCategory();
	void addCategoryObj(Category category);
	//Getters
	string getCourseName();
	double getCourseGrade();
	double getCourseWeightedGrade();
	double getTotalCategoryWeight();
	int getCategoriesSize();
	vector<Category> getCategoriesVector();
	//menu
	void courseMenuTable();
	void courseMenu();
};