#include "shell.h"

/**
 * _prompt - function that displays prompt and accepts user input
 * @input: Stores data taken from the user
 * @inputSize: stores the size of input stored
 * @userInput: number of bytes returned
 *  Return: Always 0 on success otherwise -1
 */

void _prompt(char **av, char **env) 
{
    /* declaring and initializing variables to use */
    char *input = NULL;
    size_t inputSize = 0;
    ssize_t userInput;
    pid_t myPid;
    int i = 0;
    char *argv[] = {NULL, NULL};
    int status;
    
    
    while (2)
    {
        /*create prompt and take in user input*/
        if (isatty(STDIN_FILENO) == 1)
        {
		printf ("$ ");
        }
       
        userInput = getline(&input, &inputSize, stdin);
        
        /*handle getline errors*/
        if (userInput == -1)
        {
            perror("Error(getline failure)");
            free(input);
            exit(EXIT_FAILURE);
        }
        /*replace last char of input to show end of command*/
        while (input[i])
        {
           if (input[i] == '\n')
            input[i] = '\0';
        i++;
        }
        
        argv[i] = NULL;
        /*printf ("%s\n", input);*/

                
        /*create a child process and execute commands*/
        myPid = fork();
        /*handle fork function failure*/
        if (myPid == -1)
        {
            perror("error(fork failure)");
            exit(EXIT_FAILURE);
        }
        /*child process, execve() call and error handling*/
        if (myPid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
            {
                printf ("%s: No such file or directory\n", av[0]);
            }
        }
	/*wait for the child process to terminate and reap it*/
        else
        {
            wait(&status);
        }
        
    }
}
