#include "common.h"
#include "DataStructure.h"
#include "divider.h"
#include "BMICalculator.h"
#include "clock.h"


void bmiCalc(RECORD &records, string age)
{
    while (1)
    {
        cout << "欢迎使用BMI登记功能，直接回车退出\n" << endl;
        fflush(stdin);
        cout << "身高（单位：m）：";
        string height;
        getline(cin, height);
        if (height == "")
        {
            cout << "\n已退出BMI登记功能" << endl;
            break;
        }
        cout << "体重（单位：kg）：";
        string weight;
        getline(cin, weight);
        double h, w;
        try 
        {
            h = stod(height);
            w = stod(weight);
            if (h >= 2.5 || w >= 594.8) 
            {
                system("clear");
                cout << RED << "输入错误，请重新输入\n" << RESET << endl;
                continue;
            }
            double bmi = divide(h, w);
            string prompt;
            double userage = stoi(age);
            prompt = bmiPrompt(bmi, userage);
            string now = time();
            if (records.count(now))
            {
                if (records[now].bmi < bmi)
                {
                    auto &t = records[now];
                    t.bmi = bmi, t.height = h, t.weight = w, t.prompt = prompt;
                }
            }
            else
            {
                records[now].bmi = bmi;
                records[now].height = h;
                records[now].weight = w;
                records[now].time = now;
                records[now].prompt = prompt;
            }
            cout << "按任意键继续..." << endl;
            getchar();
            system("clear");
            return;
        } 
        catch (const std::exception& e) 
        {
            system("clear");
            cout << RED << "输入错误，请重新输入\n" << RESET << endl;
            continue;
        }
    }
}

string bmiPrompt(double bmi, int age)
{
    cout << "你的BMI指数：" << fixed << setprecision(1) << bmi << endl;
    cout << "体重健康状况：";
    string prompt;
    if (bmi >= 40) prompt = "肥胖III级（严重肥胖）";
    else if (bmi >= 35) prompt = "肥胖II级（中度肥胖）";
    else if (bmi >= 30) prompt = "肥胖II级（轻度肥胖）";
    else if (bmi >= 25) prompt = "体重过重（肥胖前期）";
    else if (bmi >= 18.5) prompt = "体重正常";
    else if (bmi >= 16) prompt = "体重过轻（轻度消瘦）";
    else if (bmi >= 15) prompt = "体重过轻（中度消瘦）";
    else prompt = "体重过轻（严重消瘦）";
    cout << prompt << endl << endl;
    return prompt;
}