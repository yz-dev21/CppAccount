#include "DB.h"
#include "Ui.h"

#include <iostream>

int main()
{
	auto db1 = DB("Database");
	std::cout << db1.ToString();
	auto user1 = User("id1", "pw1");
	auto user2 = User("id2", "pw2");

	user2.SetName("DIICK");
	user2.SetDescription("SEXMASTER");

	db1.EditUser(user2.GetId(), user2);

	db1.Sync();

	std::cout << db1.ToString();

	//std::cout << "After : \n" << db1.GetJsonString();
}