//
// Created by orys on 31.03.23.
//

#include <filesystem>
#include "ReaderFactory.h"
#include "ReaderTBL.h"
#include "ReaderZGT.h"
#include "ReaderCFM.h"
#include "ReaderNBR.h"
#include "filesystem"

short ReaderFactory::DetermineFileType(const std::string &filename_)
{
    std::filesystem::path path(filename_);
    std::filesystem::path  filename = path.stem();
    std::string extension = path.filename().string().substr(filename.string().length());

    //std::string extension = filename.substr(filename.find((".") + 1));
    std::cout << extension << std::endl;
    if (extension == "tbl" || extension == "tbl.json")
    {
        return 1;
    }
    else if (extension == "згт" || extension == "згт.json")
    {
        return 2;
    }
    else if (extension == "cfm" || extension == "cfm.json")
    {
        return 3;
    }
    else if (extension == "нбр" || extension == "нбр.json")
    {
        return 4;
    }
    return -1;
}

std::unique_ptr<Reader> ReaderFactory::CreateReader(const std::string &filename)
{
    short file_type = DetermineFileType(filename);
    // Создание соответствующего объекта FileReader
    switch (file_type)
    {
        case 1:
            return std::make_unique<ReaderTBL>(filename);
        case 2:
            return std::make_unique<ReaderZGT>(filename);
        case 3:
            return std::make_unique<ReaderCFM>(filename);
        case 4:
            return std::make_unique<ReaderNBR>(filename);
        default:
            return nullptr;
    }
}