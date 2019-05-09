#pragma once

#include "Pub.h"

#include <mariadb++/connection.hpp>
#include <mariadb++/exceptions.hpp>

#pragma comment(lib, "libmariadb.lib")
#pragma comment(lib, "mariadbclientpp.lib")


class MariadbProcess
{
public:
	MariadbProcess(const std::string host_name, const std::string user_name,
		const std::string password, const std::string schema = "", uint32 port = 3306);
	~MariadbProcess();

public:
	// ���ݿ����
	// ����Mariadb���ݿ�
	bool open_mariadb_connect();
	// �ر�Mariadb���ݿ�
	void close_mariadb_connect();

	// ��student���ѯ����
	void select_from_student_table(StudentArray &stuArray);

private:
	mariadb::connection_ref m_db_connection;

	std::string m_hostName;
	std::string m_usrName;
	std::string m_pwd;
	std::string m_dbName;
	uint32 m_port;
};

