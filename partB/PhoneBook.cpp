#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    numberOfPeople = 0;
    head = NULL;
}

PhoneBook::~PhoneBook()
{
    if (head != NULL)
    {
        Node *toDel;
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
        Node *toAdd = phoneBookToCopy.head;

        Node *curr = new Node();
        head = curr;
        curr->t = toAdd->t;
        while (toAdd->next != NULL)
        {
            curr->next = new Node();
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
        Node* toRemove = head;
        while (head != NULL)
        {
            head = head->next;
            toRemove->next = NULL;
            delete toRemove;
            toRemove = head;
        }
        
        Node *toAdd = right.head;

        Node *curr = new Node();
        head = curr;
        curr->t = toAdd->t;
        while (toAdd->next != NULL)
        {
            curr->next = new Node();
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
    {
        cout << "Person already present." << endl;
        return false;
    }

    numberOfPeople++;
    Node *toAdd = new Node();
    toAdd->next = NULL;
    toAdd->t = Person(name);
    if (head == NULL)
    {
        head = toAdd;
        return true;
    }

    Node *prev = head;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = toAdd;
    return true;
}

bool PhoneBook::removePerson(const string name)
{
    Node *toDel = findPerson(name);

    if (toDel == NULL)
    {
        cout << "Person to delete is not present." << endl;
        return false;
    }
        

    numberOfPeople--;

    if (head == toDel)
    {
        head = head->next;
        toDel->next = NULL;
        delete toDel;
    }
    else
    {
        Node *prev = head;
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

bool PhoneBook::addPhone(string personName, int areaCode, int number)
{
    Node *a = findPerson(personName);
    if (a == NULL)
    {
        cout << "The Person to add the phone to is not present." << endl;
        return false;
    }
    return (a->t).addPhone(areaCode, number);
}
bool PhoneBook::removePhone(string personName, int areaCode, int number)
{
    Node *a = findPerson(personName);
    if (a == NULL)
    {
        cout << "The Person to remove the phone from is not present." << endl;
        return false;
    }
    return (a->t).removePhone(areaCode, number);
}
void PhoneBook::displayPerson(string name)
{
    cout << name << endl;
    Node *a = findPerson(name);
    if (a == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else
    {
        a->t.displayPhoneNumbers();
    }
}
void PhoneBook::displayAreaCode(int areaCode)
{
    bool temp = false;
    cout << areaCode << endl;
    if (head == NULL)
        cout << "--EMPTY--" << endl;
    Node *toDisplay = head;
    while (toDisplay != NULL)
    {   
        if (toDisplay->t.areaCodePresent(areaCode))
        {
            temp = true;
            cout << toDisplay->t.getName() << endl;
            toDisplay->t.displayAreaPhoneNumbers(areaCode);
        }
        toDisplay = toDisplay->next;
    }
    if (!temp)
        cout << "--EMPTY--" << endl;
}

void PhoneBook::displayPeople()
{
    if (head == NULL)
        cout << "--EMPTY--" << endl;
    Node *toDisplay = head;
    while (toDisplay != NULL)
    {
        cout << toDisplay->t.getName() << ", " << toDisplay->t.getNoOfNum() << endl;
        toDisplay = toDisplay->next;
    }
}

PhoneBook::Node *PhoneBook::findPerson(string name)
{
    string lname = "";
    for (int i = 0; i < name.length(); i++)
    {
        lname = lname + (char)tolower(name[i]);
    }

    Node *toFind = head;
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