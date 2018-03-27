//
//  copy.cpp
//  random password generator
//
//  Created by Parth on 05/06/17.
//  Copyright © 2017 Parth. All rights reserved.
//




std::string exec(const char* cmd)
{
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
        {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

std::string paste()             //paste strng to clipboard i.e.memory
{
    return exec("pbpaste");
}

std::string copy(string a)      //copy string
{
    std::stringstream cmd;
    cmd << "echo \"" << a << "\" | pbcopy";
    return exec(cmd.str().c_str());
}

void copyclip(string a)
{
   // cout<<"old clipboard: "<<paste()<<endl;
    copy(a);
   // cout<<"new clipboard: "<<paste()<<endl;
    cout<<"Password copied to clipboard\n";
}
