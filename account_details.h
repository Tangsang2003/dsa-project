#ifndef account_details_h
#define account_details_h
#pragma once
#include <string>
#include <list>
using namespace std;
class account_details {
    private:
    string first_name;
    string last_name;
    string age;
    string DOB;
    string email;
    string phoneNumber;
    string username;
    string password;
    int num_of_followers = 0; 
    int num_of_following = 0;
    public:
    void get_first_name();
    void get_last_name();
    void get_details ();
    void get_date_of_birth();
    void get_age();
    void get_phonenumber();
    void get_username();
    void get_password();
    void get_email();
    //These are global functions to write and load from a file
    friend void write_details ();
    friend void load_details ();
    friend void forgot_password ();
    friend void login ();
    friend void screen_one (account_details);
    friend void post_status (account_details);
    friend void view_profile (account_details);
    friend void follow_a_friend (account_details);
    friend void search_by_name_or_email (account_details);
    friend void search_by_uname(account_details);
    friend void unfollow_a_user (account_details);
    friend void delete_a_status (account_details);
    friend void view_followers (account_details);
    friend void view_following (account_details);
    friend void view_other_profile (account_details);
};
list <account_details> accounts_list;
#endif