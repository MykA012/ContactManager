#pragma once
#include <vector>
#include "Contact.h"

class ContactBook
{
public:
	// Set / Del
	void addContact(const Contact& contact);

	bool deleteContact(const Contact& contact);
	bool deleteContact(size_t index);

	// Search
	std::vector<Contact> findByName(const std::string& name) const;

	// Get
	const std::vector<Contact>& getAllContacts() const;

	void printAll();

	size_t size() const;
private:
	std::vector<Contact> contacts;
};
