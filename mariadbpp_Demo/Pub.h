#pragma once

#include <vector>
#include <string>

// Student���ж�Ӧ�Ľṹ�嶨��
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
