#include "common.h"
#include "clock.h"

string time()
{
    // 获取当前系统时间
    auto currentTime = std::chrono::system_clock::now();

    // 将当前系统时间转换为时间点结构 tm
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* localTime = std::localtime(&currentTimeT);

    // 从时间点结构 tm 中获取年、月、日
    int year = localTime->tm_year + 1900; // tm_year 是从1900年开始的偏移量
    int month = localTime->tm_mon + 1; // tm_mon 的范围是 0-11，需要加 1
    int day = localTime->tm_mday;

    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year
       << std::setw(2) << std::setfill('0') << month
       << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

string setForm()
{
    system("clear");
    while (1)
    {
        cout << "\n---------------------------------------------------------------------\n";
        cout << "本系统提供一下日期格式，直接回车退出：\n\n";
        cout << "1 YYYY年M月D日" << endl;
        cout << "2 YYYY-M-D" << endl;
        cout << "3 M/D/YYYY" << endl;
        cout << "4 YYYY年MM月DD日" << endl;
        cout << "5 YYYY-MM-DD" << endl;
        cout << "6 MM/DD/YYYY";
        cout << "\n----------------------------------------------------------------------\n";
        cout << "\n请输入您想要的格式对应的数字：";
        
        string input;
        getline(cin, input);
        fflush(stdin);
        if (input.empty()) return "Y-M-D";
        try 
        {
            int select = stoi(input);
            switch (select)
            {
                case 1: return "Y年M月D日";
                case 2: return "Y-M-D";
                case 3: return "M/D/Y";
                case 4: return "YYYY年MM月DD日";
                case 5: return "YYYY-MM-DD";
                case 6: return "MM/DD/YYYY";
                default: 
                    system("clear");
                    cout << RED << "输入错误，请重新输入\n" << RESET;
                    break;
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

string parseTime(const string &time, const string &format)
{
    int year = stoi(time.substr(0, 4));
    int month = stoi(time.substr(4, 2));
    int day = stoi(time.substr(6, 2));
    
    char buffer[100]{};
    char* form = NULL;
    if (format == "Y年M月D日") sprintf(buffer, "%d年%d月%d日", year, month, day);
    else if (format == "Y-M-D") sprintf(buffer, "%d-%d-%d", year, month, day);
    else if (format == "M/D/Y") sprintf(buffer, "%d/%d/%d", month, day, year);
    else if (format == "YYYY年MM月DD日") sprintf(buffer, "%04d年%02d月%02d日", year, month, day);
    else if (format == "YYYY-MM-DD") sprintf(buffer, "%04d-%02d-%02d", year, month, day);
    else if (format == "MM/DD/YYYY") sprintf(buffer, "%02d/%02d/%04d", month, day, year);
    
    string formattedTime(buffer);
    return formattedTime;
}