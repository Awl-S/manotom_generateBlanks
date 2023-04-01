#include "ReaderTBL.h"
#include "regex"

ReaderTBL::ReaderTBL(const std::string &filename) : filename(filename)
{
    data = new tbl(-1, "", {});
    ReadFile();
}

void ReaderTBL::ReadFile()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::string file_name = filename.substr(filename.find_last_of("/") + 1);
    std::regex pattern("\\d+");
    std::smatch matches;
    if (std::regex_search(file_name, matches, pattern))
    {
        data->position = std::stoi(matches[0]);
    }

    std::string line;
    readLineString(file);
    data->model = readLineString(file);

    std::vector<double> mnt;
    mnt.reserve(5);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        mnt.clear();
        double temp;
        while (iss >> temp)
        {
            mnt.push_back(temp);
        }
        double col2 = mnt[1];
        double col3 = mnt[2];
        data->measurements.push_back({col2, col3});
    }
}

void ReaderTBL::ReadJson()
{
    std::cout << "tblJ" << std::endl;
}

std::variant<tbl *, cfm *, zgt *, nbr *, location *> ReaderTBL::GetData()
{
    return data;
}

void ReaderTBL::SetFilename(const std::string &path)
{
    filename = path;
    preRead(filename);
}

void ReaderTBL::display() {
    std::cout << std::endl;
    std::cout << "Позиция: " << data->position << std::endl;
    std::cout << "Модель: " << data->model << std::endl;
    for (auto i : data->measurements)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
