#include"file.h"

File::File() {};
File::~File()=default;

void File::userFile()
{
	std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out);	
	
		if (!user_file)
		user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);

		std::filesystem::permissions("users.txt", std::filesystem::perms::group_write | std::filesystem::perms::group_read 
		| std::filesystem::perms::others_read, std::filesystem::perm_options::remove);

	if (user_file) 
	{
		User user0("Alex", "qwerty", "12345");
		User user1("Gala", "asdfgh", "09876");
		User user2("Sofia", "zxcvbn", "45678");

		user_file << user0 << std::endl;
		user_file << user1 << std::endl;
		user_file << user2 << std::endl;

		user_file.seekg(0, std::ios_base::beg);

		while (true)
		{
			User user;
			user_file >> user;
			if (user_file.eof()) 
			{ 
				break; 
			}
			_user.push_back(user);
		}

		for (auto& user : _user) 
		{
			std::cout << "Name: " << user.getName() << "  " << "Login:  " << user.getLogin() << "  "
				<< "Password: " << user.getPassword() << std::endl;
		}			
	}

	else
	{
		std::cout << "Could not open file users.txt !" << '\n';
	}
}

void File::messageFile()
{
	std::fstream message_file = std::fstream("message.txt", std::ios::in | std::ios::out);

	if (!message_file)
		message_file = std::fstream("message.txt", std::ios::in | std::ios::out | std::ios::trunc);

		std::filesystem::permissions("message.txt", std::filesystem::perms::group_write | std::filesystem::perms::group_read 
		| std::filesystem::perms::others_read, std::filesystem::perm_options::remove);

	if (message_file)
	{
		Message message0("Alex", "Gala" , "Hi! How are you?");
		Message message1("Alex", "Sofia", "Meet me at noon at the school.");
		Message message2("Gala", "Alex", "I'm fine thanks.");

		message_file << message0 << std::endl;
		message_file << message1 << std::endl;
		message_file << message2 << std::endl;

		message_file.seekg(0, std::ios_base::beg);

		while (true)
		{
			Message message;
			message_file >> message;
			if (message_file.eof())
			{
				break;
			}
			_message.push_back(message);
		}

		for (auto& message : _message)
		{
			std::cout << message.getSender() << "  to  " << message.getReceiver() 
				<< "  messege:  " << message.getText() << std::endl;
		}
	}

	else
	{
		std::cout << "Could not open file users.txt !" << '\n';
	}
}

std::istream& operator >>(std::istream& is, User& user)
{
	is >> user._name;
	is >> user._login;
	is >> user._password;
	return is;
}

std::ostream& operator <<(std::ostream& os, User& user)
{
	os << user._name;
	os << ' ';
	os << user._login;
	os << ' ';
	os << user._password;
	return os;
}

std::istream& operator >>(std::istream& is, Message& message)
{	
	is >> message._sender;
	is >> message._receiver;
	std::getline(is, message._text);
	return is;
}

std::ostream& operator <<(std::ostream& os, Message& message)
{	
	os << message._sender;
	os << ' ';
	os << message._receiver;
	os << ' ';
	os << message._text;
	
	return os;
}

