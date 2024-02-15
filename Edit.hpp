#ifndef EDIT_HPP
#define EDIT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Variable_info
{
			std::string type_info = "";
			std::string name = "_";
			std::string value = "_";
			int line = 0;
			int position = 0;
};

std::vector<std::string> keywords {"int", "short", "char", "bool", "long", "double", "float", "const", "signed", "unsigned"};
std::vector<Variable_info> all_vars;
std::vector<std::vector<std::string>> declarations_in_lines;

//function to split a string by semicolons
std::vector<std::string> split_by_semicolon(const std::string& str)
{
  std::vector<std::string> vec;
    std::string decl;
    std::istringstream ss(str);

    while (std::getline(ss, decl, ';')) {
		if(decl.find_first_not_of(' ') != std::string::npos)
		{
			decl = decl.substr(decl.find_first_not_of(' ')); // hanum enq toxi skzbi prabelnery (ete kan), vor arandzin bar chdarnan
		}
        vec.push_back(decl);
    }

    return vec;
}
//function to split a string by a ' '(space)
std::vector<std::string> split_by_space(const std::string& str)
{
    std::vector<std::string> vec;
    std::string token;
    std::istringstream ss(str);

    while (ss >> token) {
        vec.push_back(token);
    }
	if(ss.eof() && ss.fail())
	{
			ss.clear();
	}
    return vec;	
}

//function which makes Variable_info object from a single declaration and stores it in a vector consisting of Variable_infos
void info_storage(std::string& declaration, int line, int pos)
{		
		std::vector<std::string> tokenized_decl = split_by_space(declaration);
		Variable_info obj;
		int ind = 0;
		while(std::find(keywords.begin(), keywords.end(), tokenized_decl[ind]) != keywords.end())
		{
				if(tokenized_decl[ind] == "short")
				{
						obj.type_info += "sh";
				} else {
						obj.type_info += tokenized_decl[ind][0];
				}
			++ind;
		}
		obj.name = tokenized_decl[ind];
		obj.line = line;
		obj.position = pos;
		if(tokenized_decl[tokenized_decl.size() - 2] != "=")
		{
			obj.value = "Garbage";

		} else {

				obj.value = tokenized_decl[tokenized_decl.size() - 1];
		}
		all_vars.push_back(obj);
}

//function to write corresponding information in a result file
void write_into_files(std::ofstream& result, const Variable_info& obj)
{
	result << std::setw(15) << std::internal << obj.type_info
           << std::setw(15) << std::internal << obj.value
           << std::setw(15) << std::internal << obj.name
           << std::setw(15) << std::internal << obj.line
           << std::setw(15) << std::internal << obj.position << std::endl;
}

//function to find a declaration from all declarations in case of existance
int find(const std::string& str)
{
		int founded_elem_index = -1;
		for(int i = 0; i < all_vars.size(); ++i)
		{
				if(all_vars[i].name == str)
				{
						return i;
				}
		}
		return founded_elem_index;
}

//function which analyzes all declarations, calls write_into_files funtion to write all corresponding variables into a result file,
//info_storage function to hold variable declarations as n object of a Varaiable_info
void analyzer()
{
	std::ofstream result("result.txt");
    if (!result.is_open())
    {
        std::cout << "Failed to open result.txt for writing." << std::endl;
        return;
    }
	result << std::setw(15) << std::internal << "Type"
           << std::setw(15) << std::internal << "Value"
           << std::setw(15) << std::internal << "Name"
           << std::setw(15) << std::internal << "Line"
           << std::setw(15) << std::internal << "Position" << std::endl;  

	for(int i = 0; i < declarations_in_lines.size(); ++i)
	{
			for(int j = 0; j < declarations_in_lines[i].size(); ++j)
			{
				std::vector<std::string> vec = split_by_space(declarations_in_lines[i][j]);
					if(vec.size() == 1)
					{
							int needed_elem_index = find(vec[0]);
							if(needed_elem_index == -1)
							{
								Variable_info ob;
								ob.type_info = "-";
								ob.name = declarations_in_lines[i][j];
								ob.line = i;
								ob.position = j;

								write_into_files(result, ob);

							} else {
								write_into_files(result, all_vars[needed_elem_index]);		
							}

					} else {
						info_storage(declarations_in_lines[i][j], i, j);
					}	
			}
	}
	result.close();
}
//funtion to wirte all possible variable types into a type)_info file
void write_into_typeinfo()
{	
    std::ofstream type_info("TypeInfo.txt");

	if (!type_info.is_open()) {
		std::cout << "Your file is't open to write in it.";
		exit(0);
	}
type_info << "int val;" << "\n"
          << "unsigned val;" << "\n"
          << "signed val;" << "\n"
          << "const signed val;" << "\n"
          << "const unsigned val;" << "\n"
          << "unsigned int val;" << "\n"
          << "signed int val;" << "\n"
          << "const unsigned int val;" << "\n"
          << "const signed int val;" << "\n"
          << "short val;" << "\n"
          << "const short val;" << "\n"
          << "signed short int val;" << "\n"
          << "unsigned short val;" << "\n"
          << "const signed short int val;" << "\n"
          << "const unsigned short val;" << "\n"
          << "long val;" << "\n"
          << "const long val;" << "\n"
          << "unsigned long int val;" << "\n"
          << "unsigned long val;" << "\n"
          << "const signed long int val;" << "\n"
          << "const unsigned long val;" << "\n"
          << "long long val;" << "\n"
          << "const long long val;" << "\n"
          << "unsigned long long int val;" << "\n"
          << "unsigned long long val;" << "\n"
          << "const unsigned long long int val;" << "\n"
          << "const unsigned long long val;" << "\n"
          << "unsigned char val;" << "\n"
          << "signed char val;" << "\n"
          << "const unsigned char val;" << "\n"
          << "const signed char val;" << "\n"
          << "float val;" << "\n"
          << "const float val;" << "\n"
          << "double val;" << "\n"
          << "const double val;" << "\n"
          << "long double val;" << "\n"
          << "const long doubl val;" << "\n"
          << "long long doubl val;" << "\n"
          << "const long long doubl val;" << "\n"
          << "bool val;" << "\n"
          << "const bool val;" << std::endl;

	type_info.close();
}

void run(std::ifstream& read)
{
	std::string line;
	while(std::getline(read, line))
	{
			declarations_in_lines.push_back(split_by_semicolon(line));
	}
	analyzer();
	write_into_typeinfo();

}
#endif
