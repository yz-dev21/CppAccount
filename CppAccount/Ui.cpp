#include <conio.h>
#include <Windows.h>

void UI::Run()
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
void UI::InitWindow()
{
	// window size
	// window title
}
void UI::Login()
{
	std::string id = "";
	std::string password = "";

	std::cin >> id;
	auto duplicate = database_.GetUser(id);
	if (duplicate == NULL)
	{
		std::cout << "There is no such account. Try again.\n";
		Login(database);
	}
	std::cin >> password;
	if (duplicate.GetPassword() != password)
	{
		std::cout << "Password is wrong. Try again.\n";
	}
}
void Register()
{

}
void Profile()
{

}
void Id()
{
    std::string id;
    std::cout << "ID : ";
    std::cin >> id;

    if (database_.GetUser(id) == NULL)
    {
        std::cout << "There is no such account.\n";
        Id();
    }
}
void PW()
{
    std::string pw;
    std::cout << "Password : ";
    std::cin >> pw;

    if (database_.GetUser())
}