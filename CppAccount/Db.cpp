#include "DB.h"
#include <iostream>
#include <sstream>
#include <tinyxml2.h>

using namespace tinyxml2;

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
	dbPath_ = dbPath + ".xml";

	XMLDocument doc;
	XMLError error = doc.LoadFile(dbPath_.c_str());
	if (error)
	{
		std::cout << error << std::endl;
		return;
	}
	XMLElement* root = doc.RootElement();
	XMLElement* firstUser = root->FirstChildElement("User");
	for (auto* ele = firstUser; ele != NULL; ele = ele->NextSiblingElement())
	{
		auto user = User(ele->Attribute("id"), ele->Attribute("password"));
		user.SetName(ele->Attribute("name"));
		user.SetDescription(ele->GetText());

		users_[user.GetId()] = user;
	}
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
std::string DB::GetXMLString()
{
	return "";
}
void DB::Sync()
{
	XMLDocument doc;
	XMLElement* root = doc.NewElement("Root");
	doc.LinkEndChild(root);

	for (const auto& user : users_)
	{
		XMLElement* userElement = doc.NewElement("User");

		userElement->SetAttribute("id", user.second.GetId().c_str());
		userElement->SetAttribute("password", user.second.GetPassword().c_str());
		userElement->SetAttribute("name", user.second.GetName().c_str());
		userElement->SetText(user.second.GetDescription().c_str());

		root->LinkEndChild(userElement);
	}
	XMLError error = doc.SaveFile(dbPath_.c_str());
	if (error)
	{
		std::cout << error << std::endl;
	}
}