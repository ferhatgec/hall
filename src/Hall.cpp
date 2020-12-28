/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */


#include <iostream>
#include <string>

#include <Hall.hpp>

#include <Colorized.hpp>
#include <ExecutePlusPlus.hpp>


void
Hall::Colorize() {
    std::string data;
    unsigned spaces = 0;
    
    for(unsigned i = 0; command_data[i] != '\0'; i++) {
        if(command_data[i] == ' ' || command_data[i] == '\n') {
            spaces++;
        }
        
        data.push_back(command_data[i]);
        
        if(spaces % 1 || spaces == 1) {
            printfc({255, 154, 0}, data);
        } else if(spaces % 2 || spaces == 2) {
            printfc({247, 95, 28}, data);
        } else if(spaces % 3 || spaces == 3) { 
            printfc({136, 30, 228}, data);
        } else if(spaces % 5 || spaces == 5) {
            printfc({133, 226, 31}, data);
        } else {
            printfc({0, 0, 0}, data);
        }
        
        data.erase();
    }
}

void
Hall::Init(std::string command) {
    ExecutePlusPlus exec;
    
    command_data = exec.ExecWithOutput(command);

    Colorize();
}


int main(int argc, char** argv) {
    if(argc < 2) {
        
        std::cout << "Fegeya Hall 🎃\n" <<
         "Use with " << argv[0] << " + command\n";
        
        return 0;
    }
    
    std::string command;
    
    for (auto i = int{1}; i < argc; ++i) {
        command.append(argv[i]);
        command.append(" ");
    }
    
    Hall halloween;
    
    halloween.Init(command);
    
    return 0;
}
