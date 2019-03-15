#include <iostream>
#include <string>
#include "Phone.h"
#include "Person.h"
#include "PhoneBook.h"

using namespace std;

int main() {
	PhoneBook c;
//	cout << c.addPerson("Saboor") << endl;
	cout << c.addPerson("saboor") << endl;


	c.displayPeople();
	c.displayPerson("saboor");
	c.displayAreaCode(324);

	cout << "========================================" << endl;

	c.addPhone("saboor", 324, 109912);
	c.addPhone("saboor", 324, 109912);
	c.addPhone("siof", 23, 29293);
	c.displayPeople();
    c.displayPerson("saboor");
    c.displayAreaCode(324);

    cout << "========================================" << endl;
	PhoneBook d(c);
	d.displayPeople();

	cout << "========================================" << endl;
	c.removePhone("saboor", 32, 183801);
	c.removePhone("eiofwoe", 324, 109912);
	c.removePhone("SABOOR", 324,109912);
	c.displayPeople();
	c.displayPerson("saboor");
	c.displayAreaCode(324);

	cout << "========================================" << endl;

	c.removePerson("SABOOR");
	c.removePerson("eio");
	c.displayPeople();

	cout << "========================================" << endl;
	d = c;
	d.displayPeople();
	return 0;
}
