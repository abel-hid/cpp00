#include <iostream>
#include <string>
#include <istream>
#include <list>

using namespace std;

class PhoneBook
{
    public:
    string contacts[8];
};

class Contact
{
    public:
    std::string index;
    std::string first_name;
    std::string last_name;
    std::string nickname;  
    std::string phone_number;
    std::string darkest_secret;

};

struct ContactList
{
    std::string index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    ContactList *next;
};

void add_contact(ContactList *contact)
{
    ContactList *new_contact = new ContactList;
    new_contact->index = contact->index;
    new_contact->first_name = contact->first_name;
    new_contact->last_name = contact->last_name;
    new_contact->nickname = contact->nickname;
    new_contact->next = NULL;
    contact->next = new_contact;
}

int main(int ac , char **av)
{
    PhoneBook phonebook;
    Contact contact;
    ContactList *contacts[8];

   string command;
   while (1)
   {
   
       cout << "enter command : " ;
        getline(cin, command);
        if(cin.eof())
            break;
        if (command == "ADD")
        {
            cout << "enter first name :" ;
            getline(cin, contact.first_name);
            cout << "enter last name :" ;
            getline(cin, contact.last_name);
            cout << "enter nickname :" ;
            getline(cin, contact.nickname);
            cout << "enter phone number :" ;
            getline(cin, contact.phone_number);
            cout << "enter darkest secret :" ;
            getline(cin, contact.darkest_secret);

            for (int i = 0; i < 8; i++)
            {
                if (contacts[i] == NULL)
                {
                    contacts[i] = new ContactList;
                    contacts[i]->index = i;
                    contacts[i]->first_name = contact.first_name;
                    contacts[i]->last_name = contact.last_name;
                    contacts[i]->nickname = contact.nickname;
                    contacts[i]->next = NULL;
                    break;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (contacts[i] != NULL)
                {
                    cout << contacts[i]->index << endl;
                    cout << contacts[i]->first_name << endl;
                    cout << contacts[i]->last_name << endl;
                    cout << contacts[i]->nickname << endl;
                }
            }
        }
        else if (command == "SEARCH")
        {
            cout << "SEARCH" << endl;


        }
        else if (command == "EXIT")
        {
            cout << "EXIT" << endl;
            break;
        }
        else
        {
            cout << "command not found" << endl;
        }
   }
        return 0;
}