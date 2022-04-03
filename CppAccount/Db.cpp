#include "DB.h"
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>

using Json = nlohmann::json;

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
DB::DB(std::string dbPath)
{
	dbPath_ = dbPath + ".json";
	in_ = std::ifstream(dbPath_);
	out_ = std::ofstream(dbPath_);
}
void DB::EditUser(std::string id, const User& user)
{
	if (users_.find(id) == users_.end()) return;

	users_[id].Set(user);
}
void DB::AddUser(const User& user)
{
	users_[user.GetId()] = user;
}
void DB::RemoveUser(std::string id)
{
	if (users_.find(id) == users_.end()) return;

	users_.erase(id);
}
User DB::GetUser(std::string id) const
{
	return users_.at(id);
}
std::unordered_map<std::string, User> DB::GetUsers() const
{
	return users_;
}
std::string DB::ToString() const
{
	std::stringstream ss;
	for (const auto& user : users_)
	{
		ss << user.second.ToString() << "\n";
	}
	return ss.str();
}
std::string DB::GetJsonString()
{
	in_.open(dbPath_, std::ifstream::in);

	Json read;
	in_ >> read;

	in_.close();

	std::stringstream ss;
	ss << std::setw(4) << read;

	return ss.str();
}
void DB::Update()
{
	out_.open(dbPath_, std::ofstream::out | std::ofstream::trunc);
	out_.close();

	out_.open(dbPath_);
	Json DB = Json::array();
	for (const auto& user : users_)
	{
		Json object = {
			{ user.second.GetId(), {
				{ "password", user.second.GetPassword() },
				{ "name", user.second.GetName() },
				{ "description", user.second.GetDescription() }
			}}
		};
		DB.push_back(object);
	}
	out_ << std::setw(4) << DB;
	out_.close();
}