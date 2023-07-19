#ifndef _DATASTRUCTURE_H
#define _DATASTRUCTURE_H

#include <map>
#include <vector>
struct Data
{
    double height, weight, bmi;
    string time, prompt;
};

struct BasicInfo
{
    string username, password, sex, age;
};

using USERDATA = vector<Data>;
using USERINFO = map<string, BasicInfo>;
using RECORD = map<string, Data>;
#endif