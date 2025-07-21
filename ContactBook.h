#pragma once
#include <vector>

#include "Contact.h"

class ContactBook
{
public:
	~ContactBook();

	void addContact(const Contact& contact);

	bool deleteContact(const Contact& contact);
	bool deleteContact(size_t index);

	std::vector<Contact> findByName(const std::string& name) const;

	const std::vector<Contact>& getAllContacts() const;

	void printAll();

	size_t size() const;

	void export_contacts(const std::string& fileName) const;
private:
	std::vector<Contact> contacts;
};