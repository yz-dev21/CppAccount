#pragma once
#include <vector>
#include <string>
#include <fstream>

class Db;

class User
{
public:
	User(Db* db, std::string id, std::string pw);

	long GetNumber() const;
	std::string GetId() const;
	std::string GetPassword() const;
	std::string GetName() const;
	std::string GetDescription() const;

	void SetName(std::string name);
	void SetDescription(std::string description);

	std::string ToString();
private:
	Db* db_ = nullptr;
	long number_ = 0;
	std::string id_ = "";
	std::string password_ = "";
	std::string name_ = "null";
	std::string description_ = "null";
};
class Db
{
public:
	Db(std::string dbPath);

	void EditUser(std::string id, User user);
	void AddUser(User user);
	void RemoveUser(std::string id);
	User GetUser(std::string id) const;
	std::vector<User> GetUsers() const;

	void Update();
private:
	std::vector<User> users_{};
	std::ifstream in_{};
	std::ofstream out_{};
};