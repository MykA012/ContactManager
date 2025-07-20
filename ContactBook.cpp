#include "ContactBook.h"
#include <algorithm>
#include <iostream>

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
	for (const auto& contact : contacts)
	{
		contact.print();
		std::cout << "---\n";
	}
}

size_t ContactBook::size() const { return contacts.size(); }
