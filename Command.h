#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "Settings.h"
#include "StringSplit.h"
#include "foreach.h"

typedef std::vector<std::string> Targs;
typedef unsigned int uint;
struct cmd {
    std::string command;
    Targs arguments;
};
class Command
{
    public:
        Command(std::string a_command);
        Command(std::string a_command, Setting settings);
        std::string Save();
        void Exec();
        void NewCommand(std::string a_command);
        Targs getargs();
        std::string getcommand();
        void on(std::string com, std::function<void(Targs*)> callback);
    protected:

    private:
        void Parse();
        std::string m_orig;
        std::string m_response;
        cmd* m_parsed;
        char prefix;
        std::map<
            std::string,
            std::function<
                void(Targs*)
            >
        > callbacks;
};



#endif // COMMAND_H

