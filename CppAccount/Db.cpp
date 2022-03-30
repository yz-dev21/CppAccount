#include "Db.h"
#include <sstream>

User::User(Db* db, std::string id, std::string pw)
{
	db_ = db;
	id_ = id;
	password_ = pw;
}
long User::GetNumber() const
{
	return number_;
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
void User::SetName(std::string name)
{
	name_ = name;
}
void User::SetDescription(std::string description)
{
	description_ = description;
}
std::string User::ToString()
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
void Db::EditUser(std::string id, User user)
{
	for (const auto& u : users_)
	{
		if ()
		{
		}
	}
}
void Db::AddUser(User user)
{

}
std::vector<User> Db::GetUsers() const
{
	return users_;
}