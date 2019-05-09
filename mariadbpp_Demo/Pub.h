#pragma once

#include <vector>
#include <string>

// Student表中对应的结构体定义
struct Student
{
	std::string Sno;
	std::string Sname;
	std::string Ssex;
	int Sage;
};

typedef std::vector<Student> StudentArray;
typedef unsigned short uint16;
typedef unsigned int uint32;
