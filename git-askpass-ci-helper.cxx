#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ofstream log_file("git-askpass-ci-helper.log", ios::out | ios::trunc);
    ostream* log = &log_file;

    const char* debug = getenv("GIT_ASKPASS_DEBUG");
    if (debug)
    {
        log = &cout;
    }

    const char * var_name_p = getenv("GIT_ASKPASS_ENVIRONMENT_VARIABLE");
    if (! var_name_p)
    {
        *log << "GIT_ASKPASS_ENVIRONMENT_VARIABLE not set" << endl;
        return 1;
    }
    string var_name(var_name_p);
    if (var_name.empty())
    {
        *log << "GIT_ASKPASS_ENVIRONEMTN_VARIABLE is empty string" << endl;
        return 2;
    }
    if (var_name.length() > 500)
    {
        *log << "GIT_ASKPASS_ENVIRONMENT_VARIABLE is too long " << var_name.length() << endl;
        return 3;
    }
         
    const char * secret_value_p = getenv(var_name.c_str());
    if (! secret_value_p)
    {
        *log << "secret value not set" << endl;
        return 4;
    }
    string secret_value(secret_value_p);
    if (secret_value.empty())
    {
        *log << "secret value is empty" << endl;
        return 5;
    }
    if (secret_value.length() > 400)
    {
        *log << "secret value is too long" << endl;
        return 6;
    }

    cout << secret_value << endl; 
    return 0;
}
