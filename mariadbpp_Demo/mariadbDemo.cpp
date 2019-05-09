#include <iostream>

#include "MariadbProcess.h"

int main(int argc, char *argv[])
{

	MariadbProcess mariadbPro("localhost", "root", "cppadmin@123", "university");
	StudentArray stuArray;
	mariadbPro.select_from_student_table(stuArray);

	int i = 0;
	for (StudentArray::iterator it = stuArray.begin(); it != stuArray.end(); ++it )
	{
		std::cout << "[第" << ++i << "个学生的数据为:]" << "学号：" << (*it).Sno << ","
			<< "姓名：" << (*it).Sname << "," << "性别：" << (*it).Ssex << ","
			<< "年龄：" << (*it).Sage << std::endl;
	}
	
	std::system("pause");

	return 0;
}


