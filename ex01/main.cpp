#include <iostream>
#include <string>

using namespace std;

class Contact {
private:
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

public:
    void setFirstName(const string& first_name) 
    {
        this->first_name = first_name;
    }

    void setLastName(const string& last_name) {
        this->last_name = last_name;
    }

    void setNickname(const string& nickname) {
        this->nickname = nickname;
    }

    void setPhoneNumber(const string& phone_number) {
        this->phone_number = phone_number;
    }

    void setDarkestSecret(const string& darkest_secret) {
        this->darkest_secret = darkest_secret;
    }

    string getFirstName() const {
        return first_name;
    }

    string getLastName() const {
        return last_name;
    }

    string getNickname() const {
        return nickname;
    }

    string getPhoneNumber() const {
        return phone_number;
    }

    string getDarkestSecret() const {
        return darkest_secret;
    }
};

class PhoneBook {
public:
    Contact* contacts[8];

    PhoneBook() {
        for (int i = 0; i < 8; i++) {
            contacts[i] = nullptr;
        }
    }

    void addContact(Contact* contact) 
    {
        for (int i = 0; i < 8; i++) {
            if (contacts[i] == nullptr) {
                contacts[i] = contact;
                break;
            }
        }
    }

    ~PhoneBook() {
        for (int i = 0; i < 8; i++) {
            delete contacts[i];
        }
    }
};

int main() {
    PhoneBook phonebook;

    string command;
    while (1) 
    {
        cout << "Enter command: ";
        getline(cin, command);
        if (cin.eof())
            break;

        if (command == "ADD") 
        {
            Contact* contact = new Contact();
            cout << "Enter first name: ";
            getline(cin, command);
            contact->setFirstName(command);
            cout << "Enter last name: ";
            getline(cin, command);
            contact->setLastName(command);
            cout << "Enter nickname: ";
            getline(cin, command);
            contact->setNickname(command);
            cout << "Enter phone number: ";
            getline(cin, command);
            contact->setPhoneNumber(command);
            cout << "Enter darkest secret: ";
            getline(cin, command);
            contact->setDarkestSecret(command);

            phonebook.addContact(contact);
        }
        else if (command == "SEARCH") 
        {
            for (int i = 0; i < 8; i++) 
            {
                if (phonebook.contacts[i] != nullptr) 
                {
                    cout << "Index: " << i << endl;
                    cout << "First Name: " << phonebook.contacts[i]->getFirstName() << endl;
                    cout << "Last Name: " << phonebook.contacts[i]->getLastName() << endl;
                    cout << "Nickname: " << phonebook.contacts[i]->getNickname() << endl;
                }
            }
            cout << "Enter index: ";
            int index;
            cin >> index;
            cin.ignore(); // Clear the newline character from the input stream

            if (index >= 0 && index < 8 && phonebook.contacts[index] != nullptr) 
            {
                cout << "Contact details for index " << index << ":" << endl;
                cout << "First Name: " << phonebook.contacts[index]->getFirstName() << endl;
                cout << "Last Name: " << phonebook.contacts[index]->getLastName() << endl;
                cout << "Nickname: " << phonebook.contacts[index]->getNickname() << endl;
                cout << "Phone Number: " << phonebook.contacts[index]->getPhoneNumber() << endl;
                cout << "Darkest Secret: " << phonebook.contacts[index]->getDarkestSecret() << endl;
            }
            else 
                cout << "Invalid index. Please try again." << endl;
        }
        else if (command == "EXIT") 
        {
            cout << "EXIT" << endl;
            break;
        }
        else
            cout << "Command not found" << endl;
    }

    return 0;
}
