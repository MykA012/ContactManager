#include <algorithm>
#include <iostream>
#include <string>

#include "ContactBook.h"
#include "File.h"

ContactBook::~ContactBook()
{
	for (const auto& contact : contacts)
	{
		contact.~Contact();
	}
}

void ContactBook::addContact(const Contact& contact)
{
	contacts.push_back(contact);
}

bool ContactBook::deleteContact(const Contact& contact)
{
	auto it = std::find(contacts.begin(), contacts.end(), contact);
	if (it != contacts.end())
	{
		contacts.erase(it);
		return true;
	}
	return false;
}

bool ContactBook::deleteContact(size_t index)
{
	if (index < contacts.size())
	{
		contacts.erase(contacts.begin() + index);
		return true;
	}
	return false;
}

std::vector<Contact> ContactBook::findByName(const std::string& name) const
{
	std::vector<Contact> result;
	for (const auto& contact : contacts)
	{
		if (contact.getName() == name)
		{
			result.push_back(contact);
		}
	}
	return result;
}

const std::vector<Contact>& ContactBook::getAllContacts() const
{
	return contacts;
}

void ContactBook::printAll()
{
	std::cout << "Contacts:\n---\n";
	for (const auto& contact : contacts)
	{
		contact.print();
		std::cout << "---\n";
	}
}

size_t ContactBook::size() const { return contacts.size(); }


void ContactBook::export_contacts(const std::string& fileName) const
{
	if (contacts.empty())
	{
		std::cout << "You have no contacts to export\n";
		return;
	}

	File outputFile(fileName);

	std::string jsonData = "{\"contacts\":[";
	outputFile.write(jsonData);
	
	for (const auto& contact : contacts)
	{
		outputFile.write(contact.export_data());
		if (!(contacts.back() == contact))
		{
			outputFile.write(",");
		}
	}
	outputFile.write("]}");
}