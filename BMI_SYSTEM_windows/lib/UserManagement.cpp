#include "common.h"
#include "DataStructure.h"
#include "UserManagement.h"
#include "UserMenu.h"
USERINFO loadUserInfo()
{
    ifstream iFile("UserData/users.txt");

    if (!iFile.is_open()) 
    {
        cerr << RED << "打开用户管理文件失败！" << RESET << endl;
        exit(1);
    }
    
    string line;
    USERINFO users;
    while (getline(iFile, line))
    {
        istringstream iss(line);
        string username, password, sex, age;
        iss >> username >> password >> sex >> age;
        users[username].username = username;
        users[username].password = password;
        users[username].sex = sex;
        users[username].age = age;
    }
    iFile.close();
    return users;
}

void loginMenu()
{
    cout << "\n---------------------------------------------------------------------\n";
    cout << "BMI管理\n";
    cout << "version 1.0 by 郑子睿\n\n";
    cout << "1 登录\n";
    cout << "2 注册\n";
    cout << "0 退出系统";
    cout << "\n----------------------------------------------------------------------\n";
    cout << "请输入功能对应的数字：";
}

void login(USERINFO &users)
{
    cout << "欢迎使用登录功能，直接回车退出\n\n";
    fflush(stdin);

    while (1)
    {
        string username;
        cout << "用户名：";
        getline(cin, username);
        if (username == "") break;
        string password;
        cout << "密码：";
        getline(cin, password);
        auto info = users[username];
        if (info.password == password)
        {
            BasicInfo userInfo;
            userInfo.username = username;
            userInfo.password = password;
            userInfo.sex = info.sex;
            userInfo.age = info.age;
            system("clear");
            userMain(userInfo);
            break;
        }
        else 
            cout << RED << "\n用户名或密码错误，请重新输入，直接回车退出\n" << RESET;
    }
}


int inputCheck(string &s)
{
    istringstream iss(s);
    int cnt = 0;
    string t;
    bool isusername = true;
    while (iss >> t) 
    {   
        if (isusername && containsChinese(t)) return 1;
        isusername = false;
        cnt ++ ;
    }
    return cnt;
}

bool containsChinese(const string& str) {
    for (char ch : str) {
        // 判断Unicode编码范围是否包含中文字符的范围
        if (ch >= -127 && ch <= -1) {
            return true;
        }
    }
    return false;
}

void signup(USERINFO &users)
{
    while (1)
    {
        cout << "欢迎使用注册功能，直接回车退出\n\n";
        fflush(stdin);
        string input;
        cout << "输入格式：用户名 密码 性别 年龄，每项之间用空格隔开，每一项内不含空格，不允许中文用户名\n";
        cout << "请输入：";
        getline(cin, input);
        if (input == "") break;
        if (inputCheck(input) != 4)
        {
            system("clear");
            cout << RED << "\n输入错误，请重新输入\n\n" << RESET;
            continue;
        }
        else
        {
            string username, password, sex, age;
            istringstream iss(input);
            iss >> username >> password >> sex >> age;
            if (users.count(username))
            {
                system("clear");
                cout << RED << "用户名已存在\n" << RESET;
                continue;
            }
            ofstream oFile("UserData/" + username + ".txt");
            if (!oFile.is_open())
            {
                system("clear");
                cout << RED << "用户文件创建失败！\n" << RESET;
                continue;
            } 
            oFile.close();
            cout << "用户文件创建成功\n";
            users[username].username = username;
            users[username].password = password;
            users[username].age = age;
            users[username].sex = sex;
            cout << "注册成功！\n";
            cout << "按任意键继续..." << endl;
            getchar();
            break;
        }
    }
}

void saveUserInfo(USERINFO &users)
{
    ofstream oFile("UserData/users.txt");
    if (!oFile.is_open())
    {
        cout << RED << "\n保存用户管理数据失败！\n" << RESET;
        return;
    }

    for (auto &user : users)
    {
        auto &info = user.second;
        oFile << info.username << ' ' << info.password << ' ' << info.sex << ' ' << info.age << endl;
    }
    oFile.flush();
    oFile.close();
    cout << "\n保存成功\n";
}

int loginMain(USERINFO &users)
{
    string input;
    int select;
    while (1)
    {
        system("clear");
        loginMenu();
        getline(cin, input);
        if (input == "") 
        {
            system("clear");
            continue;
        }
        try { select = stoi(input); }
        catch (const invalid_argument& e) 
        {
            cout << RED << "\n输入错误，请重新输入!\n" << RESET;
            continue;
        }
        
        switch (select)
        {
            case 1: system("clear"); login(users); break;
            case 2: system("clear"); signup(users); break;
            case 0: saveUserInfo(users); cout << "已安全退出\n"; return 0;
            default: cout << RED << "\n输入错误，请重新输入!\n" << RESET;
        }
    }
    return 0;
}