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

double string_to_double( const std::string& s )
{
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

void start(int argc, char *argv[]) {
    if (argc > 1) {
        const char* cmd = argv[1];
        // Конвертация
        if (std::strcmp(cmd, "-c") == 0) {
            Converter::ConverterUTF(argv[2], argv[3]);
        } else if (std::strcmp(cmd, "-C") == 0) {
            Converter::ConverterUTF(argv[2], argv[3], argv[4], argv[5]);
        } else if (std::strcmp(cmd, "--c") == 0) {
            Converter::convert_file("WINDOWS-1251", "UTF-8", argv[2], argv[3]);
        }
            // Настройка путей
        else if (std::strcmp(cmd, "-new") == 0) {
            const char* path = (argc == 2) ? "" : argv[2];
            PathMaker::create(path);
        } else if (std::strcmp(cmd, "-edit") == 0) {
            const char* path_arg = argv[2];
            for (int i = 3; i < argc; ++i) {
                PathMaker::editJsonFile((std::strcmp(path_arg, "-path") == 0) ? argv[i] : path_arg, argv[i]);
            }
        }
            // Печать
            //json тбл нбр ... ... ... ...
        else if (std::strcmp(cmd, "-печать") == 0 || std::strcmp(cmd, "-print") == 0) {
            std::string jsonPath = argv[2];
            std::string tblPath = argv[3];
            std::string nbrPath = argv[4];

            bool isContour = false;
            bool isTemperature = false;

            if(std::strcmp(argv[6], "true") == 0 || std::strcmp(argv[6], "1") == 0){
                isTemperature = true;
            }
            if(std::strcmp(argv[8], "true") == 0 || std::strcmp(argv[8], "1") == 0){
                isContour = true;
            }
            settings data_settings(argv[5], isTemperature, string_to_double(argv[7]), isContour);
            // путь, класс точности, bool -65, double значение цвета, bool контур
            Manager::readFile(PathMaker::getDataStruct(argv[2]), argv[3], argv[4]);
        }
            // Справка
        else if (std::strcmp(cmd, "-help") == 0) {
            std::ifstream file("help.txt");
            std::cout << file.rdbuf();
            file.close();
        }
    } else {
        std::cout << "test!" << std::endl;
//        test();
    }
}

#endif //MANOTOM_GENERATEBLANKS_START_H
