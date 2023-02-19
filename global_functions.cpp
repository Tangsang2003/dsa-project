#include "global_functions.h"
#include "account_details.h"
#include "follow_functions.hpp"
#include "logged_functions.hpp"
#include <windows.h>
#include <stack>
#include <conio.h>
#include <ctime>
void load_details()
{
    //An account_details object. This object is used to fetch stored information in the database and then push back the fetched information
    //to the linked list of the global list accounts_list
    account_details details_to_load;
    string num_of_flw;
    string num_of_flwng;
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
            //Added Extra features
            getline(readfile, num_of_flw);
            details_to_load.num_of_followers = stoi (num_of_flw);
            getline(readfile, num_of_flwng);
            details_to_load.num_of_following = stoi (num_of_flwng);
            //Yaa Samma
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
        //Added extra features
        file << details_to_write.num_of_followers << endl;
        file << details_to_write.num_of_following << endl;
        //Yaa samma
        SetConsoleTextAttribute (h, 6);
        cout << endl<< endl;
        cout << "Account registered successfully! "<<endl;
        SetConsoleTextAttribute (h, 2);
        cout << "\nPress any key to continue...";
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
    for (int i = 0; i < 18; i++)
    {
        cout << char(205);
    }
    cout << char(187)<< endl;
    cout << char (186) << " Forgot Password? " <<char (186)<<endl;
    cout << char (200);
    for (int i = 0; i < 18; i++)
    {
        cout << char (205);
    }
    cout << char (188);
    cout << endl << endl;
    cin.ignore();
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl << endl;
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
            cout << endl;
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl;
            SetConsoleTextAttribute (h, 14);
            cout << endl << "Account Found! "<<endl << endl;
            SetConsoleTextAttribute (h, 2);
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl;
            newpassword.get_password();
            cout << endl << endl;
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
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
            cout << endl;
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl;
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
            output_file << (*it).num_of_followers << endl;
            output_file << (*it).num_of_following << endl;
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
    ifstream codelog_title ("titles/codelog_title.txt");
    string title;
    SetConsoleTextAttribute (h, 5);
    if (codelog_title.is_open())
    {
        while (!codelog_title.eof())
        {
            getline (codelog_title, title);
            cout << title << endl;
        }
    }
    codelog_title.close();
    SetConsoleTextAttribute (h, 2);
    cout << char (201);
    for (int i = 0; i < 12; i++)
    {
        cout << char (205);
    }
    cout << char (187) << "\n";
    cout << char(186);
    SetConsoleTextAttribute (h, 5); 
    cout<< " USER LOGIN ";
    SetConsoleTextAttribute (h, 2);  
    cout<< char (186) <<endl;
    cout << char (200);
    for (int i = 0; i < 12; i++)
    {
        cout << char(205);
    }
    cout << char (188) << "\n";
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char(196);
    }
    cout << "\n";
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
            cout << endl << endl;
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
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
            cout << "\n";
            for (int i = 0; i < 60; i++)
            {
                cout << char(196);
            }
            cout << endl;
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
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl;
        SetConsoleTextAttribute (h, 5);
        ifstream codelog_title ("titles/codelog_title.txt");
        string title;
        
        if (codelog_title.is_open())
        {
            while (!codelog_title.eof())
            {
                getline (codelog_title, title);
                cout << "  "<<title << endl;
            } 
        }
        SetConsoleTextAttribute (h, 2);
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        codelog_title.close();
        cout << endl << endl;
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
        cout << char (188) << endl<<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 1 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "Post a status update.\n" <<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 2 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "View your profile. \n" <<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 3 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "Delete a Status. \n" << endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 4 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "Follow a user. \n"<<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 5 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "Followers. \n" << endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 6 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "Following.\n"<<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 7 --]  ";
            SetConsoleTextAttribute (h, 2);
            cout << "View your friend's profile. \n"<<endl;
            SetConsoleTextAttribute (h, 13);
            cout << setw(13) << left << "[-- 8 --]  ";
            SetConsoleTextAttribute (h, 2); 
            cout << "Logout! \n" << endl;
            for (int i = 0; i < 50; i++)
            {
                cout << char (196);
            }
            cout << endl;
            SetConsoleTextAttribute (h, 13);
            cout << "\nEnter your choice: ";
            SetConsoleTextAttribute (h, 2);
            cin >> choice;
            while (!cin.good())
            {
                SetConsoleTextAttribute (h, 4);
                cout << "ERR: ";
                SetConsoleTextAttribute (h, 2);
                cout << "Enter integer only: ";
                cin.clear();
                cin.ignore();
                cin >> choice;
                cout << endl;
            }
            switch(choice)
            {
                    case 1: post_status (logged_user);
                    break;
                    case 2: view_profile (logged_user);
                    break;
                    case 3: delete_a_status (logged_user);
                    break;
                    case 4: follow_a_friend (logged_user);
                    break;
                    case 5: view_followers (logged_user);
                    break;
                    case 6: view_following (logged_user);
                    break;
                    case 7: view_other_profile (logged_user);
                    break;
                    case 8: 
                    SetConsoleTextAttribute (h, 4);
                    cout << "\nLOGGING OUT..." << endl;
                    SetConsoleTextAttribute (h, 2);
                    cout << "\nPress any key...";
                    getch();
                    break;
                    default: 
                    SetConsoleTextAttribute (h, 4);
                    cout << "Invalid choice! ";
                    SetConsoleTextAttribute (h, 2);
                    getch();

            }
        
    } while (choice != 8);
    
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

void post_status (account_details logged_user)
{
    system ("cls");
    int return_flag = 0;
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    char check;
    string time_of_status; 
    string status;
    string filename;
    int flag = 0;
    filename = "db/";
    filename += logged_user.username;
    filename += ".txt";
    
    //Code for getting current time
    time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()

    SetConsoleTextAttribute (h, 2);
    
    cout << char (201);
    for (int i = 0; i < 15; i++)
    {
        cout << char (205);
    }
    cout << char (187);
    cout << "\n" << char (186) << " Post a status ";
    cout << char (186);
    cout << "\n" << char (200);
    for (int i = 0; i < 15; i++)
    {
        cout << char (205);
    }
    cout << char (188);
    cout << endl;

    cout << "\nWhat's on your mind? Press";
    SetConsoleTextAttribute (h, 4); 
    cout << " Esc ";
    SetConsoleTextAttribute (h, 2);
    cout << "to cancel and go back." << endl << endl;
    do
    {
        check = getch();
        if (check == 8)
        {
            if (status.length() > 0)
            {
                cout << "\b \b";
                status.pop_back();
            }
            else
            continue;
        }

        else if (check == 27)
        {
            return_flag = 1;
            break;
        }
        else if (check == 13 && status.length() == 0)
        {
            return_flag = 1;
            SetConsoleTextAttribute (h, 4);
            cout << "\nERR: NOTHING TO POST! PRESS ANY KEY TO GO BACK...";
            getch();
            SetConsoleTextAttribute (h, 2);
            break;
        }
        else
        {
            SetConsoleTextAttribute (h, 15);
            cout << check;
            if (check != 13)
            status += check;
        }      
    } while (check != 13);
    SetConsoleTextAttribute (h, 2);
    tt = localtime(&t);
    time_of_status = asctime(tt);
    time_of_status.pop_back();
    if (return_flag == 1)
    {
        return;
    }
    else
    {
        ofstream status_output (filename, ios :: app);
        if (status_output.is_open())
        {
            status_output << time_of_status << endl;
            status_output << status << endl;
            SetConsoleTextAttribute (h, 14);
            cout << "\n\nSTATUS POSTED SUCCESSFULLY ! \n"<<endl;
            SetConsoleTextAttribute (h, 2);
            cout << "Press any key to go back...";
            getch();
            return;
        }
        else
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\nERR: STATUS COULDN'T BE POSTED! PRESS ANY KEY TO RETURN...";
            getch();
            SetConsoleTextAttribute (h, 2);
            return;
        }
    }
    
}

void view_profile (account_details logged_user)
{
    system ("cls");
    string title;
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if ((*it).username == logged_user.username)
        {
            logged_user.num_of_followers = (*it).num_of_followers;
            logged_user.num_of_following = (*it).num_of_following;
            break;
        }
    }
    // ifstream file ("titles/profile_title.txt");
    // if (file.is_open())
    // {
    //     while (!file.eof())
    //     {
    //         getline (file, title);
    //         cout << title << endl;
    //     }
    // }
    // else
    // {
    //     SetConsoleTextAttribute (h, 4);
    //     cout << "ERR: TITLE COULDN'T BE LOADED PROPERLY\n";
    //     SetConsoleTextAttribute (h, 2);
    // }
    struct stat_format
    {
        int stat_num = 0;
        string date;
        string ind_status;
    };
    cout << char(218);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char(196);
    }
    cout << char (191);
    cout << "\n";
    cout << char (179);
    SetConsoleTextAttribute (h, 5);
    cout << " @";
    cout << logged_user.username;
    SetConsoleTextAttribute (h, 2);
    cout << " " << char(179) << "\n";
    cout << char (192);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char(196);
    }
    cout << char (217);
    cout << "\n";
    cout << char (218);
    int length_var;
    length_var = logged_user.first_name.length() + logged_user.last_name.length() + 1;
    for (int i = 0; i < 16 + logged_user.first_name.length() + logged_user.last_name.length(); i++)
    {
        cout << char (196);
    }
    cout << char (191) << endl;
    cout << char(179);
    SetConsoleTextAttribute (h, 5);
    cout << setw(12) << left << " Name" << setw(2) << ": ";
    SetConsoleTextAttribute (h, 2);
    cout << logged_user.first_name + " " << logged_user.last_name << " " << char(179)<< endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 5);
    cout << setw(12) << left << " Followers" << setw(2) << ": ";
    SetConsoleTextAttribute (h, 2);
    cout << setw(length_var) << logged_user.num_of_followers<< " " << char (179) << endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 5);
    cout << setw(12) << left << " Following" << setw(2) << ": ";
    SetConsoleTextAttribute (h, 2);
    cout << setw(length_var) << logged_user.num_of_following<< " " << char (179)<<endl;
    cout << char (192);
    for (int i = 0; i < 16 + logged_user.first_name.length() + logged_user.last_name.length(); i++)
    {
        cout << char (196);
    }
    cout << char(217) << endl << endl;
    string filename;
    stack <stat_format> stack_of_status;
    stat_format loader;
    filename = "db/";
    filename += logged_user.username;
    filename += ".txt";
    ifstream get_status (filename);
    if (!get_status.is_open())
    {
        SetConsoleTextAttribute (h, 6);
        cout << "\n** No status has been posted! **" << endl;
        SetConsoleTextAttribute (h, 2);
        goto back;
    }
    while (!get_status.eof())
    {
        loader.stat_num++;
        getline (get_status, loader.date);
        getline (get_status, loader.ind_status);
        stack_of_status.push(loader);
    }
    stack_of_status.pop();
    get_status.close();
    if (stack_of_status.empty())
    {
        SetConsoleTextAttribute (h, 6);
        cout << "\n** No status has been posted! **" << endl;
        SetConsoleTextAttribute (h, 2);
        goto back;
    }

    while (!stack_of_status.empty())
    {
        for (int i = 0; i < 80; i++)
        {
            SetConsoleTextAttribute (h, 2);
            cout << char (196);
        }
        cout << endl << endl;
        cout << "  Status # " << stack_of_status.top().stat_num << endl;
        SetConsoleTextAttribute (h, 6);
        cout << "  On "<< stack_of_status.top().date << endl << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "  "<<stack_of_status.top().ind_status << endl << endl;
        stack_of_status.pop();
    }
    for (int i = 0; i < 80; i++)
    {
        cout << char(196);
    }
    cout << "\n";
    char ch;
    back: 
    cout << "\n  Press";
    SetConsoleTextAttribute (h, 4);
    cout << " 'b'";
    SetConsoleTextAttribute (h, 2);
    cout << " to go back! ";
    do
    {
        ch = getch();
    } while (ch != 'b');   
}