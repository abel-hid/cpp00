#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Contact
{
private:
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

public:
    void setFirstName(const string &first_name)
    {
        this->first_name = first_name;
    }

    void setLastName(const string &last_name)
    {
        this->last_name = last_name;
    }

    void setNickname(const string &nickname)
    {
        this->nickname = nickname;
    }

    void setPhoneNumber(const string &phone_number)
    {
        this->phone_number = phone_number;
    }

    void setDarkestSecret(const string &darkest_secret)
    {
        this->darkest_secret = darkest_secret;
    }

    string getFirstName() const
    {
        return first_name;
    }

    string getLastName() const
    {
        return last_name;
    }

    string getNickname() const
    {
        return nickname;
    }

    string getPhoneNumber() const
    {
        return phone_number;
    }

    string getDarkestSecret() const
    {
        return darkest_secret;
    }
};

class PhoneBook
{
public:
    Contact contacts[8];

    PhoneBook()
    {
    }

    void addContact(const Contact &contact, int &oldest_index)
    {
        int i;
        for (i = 0; i < 8; i++)
        {
            if (contacts[i].getFirstName().empty())
            {
                contacts[i] = contact;
                break;
            }
            else if (i == 7)
            {
                if(oldest_index == 8)
                    oldest_index = 0;
                contacts[oldest_index] = contact;
                oldest_index++;
                break;
            }
        }

        // if (i == 8)
        // {
        //     contacts[oldest_index] = contact;
        //     oldest_index = (oldest_index + 1) % 8;
        // }
    }
};

string ft_substr(const string &str, unsigned long len)
{
    if (str.length() <= len)
        return str;
    return (str.substr(0, len - 1) + ".");
}

void show_column(const string &data, int len)
{
    cout << std::setw(len) << std::right << ft_substr(data, len) << "|";
}

void haha(PhoneBook phonebook)
{
    while (1)
    {
        int index;
        cout << "Enter index: ";
        if (cin.eof())
            break;
        if (!(std::cin >> index))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please try again." << endl;
        }

        else if (index >= 0 && index < 8 && !phonebook.contacts[index].getFirstName().empty())
        {
            cout << "Contact details for index " << index << ":" << endl;
            cout << "First Name: " << phonebook.contacts[index].getFirstName() << endl;
            cout << "Last Name: " << phonebook.contacts[index].getLastName() << endl;
            cout << "Nickname: " << phonebook.contacts[index].getNickname() << endl;
            cout << "Phone Number: " << phonebook.contacts[index].getPhoneNumber() << endl;
            cout << "Darkest Secret: " << phonebook.contacts[index].getDarkestSecret() << endl;
            break;
        }
        else
        {
            cout << "Invalid index. Please try again." << endl;
            cin.clear();
        }
    }
}

int parsing_num(string command)
{
    int i = 0;
    command[0] == '+' ? i++ : 0;
    while (command[i])
    {
        if (!isdigit(command[i]))
            return 1;
        i++;
    }
    return (0);
}

int main()
{
    PhoneBook phonebook;
    Contact contact;
    int oldest_index = 0;

    string command;
    while (true)
    {
        cout << "Enter command: ";
        getline(cin, command);
        if (cin.eof())
            break;
        if (command.empty())
            continue;
        if (command == "ADD")
        {
            while (1)
            {
                cout << "Enter first name: ";
                getline(cin, command);
                if (command.empty())
                {
                    cout << "Invalid first name. Please try again." << endl;
                    continue;
                }
                contact.setFirstName(command);
                cout << "Enter last name: ";
                getline(cin, command);
                if (command.empty())
                {
                    cout << "Invalid last name. Please try again." << endl;
                    continue;
                }
                contact.setLastName(command);
                cout << "Enter nickname: ";
                getline(cin, command);
                if (command.empty())
                {
                    cout << "Invalid nickname. Please try again." << endl;
                    continue;
                }
                contact.setNickname(command);
                cout << "Enter phone number: ";
                getline(cin, command);
                if (command.empty())
                {
                    cout << "Invalid phone number. Please try again." << endl;
                    continue;
                }
                else if (command.length() < 10 || parsing_num(command))
                {
                    cout << "Invalid phone number. Please try again." << endl;
                    continue;
                }
                contact.setPhoneNumber(command);
                cout << "Enter darkest secret: ";
                getline(cin, command);
                if (command.empty())
                {
                    cout << "Invalid darkest secret. Please try again." << endl;
                    continue;
                }
                contact.setDarkestSecret(command);
                phonebook.addContact(contact, oldest_index);
                break;
            }
        }
        else if (command == "SEARCH")
        {
            bool isEmpty = true;
            for (int i = 0; i < 8; i++)
            {
                if (!phonebook.contacts[i].getFirstName().empty())
                {
                    isEmpty = false;
                    break;
                }
            }

            if (isEmpty)
            {
                cout << "Phonebook is empty" << endl;
                continue;
            }
            cout << std::setw(10) << std::right << "Index|";
            cout << std::setw(10) << std::right << "First Name|";
            cout << std::setw(10) << std::right << "Last Name|";
            cout << std::setw(10) << std::right << "Nickname|" << endl;
            for (int i = 0; i < 8; i++)
            {
                if (!phonebook.contacts[i].getFirstName().empty())
                {
                    cout << std::setw(10) << std::right << i << "|";
                    show_column(phonebook.contacts[i].getFirstName(), 10);
                    show_column(phonebook.contacts[i].getLastName(), 10);
                    show_column(phonebook.contacts[i].getNickname(), 10);
                    cout << endl;
                }
            }
            haha(phonebook);
            continue;
        }
        else if (command == "EXIT")
        {
            cout << "EXIT" << endl;
            break;
        }
        else
            cout << "Invalid command. Please try again." << endl;
    }
    return 0;
}
