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
            if (records.count(now) && records[now].bmi < bmi)
            {
                auto &t = records[now];
                t.bmi = bmi, t.height = h, t.weight = w, t.prompt = prompt;
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
    if (age >= 65)
    {
        if (bmi >= 28.0) prompt = "肥胖";
        else if (bmi >= 26.9) prompt = "超重";
        else if (bmi >= 20.0) prompt = "体重正常";
        else prompt = "体重过低";
    }
    else 
    {
        if (bmi >= 28.0) prompt = "肥胖";
        else if (bmi >= 24.0) prompt = "超重";
        else if (bmi >= 18.5) prompt = "超重";
        else prompt = "体重过低";
    }
    cout << prompt << endl << endl;
    return prompt;
}