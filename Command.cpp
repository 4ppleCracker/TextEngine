#include "Command.h"

Command::Command(std::string a_command): m_orig(a_command)
{
    this->m_parsed = new cmd();
    this->prefix = '$';
}
Command::Command(std::string a_command, Setting settings): Command(a_command){
    this->prefix = settings.prefix;
}

void Command::Parse()
{
    std::vector<std::string> temp_vec;
    split(this->m_orig, temp_vec);
    foreach<std::string>(temp_vec, [this](std::string val, int i){
        if (i == 0) {
            this->m_parsed->command = val;
        } else {
            this->m_parsed->arguments.push_back(val);
        }
    });
}

void Command::Exec()
{
    this->Parse();
    std::string* command = &(this->m_parsed->command);
    Targs* arguments = &(this->m_parsed->arguments);
    if (this->callbacks.find(*command) == callbacks.end()) return;
    (this->callbacks)[*command](arguments);
}
void Command::NewCommand(std::string a_command)
{
    this->m_orig = a_command;
    this->m_parsed->arguments.clear();
    this->m_parsed->command = "";
    this->m_response = "";
}

std::string Command::Save() const
{
    std::string ret = "";
    ret += this->prefix;
    ret += " ";
    ret += this->m_orig;
    ret += "\n";
    ret += this->m_response;
    return ret;
}

std::vector<std::string> Command::getargs() const
{
    return this->m_parsed->arguments;
}
std::string Command::getcommand() const
{
    return this->m_parsed->command;
}

void Command::on(std::string com, std::function<void(Targs*)> callback)
{
    (this->callbacks)[com] = callback;
}


