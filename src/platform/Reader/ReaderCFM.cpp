//
// Created by orys on 31.03.23.
//


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
