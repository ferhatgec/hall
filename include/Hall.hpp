#ifndef HALL_HPP
#define HALL_HPP

#include <iostream>
#include <string>

class Hall {
	std::string command_data;
public:
	void Colorize();
	
	void Init(std::string command);
};


#endif // HALL_HPP
