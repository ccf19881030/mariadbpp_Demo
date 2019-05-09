# mariadbpp_Demo-关于mariadbpp的C++示例程序
## 1、依赖库：mariadb的C语言接口库[mariadb-connector-c](https://github.com/MariaDB/mariadb-connector-c)和C++库[mariadbpp](https://github.com/viaduck/mariadbpp)
MariaDB Connector/C is used to connect applications developed in C/C++ to MariaDB and MySQL databases.
mariadbpp is a C++ client library for MariaDB. Continuation of https://code.launchpad.net/mariadb++

### 2、这是关于mariadbpp的VC++示例程序，需要在VS2017中配置mariadbpp和mariadb-connector-c库。使用时，需要将依赖库目录中的mariadb-connector-c和mariadbpp放在自己机器中对应的目录，例如D:\env_build目录下，最好针对每个依赖库建一个属性配置文件。
#### (1)、主项目mariadbpp_Demo目录下，mariadb_win32_debug.props是mariadb-connector-c库的属性配置文件，其头文件路径为：D:\env_build\mariadb-connector-c\include，库文件路径为：D:\env_build\mariadb-connector-c\build\libmariadb\Debug，需要链接的lib库为：libmariadb.lib和mariadbclient.lib。
#### (2)、主项目mariadbpp_Demo目录下，mariadbpp_win32_debug.props是mariadbpp库的属性配置文件，其头文件路径为：D:\env_build\mariadbpp\include，lib库文件路径为：D:\env_build\mariadbpp\build\Debug，需要链接的lib库为：mariadbclientpp.lib。
我编译的是x86的Debug和Release版本的，如果需要在x64位环境下运行需要自行编译对应的Win64位版本。
### 3、数据库：MySQL或者Mariadb
#### (1)、本项目使用数据库前，在MySQL或者Mariadb库中建立一个university数据库，在university数据库再建立一张学生表Student，
Student表的结构为：
![image](https://github.com/ccf19881030/mariadbpp_Demo/tree/master/images/Student.png)
### 4、使用mariadbpp库
#### (1)、可以参考[mariadbpp](https://github.com/viaduck/mariadbpp)
```c++
// set up the account
std::string hostName;
std::string usrName;
std::string pwd;
std::string dbName;
account_ref acc = account::create(hostName, usrName, pwd, dbName, port);

// create connection
connection_ref con = connection::create(acc);

// insert, update, select on the connection
u64 id = con->insert("INSERT INTO table VALUES (1, 2, 3)");
u64 affected = con->execute("UPDATE table SET a=1");
result_set_ref result = con->query("SELECT * FROM table");

// create statement
statement_ref stmt = con->create_statement(...);

// insert, update, select on the statement
u64 id = stmt->insert();
u64 affected = stmt->execut();
result_set_ref result = stmt->query();

// reading from a result set
while (result->next()) {
    int a = result->get_unsigned32(0);
    int b = result->get_unsigned32("b");
}

// insert using prepared statement
statement_ref stmt = con->create_statement("INSERT INTO table (?, ?, ?)");
stmt->set_unsigned32(0, 13);
stmt->set_unsigned32(1, 37);
stmt->set_unsigned32(2, 42);
stmt->insert();

```
自己写C++项目时，可以针对具体的业务逻辑封装一个MariadbProcess类，对数据库进行操作，具体见相应的代码。



