#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string& name, const std::string& phoneNumber)
{
	this->name = name;
	this->phoneNumber = phoneNumber;
}

const std::string& Contact::getName() const { return name; }

const std::string& Contact::getPhoneNumber() const { return phoneNumber; }

void Contact::setName(const std::string& name)
{
	this->name = name;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::print() const
{
	std::cout << "Name: " << name << "\tPhone: " << phoneNumber << "\n";
}

bool Contact::operator==(const Contact& other) const
{
	return name == other.name && phoneNumber == other.phoneNumber;
}
