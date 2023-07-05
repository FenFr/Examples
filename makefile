PROGRAMS = A-1-fork_and_pipe A-2.1-msg_writer A-2.2-msg_reader
PROGRAM  = $(O)A-1-fork_and_pipe $(O)A-2.1-msg_writer $(O)A-2.2-msg_reader

C = EXX-LNX/
O = OBJ/


all: $(PROGRAMS)


A-1-fork_and_pipe:	EXX-LNX/A-1-fork_and_pipe.c
					gcc EXX-LNX/A-1-fork_and_pipe.c -o OBJ/A-1-fork_and_pipe

A-2.1-msg_writer:	EXX-LNX/A-2.1-msg_writer.c
					gcc EXX-LNX/A-2.1-msg_writer.c -o OBJ/A-2.1-msg_writer

A-2.2-msg_reader:	EXX-LNX/A-2.2-msg_reader.c
					gcc EXX-LNX/A-2.2-msg_reader.c -o OBJ/A-2.2-msg_reader


clean:	
	rm -f $(PROGRAM)