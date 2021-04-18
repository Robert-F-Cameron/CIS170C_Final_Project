#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Category.h"

using namespace std;

class Course {
private:
	string courseName;
	double courseGrade, totalCategoryWeight;
	vector<Category> categories;
public:
	//Constructors
	Course();
	Course(string name);
	//Setters
	void setCourseName(string name);
	void setCourseGrade();
	void setTotalCategoryWeight();
	void addCategory();
	//Getters
	string getCourseName();
	double getCourseGrade();
	double getTotalCategoryWeight();
	int getCategoriesSize();
	vector<Category> getCategoriesVector();
};