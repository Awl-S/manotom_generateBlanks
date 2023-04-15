#ifndef MANOTOM_GENERATEBLANKS_START_H
#define MANOTOM_GENERATEBLANKS_START_H

#include <iostream>
#include <cstring>
#include "fstream"
#include "string"
#include "src/platform/Converter/Converter.h"
#include "src/platform/Reader/ReaderFactory.h"
#include "src/platform/PathMaker/PathMaker.h"
#include "src/struct/settings/settings.h"
#include "src/platform/Manager/Manager.h"
#include "test.h"
#include "HELP_TEXT.h"

double string_to_double( const std::string& s )
{
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

std::string time_now1(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string time = "./" + std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + "_" + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + ".pdf";
    return time;
}

void print(char* argv[]){
    // Считывание настроек
    // путь, класс точности, bool -65, double значение цвета, bool контур
    settings data_settings(argv[5], false, string_to_double(argv[7]), false);

    if(std::strcmp(argv[6], "true") == 0 || std::strcmp(argv[6], "1") == 0){
        data_settings.temperature = true;
    }
    if(std::strcmp(argv[8], "true") == 0 || std::strcmp(argv[8], "1") == 0){
        data_settings.contour = true;
    }

    auto output = Manager::readFile(PathMaker::getDataStruct(argv[2]), argv[3], argv[4]);
//    DrawingLibrary manometr(time_now(), output, data_settings);
}

void start(int argc, char *argv[]) {
    if (argc > 1) {
        const char* cmd = argv[1];
        std::map<std::string, std::function<void()>> command_map = {
                {"-c", [&]() {
                    Converter converter;
                    converter.ConvertUTF(argv[2], argv[3]);
                }},
                {"-C", [&]() {
                    Converter converter;
                    converter.ConvertUTF(argv[2], argv[3], argv[4], argv[5]);
                }},
                {"--c", [&]() {
                    Converter converter;
                    converter.ConvertUTF(argv[2], argv[3]);
                }},
                {"-new", [&]() {
                    const char* path = (argc == 2) ? "" : argv[2];
                    PathMaker::create(path);
                }},
                {"-edit", [&]() {
                    const char* path_arg = argv[2];
                    for (int i = 3; i < argc; ++i) {
                        PathMaker::editJsonFile((std::strcmp(path_arg, "-path") == 0) ? argv[i] : path_arg, argv[i]);
                    }
                }},
                {"-печать", [&]() {
                    print(argv);
                }},
                {"-print", [&]() {
                    print(argv);
                }},
                {"-help", [&]() {
                    std::cout << HELP_TEXT << std::endl;
                }},
        };

        if (command_map.contains(cmd)) {
            command_map[cmd]();
        } else {
            // Если введенная команда не найдена, запустите функцию тестирования
            test();
//            std::cout << HELP_TEXT << std::endl;

        }

    } else {
        test();
    }
}

#endif //MANOTOM_GENERATEBLANKS_START_H
