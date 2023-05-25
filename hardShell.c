#include "shell.h"

/**
 * hardshell - my own shell program
 * @input: Stores data taken from the user
 * @inputSize: stores the size of input stored
 * @userInput: number of bytes returned
 *  Return: Always 0 on success otherwise -1
 */

int main(int ac, char **argv)
{
    char *prompt = "#";
    char *input = NULL, *inputCpy = NULL;
    size_t inputSize = 0;
    ssize_t inputRV;
    const char *delim = " \n";
    int numTokens = 0;
    char *token;
    int i;

    /* declare void variables */
    (void)ac;

    /* Create infinite loop for the shell's prompt */
    while (1)
     {
        /**/
        printf("%s", prompt);
        inputRV = getline(&input, &inputSize, stdin);
        /* handle getline errors */ 
        if (inputRV == -1){
            printf("getline failure\n");
            return (-1);
        }

        /* allocate dynamic memory for inputcpy */
        inputCpy = malloc(sizeof(char) * inputRV);
        if (inputCpy== NULL){
            perror("malloc failure");
            return (-1);
        }
        /* copy input data into inputCpy */
        strcpy(inputCpy, input);

        /*tokenize input from user to array of strings*/
        /* calculate the number of tokens parsed*/
        token = strtok(input, delim);

        while (token != NULL){
            numTokens++;
            token = strtok(NULL, delim);
        }
        numTokens++;

        /* Allocate space for array of tokens */
        argv = malloc(sizeof(char *) * numTokens);

        /* Store each token in the array */
        token = strtok(inputCpy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /*printf("%s\n", argv[0]);*/
        
        /*execute the command using execve */
        cmdExec(argv);

    } 

    /* prevent memory leaks */ 
    free(inputCpy);
    free(input);

    return (0);
}
