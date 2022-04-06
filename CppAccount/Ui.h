#pragma once

class DB;

class UI
{
public:
	UI(const DB& database);
	void Run();
private:
	DB database_;

	void InitWindow();
	
	void Login();
	void Register();
	void Profile();

	void Id();
	void PW();
};