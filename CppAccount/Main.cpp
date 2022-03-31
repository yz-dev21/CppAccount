#include "Db.h"
#include "Ui.h"

#include <iostream>

int main()
{
	auto db1 = Db("Database.txt");
	auto user1 = User("noobmaster69", "6974");
	db1.AddUser(user1);
	std::cout << db1.ToString() << "\n";
	user1.SetName("sexmachine");
	db1.EditUser(user1.GetId(), user1);
	std::cout << db1.ToString();
}