#include "ReaderCFM.h"

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }
    return str.substr(first, last - first + 1);
}

void ReaderCFM::ReadFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    size_t count = 1;
    while (std::getline(file, line)) {
        if (count == 1) {
            data->header = trim(line);
        } else if (count == 3) {
            data->blank = trim(line);
        } else if (count == 6) {
            std::istringstream iss(line);
            double temp;
            while (iss >> temp) {
                data->marks.push_back(temp);
            }
        } else if (count == 8) {
            std::istringstream(line) >> data->format[0] >> data->format[1];
        } else if (count == 10) {
            std::istringstream(line) >> data->diameter;
        } else if (count == 12) {
            std::istringstream(line) >> data->small_tick[0] >> data->small_tick[1];
        } else if (count == 14) {
            std::istringstream(line) >> data->big_tick[0] >> data->big_tick[1];
        } else if (count == 16) {
            std::istringstream(line) >> data->digital_tick[0] >> data->digital_tick[1] >> data->digital_tick[2] >> data->digital_tick[3];
        } else if (count == 18) {
            std::istringstream(line) >> data->digit_height >> data->label_height;
        } else if (count == 20) {
            data->tick_mask = trim(line);
        }
        count++;
    }
}

ReaderCFM::ReaderCFM(const std::string &filename)
{
    data = new cfm("", "", {}, {}, 0, {}, {}, {}, 0, 0, "");
    SetFilename(filename);
}

void ReaderCFM::ReadJson()
{
    std::cout << "tblJ" << std::endl;
}

std::variant<tbl *, cfm *, zgt *, nbr *, location *> ReaderCFM::GetData()
{
    return data;
}

void ReaderCFM::SetFilename(const std::string &path)
{
    filename = path;
    preRead(filename);
}

void ReaderCFM::display() {
    std::cout << "\n\nHeader: " << data->header << '\n';
    std::cout << "-заготовка: " << data->blank << '\n';
    std::cout << "отметки:: ";
    for (const auto &mark : data->marks)
    {
        std::cout << mark << ' ';
    }
    std::cout << '\n';
    std::cout << "формат вывода отметок:: {" << data->format[0] << ", " << data->format[1] << "}\n";
    std::cout << "диаметр шкалы внешний:: " << data->diameter << '\n';
    std::cout << "длина и толщина малой риски: {" << data->small_tick[0] << ", " << data->small_tick[1] << "}\n";
    std::cout << "длина и толщина большой риски: {" << data->big_tick[0] << ", " << data->big_tick[1] << "}\n";
    std::cout << "цифровая риска (общая длина, общая толщина, длина утолщения, толщина утолщения): {" << data->digital_tick[0] << ", " << data->digital_tick[1]
              << ", " << data->digital_tick[2] << ", " << data->digital_tick[3] << "}\n";
    std::cout << "высота цифр (мм): " << data->digit_height << '\n';
    std::cout << "высота надписи класс точности: " << data->label_height << '\n';
    std::cout << "маска вывода рисок:: " << data->tick_mask << "\n\n";
}