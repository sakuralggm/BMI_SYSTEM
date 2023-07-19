#ifndef _USERMANAGEMENT_H
#define _USERMANAGEMENT_H
#include <sstream>
#include <fstream>
USERINFO loadUserInfo();
void loginMenu();
void login(USERINFO &users);
void signup(USERINFO &users);
void saveUserInfo(USERINFO &users);
int loginMain(USERINFO &users);
int inputCheck(string &s);
bool containsChinese(const string& str);
#endif