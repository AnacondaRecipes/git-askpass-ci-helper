#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv)
{
    const char * var_name = getenv("GIT_ASKPASS_ENVIRONMENT_VARIABLE");
    if (!var_name)
        var_name = "CONDA_CLONE_SECRET";

    const char * secret_value = getenv(var_name);
    if (!secret_value)
        return 1;
    
    printf("%s\n", secret_value);
    return 0;
}
