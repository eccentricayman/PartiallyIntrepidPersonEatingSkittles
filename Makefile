compile:
	gcc client.c pipe_networking.c -o client
	gcc server.c pipe_networking.c -o server

clean:
	rm -rf MEME.JPG
