#include "Person.h"

Person::Person(const string name)
{
    this->name = name;
    this->head = NULL;
    noOfNum = 0;
}

Person::~Person()
{
    PhoneNode* toRemove = head;
    while (head != NULL)
    {
        head = head->next;
        toRemove->next = NULL;
        delete toRemove;
        toRemove = head;
    }
}

Person::Person(const Person &personToCopy)
{
    this->name = personToCopy.name;
    noOfNum = personToCopy.noOfNum;
    if (personToCopy.head == NULL)
    {
        this->head = NULL;
    }
    else 
    {
        PhoneNode* toAdd = new PhoneNode();
        toAdd->p = Phone(personToCopy.head->p);
        this->head = toAdd;

        PhoneNode* goOn = personToCopy.head->next;

        while(goOn != NULL)
        {
            toAdd->next = new PhoneNode();
            toAdd = toAdd->next;
            toAdd->p = Phone(goOn->p);
            goOn = goOn->next;
        }
        toAdd->next = NULL;
    }
}

void Person::operator=(const Person &right)
{
    this->name = right.name;
    noOfNum = right.noOfNum;
    if (right.head == NULL)
    {
        this->head = NULL;
    }
    else 
    {
        PhoneNode* toRemove = head;
        while (head != NULL)
        {
            head = head->next;
            toRemove->next = NULL;
            delete toRemove;
            toRemove = head;
        }

        PhoneNode* toAdd = new PhoneNode();
        toAdd->p = Phone(right.head->p);
        this->head = toAdd;

        PhoneNode* goOn = right.head->next;

        while(goOn != NULL)
        {
            toAdd->next = new PhoneNode();
            toAdd = toAdd->next;
            toAdd->p = Phone(goOn->p);
            goOn = goOn->next;
        }
        toAdd->next = NULL;
    }
}

string Person::getName()
{
    return this->name;
}

int Person::getNoOfNum()
{
    return noOfNum;
}

bool Person::addPhone(const int areaCode, const int number)
{
    PhoneNode* a = findPhone(areaCode, number);

    if (a != NULL)
    {
        cout << "Phone number is already present." << endl;
        return false;
    }
    else 
    {
        noOfNum++;
        PhoneNode* toAdd = new PhoneNode();

        toAdd->p = Phone(areaCode, number);
        toAdd->next = NULL;

        PhoneNode* iterate = head;
        if (head == NULL)
            head = toAdd;
        else
        {
            while(iterate->next != NULL)
            {
                iterate = iterate->next;
            }
            iterate->next = toAdd;
        }
        return true;
    }
}

bool Person::removePhone(const int areaCode, const int number)
{
    PhoneNode* a = findPhone(areaCode, number);

    if (a == NULL)
    {
        cout << "Phone to remove cannot be found." << endl;
        return false;
    }
    else 
    {
        noOfNum--;
        if (head == a)
        {
            head = head->next;
        }
        else 
        {
            PhoneNode* prev = head;
            while (prev->next != a)
            {
                prev = prev->next;
            }

            prev->next = a->next;
        }
        a->next = NULL;
        delete a;
        a = NULL;
        return true;
    }
}

void Person::displayPhoneNumbers()
{
    if (head == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else 
    {
        PhoneNode* a = head;
        while (a != NULL)
        {
            cout << "Phone Number: " << (a->p).getAreaCode() << "," << (a->p).getNumber() << endl;
            a = a->next; 
        }
    }
}

bool Person::areaCodePresent(int areaCode)
{
    PhoneNode* a = head;

    while (a != NULL)
    {
        if ((a->p).getAreaCode() == areaCode)
        {
            return true;
        }
        a = a->next;
    }
    return false;
}

void Person::displayAreaPhoneNumbers(int areaCode)
{
    PhoneNode* a = head;
        while (a != NULL)
        {
            if ((a->p).getAreaCode() == areaCode)
            {
                cout << "Phone Number: " << (a->p).getAreaCode() << "," << (a->p).getNumber() << endl;
            }
            a = a->next; 
        }
}

Person::PhoneNode* Person::findPhone(const int areaCode, const int number)
{
    PhoneNode* a = head;
    while (a != NULL)
    {
        if (((a->p).getAreaCode() == areaCode) && ((a->p).getNumber() == number))
        {
            return a;
        }
        a = a->next;
    }
    return NULL;
}