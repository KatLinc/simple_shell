#include "main.h"

/**
 * getPath - function that appends path of a cmd to the cmd
 * @ _path: Stores data taken from the user
 * @_pathCopy: stores the size of input stored
 * @pathToken: number of bytes returned
 * @filePath:
 * @ buf: struct to store stat data
 *  Return: Always 0 on success otherwise -1
 */

char *getPath(char *cmd)
{
    /*declaration and initialization of variables*/
    char *_path, *_pathCopy, *pathToken, *filePath;
    int cmdLength, dirLength;
    struct stat buf;

    _path = getenv("PATH");

    if (_path){
        /* Duplicate _path before calling strtok()*/ 
        _pathCpy = strdup(_path);
        /* Get command length*/
        cmdLength = strlen(cmd);

        /*tokenize _path and get all available directories in it*/
        pathToken = strtok(pathCopy, ":");

        while (pathToken != NULL)
        {
            /* calculate directory length*/
            dirLength = strlen(pathToken);
            /* allocate memory for the cmd name, dir name and extra 2chars to be appended */
            filePath = malloc(cmdLength + dirLength + 2); 
            
            /*build the path for the cmd by Copying dirPath and concatenating the cmd to it*/
            strcpy(filePath, pathToken);
            strcat(filePath, "/");
            strcat(filePath, cmd);
            strcat(filePath, "\0");

            /* Test filePath existence and return it, else try next dir*/
            if (stat(filePath, &buf) == 0)
            {
                /*0 means filePath does exist*/

                /* free pathCpy before returning filePath */
                free(pathCpy);

                return (filePath);
            }
            else
            {
                /* free up filePath memory so that we can check for another path*/
                free(filePath);
                pathToken = strtok(NULL, ":");

            }

        }

        /* return NULL if no filePath exists then free memory of pathCpy*/ 
        free(path_Cpy);

        /* Check if cmd itself is a filePath that exists before exiting without luck*/
        if (stat(cmd, &buf) == 0)
        {
            return (cmd);
        }


        return (NULL);

    }


    return (NULL);
}
