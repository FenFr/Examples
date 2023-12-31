//////////////////////////////////////////////////////////////////////////////
//  Author:                 B.Sc. Fenja Freitag                             //
//  Name:                   fork_and_pipe.c                                 //
//  Description:            testing different methods of fork() and pipe()  //
//  Version:                1.0                                             //
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define buffsize 64


int main(int argc, char**argv){
    if (argc != 2){
        printf("\nType: '%s number'!\n\n", argv[0]);
        exit(1);
    }
    int module = (int)argv[1][0] - 48;
    if(module < 0 || module > 9 || argv[1][1]){
        printf("\nNumber must be between 0 and 9!\n\n");
        exit(2);
    }

    int n_of_childs;
    int pid;
    int pipefd[2];
    int wstatus;
    char message[buffsize];

    switch(module){
        
        // creating one child by using fork()
        case 0:
            printf("Creating one child:\n");
            if(fork() == 0)
                printf("Hello, I'm child.\n");
            else
                printf("Hello, I'm parent.\n");
            break;

        // creating multiple childs
        case 1:
            printf("Type in number of childs: ");
            scanf("%d", &n_of_childs);

            while(n_of_childs-- > 0){
                pid = fork();
                if(pid == 0)
                    break;
            }

            if(pid == 0)
                printf("Hello, I'm child #%d.\n", n_of_childs);
            else
                printf("Hello, I'm parent.\n");
            break;

        // creating a pipe via pipe() between a child and an parent process
        case 2:
            printf("Creating pipes:\n");
            if(pipe(pipefd)){
                printf("\nError with pipe!\n");
                exit(3);
            }
            if(fork() == 0){
                printf("Reading (Child) : ");
                fgets(message, buffsize, stdin);
                write(pipefd[1], message, buffsize);
            }
            else{
                wait(&wstatus);
                read(pipefd[0], message, buffsize);
                printf("Writing (Parent): %s\n", message);
            }
            break;


        default:
            printf("Nothing is here ...\n");
            break; 
    }
}