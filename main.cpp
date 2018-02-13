#include <iostream>
#include "Command.h"
#include "join.h"

using namespace std;

int main()
{
    Command* cmd = new Command("Command ONE TWO THREE");
    cmd->on("Command", [](Targs* args){
        cout << join(*args) << endl;
    });
    cmd->Exec();
    return 0;
}
