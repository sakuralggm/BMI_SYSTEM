#include "common.h"
#include "BMIRecordManager.h"
bool loadRecord(string username, RECORD &records)
{
    ifstream iFile("UserData/" + username + ".txt");
    if (!iFile.is_open())
    {
        cerr << "打开用户文件失败！" << endl;
        return false;
    }
    string line;
    while (getline(iFile, line))
    {
        istringstream iss(line);
        string time, prompt;
        double bmi, height, weight;
        try {
            iss >> time >> height >> weight >> bmi >> prompt;
            records[time].time = time;
            records[time].bmi = bmi;
            records[time].height = height;
            records[time].weight = weight;
            records[time].prompt = prompt;
        }
        catch (const invalid_argument& e) {
            break;
        }
    }
    iFile.close();
    return true;
}

bool savaRecord(string username, RECORD &records)
{
    ofstream oFile("UserData/" + username + ".txt");
    if (!oFile.is_open())
    {
        cout << "\n保存用户数据失败！\n";
        return false;
    }

    for (auto &record : records)
    {
        auto &data = record.second;
        oFile << data.time << ' ' << data.height << ' ' << data.weight << ' ' << data.bmi << ' ' << data.prompt << endl;
    }
    oFile.flush();
    oFile.close();
    cout << "\n保存用户数据成功\n";
    return true;
}