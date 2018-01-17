
test.exe : main.o BBoard.o Message.o User.o Topic.o Reply.o
	g++ -g main.o BBoard.o Message.o User.o Topic.o Reply.o -o test.exe

main.o : main.cpp BBoard.cpp BBoard.h Message.cpp Message.h User.cpp User.h Topic.cpp Topic.h Reply.cpp Reply.h
	g++ -g -c -W -Wall -Werror -pedantic -ansi main.cpp

BBoard.o : BBoard.cpp BBoard.h Message.cpp Message.h User.cpp User.h Topic.cpp Topic.h Reply.cpp Reply.h
	g++ -g -c -W -Wall -Werror -pedantic -ansi BBoard.cpp

User.o : User.cpp User.h
	g++ -g -c -W -Wall -Werror -pedantic -ansi User.cpp

Message.o : Message.h Message.cpp
	g++ -g -c -W -Wall -Werror -pedantic -ansi Message.cpp

Topic.o : Topic.h Topic.cpp Message.h Message.cpp
	g++ -g -c -W -Wall -Werror -pedantic -ansi Topic.cpp

Reply.o : Reply.h Reply.cpp Message.h Message.cpp
	g++ -g -c -W -Wall -Werror -pedantic -ansi Reply.cpp