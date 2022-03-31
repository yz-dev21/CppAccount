#include "Db.h"
#include <sstream>

User::User(std::string id, std::string pw)
{
	id_ = id;
	password_ = pw;
}
std::string User::GetId() const
{
	return id_;
}
std::string User::GetPassword() const
{
	return password_;
}
std::string User::GetName() const
{
	return name_;
}
std::string User::GetDescription() const
{
	return description_;
}
void User::Set(User user)
{
	password_ = user.password_;
	name_ = user.name_;
	description_ = user.description_;
}
void User::SetPassword(std::string pw)
{
	password_ = pw;
}
void User::SetName(std::string name)
{
	name_ = name;
}
void User::SetDescription(std::string description)
{
	description_ = description;
}
std::string User::ToString() const
{
	std::stringstream ss;
	ss << "Id: " << id_ << " / Pw: " << password_ << " / Name: " << name_ << " / Description: " << description_;
	return ss.str();
}
Db::Db(std::string dbPath)
{
	in_ = std::ifstream(dbPath);
	out_ = std::ofstream(dbPath);
}
void Db::EditUser(std::string id, const User& user)
{
	if (users_.find(id) == users_.end()) return;

	users_[id].Set(user);
}
void Db::AddUser(const User& user)
{
	users_[user.GetId()] = user;
}
void Db::RemoveUser(std::string id)
{
	if (users_.find(id) == users_.end()) return;

	users_.erase(id);
}
User Db::GetUser(std::string id) const
{
	return users_.at(id);
}
std::unordered_map<std::string, User> Db::GetUsers() const
{
	return users_;
}
std::string Db::ToString() const
{
	std::stringstream ss;

	for (const auto& user : users_)
	{
		ss << user.second.ToString() << "\n";
	}
	return ss.str();
}
void Db::Update()
{
	char lines[512] = { 0, };
	while (in_.getline(lines, sizeof(lines) / sizeof(char)))
	{

	}
}