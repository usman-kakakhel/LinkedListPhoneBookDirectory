#include <iostream>
#include <string>
#include "SimplePerson.h"
#include "SimplePhoneBook.h"

using namespace std;

int main() {
	PhoneBook book;

	book.displayPeople();
	book.addPerson("Saboor");

//	PhoneBook c(book);
//	c.displayPeople();

	cout << book.addPerson("Saboor") << endl;
	cout << book.addPerson("Hassan") << endl;
	cout << book.addPerson("Hassand") << endl;
	book.displayPeople();
	cout << book.addPerson("saboor") << endl;
	cout << book.removePerson("saboor") << endl;
	cout << book.addPerson("Saboor") << endl;

	book.displayPeople();

	cout << book.removePerson("Saboor") << endl;
	cout << book.removePerson("") << endl;
	cout << book.removePerson("Saboor") << endl;

	book.displayPeople();

	cout << endl;

	PhoneBook c;
	c = book;
	c.displayPeople();
	cout << c.addPerson("abc") << endl;
	cout << c.addPerson("cda") << endl;
	cout << c.removePerson("abc") << endl;
	cout << c.removePerson("") << endl;
	cout << endl;
	c.displayPeople();
	c = book;
	cout << endl;
	c.displayPeople();

	cout << c.removePerson("cda") << endl;
	cout << c.addPerson("xes") << endl;
	book = c;
	book.displayPeople();
	book.removePerson("xes");
	book.removePerson("Hassan");
	book.removePerson("Hassand");
	book.displayPeople();

	cout << "=================================" << endl;
	PhoneBook d;
	d.displayPeople();
	book = d;
	book.displayPeople();
	cout << "===================================="<< endl;
	c = d;
	c.displayPeople();
	d.displayPeople();
	return 0;
}
