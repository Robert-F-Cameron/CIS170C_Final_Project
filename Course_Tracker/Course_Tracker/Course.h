#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include<array>
#include "Category.h"

using namespace std;

class Course {
private:
	string courseName;
	double courseGrade;
	vector<Category*> categories;
public:
	//Constructors
	Course();
	Course(string name);
	//Setters
	void setCourseName(string name);
	void setCourseGrade();
	void setAddCategory();
	//Getters
	string getCourseName();
	double getCourseGrade();
	double getTotalCategoryWeight();
};