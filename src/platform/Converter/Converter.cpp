//
// Created by orys on 31.03.23.
//

#include "Converter.h"
#include <iconv.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "filesystem"
#include <string>
namespace fs = std::filesystem;

void Converter::ConverterUTF(std::string path_in, std::string path_out)
{
    std::string from_charsets = "WINDOWS-1251";
    std::string to_charsets = "UTF-8";

    copyDirectories(path_in, path_out); // Создаем копию директории без папок.

    // Обходим все файлы.
    fs::path start_path(path_in);
    for (const auto &entry : fs::recursive_directory_iterator(path_in))
    {
        if (fs::is_regular_file(entry.path()))
        {
            auto ext = entry.path().extension();
            if (ext == ".cfm" || ext == ".tbl" || ext == ".згт")
            {
                convert_file(from_charsets, to_charsets, path_in + entry.path().string().substr(start_path.string().length()), path_out + entry.path().string().substr(start_path.string().length()));
                std::cout << entry.path().string().substr(start_path.string().length()) << '\n';
            } else{
                std::filesystem::copy(path_in + entry.path().string().substr(start_path.string().length()), path_out + entry.path().string().substr(start_path.string().length()));
            }
        }
    }
}

[[maybe_unused]] void Converter::ConverterUTF(std::string path_in, std::string in_charset, std::string path_out,
                                                     std::string out_charset)
{
    if (path_in == path_out)
    {
        std::cerr << "FILE 1 == FILE 2" << std::endl;
        return;
    }
    copyDirectories(path_in, path_out); // Создаем копию директории без папок.

    // Обходим все файлы.
    fs::path start_path(path_in);
    for (const auto &entry : fs::recursive_directory_iterator(path_in))
    {
        if (fs::is_regular_file(entry.path()))
        {
            auto ext = entry.path().extension();
            if (ext == ".cfm" || ext == ".tbl" || ext == ".згт")
            {
                convert_file(in_charset, out_charset, path_in + entry.path().string().substr(start_path.string().length()), path_out + entry.path().string().substr(start_path.string().length()));
            }
            else
            {
                std::filesystem::copy(path_in + entry.path().string().substr(start_path.string().length()), path_out + entry.path().string().substr(start_path.string().length()));
            }
        }
    }
}

void Converter::copyDirectories(std::filesystem::path source, std::filesystem::path target)
{
    fs::create_directories(target);
    // Обходим все папки в исходной директории
    for (const auto &entry : fs::directory_iterator(source))
    {
        // Проверяем, является ли путь в entry папкой
        if (fs::is_directory(entry))
        {
            // Создаем новый путь для целевой папки
            fs::path new_target_path = target / entry.path().filename();

            // Рекурсивно вызываем эту же функцию для копирования подпапок
            copyDirectories(entry, new_target_path);
        }
    }
}

bool Converter::convert_file(const std::string &from_charset, const std::string &to_charset,
                                    const std::string &input_file, const std::string &output_file)
{
    iconv_t cd = iconv_open(to_charset.c_str(), from_charset.c_str());
    if (cd == (iconv_t)-1)
    {
        std::cerr << "iconv_open error: " << strerror(errno) << std::endl;
        return false;
    }

    std::ifstream ifs(input_file.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open input file: " << strerror(errno) << std::endl;
        return false;
    }

    std::ofstream ofs(output_file.c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Failed to open output file: " << strerror(errno) << std::endl;
        return false;
    }

    // Читаем построчно из файла входного файла, конвертируем и пишем в выходной файл
    std::string line;
    while (std::getline(ifs, line))
    {
        char *inbuf = const_cast<char *>(line.c_str());
        size_t inbytesleft = line.length();
        size_t outbytesleft = inbytesleft * 4; // Максимальный размер для UTF-8
        char *outbuf = new char[outbytesleft];

        char *inptr = inbuf;
        char *outptr = outbuf;

        if (iconv(cd, &inptr, &inbytesleft, &outptr, &outbytesleft) == (size_t)-1)
        {
            std::cerr << "iconv error: " << strerror(errno) << std::endl;
            std::cerr << input_file << std::endl;
            delete[] outbuf;
            return false;
        }

        *outptr = '\0';

        ofs << outbuf << std::endl;

        delete[] outbuf;
    }

    iconv_close(cd);

    return true;
}