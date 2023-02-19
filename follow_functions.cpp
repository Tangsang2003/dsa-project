#include "follow_functions.hpp"
#include "global_functions.h"
#include "codelog.h"
#include "account_details.h"
#include <windows.h>
#include <conio.h>
using namespace std;
void follow_a_friend (account_details logged_user)
{
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    int ch;
    do {
        system ("cls");
        HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute (h, 2);
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl;
        SetConsoleTextAttribute (h, 5);
        ifstream title ("titles/codelog_title.txt");
        string title_load;
        if (title.is_open())
        {
            while (!title.eof())
            {
                getline (title, title_load);
                cout << "  " << title_load << endl;
            }
        }
        SetConsoleTextAttribute (h, 2);
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;


    
        SetConsoleTextAttribute (h, 5);
        cout<<setw(10) << left << "[-- 1 --]";
        SetConsoleTextAttribute (h, 2);
        cout << "Search User by Name or Email" << endl;
        SetConsoleTextAttribute (h, 5);
        cout <<setw(10) << left << "[-- 2 --]";
        SetConsoleTextAttribute (h, 2);
        cout << "Search User by Username or Phonenumber"<<endl;
        SetConsoleTextAttribute (h, 5);
        cout << setw(10) << left << "[-- 3 --]";
        SetConsoleTextAttribute (h, 2);
        cout << "Unfollow a User. " << endl;
        SetConsoleTextAttribute (h, 5);
        cout << setw(10) << left << "[-- 4 --]";
        SetConsoleTextAttribute (h, 2);
        cout << "Go Back! " << endl;
        cout << endl;
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        SetConsoleTextAttribute (h, 5);
        cout<<endl << "Enter your choice: ";
        SetConsoleTextAttribute (h, 2);
        cin >> ch;
        while (!cin.good())
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\nERR: Input Integer Only!\n";
            SetConsoleTextAttribute (h, 5);
            cout << "Enter your choice: ";
            cin.clear();
            cin.ignore();
            SetConsoleTextAttribute (h, 2);
            cin >> ch;
        }
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl;
        switch (ch)
        {
            case 1: search_by_name_or_email (logged_user);
            break;
            case 2: search_by_uname(logged_user);
            break;
            case 3: unfollow_a_user (logged_user);
            break;
            case 4:
            SetConsoleTextAttribute (h, 5);
            cout << "\nPress any key to go back..."; 
            SetConsoleTextAttribute (h, 2);
            getch();
            return;
            default: 
            SetConsoleTextAttribute (h, 4);
            cout << "ERR: INVALID CHOICE...";
            getch();
            SetConsoleTextAttribute (h, 2);
        }
    }while (ch != 4);
}
void search_by_name_or_email (account_details logged_user)
{
    system ("cls");
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl;
    SetConsoleTextAttribute (h, 5);
    ifstream title ("titles/codelog_title.txt");
    string title_load;
    if (title.is_open())
    {
        while (!title.eof())
        {
            getline (title, title_load);
            cout << "  " << title_load << endl;
        }
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl << endl;
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    //Pointers Declarations
    account_details *logged_user_address;
    account_details *address_of_user_to_be_followed;
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if ((*it).username == logged_user.username)
        {
            logged_user_address = &(*it);
            break;
        }
    }
    // String Variable Declarations
    string name_or_email; //This stores the name or email i.e. the search key
    string follow_username;
    string filename_for_following = "__LISTS/" + logged_user_address->username + "_FLWING_LST.txt";
    string filename_for_followers;
    SetConsoleTextAttribute (h, 5);
    cout<<setw(20) << left << "Enter Name or Email" << setw(2) << ": ";
    cin.ignore();
    SetConsoleTextAttribute (h, 2);
    getline (cin, name_or_email);
    cout << endl;
    int search_res_found_flag = 0;
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (name_or_email == (*it).username || name_or_email == (*it).first_name || name_or_email == (*it).first_name + " " + (*it).last_name || name_or_email == (*it).email)
        {
            for (int i = 0; i < 50; i++)
            {
                cout << char (196);
            }
            cout << endl << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(20) << left << "Name" << setw(2) << ": ";
            SetConsoleTextAttribute (h, 2);
            cout<< (*it).first_name + " " << (*it).last_name << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(20) << left << "Username" << setw(2) << ": ";
            SetConsoleTextAttribute (h, 2); 
            cout << (*it).username << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(20) << left << "Age" << setw(2) << ": ";
            SetConsoleTextAttribute (h, 2);
            cout <<  (*it).age << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(20) << left << "Followers" <<setw(2) << ": "; 
            SetConsoleTextAttribute (h, 2);
            cout << (*it).num_of_followers << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(20) << left <<  "Following" << setw(2) << ": ";
            SetConsoleTextAttribute (h, 2);
            cout << (*it).num_of_following << endl << endl;
            ifstream input_for_following (filename_for_following);
            string loader;
            list <string> following_list;
            if (input_for_following.is_open())
            {
                while (!input_for_following.eof())
                {
                    getline (input_for_following, loader);
                    following_list.push_back (loader);
                }
                input_for_following.close();
                following_list.pop_back();
                for (auto itr = following_list.begin(); itr != following_list.end(); itr++)
                {
                    if (*itr == (*it).username)
                    {
                        SetConsoleTextAttribute (h, 14);
                        cout << "** You are following this user **"<<endl << endl;
                        SetConsoleTextAttribute (h, 2);
                    }
                }
            }
            search_res_found_flag = 1;
        } 
        else if (search_res_found_flag == 0 && it == prev(accounts_list.end()))
        {
            SetConsoleTextAttribute (h, 4);
            cout << "** No results **" << endl << endl;
            SetConsoleTextAttribute (h, 2);
            for (int i = 0; i < 50; i++)
            {
                cout << char (196);
            }
            cout << endl;
            cout << "\nPress any key to go back...";
            getch();
            return;
        }
    }
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl;
    SetConsoleTextAttribute (h, 5);
    cout << setw(30) << left<< "\nEnter Username to Follow" << setw(2) << ": ";
    SetConsoleTextAttribute (h, 2);
    getline (cin, follow_username);
    if(follow_username == logged_user_address -> username)
    {
        SetConsoleTextAttribute (h, 4);
        cout << "\nERR: You can't follow yourself! " << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "\nPress any key to go back...";
        getch();
        return;
    }
    ifstream input_following (filename_for_following);
    string loader;
    list <string> following_list;
    if (input_following.is_open())
    {
        while (!input_following.eof())
        {
            getline (input_following, loader);
            following_list.push_back(loader);
        }
        following_list.pop_back();
    }

    int already_follow_flag = 0;
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (follow_username == (*it).username)
        {
            for (auto itr = following_list.begin(); itr != following_list.end(); itr++)
            {
                if (*itr == follow_username)
                {
                    SetConsoleTextAttribute (h, 14);
                    cout << "\n** Already Followed **" << endl;
                    SetConsoleTextAttribute (h, 2);
                    cout << endl;
                    for (int i = 0; i < 50; i++)
                    {
                        cout << char(196);
                    }
                    cout << endl;
                    cout << "\nPress any key to go back...";
                    getch();
                    already_follow_flag = 1;
                    break;
                }
            }
            address_of_user_to_be_followed = &(*it);
            break;
        }
        else if (follow_username != (*it).username && it == prev(accounts_list.end()))
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\n** No results **" << endl;
            SetConsoleTextAttribute (h, 2);
            cout << endl;
            for (int i = 0; i < 50; i++)
            {
                cout << char(196);
            }
            cout << endl;
            cout << "\nPress any key to go back...";
            getch();
            return;
        }
    }
    
    int change_flag = 0;
    if (already_follow_flag == 0)
    {
        filename_for_followers = "__LISTS/" + address_of_user_to_be_followed -> username + "_FLWRS_LST.txt";
        ofstream output_following (filename_for_following, ios :: app);
        ofstream output_followers (filename_for_followers, ios :: app);  
        if (output_following.is_open())
        {
            output_following << address_of_user_to_be_followed -> username << endl;
            logged_user_address -> num_of_following ++;
            change_flag = 1;
        } 
        output_following.close();
        if (output_followers.is_open())
        {
            output_followers << logged_user_address -> username << endl;
            address_of_user_to_be_followed -> num_of_followers++;
            change_flag = 1;
        }
        output_followers.close();
        SetConsoleTextAttribute (h, 14);
        cout<< endl << "** Started Following ";
        SetConsoleTextAttribute (h, 5);
        cout << "@" << address_of_user_to_be_followed -> username << " **"<< endl;
        SetConsoleTextAttribute (h, 2);
        cout << endl;
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl;
        cout << "\nPress any key to go back...";
        getch();
    }
    if (change_flag == 1)
    {
        ofstream file ("registered_accounts_new.txt");
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            file << (*it).first_name <<endl;
            file << (*it).last_name <<endl;
            file << (*it).age <<endl;
            file << (*it).DOB <<endl;
            file << (*it).email <<endl;
            file << (*it).phoneNumber <<endl;
            file << (*it).username <<endl;
            file << (*it).password <<endl;
        //Added extra features
            file << (*it).num_of_followers << endl;
            file << (*it).num_of_following << endl;
        }
    }
}

void search_by_uname (account_details logged_user)
{
    system ("cls");
    accounts_list.clear();
    load_details();
    accounts_list.pop_back();
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl;
    SetConsoleTextAttribute (h, 5);
    ifstream title ("titles/codelog_title.txt");
    string title_load;
    if (title.is_open())
    {
        while (!title.eof())
        {
            getline (title, title_load);
            cout << "  "<< title_load << endl;
        }
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl<< endl;
    string uname;
    SetConsoleTextAttribute (h, 5);
    cout << setw(29) << left << "Enter Username/PhoneNumber" << setw(2) << ": ";
    cin.ignore();
    SetConsoleTextAttribute (h, 2);
    getline (cin, uname);
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    if(uname == logged_user.username || uname == logged_user.phoneNumber)
    {
        SetConsoleTextAttribute (h, 4);
        cout << "\n\nERR: You can't follow yourself" << endl << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "Press any key to go back...";
        getch();
        return;
    }
    string file_name_following = "__LISTS/" + logged_user.username + "_FLWING_LST.txt";
    string file_name_followers;
    ifstream input_following (file_name_following);
    string loader;
    list <string> following_list;
    account_details *logged_user_address;
    account_details *address_of_account_to_be_followed;
    if (input_following.is_open())
    {
        while (!input_following.eof())
        {
            getline (input_following, loader);
            following_list.push_back(loader);
        }
        following_list.pop_back();
    }
    input_following.close();
    
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (logged_user.username == (*it).username || logged_user.phoneNumber == (*it).phoneNumber)
        {
            logged_user_address = &(*it);
            break;
        }
    }

    int already_follow_flag = 0;
    int found_flag = 0;
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if (uname == (*it).username)
        {
            found_flag = 1;
            address_of_account_to_be_followed = &(*it);
            cout << endl << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(29) << left << "Name" << setw(2) <<": "; 
            SetConsoleTextAttribute (h, 2);
            cout << (*it).first_name << " " << (*it).last_name << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(29) << left << "Username"<< setw(2) << ": ";
            SetConsoleTextAttribute (h, 2);
            cout << (*it).username << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(29) << left << "Age" << setw(2) << ": ";
            SetConsoleTextAttribute (h, 2); 
            cout << (*it).age << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(29) << left << "Followers"<<setw(2) << ": ";
            SetConsoleTextAttribute (h, 2); 
            cout << (*it).num_of_followers << endl;
            SetConsoleTextAttribute (h, 5);
            cout << setw(29) << left << "Following"<<setw(2) << ": "; 
            SetConsoleTextAttribute (h, 2);
            cout << (*it).num_of_following << endl;
            for (auto itr = following_list.begin(); itr != following_list.end(); itr++)
            {
                if (*itr == uname)
                {
                    SetConsoleTextAttribute (h, 14);
                    cout << "\n** Already Following this user **" << endl << endl;
                    SetConsoleTextAttribute (h, 2);
                    for (int i = 0; i < 50; i++)
                    {
                        cout << char (196);
                    }
                    already_follow_flag = 1;
                    cout << "\n\nPress any key to go back...";
                    getch();
                    return;
                }
            }
            cout << endl;
            for (int i = 0; i < 50; i++)
            {
                cout << char (196);
            }
            break;
        }
        else if (found_flag == 0 && it == prev(accounts_list.end()))
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\n\n** No results **" << endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to go back...";
            getch();
            return;
        }
    }

    int change_flag = 0;
    if (already_follow_flag == 0)
    {
        char ch;
        SetConsoleTextAttribute (h, 5);
        cout << "\n\nDo you want to follow this user?";
        SetConsoleTextAttribute (h, 14);
        cout << " (Y/N): "; 
        SetConsoleTextAttribute (h, 2);
        do
        {
            ch = getch();
        } while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N');

        if (ch == 'Y' || ch == 'y')
        {
            file_name_followers = "__LISTS/" + address_of_account_to_be_followed -> username + "_FLWRS_LST.txt";
            ofstream output_followers (file_name_followers, ios :: app);
            ofstream output_following (file_name_following, ios :: app);
            address_of_account_to_be_followed -> num_of_followers ++;
            logged_user_address -> num_of_following++;
            SetConsoleTextAttribute (h, 14);
            cout<< endl << "\n** Started Following ";
            SetConsoleTextAttribute (h, 5);
            cout << "@" << address_of_account_to_be_followed -> username<< " **" << endl;
            SetConsoleTextAttribute (h, 2);
            cout << endl;
            for (int i = 0; i < 50; i++)
            {
                cout << char(196);
            }
            cout << endl;
            cout << "\nPress any key to go back..."; 
            getch();
            output_followers << logged_user_address -> username << endl;
            output_following << address_of_account_to_be_followed -> username << endl;
            change_flag = 1;
            output_followers.close();
            output_following.close();
        }
        else if (ch == 'n' || 'N')
        {
            return;
        }   
    }
    if (change_flag == 1)
    {
        ofstream file ("registered_accounts_new.txt");
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            file << (*it).first_name <<endl;
            file << (*it).last_name <<endl;
            file << (*it).age <<endl;
            file << (*it).DOB <<endl;
            file << (*it).email <<endl;
            file << (*it).phoneNumber <<endl;
            file << (*it).username <<endl;
            file << (*it).password <<endl;
            //Added extra features
            file << (*it).num_of_followers << endl;
            file << (*it).num_of_following << endl;
        }
    }
}

void unfollow_a_user (account_details logged_user)
{
    system ("cls");
    ifstream title ("titles/codelog_title.txt");
    string title_load;
    string filename_following = "__LISTS/" + logged_user.username + "_FLWING_LST.txt";
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl;
    SetConsoleTextAttribute (h, 5);
    if (title.is_open())
    {
        while (!title.eof())
        {
            getline(title, title_load);
            cout<< "  " << title_load << endl;
        }
        title.close();
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }
    cout << endl << endl;
    ifstream input_following (filename_following);
    string following_string_loader;
    list <string> following_list;
    SetConsoleTextAttribute (h, 14);
    cout << "YOUR FOLLOWING LIST: \n" << endl;
    SetConsoleTextAttribute (h, 2);

    if (input_following.is_open())
    {
        while (!input_following.eof())
        {
            getline (input_following, following_string_loader);
            following_list.push_back (following_string_loader);
        }
        following_list.pop_back();
    }
    else
    {
        SetConsoleTextAttribute (h, 4);
        cout << "** You don't follow anyone! **"<<endl;
        SetConsoleTextAttribute (h, 2);
        cout << "\nPress any key to return...";
        getch();
        return;
    }
    if (following_list.empty())
    {
        SetConsoleTextAttribute (h, 4);
        cout << "** You don't follow anyone! **" << endl;
        SetConsoleTextAttribute (h, 2);
        cout << endl;
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << endl;
        cout << "\nPress any key to return...";
        getch();
        return;
    }
    int count = 1;
    for (auto it = following_list.begin(); it != following_list.end(); it++)
    {
        SetConsoleTextAttribute (h, 5); 
        cout<< "[-- " << count << " --]" << setw(4) << "  :";
        SetConsoleTextAttribute (h, 2);
        cout<< *it << endl;
        count++;
    }
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << char (196);
    }

    string unfollow_uname;
    cout << endl << endl;
    SetConsoleTextAttribute (h, 5);
    cout << "Unfollow [Username]  :  ";
    cin.ignore();
    SetConsoleTextAttribute (h, 4);
    getline (cin, unfollow_uname);
    SetConsoleTextAttribute (h, 2);

    bool change_flag = 0;
    for (auto it = following_list.begin(); it != following_list.end(); it++)
    {
        if (*it == unfollow_uname)
        {
            following_list.remove (unfollow_uname);
            change_flag = 1;
            break;
        }
        else if ((*it) != unfollow_uname && it == prev(following_list.end()))
        {
            SetConsoleTextAttribute (h, 4); 
            cout << "\n\nERR: Invalid Unfollow Request"<< endl;
            cout << endl;
            SetConsoleTextAttribute (h, 2); 
            for (int i = 0; i < 50; i++)
            {
                cout << char (196);
            }
            cout << endl << endl;
            cout << "Press any key to return..."; 
            getch();
            return;
        }
    }
    if (change_flag == 1)
    {
        string filename_followers  = "__LISTS/" + unfollow_uname + "_FLWRS_LST.txt";
        ifstream input_followers (filename_followers);
        list <string> output_followers_list;
        string output_follower_loader;
        if (input_followers.is_open())
        {
            while (!input_followers.eof())
            {
                getline (input_followers, output_follower_loader);
                output_followers_list.push_back(output_follower_loader);
            }
            output_followers_list.pop_back();

            for (auto it = output_followers_list.begin(); it != output_followers_list.end(); it++)
            {
                if (*it == logged_user.username)
                {
                    output_followers_list.remove (logged_user.username);
                    break;
                }
            }
        }
        accounts_list.clear();
        load_details();
        accounts_list.pop_back();
        account_details *address_of_unfollower;
        account_details *address_of_unfollowed;
        for (auto it = accounts_list.begin (); it != accounts_list.end(); it++)
        {
            if ((*it).username == logged_user.username)
            {
                address_of_unfollower = &(*it);
                break;
            }
        }
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            if ((*it).username == unfollow_uname)
            {
                address_of_unfollowed = &(*it);
                break;
            }
        }
        address_of_unfollowed -> num_of_followers--;
        address_of_unfollower -> num_of_following--;
        ofstream file ("registered_accounts_new.txt");
        ofstream output_followers (filename_followers);
        ofstream output_following (filename_following);
        for (auto it = output_followers_list.begin(); it != output_followers_list.end(); it++)
        {
            output_followers << *it << endl;
        }
        output_followers.close();
        for (auto it = following_list.begin(); it != following_list.end(); it++)
        {
            output_following << *it << endl;
        }
        output_following.close();
        for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
        {
            file << (*it).first_name <<endl;
            file << (*it).last_name <<endl;
            file << (*it).age <<endl;
            file << (*it).DOB <<endl;
            file << (*it).email <<endl;
            file << (*it).phoneNumber <<endl;
            file << (*it).username <<endl;
            file << (*it).password <<endl;
            //Added extra features
            file << (*it).num_of_followers << endl;
            file << (*it).num_of_following << endl;
        }
        file.close();

        SetConsoleTextAttribute (h, 14); 
        cout << "\n** Unfollowed";
        SetConsoleTextAttribute (h, 5);
        cout << " @" << address_of_unfollowed -> username << " **" << endl;
        cout << endl;
        SetConsoleTextAttribute (h, 2);
        for (int i = 0; i < 50; i++)
        {
            cout << char (196);
        }
        cout << "\n\nPress any key to return...";
        getch();
    }
}