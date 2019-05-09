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


// 连接Mariadb数据库
bool MariadbProcess::open_mariadb_connect()
{
	// TODO: 在此处添加实现代码.
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
		std::cout << "连接mariadb数据库失败：" << e.what() << std::endl;
	}
	
	return false;
}


// 关闭Mariadb数据库
void MariadbProcess::close_mariadb_connect()
{
	// TODO: 在此处添加实现代码.
	if (m_db_connection)
	{
		m_db_connection->disconnect();
	}
}


// 从student表查询数据
void MariadbProcess::select_from_student_table(StudentArray &stuArray)
{
	// TODO: 在此处添加实现代码.
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
			// 获取一个学生的信息
			stu.Sno = result->get_string("Sno");
			stu.Sname = result->get_string("Sname");
			stu.Ssex = result->get_string("Ssex");
			stu.Sage = result->get_signed32("Sage");

			// 将每行数据放到结果数组中
			stuArray.push_back(stu);
		}

		close_mariadb_connect();
	}
	catch (const mariadb::exception::connection& e)
	{
		std::cout << "学生表读取失败:" << e.what() << std::endl;
	}
}
