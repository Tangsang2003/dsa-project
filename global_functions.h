#ifndef global_functions_h
#define global_functions_h
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "account_details.h"
void load_details();
void write_details();
void forgot_password();
void login();
void screen_one(account_details);
string get_password_for_login();
void post_status (account_details logged_user);
void view_profile (account_details logged_user);
#endif