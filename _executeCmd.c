#include "shell.h"

void cmdExec(char **argv)
{
        char *cmd = NULL; *actualCmd = NULL;
        if (argv)
        {
                /*assign input cmd to argv[0] for execve()*/
                argv[0] = cmd;

                /*append path to cmd before executing*/
                actualCmd = getPath(cmd);
                /*Execute the cmd with execve()*/
                if (execve(argv[0], argv, NULL) == -1)
                {
                        perror("execve() failure");
                };
        }
}
