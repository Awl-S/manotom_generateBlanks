#include <string>
#include "Reader.h"

std::string Reader::readLineString(std::ifstream &file)
{
    std::string line;
    if (std::getline(file, line))
    {
        // Remove any leading/trailing whitespace
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
    }
    return line;
}

void Reader::preRead(const std::string &path)
{
    if (DetermineFileOrJson(path) == 0)
    {
        ReadFile();
    }
    if (DetermineFileOrJson(path) == 1)
    {
        ReadJson();
    }
}

short Reader::DetermineFileOrJson(const std::string &filename)
{
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    if (extension == "tbl" || extension == "cfm" || extension == "нбр" || extension == "згт")
    {
        return 0;
    }
    if (extension == "tbl.json" || extension == "cfm.json" || extension == "нбр.json" || extension == "згт.json")
    {
        return 1;
    }
    return -1;
}
