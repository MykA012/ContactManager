#pragma once
#include <string>
#include <fstream>

#include "ContactBook.h"

class File
{
public:
	File(const std::string& name);
	~File();

	void write(const std::string& content);

	std::string getName() const;

	File(const File&) = delete;
	File& operator=(const File&) = delete;
private:
	std::ofstream file;
	std::string name;
};