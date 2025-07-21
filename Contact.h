#pragma once
#include <string>

class Contact
{
public:
	Contact(const std::string& name, const std::string& phoneNumber);

	const std::string& getName() const;
	const std::string& getPhoneNumber() const;

	void setName(const std::string& name);
	void setPhoneNumber(const std::string& phoneNumber);

	void print() const;

	bool operator ==(const Contact& other) const;
	
	std::string export_data() const;
private:
	std::string name;
	std::string phoneNumber;
};