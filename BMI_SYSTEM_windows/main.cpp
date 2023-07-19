#include "common.h"
#include "DataStructure.h"
#include "UserManagement.h"
#include "UserMenu.h"
#include "BMIRecordManager.h"

USERINFO users;
string RED = "\033[31m";
string RESET = "\033[0m";
int main()
{
    users = loadUserInfo();
    loginMain(users);
    return 0;
}