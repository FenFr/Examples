fork_and_pipe:	A-1-fork_and_pipe.o
				gcc OBJ/A-1-fork_and_pipe.o -o A-1-fork_and_pipe

fork_and_pipe.o:	A-1-fork_and_pipe.c
					gcc A-1-fork_and_pipe.c -o OBJ/A-1-fork_and_pipe.o