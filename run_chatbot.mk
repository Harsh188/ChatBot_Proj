a.out:chatBot.o server.o
	gcc chatBot.o server.o
chatBot.o:chatBot.c header.h
	gcc -c chatBot.c
server.o:server.c header.h
	gcc -c server.c
