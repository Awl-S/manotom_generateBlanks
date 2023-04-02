#include "ReaderCFM.h"

void ReaderCFM::ReadFile()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    size_t count = 1;
    while (std::getline(file, line))
    {
        switch (count)
        {
            case 1:
            {
                data->header = line;
                data->header.erase(0, data->header.find_first_not_of(" \t\r\n"));
                data->header.erase(data->header.find_last_not_of(" \t\r\n") + 1);
                break;
            }
            case 3:
            {
                data->blank = line;
                data->blank.erase(0, data->blank.find_first_not_of(" \t\r\n"));
                data->blank.erase(data->blank.find_last_not_of(" \t\r\n") + 1);
                break;
            }
            case 6:
            {
                std::istringstream iss(line);
                double temp;
                while (iss >> temp)
                {
                    data->marks.push_back(temp);
                }
                break;
            }
            case 8:
            {
                std::istringstream(line) >> data->format[0] >> data->format[1];
                break;
            }
            case 10:
            {
                std::istringstream(line) >> data->diameter;
                break;
            }
            case 12:
            {
                std::istringstream(line) >> data->small_tick[0] >> data->small_tick[1];
                break;
            }
            case 14:
            {
                std::istringstream(line) >> data->big_tick[0] >> data->big_tick[1];
                break;
            }
            case 16:
            {
                std::istringstream(line) >> data->digital_tick[0] >> data->digital_tick[1] >> data->digital_tick[2] >> data->digital_tick[3];
                break;
            }
            case 18:
            {
                std::istringstream(line) >> data->digit_height >> data->label_height;
                break;
            }
            case 20:
            {
                data->tick_mask = line;
                data->tick_mask.erase(0, data->tick_mask.find_first_not_of(" \t\r\n"));
                data->tick_mask.erase(data->tick_mask.find_last_not_of(" \t\r\n") + 1);
                break;
            }
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