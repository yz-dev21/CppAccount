#include "DB.h"
#include "Ui.h"

#include <iostream>

int main()
{
	auto db1 = DB("Database");
	auto user1 = User("user1", "6974");
	auto user2 = User("user2", "6974");
	db1.AddUser(user1);
	db1.AddUser(user2);
	db1.Update();
	std::cout << db1.ToString();
	std::cout << db1.GetJsonString() << "\n";

	db1.RemoveUser(user1.GetId());
	db1.Update();
	std::cout << db1.ToString();
	std::cout << db1.GetJsonString() << "\n";
}