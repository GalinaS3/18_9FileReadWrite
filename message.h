#pragma once
#include <iostream>

class Message {
    std::string _sender;
    std::string _receiver;
    std::string _text;

public:
    Message(const std::string& sender, const std::string& receiver, const std::string& text);
    Message();
    ~Message();

    std::string getText();
    std::string getSender();
    std::string getReceiver();
    friend std::istream& operator >>(std::istream& is, Message& message);
    friend std::ostream& operator <<(std::ostream& os, Message& message);
};