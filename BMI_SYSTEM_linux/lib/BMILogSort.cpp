#include "common.h"
#include "BMILogSort.h"

bool cmp1(Data &a, Data &b)
{
    return a.time > b.time;
}
bool cmp2(Data &a, Data &b)
{
    return a.time < b.time;
}
bool cmp3(Data &a, Data &b)
{
    return a.bmi < b.bmi;
}
bool cmp4(Data &a, Data &b)
{
    return a.bmi > b.bmi;
}
bool cmp5(Data &a, Data &b)
{
    return a.weight < b.weight;
}
bool cmp6(Data &a, Data &b)
{
    return a.weight > b.weight;
}

void bmiLogSort(USERDATA &all, int select)
{
    switch (select)
    {
        case 1: sort(all.begin(), all.end(), cmp1); break;
        case 2: sort(all.begin(), all.end(), cmp2); break;
        case 3: sort(all.begin(), all.end(), cmp3); break;
        case 4: sort(all.begin(), all.end(), cmp4); break;
        case 5: sort(all.begin(), all.end(), cmp5); break;
        case 6: sort(all.begin(), all.end(), cmp6); break;
    }
}

void bmiSortMenu(USERDATA &all)
{
    system("clear");
    while (1)
    {
        cout << "\n---------------------------------------------------------------------\n";
        cout << "BMI记录可以按照以下方式排序，直接回车退出：\n\n";
        cout << "1 时间 最新（默认）" << endl;
        cout << "2 时间 最早" << endl;
        cout << "3 BMI 升序" << endl;
        cout << "4 BMI 降序" << endl;
        cout << "5 体重 升序" << endl;
        cout << "6 体重 降序" << endl;
        cout << "\n----------------------------------------------------------------------\n";
        cout << "\n请输入您想要的排序方式对应的数字：";
        
        string input;
        getline(cin, input);
        fflush(stdin);
        if (input.empty()) 
        {
            bmiLogSort(all, 1);
            return;
        }
        try 
        {
            int select = stoi(input);
            if (select >= 1 && select <= 6) 
            {
                bmiLogSort(all, select);
                return;
            }
            else
            {
                system("clear");
                cout << RED << "输入错误，请重新输入\n" << RESET;
                continue;
            }
        }
        catch (const invalid_argument& e)
        {
            system("clear");
            cout << RED << "输入错误，请重新输入\n" << RESET;
            continue;
        }
    }
}