#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class ChatRoom;

class Person
{
public:
  string name;
  ChatRoom* room = nullptr;
  vector<string> chat_log;

  explicit Person(const string& name);
  void say(const string& message) const;
  void receive(const string& origin, const string& message);
  void pm(const string& who, const string& message);
};
