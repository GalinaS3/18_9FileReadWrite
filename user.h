#pragma once
#include <iostream>

class User {
	std::string _name;
	std::string _login;
	std::string _password;

public:
	User(const std::string& name, const std::string& login, const std::string& password);
	User();
	~User();

	std::string getName();
	std::string getLogin();
	std::string getPassword();
	friend std::istream& operator >>(std::istream& is, User& user);
	friend std::ostream& operator <<(std::ostream& os, User& user);

};