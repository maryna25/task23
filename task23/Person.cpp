#include "person.h"
#include "chatroom.h"

Person::Person(const string& name): name(name)
{
}

void Person::say(const string& message) const
{
  room->broadcast(name, message);
}

void Person::receive(const string& origin, const string& message)
{
  string s{ origin + ": \"" + message + "\"" };
  ofstream f1("chat.txt", ios::app);
  f1 << "[" << name << "'s chat session] " << s << "\n";
  f1.close();
  chat_log.emplace_back(s);
}

void Person::pm(const string& who, const string& message)
{
  room->message(name, who, message);
}
