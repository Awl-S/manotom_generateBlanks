#ifndef MANOTOM_GENERATEBLANKS_MANAGER_H
#define MANOTOM_GENERATEBLANKS_MANAGER_H

#include <string>
#include <filesystem>
#include <algorithm>
#include "../Reader/ReaderFactory.h"
#include "../Reader/Reader.h"
#include "../../struct/settings/path.h"

namespace fs = std::filesystem;
class Manager {
    static std::string search_directory(const fs::path &dir_path, const std::string &file_name);
public:
    static std::tuple<std::vector<tbl *>, cfm *, zgt *, nbr *> readFile(const path& pathdata, const std::string& path_tbl, const std::string& path_nbr);
};
#endif //MANOTOM_GENERATEBLANKS_MANAGER_H
