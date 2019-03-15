#include "SimplePhoneBook.h"

PhoneBook::PhoneBook()
{
    numberOfPeople = 0;
    head = NULL;
}

PhoneBook::~PhoneBook()
{
    if (head != NULL)
    {
        PersonNode *toDel;
        toDel = head;
        do
        {
            head = head->next;
            toDel->next = NULL;
            delete toDel;
            toDel = head;
        } while (toDel != NULL);
    }
}

PhoneBook::PhoneBook(const PhoneBook &phoneBookToCopy)
{
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    if (phoneBookToCopy.head == NULL)
        head = NULL;
    else
    {
        PersonNode *toAdd = phoneBookToCopy.head;

        PersonNode *curr = new PersonNode();
        head = curr;
        curr->t = toAdd->t;
        while (toAdd->next != NULL)
        {
            curr->next = new PersonNode();
            curr = curr->next;
            toAdd = toAdd->next;
            curr->t = toAdd->t;
        }
        curr->next = NULL;
    }
}

void PhoneBook::operator=(const PhoneBook &right)
{
    numberOfPeople = right.numberOfPeople;
    if (right.head == NULL)
        head = NULL;
    else if (head != right.head)
    {
        PersonNode* toRemove = head;
        while (head != NULL)
        {
            head = head->next;
            toRemove->next = NULL;
            delete toRemove;
            toRemove = head;
        }
        
        PersonNode *toAdd = right.head;

        PersonNode *curr = new PersonNode();
        head = curr;
        curr->t = toAdd->t;
        while (toAdd->next != NULL)
        {
            curr->next = new PersonNode();
            curr = curr->next;
            toAdd = toAdd->next;
            curr->t = toAdd->t;
        }
        curr->next = NULL;
    }
}

bool PhoneBook::addPerson(const string name)
{
    if (findPerson(name) != NULL)
        return false;

    numberOfPeople++;
    PersonNode *toAdd = new PersonNode();
    toAdd->next = NULL;
    toAdd->t = Person(name);
    if (head == NULL)
    {
        head = toAdd;
        return true;
    }

    PersonNode *prev = head;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = toAdd;
    return true;
}

bool PhoneBook::removePerson(const string name)
{
    PersonNode *toDel = findPerson(name);

    if (toDel == NULL)
        return false;

    numberOfPeople--;

    if (head == toDel)
    {
        head = head->next;
        toDel->next = NULL;
        delete toDel;
    }
    else
    {
        PersonNode *prev = head;
        while (prev->next != toDel)
        {
            prev = prev->next;
        }
        prev->next = toDel->next;
        toDel->next = NULL;
        delete toDel;
    }

    return true;
}

void PhoneBook::displayPeople()
{
    if (head == NULL)
        cout << "--EMPTY--" << endl;
    PersonNode *toDisplay = head;
    while (toDisplay != NULL)
    {
        cout << toDisplay->t.getName() << endl;
        toDisplay = toDisplay->next;
    }
}

PhoneBook::PersonNode *PhoneBook::findPerson(string name)
{
    string lname = "";
    for (int i = 0; i < name.length(); i++)
    {
        lname = lname + (char)tolower(name[i]);
    }

    PersonNode *toFind = head;
    string nname = "";
    string nnname = "";
    if (head != NULL)
    {
         nname = toFind->t.getName();
        
        for (int i = 0; i < nname.length(); i++)
        {
            nnname = nnname + (char)tolower(nname[i]);
        }
    }

    while ((toFind != NULL) && (nnname != lname))
    {
        nnname = "";
        toFind = toFind->next;
        if (toFind != NULL)
        {
            nname = toFind->t.getName();
            for (int i = 0; i < nname.length(); i++)
            {
                nnname = nnname + (char)tolower(nname[i]);
            }
        }
        
    }
    return toFind;
}