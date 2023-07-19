#include "common.h"
#include "BMILogs.h"
void bmiLogMenu(bool state)
{
    cout << "\n---------------------------------------------------------------------\n";
    cout << "BMI管理\n";
    cout << "version 1.0 by 郑子睿\n\n";
    cout << "n:下一页  p:上一页  s:排序  t:设置时间格式  q:退出  ";
    cout << (state ? "g:图" : "l:列表"); 
    cout << "\n----------------------------------------------------------------------\n";
}

void bmiHistory(RECORD &records)
{
    USERDATA all;
    for (auto &i : records)
    {
        auto &record = i.second;
        Data t;
        t.time = record.time;
        t.height = record.height;
        t.weight = record.weight;
        t.bmi = record.bmi;
        t.prompt = record.prompt;
        all.push_back(t);
    }
    bmiLogSort(all, 1);
    bool state = true;
    while (1)
    {
        int sl = 0, sg = 0, increment = 10;
        string format = "Y-M-D";
        while (state)
        {
            system("clear");
            bmiLogMenu(state);
            bmiLogList(all, sl, increment, format);
            cout << "\n请输入功能对应的字母：";
            string select;
            getline(cin, select);
            if (select == "n" or select == "N")
            {
                if (sl + increment < all.size()) 
                    sl += increment;
            }
            else if (select == "p" or select == "P") 
            {
                if (sl - increment < 0) sl = 0;
                else sl -= increment;
            }
            else if (select == "s" or select == "S")
            {
                bmiSortMenu(all);
                sl = 0;
            }
            else if (select == "t" or select == "T") format = setForm();
            else if (select == "q" or select == "Q")
            {
                system("clear");
                return;
            }
            else if (select == "g" or select == "G") state = false;
        }
        while (!state)
        {
            system("clear");
            bmiLogMenu(state);
            bmiLogGraph(all, sg, increment, format);
            cout << "\n请输入功能对应的字母：";
            string select;
            getline(cin, select);
            if (select == "n" or select == "N")
            {
                if (sg + increment < all.size()) 
                    sg += increment;
            }
            else if (select == "p" or select == "P") 
            {
                if (sg - increment < 0) sg = 0;
                else sg -= increment;
            }
            else if (select == "s" or select == "S")
            {
                bmiSortMenu(all);
                sg = 0;
            }
            else if (select == "t" or select == "T") format = setForm();
            else if (select == "q" or select == "Q") 
            {
                system("clear");
                return;
            }
            else if (select == "l" or select == "L") state = true;
        }
    }
}

void bmiLogList(USERDATA &records, int start, int increment, string format)
{
    USERDATA sub(records.begin() + start, records.begin() + min(start + increment, (int)records.size()));
    int index = start;
    for (auto &record : sub)
    {
        cout << index + 1 << ". ";
        cout << setw(10) << left << parseTime(record.time, format) << ": " ; cout << record.weight << "公斤" << "（BMI：" << record.bmi << ", " << record.prompt << "）" << endl;
        index ++ ;
    }
}

void bmiLogGraph(USERDATA &records, int start, int increment, string format)
{
    USERDATA sub(records.begin() + start, records.begin() + min(start + increment, (int)records.size()));
    
    // 寻找最大的BMI值
    double maxBmi = 0.0;
    for (auto record : sub) {
        if (record.bmi > maxBmi) {
            maxBmi = record.bmi;
        }
    }

    // 定义长条的比例因子
    const int barLength = 20;
    const double scaleFactor = barLength / maxBmi;

    // 绘制条形图
    for (auto record : sub) {
        // 打印日期和BMI值
        cout << setw(10) << left << parseTime(record.time, format) << " ";
        cout << "|" << string(static_cast<int>(record.bmi * scaleFactor), '*') << " ";
        cout << record.bmi << endl;
    }
}