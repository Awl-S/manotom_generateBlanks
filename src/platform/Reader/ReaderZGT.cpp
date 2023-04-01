//
// Created by orys on 31.03.23.
//

#include "ReaderZGT.h"

ReaderZGT::ReaderZGT(const std::string &filename) : filename(filename)
{
    data = new zgt(0, 0, {}, {});
    ReadFile();
}

void ReaderZGT::ReadFile()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    size_t count = 1;
    std::string line;
    while (std::getline(file, line))
    {
        switch (count)
        {
            case 2:
            {
                std::istringstream(line) >> data->diameter;
                break;
            }
            case 4:
            {
                std::istringstream(line) >> data->center_hole_diameter;
                break;
            }
            case 6:
            {
                std::istringstream iss(line);
                double temp;
                while (iss >> temp)
                {
                    data->mounting_holes.push_back(temp);
                }
                break;
            }
            case 8:
            {
                std::istringstream iss(line);
                double temp;
                while (iss >> temp)
                {
                    data->marker_position.push_back(temp);
                }
                break;
            }
            case 10:{
                std::istringstream (line) >> data->font_serial_number[0] >> data->font_serial_number[1];
                break;
            }
            case 12:{
                std::istringstream (line) >> data->stop_position[0] >> data->stop_position[1] >> data->stop_position[2];
                break;
            }
        }
        count++;
    }
}

void ReaderZGT::ReadJson()
{
    std::cout << "tblJ" << std::endl;
}

std::variant<tbl *, cfm *, zgt *, nbr *, location *> ReaderZGT::GetData()
{
    return data;
}

void ReaderZGT::SetFilename(const std::string &path)
{
    filename = path;
    preRead(filename);
}