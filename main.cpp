#include <iostream>
#include <cstring>
#include "fstream"
#include "string"
#include "src/platform/Converter/Converter.h"
#include "src/platform/Reader/ReaderFactory.h"
#include "src/platform/PathMaker/PathMaker.h"
#include "src/struct/settings/settings.h"
#include "src/platform/Manager/Manager.h"

void start(int argc, char *argv[]){
    if(argc > 1){
        //Конвертация
        if(std::strcmp(argv[1], "-c") == 0){
            Converter::ConverterUTF(argv[2], argv[3]);
        }
        if(std::strcmp(argv[1], "-C") == 0){
            Converter::ConverterUTF(argv[2], argv[3], argv[4], argv[5]);
        }
        if(std::strcmp(argv[1], "--c") == 0){
            Converter::convert_file("WINDOWS-1251", "UTF-8", argv[2], argv[3]);
        }
        //Настройка путей
        if(std::strcmp(argv[1], "-new") == 0){
            if(argc == 2){
                PathMaker::create(); // без указания пути
            }
            else{
                PathMaker::create(argv[2]); // c указанием пути
            }
        }
        if(std::strcmp(argv[1], "-edit") == 0){
            if(std::strcmp(argv[2], "-path")==0){
                for (int i = 3; i < argc; ++i) {
                    PathMaker::editJsonFile( argv[i]); // c указанием пути
                }
            } else{
                for (int i = 2; i < argc; ++i) {
                    PathMaker::editJsonFile(argv[2], argv[i]); // c указанием пути
                }
            }
        }

        if(std::strcmp(argv[1], "-печать") == 0 || std::strcmp(argv[1], "-print") == 0){
            settings* data = new settings("", 0, 0, 0);
            data->accuracy = argv[2];
            data->color = atof(argv[3]);

            // Температура
            if(std::strcmp(argv[4], "true") == 0 || std::strcmp(argv[4], "1") == 0){
                data->temperature = true;
            }
            if(std::strcmp(argv[4], "false") == 0 || std::strcmp(argv[4], "0") == 0){
                data->temperature = false;
            }

            // Контур
            if(std::strcmp(argv[5], "true") == 0 || std::strcmp(argv[5], "1") == 0){
                data->contour = true;
            }
            if(std::strcmp(argv[5], "false") == 0 || std::strcmp(argv[5], "0") == 0){
                data->contour = false;
            }
            //путь, класс точности, bool -65, double значение цвета, bool контур
        }

        if(std::strcmp(argv[1], "-test") == 0) {
            auto obj1 = ReaderFactory::CreateReader(argv[2]);
            obj1->display();
        }
    }
    else{
        std::string line;
        std::ifstream file("help.txt");
        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
    }
}
int main(int argc, char *argv[] ){
    auto data = PathMaker::getDataStruct("/home/orys/CLionProjects/manotom_generateBlanks/cmake-build-debug/path.json");
    auto [dataVector, dataCFM, dataZGT, dataNBR] =  Manager::readFile(data, "/home/orys/Desktop/target/манометры/p4-6/");

    for (auto & i : dataVector) {
        std::cout << i->position << std::endl;
        std::cout << i->model << std::endl;
    }

//    start(argc, argv);
    return 0;
}
