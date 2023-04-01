#include <iostream>
#include <cstring>
#include "fstream"
#include "string"
#include "src/platform/Converter/Converter.h"
#include "src/platform/Reader/ReaderFactory.h"
#include "src/platform/PathMaker/PathMaker.h"

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
    start(argc, argv);

    //PathMaker::create("path.json");
    return 0;
}
