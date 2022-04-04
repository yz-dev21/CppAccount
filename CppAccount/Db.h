#pragma once
#include <unordered_map>
#include <string>

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

class DB
{
public:
	DB(std::string dbPath);

	// Edit a specific user with id.
	void EditUser(std::string id, const User& user);
	// Add an user.
	void AddUser(const User& user);
	// Remove a specific user with id.
	void RemoveUser(std::string id);
	// Get a specific user with id.
	User GetUser(std::string id) const;
	// Get users map.
	std::unordered_map<std::string, User> GetUsers() const;

	// Get users as string from DB class.
	std::string ToString() const;
	// Get users as json from local database file.
	std::string GetXMLString();

	// Sync database with local database file.
	void Sync();
private:
	std::unordered_map<std::string, User> users_{};
	std::string dbPath_ = "";
};