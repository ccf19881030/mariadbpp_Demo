#include "MariadbProcess.h"

MariadbProcess::MariadbProcess(const std::string host_name, const std::string user_name,
	const std::string password, const std::string schema, uint32 port)
{
	m_hostName = host_name;
	m_usrName = user_name;
	m_pwd = password;
	m_dbName = schema;
	m_port = port;
}


MariadbProcess::~MariadbProcess()
{
}


// ����Mariadb���ݿ�
bool MariadbProcess::open_mariadb_connect()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		// set up the account
		mariadb::account_ref acc = mariadb::account::create(m_hostName, m_usrName, m_pwd, m_dbName, m_port);
		// create connection
		m_db_connection = mariadb::connection::create(acc);
		m_db_connection->set_charset("utf8");
		return true;
	}
	catch (const mariadb::exception::connection& e)
	{
		std::cout << "����mariadb���ݿ�ʧ�ܣ�" << e.what() << std::endl;
	}
	
	return false;
}


// �ر�Mariadb���ݿ�
void MariadbProcess::close_mariadb_connect()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (m_db_connection)
	{
		m_db_connection->disconnect();
	}
}


// ��student���ѯ����
void MariadbProcess::select_from_student_table(StudentArray &stuArray)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		open_mariadb_connect();
		// select on the connection
		mariadb::result_set_ref result =
			m_db_connection->query("select Sno, Sname, Ssex, Sage from Student;");

		// reading from a result set
		while (result->next())
		{
			Student stu;
			// ��ȡһ��ѧ������Ϣ
			stu.Sno = result->get_string("Sno");
			stu.Sname = result->get_string("Sname");
			stu.Ssex = result->get_string("Ssex");
			stu.Sage = result->get_signed32("Sage");

			// ��ÿ�����ݷŵ����������
			stuArray.push_back(stu);
		}

		close_mariadb_connect();
	}
	catch (const mariadb::exception::connection& e)
	{
		std::cout << "ѧ�����ȡʧ��:" << e.what() << std::endl;
	}
}
