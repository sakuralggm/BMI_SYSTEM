#ifndef _CLOCK_H
#define _CLOCK_H

#include <chrono>
#include <iomanip>
string time();
string setForm();
string parseTime(const string &time, const string &format);
#endif