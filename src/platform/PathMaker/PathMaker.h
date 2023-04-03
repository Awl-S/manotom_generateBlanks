#ifndef MANOTOM_GENERATEBLANKS_PATHMAKER_H
#define MANOTOM_GENERATEBLANKS_PATHMAKER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "../../struct/settings/path.h"

class PathMaker {
private:
    static void createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon, std::string path);
    static void createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon);
public:
    //Создание файла с путями
    static void create(std::string path);
    [[maybe_unused]] static void create();
    //Редактирование файла с путями
    static void editJsonFile(std::string path, std::string paramToEdit);
    [[maybe_unused]] static void editJsonFile(std::string paramToEdit);
    static path getDataStruct(std::string filename);
};
#endif //MANOTOM_GENERATEBLANKS_PATHMAKER_H

// Функция создания уникального объекта в json файле
// В ходе разработки не используется, при необходимости можно использовать
//    static void newObj(nlohmann::json &jsonObj, std::string path)
//    {
//        std::string name;
//        std::string param;
//        jsonObj[name] = param;
//        std::ofstream(path) << std::setw(4) << jsonObj << std::endl;
//    }