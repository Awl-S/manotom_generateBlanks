#include "ReaderNBR.h"

std::variant<tbl *, cfm *, zgt *, nbr *, location *> ReaderNBR::GetData()
{
    return data;
}

void ReaderNBR::ReadJson()
{
    std::cout << "nbr JSON" << std::endl;
}

void ReaderNBR::ReadFile()
{
    std::cout << "nbr" << std::endl;
}

ReaderNBR::ReaderNBR(const std::string &filename) : filename(filename) {}

void ReaderNBR::SetFilename(const std::string &path)
{
    filename = path;
    preRead(filename);
}
