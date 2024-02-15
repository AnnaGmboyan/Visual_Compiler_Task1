#include <iostream>
#include <fstream>
#include  "Edit.hpp"

int main()
{
	std::ifstream read("text.txt");
	if(!read.is_open())
	{
			std::cout << "file isn't open to read from" << std::endl;
			return 0;
	}
	run(read);
	read.close();

	return 0;
}

