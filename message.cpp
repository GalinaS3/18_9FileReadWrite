#include "message.h"

Message::Message(const std::string& sender, const std::string& receiver, const std::string& text)
    : _sender(sender), _receiver(receiver), _text(text) {};
Message::Message() {};
Message::~Message() = default;

std::string Message::getText() { return _text; }
std::string Message::getSender() { return _sender; }
std::string Message::getReceiver() { return _receiver; }
