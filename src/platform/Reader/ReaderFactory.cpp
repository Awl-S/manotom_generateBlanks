#include <filesystem>
#include <unordered_map>
#include "ReaderFactory.h"
#include "ReaderTBL.h"
#include "ReaderZGT.h"
#include "ReaderCFM.h"
#include "ReaderNBR.h"

short ReaderFactory::DetermineFileType(const std::string &filename)
{
    static const std::unordered_map<std::string, short> extension_map = {
            { "tbl", 1 },
            { "tbl.json", 1 },
            { "згт", 2 },
            { "згт.json", 2 },
            { "cfm", 3 },
            { "cfm.json", 3 },
            { "нбр", 4 },
            { "нбр.json", 4 }
    };

    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    auto it = extension_map.find(extension);
    if (it != extension_map.end()) {
        return it->second;
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