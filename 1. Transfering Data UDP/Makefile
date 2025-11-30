client:	client.c
	gcc file_utils.c file_utils.h client.c	-o	client

server: server.c
	gcc file_utils.h server.c -o server


all: server.c client.c file_utils.c file_utils.h
	make client
	make server

clean:
	rm client server