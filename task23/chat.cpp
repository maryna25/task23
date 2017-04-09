#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "person.h"
#include "chatroom.h"

TEST_CASE("Adding to the chat")
{
	ofstream f("chat.txt"); //too clean the file before using
	f.close();
	string res = "";

	ChatRoom room;

	auto ali = room.join(Person{"Ali"});
	ifstream f1("chat.txt");
	getline(f1, res);
	REQUIRE(res == "");
	f1.close();

	auto galya = room.join(Person{ "Galya" });
	ifstream f2("chat.txt");
	getline(f2, res);
	REQUIRE(res == "[Ali's chat session] room: \"Galya joins the chat\"");
	f2.close();

	auto sofa = room.join(Person{ "Sofa" });
	ifstream f3("chat.txt");
	getline(f3, res); 
	REQUIRE(res == "[Ali's chat session] room: \"Galya joins the chat\"");
	getline(f3, res);
	REQUIRE(res == "[Ali's chat session] room: \"Sofa joins the chat\"");
	getline(f3, res);
	REQUIRE(res == "[Galya's chat session] room: \"Sofa joins the chat\"");
	f3.close();
}

TEST_CASE("Sending message")
{
	ofstream f("chat.txt"); //too clean the file before using
	f.close();
	string res = "";

	ChatRoom room;

	auto ali = room.join(Person{ "Ali" });
	auto galya = room.join(Person{ "Galya" });
	auto sofa = room.join(Person{ "Sofa" });

	ali->say("hi!");
	ifstream f1("chat.txt");
	getline(f1, res);//to skip entering
	getline(f1, res);
	getline(f1, res);
	getline(f1, res);
	REQUIRE(res == "[Galya's chat session] Ali: \"hi!\"");
	getline(f1, res);
	REQUIRE(res == "[Sofa's chat session] Ali: \"hi!\"");
	f1.close();
}

TEST_CASE("Sending private message")
{
	ofstream f("chat.txt"); //too clean the file before using
	f.close();
	string res = "";

	ChatRoom room;

	auto ali = room.join(Person{ "Ali" });
	auto galya = room.join(Person{ "Galya" });
	auto sofa = room.join(Person{ "Sofa" });

	galya->pm("Sofa", "will we go out today?");
	ifstream f1("chat.txt");
	getline(f1, res);//to skip entering
	getline(f1, res);
	getline(f1, res);
	getline(f1, res);
	REQUIRE(res == "[Sofa's chat session] Galya: \"will we go out today?\"");
	f1.close();
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}
