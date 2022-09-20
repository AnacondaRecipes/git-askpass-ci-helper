#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main_func(int argc, char** argv)
{
    ofstream log("git-askpass-ci-helper.log", ios::out | ios::trunc);
    log << "start" << endl;

    if (log.fail() || log.bad())
    {
        return 99;
    }

    for (int ac=1; ac < argc; ++ac)
    {
        log << "arg " << ac << " " << argv[ac] << endl;
    }

    // get variable name which has secret
    const char * var_name_p = getenv("GIT_ASKPASS_ENVIRONMENT_VARIABLE");
    if (! var_name_p)
    {
        log << "GIT_ASKPASS_ENVIRONMENT_VARIABLE not set" << endl;
        return 1;
    }
    string var_name(var_name_p);
    if (var_name.empty())
    {
        log << "GIT_ASKPASS_ENVIRONEMTN_VARIABLE is empty string" << endl;
        return 2;
    }
    if (var_name.length() > 100)
    {
        log << "GIT_ASKPASS_ENVIRONMENT_VARIABLE is too long " << var_name.length() << endl;
        return 3;
    }

    // get secret 
    const char * secret_value_p = getenv(var_name.c_str());
    if (! secret_value_p)
    {
        log << "secret value not set" << endl;
        return 4;
    }
    string secret_value(secret_value_p);
    if (secret_value.length() != 40)
    {
        log << "secret value not length of 40: " << secret_value.length() << endl;
        return 5;
    }

    // print secret
    cout << secret_value << endl; 
    return 0;
}

int main(int argc, char** argv)
{
    int val = main_func(argc, argv);
    
    if (val != 0)
    {
        ofstream faillog("C:\\b\\git-askpass-ci-helper.fail", ios::out | ios::trunc);
        faillog << "failed " << val << endl;
    }
  
    return val;
}
