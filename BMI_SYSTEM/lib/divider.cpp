#include "common.h"
#include "divider.h"

double divide(double h, double w)
{
    double bmi = w / (h * h);
    double roundedBMI = round(bmi * 10) / 10;  // 四舍五入并保留一位小数
    return roundedBMI;
}