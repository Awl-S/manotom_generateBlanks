#ifndef MANOTOM_GENERATEBLANKS_CONVERTER_H
#define MANOTOM_GENERATEBLANKS_CONVERTER_H

#include <filesystem>
#include <iostream>
#include <fstream>
#include <iconv.h>
#include <string>
#include <cstring>

namespace fs = std::filesystem;

class Converter {
public:
    void ConvertUTF(const std::string& path_in, const std::string& path_out,
                    const std::string& from_charset = "WINDOWS-1251",
                    const std::string& to_charset = "UTF-8");

private:
    void copyDirectories(fs::path source, fs::path target);
    bool convertFile(const std::string& from_charset, const std::string& to_charset,
                     const std::string& input_file, const std::string& output_file);
};

#endif //MANOTOM_GENERATEBLANKS_CONVERTER_H