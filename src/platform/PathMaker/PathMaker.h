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
    static void createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon, std::string path)
    {
        nlohmann::json jsonObj;
        jsonObj["nbr"] = nbr;
        jsonObj["zgt"] = zgt;
        jsonObj["cfm"] = cfm;
        jsonObj["pos"] = pos;
        jsonObj["icon"] = icon;

        // Open a file stream to the specified path
        std::ofstream file(path);

        file << std::setw(4) << jsonObj << std::endl;

        // Close the file stream
        file.close();
    }

    static void createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon)
    {
        nlohmann::json jsonObj;
        jsonObj["nbr"] = nbr;
        jsonObj["zgt"] = zgt;
        jsonObj["cfm"] = cfm;
        jsonObj["pos"] = pos;
        jsonObj["icon"] = icon;
        // Open a file stream to the specified path
        std::ofstream file("path.json");
        file << std::setw(4) << jsonObj << std::endl;
        // Close the file stream
        file.close();
    }

public:
    //Создание файла с путями
    static void create(std::string path)
    {
        std::string nbr, zgt, cfm, pos, icon;

        std::cout << "Введите nbr: ";
        std::cin >> nbr;

        std::cout << "Введите zgt: ";
        std::cin >> zgt;

        std::cout << "Введите cfm: ";
        std::cin >> cfm;

        std::cout << "Введите pos: ";
        std::cin >> pos;

        std::cout << "Введите icon: ";
        std::cin >> icon;

        createJsonFile(nbr, zgt, cfm, pos, icon, path);
    }

    static void create()
    {
        std::string nbr, zgt, cfm, pos, icon;

        std::cout << "Введите nbr: ";
        std::cin >> nbr;

        std::cout << "Введите zgt: ";
        std::cin >> zgt;

        std::cout << "Введите cfm: ";
        std::cin >> cfm;

        std::cout << "Введите pos: ";
        std::cin >> pos;

        std::cout << "Введите icon: ";
        std::cin >> icon;

        createJsonFile(nbr, zgt, cfm, pos, icon);
    }

    //Редактирование файла с путями
    static void editJsonFile(std::string path, std::string paramToEdit);

    static void editJsonFile(std::string paramToEdit);

    // Функция создания уникального объекта в json файле
    // В ходе разработки не используется, при необходимости можно использовать
//    static void newObj(nlohmann::json &jsonObj, std::string path)
//    {
//        std::string name;
//        std::string param;
//        jsonObj[name] = param;
//        std::ofstream(path) << std::setw(4) << jsonObj << std::endl;
//    }

    static auto getDataStruct(std::string filename){
        std::ifstream file(filename);
        nlohmann::json jsonObj;
        file >> jsonObj;
        file.close();
        path data;
        data.cfm = jsonObj["cfm"];
        data.icon = jsonObj["icon"];
        data.nbr = jsonObj["nbr"];
        data.zgt = jsonObj["zgt"];
        return data;
    }
};
#endif //MANOTOM_GENERATEBLANKS_PATHMAKER_H