#include "common.h"
#include "DataStructure.h"
#include "BMICalculator.h"
#include "BMILogs.h"
#include "BMIRecordManager.h"

void userMenu()
{
    cout << "\n---------------------------------------------------------------------\n";
    cout << "BMI管理\n";
    cout << "version 1.0 by 郑子睿\n\n";
    cout << "1 登记BMI\n";
    cout << "2 查看历史BMI\n";
    cout << "3 切换用户/退出";
    cout << "\n----------------------------------------------------------------------\n";
    cout << "请输入功能对应的数字：";
}

void userMain(BasicInfo userInfo)
{
    RECORD records{}; 
    
    if (!loadRecord(userInfo.username, records)) return;
    
    string input;
    int select;
    while (1)
    {
        cout << "\n登录成功！";
        cout << userInfo.username << "，欢迎您。\n";
        userMenu();
        getline(cin, input);
        if (input == "")
        {
            system("clear");
            continue;
        }
        try {
            select = stoi(input);
        }
        catch (const invalid_argument& e) {
            system("clear");
            cout << RED << "\n输入错误，请重新输入!\n" << RESET;
            continue;
        }
        system("clear");
        
        switch (select)
        {
            case 1: bmiCalc(records, userInfo.age); break;
            case 2: bmiHistory(records); break;
            case 3: savaRecord(userInfo.username, records); return;
            default: 
            {
                system("clear"); 
                cout << RED << "\n输入错误，请重新输入!\n" << RESET;
                break;
            }
        }
    }
}