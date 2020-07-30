#include "db.hpp"
int main()
{
	MYSQL* mysql = blog_systream::Mysqlinit();
	blog_systream::TableUser table_user(mysql);
	Json::Value user;
	user["name"] = "³Â¶«Èð";
	table_user.Insert(user);

	blog_systream::MysqlRelease(mysql);

	return 0;
}
