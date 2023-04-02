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
        else if (std::strcmp(cmd, "-печать") == 0 || std::strcmp(cmd, "-print") == 0) {
            settings data("", std::stoi(argv[2]), std::atof(argv[3]), std::strcmp(argv[4], "true") == 0 || std::strcmp(argv[4], "1") == 0);
            data.contour = std::strcmp(argv[5], "true") == 0 || std::strcmp(argv[5], "1") == 0;
            // путь, класс точности, bool -65, double значение цвета, bool контур
        }
            // Справка
        else if (std::strcmp(cmd, "-help") == 0) {
            std::ifstream file("help.txt");
            std::cout << file.rdbuf();
            file.close();
        }
    } else {
        auto data = PathMaker::getDataStruct("/home/orys/CLionProjects/manotom_generateBlanks/cmake-build-debug/path.json");
        auto [dataVector, dataCFM, dataZGT, dataNBR] =  Manager::readFile(data, "/home/orys/Desktop/target/манометры/p4-6/");
        for (auto& i : dataVector) {
            std::cout << i->position << std::endl << i->model << std::endl;
        }
    }
}

#endif //MANOTOM_GENERATEBLANKS_START_H
