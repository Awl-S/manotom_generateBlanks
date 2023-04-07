#ifndef MANOTOM_GENERATEBLANKS_CONVERTER_H
#define MANOTOM_GENERATEBLANKS_CONVERTER_H

#include <filesystem>
#include "string"

class Converter {

    static void copyDirectories(std::filesystem::path source, std::filesystem::path target);

public:
    static bool convert_file(const std::string &from_charset, const std::string &to_charset,
                             const std::string &input_file, const std::string &output_file);

    static void ConverterUTF(const std::string& path_in, const std::string& path_out);

    [[maybe_unused]] static void ConverterUTF(std::string path_in, std::string in_charset, std::string path_out, std::string out_charset);
};

#endif //MANOTOM_GENERATEBLANKS_CONVERTER_H
