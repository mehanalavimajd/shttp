run:
	gcc -o bin/server server.c 
	./bin/server
debug:
	gcc -g -o bin/server server.c 
	gdb ./bin/server