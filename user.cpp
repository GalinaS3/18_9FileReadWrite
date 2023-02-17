#include "user.h"


User::User(const std::string& name, const std::string& login, const std::string& password)
	:_name(name), _login(login), _password(password) {}
User::User() {};
User::~User() = default;

std::string User::getName() { return _name; }
std::string User::getLogin() { return _login; }
std::string User::getPassword() { return _password; }

