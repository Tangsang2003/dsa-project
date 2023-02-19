#ifndef LOGGED_FUNCTIONS_HPP
#define LOGGED_FUNCTIONS_HPP
#pragma once
#include <iostream>
#include "account_details.h"

void delete_a_status (account_details logged_user);
void view_followers (account_details logged_user);
void view_following (account_details logged_user);
void view_other_profile (account_details logged_user);
#endif