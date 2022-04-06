#include "DB.h"
#include "Ui.h"
#include <conio.h>

#include <iostream>

#include <Windows.h>

void InitWindow()
{
	// window size
	// window title
}
void Login()
{
	std::string id = "";
	std::string password = "";

	std::cin >> id;
	
}
void Register()
{

}
void Profile()
{

}
void Menu()
{
	std::cout << "CppAccount\n\n";

	std::cout << "1 - Login\n";
	std::cout << "2 - Register\n";

	char key{};

	do
	{
		key = _getch();
	} while (key < '1' || key > '2');

	switch (key)
	{
		case '1':
			Login();
			break;
		case '2':
			Register();
			break;
	}
}

int main()
{
	auto db1 = DB("Database");
}