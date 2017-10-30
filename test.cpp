nclude <iostream>
#include <vector>
#include <string>

class Command{
	public:
			std::string cmd;
					std::vector <std::string> arg;
							std::string connect;
									std::bool ran;
											std::bool valid;
													void execvp();
															void fork();
																	void waitpid();
																			
																			};
																			// Holds one command which includes all its command, a list of its arguments, a connector, a bool whether or not the command it's valid
																			// // and a bool to return whether or not it ran
																			// // The void functions are used to execute the command
																			// class cmd_list{
																			// 	std::vector <Command> list;
																			// 		public:
																			// 				void add(Command);
																			// 						void rm(Command);
																			// 						};
																			// 						// Is a composite for commands
																			// 						// Allows us to have a log of commands
																			//
																			// 						class connector{
																			// 							public:
																			// 									std::bool semi(std::bool &ran);
																			// 											std::bool andAnd(std::bool &ran);
																			// 													std::bool orOr(std::bool &ran);
																			// 															std::bool comment(std::bool &ran);
																			// 															};
																			// 															// Different connectors require different implementations
																			// 															// Implementations can be added or removed here
																			//
																			// 															void parse(std::string &strInput, std::cmd_list &cmdline){
																			// 																if(strInput.size() != 0){
																			// 																		for(int i=0; i<strInput.size()-1; i++){		// loops through the whole string
																			// 																					
																			// 																							}
																			// 																								}
																			// 																								}
																			// 																								/// Words are strings that end with a space
																			// 																								// If the char '#' is detected everything past this is a comment
																			// 																								// If any of the key chars (; && ||) are detected then the previous command is finished
																			// 																								// Take in the first word as cmd
																			// 																								// Take in the next words as arguments
																			//
																			// 																								int main()
																			// 																								{
																			// 																									std::string RawCmd;
																			// 																										std::cmd_list cmdline;
																			//
																			// 																											std::cout << "$ ";
																			//
																			// 																												std::getline(std::cin, RawCmd);
																			// 																													// Take in the raw information from user
																			// 																														
																			// 																															void parse(RawCmd, cmdline);
																			// 																																// Parse the information
																			// 																																	
																			// 																																		// Run the commands
																			//
																			// 																																			return 0
																			// 																																			}
																			//
																			// 																																			// Prompted user
																			// 																																			// Took in input
																			// 																																			
