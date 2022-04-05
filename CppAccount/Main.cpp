#include "DB.h"
#include "Ui.h"

#include <iostream>

int main()
{
	auto db1 = DB("Database");


	std::cout << db1.GetUser("id2").ToString();

	//std::cout << "After : \n" << db1.GetJsonString();
}