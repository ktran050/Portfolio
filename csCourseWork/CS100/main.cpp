#include <iostream>
#include <vector>
#include <string>

class Command{
	public:
		string cmd;
		vector <string> arg;
		string connect;
		bool ran;
		bool valid;
		void execvp();
		void fork();
		void waitpid();
		
};
// Holds one command which includes all its command, a list of its arguments, a connector, a bool whether or not the command it's valid
// and a bool to return whether or not it ran
// The void functions are used to execute the command

class cmd_list{
	vector <command> list;
	public:
		void add(*command);
		void rm(*command);
};
// Is a composite for commands
// Allows us to have a log of commands

class connector{
	public:
		bool semi(*ran);
		bool and(*ran);
		bool or(*ran);
		bool comment(*ran);
};
// Different connectors require different implementations
// Implementations can be added or removed here

void parse(string &Raw){
	
}
/// Words are strings that end with a space
// If the char '#' is detected everything past this is a comment
// If any of the key chars (; && ||) are detected then the previous command is finished
// Take in the first word as cmd
// Take in the next words as arguments

int main()
{
	std::string RawCmd;

	cout << "$" << endl;

	std::getline(cin, RawCmd);
	// Take in the raw information from user
	
	void parse(&RawCmd);
	// Parse the information
	
	// Run the commands

	return 0
}

// Prompted user
// Took in input
