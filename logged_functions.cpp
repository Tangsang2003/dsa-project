#include "logged_functions.hpp"
using namespace std;

void delete_a_status (account_details logged_user)
{
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    struct status_del
    {
        string time;
        string stat;
        int index;
    };
    int num;
    bool change_flag = 0;
    
    string filename;
    filename = "db/" + logged_user.username + ".txt";
    ifstream input_status (filename);
    system ("cls");

    status_del status_loader;
    list <status_del> status_list;
    int ind_ex = 1;

    SetConsoleTextAttribute (h, 2);
    cout << char (218);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (191);
    cout << endl;
    cout << char(179);
    SetConsoleTextAttribute (h, 5);
    cout << " @" << logged_user.username << " ";
    SetConsoleTextAttribute (h, 2);
    cout << char (179) << endl;
    cout << char (192);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (217) << endl;
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

    if (input_status.is_open())
    {
        while (!input_status.eof())
        {
            getline (input_status, status_loader.time);
            getline (input_status, status_loader.stat);
            status_loader.index = ind_ex;
            status_list.push_back(status_loader);
            ind_ex ++;
        }
        status_list.pop_back();

        if (status_list.empty())
        {
            cout << endl;
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl << endl;
            SetConsoleTextAttribute (h, 4);
            cout << "You haven't posted any status." << endl << endl;
            SetConsoleTextAttribute (h, 2);
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl << endl;
            SetConsoleTextAttribute (h, 2);
            cout << "Press any key to return...";
            getch();
            return;
        }
        else
        {
            SetConsoleTextAttribute (h, 2);
            status_list.reverse();
            for (auto it = status_list.begin(); it != status_list.end(); it++)
            {
                for (int i = 0; i < 60; i++)
                {
                    cout << char (196);
                }
                cout << endl << endl;
                cout << "Status #" << (*it).index << endl;
                SetConsoleTextAttribute (h, 14);
                cout << "On " << (*it).time << endl;
                SetConsoleTextAttribute (h, 2);
                cout << endl << (*it).stat << endl << endl;
            }
            for (int i = 0; i < 60; i++)
            {
                cout << char (196);
            }
            cout << endl << endl;
            SetConsoleTextAttribute (h, 5);
            status_list.reverse(); //O
            cout << "Enter (#) of the status that you want to delete: ";
            SetConsoleTextAttribute (h, 2);
            cin >> num;
            while (!cin.good())
            {
                SetConsoleTextAttribute (h, 4);
                cout << "\nEnter integer only!" <<endl;
                SetConsoleTextAttribute (h, 5);
                cout << "Enter (#): ";
                SetConsoleTextAttribute (h, 2);
                cin.clear();
                cin.ignore();
                cin >> num;
            }
            for (auto it = status_list.begin(); it!= status_list.end(); it++)
            {
                if ((*it).index == num)
                {
                    status_list.erase(it++);
                    change_flag = 1;
                    break;
                }
                else if ((*it).index != num && it == prev(status_list.end()))
                {
                    cout << endl;
                    for (int i = 0; i < 60; i++)
                    {
                        cout << char (196);
                    }
                    cout << endl << endl;
                    SetConsoleTextAttribute (h, 4);
                    cout << "ERR: No Status with that (#)" << endl;
                    SetConsoleTextAttribute (h, 2);
                    cout << "\nPress any key to return...";
                    getch();
                    return;
                }
            }
            if (change_flag == 1)
            {
                ind_ex = 1;
                //status_list.reverse(); //R
                /*
                for (auto it = status_list.begin(); it != status_list.end(); it++)
                {
                    (*it).index = ind_ex;
                    ind_ex++;
                }
                */
                //status_list.reverse();//R
                /*
                for (auto it = status_list.begin(); it!= status_list.end(); it++)
                {
                    cout << "Status #" << (*it).index << endl;
                    cout << "On " << (*it).time << endl;
                    cout << endl << (*it).stat << endl << endl;
                }
                */
                //status_list.reverse(); //O
                ofstream output_status (filename);
                if (output_status.is_open())
                {
                    for (auto it = status_list.begin(); it != status_list.end(); it++)
                    {
                        output_status << (*it).time << endl;
                        output_status << (*it).stat << endl;
                    }
                    cout << endl;
                    output_status.close();
                    SetConsoleTextAttribute (h, 2);
                    for (int i = 0; i < 60; i++)
                    {
                        cout << char (196);
                    }
                    cout << endl << endl;
                    SetConsoleTextAttribute (h, 14);
                    cout << "Status Removed! " << endl;
                    SetConsoleTextAttribute (h, 2);
                    cout <<endl; 
                    cout << "Press any key to return...";
                    getch();
                    return;
                }   
            }
        }
    }
    else
    {
        cout << endl;
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;
        SetConsoleTextAttribute (h, 4);
        cout << "You haven't posted any status." << endl << endl;
        SetConsoleTextAttribute (h, 2);
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "Press any key to return...";
        getch();
        return;
    }
}

void view_followers (account_details logged_user)
{
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
    system ("cls");
    string followers_input;
    followers_input = "__LISTS/" + logged_user.username + "_FLWRS_LST.txt";
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    cout << char (218);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (191) << endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 5);
    cout << " @"<<logged_user.username << " ";
    SetConsoleTextAttribute (h, 2);
    cout << char (179) << endl;
    cout << char (192);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (217) << endl;
    cout << endl;
    cout << "You are followed by: ";
    SetConsoleTextAttribute (h, 6);
    cout  << logged_user.num_of_followers;
    SetConsoleTextAttribute (h, 2);
    cout << " Users.";
    cout << endl << endl;
    SetConsoleTextAttribute (h, 2);
    cout << char (218);
    for (int i = 0; i < 16; i++)
    {
        cout << char (196);
    }
    cout << char (191) << endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 6);
    cout << " YOUR FOLLOWERS ";
    SetConsoleTextAttribute (h, 2);
    cout << char (179) << endl;
    cout << char (192);
    for (int i = 0; i < 16; i++)
    {
        cout << char (196);
    }
    cout << char (217);
    for (int i = 0; i < 60 - 18; i++)
    {
        cout << char (196);
    }
    cout << endl;
    ifstream input_followers (followers_input);
    if (input_followers.is_open())
    {
        string loader;
        list <string> followers_list;
        while (!input_followers.eof())
        {
            getline (input_followers, loader);
            followers_list.push_back (loader);
        }
        input_followers.close();
        followers_list.pop_back();
        if (followers_list.empty())
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\n** NO FOLLOWERS :p ** " << endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to return...";
            getch();
            return;
        }

        int counter = 1;
        cout << endl;
        for (auto it = followers_list.begin(); it != followers_list.end(); it++)
        {
            SetConsoleTextAttribute (h, 5);
            cout << "[-- " << counter << " --]     : ";
            SetConsoleTextAttribute (h, 2);
            cout << (*it) << endl;
            counter++;
        }
        cout << endl;
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;
        SetConsoleTextAttribute (h, 5);
        cout << "Press any key to return...";
        SetConsoleTextAttribute (h, 2);
        getch();
        return;
    }

    else
    {
        SetConsoleTextAttribute (h, 4);
        cout << "\n** NO FOLLOWERS :p ** " << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "\nPress any key to return...";
        getch();
        return;
    }
}

void view_following (account_details logged_user)
{
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
    system ("cls");
    string filename;
    filename = "__LISTS/" + logged_user.username + "_FLWING_LST.txt";
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (h, 2);
    cout << char (218);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (191) << endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 5);
    cout << " @"<<logged_user.username << " ";
    SetConsoleTextAttribute (h, 2);
    cout << char (179) << endl;
    cout << char (192);
    for (int i = 0; i < logged_user.username.length() + 3; i++)
    {
        cout << char (196);
    }
    cout << char (217) << endl;
    cout << endl;
    cout << "You are following: ";
    SetConsoleTextAttribute (h, 6);
    cout  << logged_user.num_of_following;
    SetConsoleTextAttribute (h, 2);
    cout << " Users.";
    cout << endl << endl;
    SetConsoleTextAttribute (h, 2);
    cout << char (218);
    for (int i = 0; i < 12; i++)
    {
        cout << char (196);
    }
    cout << char (191) << endl;
    cout << char (179);
    SetConsoleTextAttribute (h, 6);
    cout << " YOU FOLLOW ";
    SetConsoleTextAttribute (h, 2);
    cout << char (179) << endl;
    cout << char (192);
    for (int i = 0; i < 12; i++)
    {
        cout << char (196);
    }
    cout << char (217);
    for (int i = 0; i < 60 - 12; i++)
    {
        cout << char (196);
    }
    cout << endl;
    ifstream input_following (filename);
    if (input_following.is_open())
    {
        string loader;
        list <string> following_list;
        while (!input_following.eof())
        {
            getline (input_following, loader);
            following_list.push_back (loader);
        }
        following_list.pop_back();
        if (following_list.empty())
        {
            SetConsoleTextAttribute (h, 4);
            cout << "\n** You don't follow anyone :p ** " << endl;
            SetConsoleTextAttribute (h, 2);
            cout << "\nPress any key to return...";
            getch();
            return;
        }

        int counter = 1;
        cout << endl;
        for (auto it = following_list.begin(); it != following_list.end(); it++)
        {
            SetConsoleTextAttribute (h, 5);
            cout << "[-- " << counter << " --]     : ";
            SetConsoleTextAttribute (h, 2);
            cout << (*it) << endl;
            counter++;
        }
        cout << endl;
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;
        SetConsoleTextAttribute (h, 5);
        cout << "Press any key to return...";
        SetConsoleTextAttribute (h, 2);
        getch();
        return;
    }
    else
    {
        SetConsoleTextAttribute (h, 4);
        cout << "\n** You don't follow anyone :p ** " << endl;
        SetConsoleTextAttribute (h, 2);
        cout << "\nPress any key to return...";
        getch();
        return;
    }
    getch();

}

void view_other_profile (account_details logged_user)
{
    system ("cls");
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    string uname;
    string filename_following;
    string filename_followers;
    filename_following = "__LISTS/" + logged_user.username + "_FLWING_LST.txt";
    filename_followers = "__LISTS/" + logged_user.username + "_FLWRS_LST.txt";

    string title;
    ifstream intitle ("titles/codelog_title.txt");
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    cout << endl;
    SetConsoleTextAttribute (h, 5);
    if (intitle.is_open())
    {
        while (!intitle.eof())
        {
            getline (intitle, title);
            cout << "      " << title << endl;
        }
        intitle.close();
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    //here getline

    ifstream input_following (filename_following);
    ifstream input_followers (filename_followers);
    accounts_list.clear();
    load_details();
    string loader;
    list <string> following_list;
    list <string> followers_list;

    bool no_followers_flag = TRUE;
    if (input_followers.is_open())
    {
        no_followers_flag = FALSE;
        while (!input_followers.eof())
        {
            getline (input_followers, loader);
            followers_list.push_back (loader);
        }
        followers_list.pop_back();
        input_followers.close();
        if (followers_list.empty())
        {
            no_followers_flag = TRUE;
        }
    }
    else
    {
        no_followers_flag = TRUE;
    }

    bool no_following_flag = TRUE;
    if (input_following.is_open())
    {
        no_following_flag = FALSE;
        while (!input_following.eof())
        {
            getline (input_following, loader);
            following_list.push_back (loader);
        }
        following_list.pop_back();
        input_following.close();
        if (following_list.empty())
        {
            no_following_flag = TRUE;
        }
    }
    else
    {
        no_following_flag = TRUE;
    }
    if (no_followers_flag == TRUE && no_following_flag == TRUE)
    {
        cout << endl << endl;
        SetConsoleTextAttribute (h, 4);
        cout << "*You have 0 followers. And, you don't follow anyone.* \nYou need to follow or be followed by any user to view their \nprofile." << endl;
        SetConsoleTextAttribute (h, 2);
        cout << endl;
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;
        SetConsoleTextAttribute (h, 5);
        cout << "Press any key to return...";
        SetConsoleTextAttribute (h, 2);
        getch();
        return;
    }
    cout << endl << endl;
    SetConsoleTextAttribute (h, 5);
    cout<< setw(35) << left << "Whose profile do you want to view?\n";
    cout << setw(15) << left << "\nEnter Username" << setw(3) << left << " : ";
    SetConsoleTextAttribute (h, 2);
    cin.ignore();
    getline (cin, uname);
    cout << endl;

    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    bool valid_account_flag = FALSE;
    for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
    {
        if ((*it).username == uname)
        {
            valid_account_flag = TRUE;
            break;
        }
        else if ((*it).username != uname && it == prev(accounts_list.end()))
        {
            cout << endl << endl;
            SetConsoleTextAttribute (h, 4);
            cout << "No user found with that username! " << endl << endl;
            SetConsoleTextAttribute (h, 5);
            cout << "Press any key to return..."; 
            SetConsoleTextAttribute (h, 2);
            getch();
            return;
        }
    }

    if (valid_account_flag == TRUE)
    {
        if (uname == logged_user.username)
        {
            view_profile (logged_user);
            return;
        }
        //here
        if (no_followers_flag == FALSE || no_following_flag == FALSE)
        {
            bool is_in_following = FALSE;
            for (auto itr = following_list.begin(); itr != following_list.end(); itr++)
            {
                if (uname == *itr)
                {
                    is_in_following = TRUE;
                    break;
                }
                else if (uname != *itr && itr == prev(following_list.end()))
                {
                    is_in_following = FALSE;
                }
            }

            bool is_in_followers = FALSE;
            for (auto itr1 = followers_list.begin(); itr1 != followers_list.end(); itr1++)
            {
                if (uname == *itr1)
                {
                    is_in_followers = TRUE;
                    break;
                }
                else if (uname != *itr1 && itr1 == prev(followers_list.end()))
                {
                    is_in_followers = FALSE;
                }
            }
            if (is_in_followers == FALSE && is_in_following == FALSE)
            {
                SetConsoleTextAttribute (h, 14);
                cout << endl << endl;
                cout << "@" << uname;
                SetConsoleTextAttribute (h, 4);
                cout << " is neither on your followers list nor on your \nfollowing list." << endl;
                cout << endl;
                SetConsoleTextAttribute (h, 5);
                cout << "Press any key to return...";
                SetConsoleTextAttribute (h, 2);
                getch();
                return;
            }

            else
            {
                system ("cls");
                struct stat
                {
                    string time;
                    string status;
                    int stat_num; 
                };
                string loader;
                stat stat_loader;
                list <stat> list_of_status;
                account_details *viewed;
                for (auto it = accounts_list.begin(); it != accounts_list.end(); it++)
                {
                    if (uname == (*it).username)
                    {
                        viewed = &(*it);
                        break;
                    }
                }
                string filename;
                filename = "db/" + viewed -> username + ".txt";
                SetConsoleTextAttribute (h, 2);
                cout << char (218);
                for (int i = 0; i < viewed -> username.length() + 3; i++)
                {
                    cout << char(196);
                }
                cout << char (191) << endl;
                cout << char (179);
                SetConsoleTextAttribute (h, 5);
                cout << " @" << viewed-> username << " ";
                SetConsoleTextAttribute (h, 2);
                cout << char (179) << endl;
                cout << char (192);
                for (int i = 0; i < viewed -> username.length() + 3; i++)
                {
                    cout << char (196);
                }
                cout << char (217) << endl;

                cout << char (218);
                int length_var;
                length_var = viewed -> first_name.length() + viewed -> last_name.length() + 1;
                for (int i = 0; i < 16 + viewed -> first_name.length() + viewed -> last_name.length(); i++)
                {
                    cout << char (196);
                }
                cout << char (191) << endl;
                cout << char(179);
                SetConsoleTextAttribute (h, 5);
                cout << setw(12) << left << " Name" << setw(2) << ": ";
                SetConsoleTextAttribute (h, 2);
                cout << viewed -> first_name + " " << viewed -> last_name << " " << char(179)<< endl;
                cout << char (179);
                SetConsoleTextAttribute (h, 5);
                cout << setw(12) << left << " Followers" << setw(2) << ": ";
                SetConsoleTextAttribute (h, 2);
                cout << setw(length_var) << viewed -> num_of_followers<< " " << char (179) << endl;
                cout << char (179);
                SetConsoleTextAttribute (h, 5);
                cout << setw(12) << left << " Following" << setw(2) << ": ";
                SetConsoleTextAttribute (h, 2);
                cout << setw(length_var) << viewed -> num_of_following<< " " << char (179)<<endl;
                cout << char (192);
                for (int i = 0; i < 16 + viewed -> first_name.length() + viewed -> last_name.length(); i++)
                {
                    cout << char (196);
                }
                cout << char(217) << endl << endl;
                for (int i = 0; i < 60; i++)
                {
                    cout << char (196);
                }
                cout << endl << endl;

                ifstream input_status (filename);
                if (input_status.is_open())
                {
                    int counter = 1;
                    while (!input_status.eof())
                    {
                        getline (input_status, loader);
                        stat_loader.time = loader;
                        getline (input_status, loader);
                        stat_loader.status = loader;
                        stat_loader.stat_num = counter;
                        list_of_status.push_back (stat_loader);
                        counter++;
                    }
                    list_of_status.pop_back();
                    input_status.close();
                    if (list_of_status.empty())
                    {
                        SetConsoleTextAttribute (h, 4);
                        cout << "EMPTY: ";
                        SetConsoleTextAttribute (h, 14);
                        cout << "@" << viewed-> username << " hasn't posted anything." << endl << endl;
                        SetConsoleTextAttribute (h, 2);
                        for (int i = 0; i < 60; i++)
                        {
                            cout << char (196);
                        }
                        cout << endl << endl;
                        SetConsoleTextAttribute (h, 5);
                        cout << "Press any key to return...";
                        SetConsoleTextAttribute (h, 2);
                        getch();
                        return;

                    }
                    else
                    {
                        list_of_status.reverse();
                        for (auto it = list_of_status.begin(); it != list_of_status.end(); it++)
                        {
                            SetConsoleTextAttribute (h, 2);
                            cout << "  Status #" << (*it).stat_num << endl;
                            SetConsoleTextAttribute (h, 14);
                            cout << "  On " << (*it).time << endl;
                            cout << endl;
                            SetConsoleTextAttribute (h, 2);
                            cout<< "  " << (*it).status << endl << endl;
                            for (int i = 0; i < 60; i++)
                            {
                                cout << char (196);
                            }
                            cout << endl << endl;
                        }

                        cout << "  " << "Press ";
                        SetConsoleTextAttribute (h, 4);
                        cout << "'Esc'";
                        SetConsoleTextAttribute (h, 2);
                        cout << " to go back...";
                        char ch;
                        do
                        {
                            ch = getch();
                        }while (ch != 27);
                        return;
                    }
                }
                else
                {
                    SetConsoleTextAttribute (h, 4);
                    cout << "EMPTY: ";
                    SetConsoleTextAttribute (h, 14);
                    cout << "@" << viewed-> username << " hasn't posted anything." << endl << endl;
                    SetConsoleTextAttribute (h, 2);
                    for (int i = 0; i < 60; i++)
                    {
                        cout << char (196);
                    }
                    cout << endl << endl;
                    SetConsoleTextAttribute (h, 5);
                    cout << "Press any key to return...";
                    SetConsoleTextAttribute (h, 2);
                    getch();
                    return;
                }   
                
            }

            
        }
    }
    else
    {
        cout << "No user found with that username! " << endl;
    }
}

