#include "File.h"
#include <iostream>

File::File(const std::string& name) : name{ name }
{
	file.open(name);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << name << std::endl;
	}
	else
	{
		std::cout << "File " << name << " created successfully." << std::endl;
	}
}

File::~File()
{
	if (file.is_open())
	{
		file.close();
		std::cout << "File " << name << " created closed." << std::endl;
	}
}

void File::write(const std::string& content)
{
	if (file.is_open())
	{
		file << content;
	}
}

std::string File::getName() const { return name; }