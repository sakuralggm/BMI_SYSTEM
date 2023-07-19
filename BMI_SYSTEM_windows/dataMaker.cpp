#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <set>

struct Person {
    std::string time;
    double height;
    double weight;
    double bmi;
    std::string health;
};

// 生成指定范围内的随机浮点数
double generateRandomDouble(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

// 判断健康情况
std::string determineHealth(double bmi) {
    if (bmi < 18.5) {
        return "体重过低";
    } else if (bmi < 24.9) {
        return "正常体重";
    } else if (bmi < 29.9) {
        return "超重";
    } else {
        return "肥胖";
    }
}

// 生成日期字符串
// 增加日期
std::string addDays(const std::string& date, int days) {
    std::tm tm = {};
    std::stringstream ss(date);
    ss >> std::get_time(&tm, "%Y%m%d");
    tm.tm_mday += days;
    std::mktime(&tm);
    std::stringstream result;
    result << std::put_time(&tm, "%Y%m%d");
    return result.str();
}

// 生成50行随机数据
std::vector<Person> generateData() {
    std::vector<Person> data;
    std::string currentDate = "20230101";
    for (int i = 0; i < 50; ++i) {
        Person person;
        std::string t = addDays(currentDate, 1);
        person.time = currentDate = t;
        person.height = generateRandomDouble(1.5, 2.0);  // 身高范围在1.5至2.0之间
        person.weight = generateRandomDouble(40.0, 100.0);  // 体重范围在40至100之间
        person.bmi = person.weight / (person.height * person.height);
        person.health = determineHealth(person.bmi);

        data.push_back(person);
    }

    return data;
}

// 输出数据到文件
void outputData(const std::vector<Person>& data, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const Person& person : data) {
            outputFile << person.time << " " << person.height << " " << person.weight << " "
                       << std::fixed << std::setprecision(1) << person.bmi << " " << person.health << std::endl;
        }
        outputFile.close();
        std::cout << "数据已写入文件：" << filename << std::endl;
    } else {
        std::cerr << "无法打开文件：" << filename << std::endl;
    }
}

int main() {
    std::vector<Person> data = generateData();
    outputData(data, "random_data.txt");

    return 0;
}
