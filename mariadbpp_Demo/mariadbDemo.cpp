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
		std::cout << "[��" << ++i << "��ѧ��������Ϊ:]" << "ѧ�ţ�" << (*it).Sno << ","
			<< "������" << (*it).Sname << "," << "�Ա�" << (*it).Ssex << ","
			<< "���䣺" << (*it).Sage << std::endl;
	}
	
	std::system("pause");

	return 0;
}


