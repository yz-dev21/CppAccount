#pragma once
#include <unordered_map>
#include <string>
#include <fstream>

class User
{
public:
	User(std::string id, std::string pw);
	User() { }

	std::string GetId() const;
	std::string GetPassword() const;
	std::string GetName() const;
	std::string GetDescription() const;

	void Set(User user);
	void SetPassword(std::string pw);
	void SetName(std::string name);
	void SetDescription(std::string description);

	std::string ToString() const;
private:
	std::string id_ = "";
	std::string password_ = "";
	std::string name_ = "null";
	std::string description_ = "null";
};

namespace std
{
	template <> struct hash<User>
	{
		size_t operator()(const User& key)
		{
			return hash<std::string>()(key.GetId());
		}
	};
}

class Db
{
public:
	Db(std::string dbPath);

	void EditUser(std::string id, const User& user);
	void AddUser(const User& user);
	void RemoveUser(std::string id);
	User GetUser(std::string id) const;
	std::unordered_map<std::string, User> GetUsers() const;

	std::string ToString() const;
	std::string GetJsonString();

	void Update();
private:
	std::unordered_map<std::string, User> users_{};
	std::ifstream in_{};
	std::ofstream out_{};
	std::string dbPath_ = "";
};