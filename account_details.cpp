#include "account_details.h"
#include "global_functions.h"
#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
void account_details :: get_first_name()
{
    int flag = 0;
    do
    {
        cout<<setw(25)<<left<< "Enter your first name ";
        cout << setw(2) <<left << ": ";
        getline (cin, first_name);
        if (first_name.length() == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (flag != 1);
}

void account_details :: get_last_name()
{
    int flag = 0;
    do
    {
        cout <<setw(25) <<left << "Enter your Last name ";
        cout << setw(2) <<left << ": ";
        getline (cin, last_name);
        if (last_name.length() == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (flag != 1);
    
}
void account_details :: get_username()
{
    //First, all the accounts are loaded from the database, in order to check if the username entered is already registered or not
    load_details();
    accounts_list.pop_back();
    string username_check;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int flag = 0;
    do
    {
        cout <<setw(25) <<left<< "Create a unique username ";
        cout << setw(2) <<left << ": ";
        getline (cin, username);
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            username_check = (*it).username;
            if (username_check == username)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Username is already taken! Enter again! "<<endl;
                SetConsoleTextAttribute(h, 2);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    } while (flag != 1); 
    accounts_list.clear();  
}

void account_details :: get_phonenumber()
{
    //For same reason as the get_username() function, details are loaded first
    load_details();
    accounts_list.pop_back();
    string phn_number_check;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int flag = 0;
    cout << endl;
    do
    {
        cout << setw(25) <<left << "Enter your Phone Number ";
        cout << setw(2) << ": ";
        getline (cin, phoneNumber);
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            phn_number_check = (*it).phoneNumber;
            if (phn_number_check == phoneNumber)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Only one account can be created from one Phone Number! "<<endl;
                SetConsoleTextAttribute(h, 2);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }   
    }while (flag != 1); 
    accounts_list.clear();      
}
void account_details :: get_email ()
{
    int valid_flag;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl;
    do
    {
        cout << setw(25) << left << "Enter your email "<< setw(2) << ": ";
        getline (cin, email);
        for (int i = 0; i < email.length(); i++)
        {
            //Checks whether or not @ is present in the provided email. A valid email has atleast one @.
            if (email[i] == '@')
            {
                for (int k = i; k < email.length(); k++)
                {
                    //If @ is found. It checks for atleast one '.' Because a email has atleast one '.' too.
                    if (email [k] == '.')
                    {
                        valid_flag = 1;
                        break;
                    }
                }
                break;
            }
            else
            {
                valid_flag = 0;
            }
        }
        if (valid_flag == 0)
        {
            SetConsoleTextAttribute (h, 4);
            cout << "Invalid email format! Enter again! "<<endl;
            SetConsoleTextAttribute (h, 2);
        }
    } while (valid_flag != 1);   
}
void account_details :: get_password()
{
    int flag = 0;
    char pass_ch;
    string checkpassword;
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    
    do
    {
        cout <<endl<< setw(55) <<left<<"Create a password (Must be 8 characters or longer) " << setw(2) <<": ";
        do
        {
            pass_ch = getch();
            //if backspace is pressed
            if (pass_ch == 8)
            {
                //Until there is character to remove from console screen
                if (password.length() > 0)
                {
                    // ignore this// if (password.length() > 1) //ignore this
                    cout << "\b \b";
                    //pop_back removes the last inputted character i.e. top of the stack character and also reduces the string
                    //length by 1
                    password.pop_back();
                    // ignore this // password.resize(password.length() - 1); //ignore this too
                }
                //Don't store backspace in the password string
                continue;
            }
            else if(pass_ch == 13)
            {
                //Don't store 'Enter' in the password string
                continue;
            }
            else
            {
                //If the entered character is neither 'Enter' nor 'Backspace', store the character onto the password string
                password += pass_ch;
                cout << "*";
            }     
        }while (pass_ch != 13); //When 'Enter' is pressed, the loop is terminated. i.e. password is taken
        //If password length is less than the specified length i.e. 8
        if (password.length() < 8)
        {
            SetConsoleTextAttribute (h, 4);
            cout<<endl << "Passwords must be 8 characters or longer! Enter again !";
            SetConsoleTextAttribute (h, 2);
            password.clear();
            flag = 0;
            continue;
        }
        else
        {
            flag = 1;
        }
    } while (flag != 1);
    do
    {  
        do
    {
        cout<<endl <<setw(55) <<left << "Re-enter password to confirm "<< setw(2) << ": "; 
        do
        {
            pass_ch = getch();
            if (pass_ch == 8)
            {
                if (checkpassword.length() > 0)
                {
                    cout << "\b \b";
                    checkpassword.pop_back();
                //Ignore this// checkpassword.resize(checkpassword.length() - 1);
                }
                continue;
            }
            else if (pass_ch == 13)
            {
                continue;
            }
            else
            {
                checkpassword += pass_ch;
                cout << "*";
            }      
        }while (pass_ch != 13);
        if (checkpassword != password)
        {
            SetConsoleTextAttribute (h, 4);
            cout<<endl << "Passwords do not match! Enter again! ";
            SetConsoleTextAttribute (h, 2);
            checkpassword.clear();
            flag = 0;
            continue;
        }
        else
        {
            flag = 1;
        }
    } while (flag != 1);    
    } while (checkpassword != password);   
}
//Function to get age
void account_details :: get_age()
{
    char check;
    int flag;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
        cout << setw(25) << left << "Enter your age ";
        cout << setw(2) <<left <<": ";
        getline(cin, age);
        for (int i = 0; i < age.length(); i++)
        {
            check = age[i];
            if (!isdigit(check))
            {
                flag = 0;
                SetConsoleTextAttribute (h, 4);
                cout<<setw(25) <<left << "Invalid input! Enter again! "<<endl;
                SetConsoleTextAttribute (h, 2);
                break;
            }
            else
            {
                flag = 1;
            }
        }  
    } while (flag != 1);   
}
void account_details :: get_date_of_birth()
{
    int flag = 0;
    cout << endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
        cout << setw(43) <<left << "Enter your DOB in the format (YYYY-MM-DD) ";
        cout << setw (2) << ": ";
        getline(cin, DOB);
        if (DOB.length() != 10)
        {
            flag = 0;
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid Format! Enter again! "<<endl;
            SetConsoleTextAttribute(h, 2);
            continue;
        }
        else
        {
            if (!isdigit(DOB[0]) || !isdigit(DOB[1]) || !isdigit (DOB[2]) || !isdigit(DOB[3]))
            {
                flag = 0;
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Format! Enter again! "<<endl;
                SetConsoleTextAttribute(h, 2);
                continue;
            }
            else
            flag = 1;
            if (DOB[4] != '-' || DOB [7] != '-')
            {
                flag = 0;
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Format! Enter again! "<<endl;
                SetConsoleTextAttribute(h, 2);
                continue;
            }
            flag = 1;
            if (!isdigit(DOB[5]) || !isdigit(DOB[6]))
            {
                flag = 0;
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Format! Enter again! "<<endl;
                SetConsoleTextAttribute(h, 2);
                continue;
            }
            else
            flag = 1;
            if (!isdigit(DOB[8]) || !isdigit(DOB[9]))
            {
                flag = 0;
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Format! Enter again! "<<endl;
                SetConsoleTextAttribute(h, 2);
                continue;
            }
            else 
            flag = 1;
        }
    } while (flag != 1);
}
void account_details :: get_details ()
{
    system ("COLOR 02");
    system ("CLS");
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    cout << endl;
    ifstream codelog_title ("titles/codelog_title.txt");
    string title;
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl;
    if (codelog_title.is_open())
    {
        SetConsoleTextAttribute (h, 5);
        while (!codelog_title.eof())
        {
            getline (codelog_title, title);
            cout << title << endl;
        }
        SetConsoleTextAttribute (h, 2);
    }
    codelog_title.close();
    cout<< char(219) << " WELCOME " << char (219);
    cout << endl;
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl <<endl;
    get_first_name();
    get_last_name();
    cout << endl;
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout <<endl <<endl;
    get_age();
    cout <<endl;
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl;
    get_date_of_birth();
    cout << endl;
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl;
    get_email();
    cout << endl;
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl;
    get_phonenumber();
    get_username();
    cout << endl;
    for (int i = 0; i < 75; i++)
    {
        cout << char (196);
    }
    cout << endl;
    
    get_password();
    cout << endl <<endl;
    for (int i = 0; i < 75; i++)
    {
        cout << char (196);
    }
    /*****************Ignore the comments of this function below this *****************/
    // cout << endl <<endl;
    // SetConsoleTextAttribute (h, 6);
    // cout << "Account Registered Successfully! "<<endl;
    // SetConsoleTextAttribute (h, 2);  
}
