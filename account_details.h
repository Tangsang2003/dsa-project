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
};
list <account_details> accounts_list;
#endif