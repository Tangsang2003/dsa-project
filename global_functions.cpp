#include "global_functions.h"
#include "account_details.h"
#include <windows.h>
#include <conio.h>
void load_details()
{
    //An account_details object. This object is used to fetch stored information in the database and then push back the fetched information
    //to the linked list of the global list accounts_list
    account_details details_to_load;
    ifstream readfile ("registered_accounts_new.txt");
    if (readfile.is_open())
    {  
        while (!readfile.eof())
        {
            getline(readfile,details_to_load.first_name);
            getline(readfile,details_to_load.last_name);
            getline(readfile,details_to_load.age) ;
            getline(readfile,details_to_load.DOB) ;
            getline(readfile,details_to_load.email) ;
            getline(readfile,details_to_load.phoneNumber );
            getline(readfile, details_to_load.username );
            getline(readfile, details_to_load.password ); 
            accounts_list.push_back(details_to_load);
        }
        readfile.close();
    }
    else
    {
        ofstream file ("registered_accounts_new.txt");
        file.close();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute (h, 4);
        cout << "Registered accounts database couldn't be loaded properly! Restart the program and try again! \n";
        SetConsoleTextAttribute (h, 2);
        cout << "Press any key...\n";
        getch();
        exit(42);
    }
} 

void write_details ()
{
    //Similar to details_to_load object 
    account_details details_to_write;
    cin.ignore();
    details_to_write.get_details ();
    ofstream file ("registered_accounts_new.txt", ios :: app);
    if (file.is_open())
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        file << details_to_write.first_name <<endl;
        file << details_to_write.last_name <<endl;
        file << details_to_write.age <<endl;
        file << details_to_write.DOB <<endl;
        file << details_to_write.email <<endl;
        file << details_to_write.phoneNumber <<endl;
        file << details_to_write.username <<endl;
        file << details_to_write.password <<endl;
        SetConsoleTextAttribute (h, 6);
        cout << endl<< endl;
        cout << "Account registered successfully! "<<endl;
        SetConsoleTextAttribute (h, 2);
        cout << "Press any key to continue..." <<endl;
        getch();
        file.close();   
    }
    else
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute (h, 4);
        cout << "Account couldn't be registered! "<<endl;
        SetConsoleTextAttribute (h, 2);
    }
}

void forgot_password ()
{
    system ("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    // for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    // {
    //     cout << (*it).first_name << endl;
    //     cout << (*it).last_name << endl;
    //     cout << (*it).age << endl;
    //     cout << (*it).DOB << endl;
    //     cout << (*it).email << endl;
    //     cout << (*it).phoneNumber << endl;
    //     cout << (*it).username << endl;
    //     cout << (*it).password << endl;
    // }
    int flag = 0;
    string username;
    string phonenumber;
    string checkemail;
    account_details newpassword;
    string newpass;
    ifstream readfile ("registered_accounts_new.txt");
    SetConsoleTextAttribute (h, 2);
    cout << char(201);
    for (int i = 0; i < 16; i++)
    {
        cout << char(205);
    }
    cout << char(187)<< endl;
    cout << char (186) << "Forgot Password?" <<char (186)<<endl;
    cout << char (200);
    for (int i = 0; i < 16; i++)
    {
        cout << char (205);
    }
    cout << char (188);
    cout << endl << endl;
    cin.ignore();
    cout << setw(25) << left << "Enter your username " << setw(2) << ": ";
    getline (cin, username);
    cout << setw(25) << left <<  "Enter your phonenumber " << setw(2) << ": ";
    getline (cin, phonenumber);
    cout << setw(25) << left << "Enter your email "<< setw(2) << ": ";
    getline (cin, checkemail);
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (phonenumber == (*it).phoneNumber && username == (*it).username && checkemail == (*it).email)
        {
            SetConsoleTextAttribute (h, 14);
            cout << endl << "Account Found! "<<endl;
            SetConsoleTextAttribute (h, 2);
            newpassword.get_password();
            newpass = newpassword.password;
            (*it).password = newpass;
            flag = 1;
            SetConsoleTextAttribute (h, 14);
            cout << endl << endl << "Your password has been reset successfully! "<<endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to continue...";
            getch();
            break;
        }
        else if ((flag == 0) && it == prev(accounts_list.end()))
        {
            SetConsoleTextAttribute (h, 4);
            cout <<endl << "Account Not Found! "<<endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to go back...";
            getch();
        }
    }
    readfile.close();
    if (flag == 1)
    {
        ofstream output_file ("registered_accounts_new.txt");
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            output_file << (*it).first_name <<endl;
            output_file << (*it).last_name <<endl;
            output_file << (*it).age <<endl;
            output_file << (*it).DOB <<endl;
            output_file << (*it).email <<endl;
            output_file << (*it).phoneNumber<<endl;
            output_file << (*it).username<<endl;
            output_file << (*it).password<<endl;
        }
        output_file.close();
    }

}

void login ()
{
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    account_details logged_user;
    string username_phoneNumber;
    string pass_word;
    int flag = 0;
    int login_flag = 0;
    system ("cls");
    cout << char (201);
    for (int i = 0; i < 12; i++)
    {
        cout << char (205);
    }
    cout << char (187) << "\n";
    cout << char(186) << " USER LOGIN "  << char (186) <<endl;
    cout << char (200);
    for (int i = 0; i < 12; i++)
    {
        cout << char(205);
    }
    cout << char (188) << "\n";
    cout << setw (35) << left<< "\nEnter your Username or PhoneNumber " << setw(2) << ": ";
    getline(cin, username_phoneNumber);
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (username_phoneNumber == (*it).username || username_phoneNumber == (*it).phoneNumber)
        {
            flag = 1;
            cout<< setw(35) << left << "Enter your password "<< setw (2) <<": ";
            // getline (cin, pass_word);
            pass_word = get_password_for_login();
            if (pass_word == (*it).password)
            {
                login_flag = 1;
                logged_user = (*it);
                SetConsoleTextAttribute (h, 14);
                cout << "\n";
                cout << "\nLogin Successful! "<<endl;
                SetConsoleTextAttribute (h, 2);
                cout << "\nPress any key to continue...";
                getch();
            }
            else
            {
                SetConsoleTextAttribute (h, 4);
                cout << "\n\nIncorrect Password! "<<endl;
                SetConsoleTextAttribute (h, 2);
                cout << "\nPress any key to go back...";
                getch();
            }
            break;
        }
        else if (flag == 0 && it == prev(accounts_list.end()))
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\nNo account found with that username or phonenumber..."<<endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to go back...";
            getch();
        }
    }
    if (login_flag == 1)
    {
        screen_one (logged_user);
    }
}

void screen_one (account_details logged_user)
{
    int choice;
    // system ("cls");
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute (h, 2);
    // cout << char(201);
    // for (int i = 0; i < (10 + logged_user.first_name.length()); i++)
    // {
    //     cout << char(205);
    // }
    // cout << char(187);
    // cout << endl;
    // cout << char(186);
    // cout << " Welcome ";
    // SetConsoleTextAttribute (h, 13);
    // cout << logged_user.first_name << " ";
    // SetConsoleTextAttribute (h, 2); 
    // cout << char(186) << "\n";
    // cout << char(200);
    // for (int i = 0; i < (10 + logged_user.first_name.length()); i++)
    // {
    //     cout << char(205);
    // }
    // cout << char (188) << endl;
    // cout << endl;
    do
    {
        system ("cls");
        SetConsoleTextAttribute (h, 2);
    cout << char(201);
    for (int i = 0; i < (10 + logged_user.first_name.length()); i++)
    {
        cout << char(205);
    }
    cout << char(187);
    cout << endl;
    cout << char(186);
    cout << " Welcome ";
    SetConsoleTextAttribute (h, 13);
    cout << logged_user.first_name << " ";
    SetConsoleTextAttribute (h, 2); 
    cout << char(186) << "\n";
    cout << char(200);
    for (int i = 0; i < (10 + logged_user.first_name.length()); i++)
    {
        cout << char(205);
    }
    cout << char (188) << endl;
    cout << endl;
        cout << "(1) Post a status update." <<endl;
        cout << "(2) View your profile." <<endl;
        cout << "(3) View your followers. "<<endl;
        cout << "(4) Follow a friend. "<<endl;
        cout << "(5) Message a friend. "<<endl;
        cout << "(6) View your friend's profile. "<<endl;
        cout << "(7) Logout! "<<endl;
        cout <<endl << "Enter your choice: ";
        cin >> choice;
    } while (choice != 7);
    
}

string get_password_for_login ()
{
    string pass;
    char ch;
    do
    {
        ch = getch();
        if (ch == 8)
        {
            if (pass.length() > 0)
            {
                cout << "\b \b";
                pass.pop_back();
            }
            continue;
        }
        else if (ch == 13)
        {
            continue;
        }
        else
        {
            cout << "*";
            pass += ch;
        }
    } while (ch != 13);

    return pass;   
}