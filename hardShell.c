#include "shell.h"



int main(int argc, char **av, char **env)
{
    if (argc < MAX_CMD)
    {
        _prompt(av, env);

    }
    return 0;
}
