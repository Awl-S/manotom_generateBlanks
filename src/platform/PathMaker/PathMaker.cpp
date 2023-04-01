#include "PathMaker.h"

void PathMaker::editJsonFile(std::string paramToEdit) {
    std::ifstream file("path.json");
    nlohmann::json jsonObj;
    file >> jsonObj;
    file.close();

    if (jsonObj.count(paramToEdit) == 0)
    {
        std::cerr << "Не существует объекта в файле\n";
        return;
    }
    std::string newValue;
    std::cout << "Введите новые значение для " << paramToEdit << ": ";
    std::cin >> newValue;

    jsonObj[paramToEdit] = newValue;
    std::ofstream("path.json") << std::setw(4) << jsonObj << std::endl;
}

void PathMaker::editJsonFile(std::string path, std::string paramToEdit) {
    std::ifstream file(path);
    nlohmann::json jsonObj;
    file >> jsonObj;
    file.close();

    if (jsonObj.count(paramToEdit) == 0)
    {
        std::cerr << "Не существует объекта в файле\n";
        return;
    }
    std::string newValue;
    std::cout << "Введите новые значение для " << paramToEdit << ": ";
    std::cin >> newValue;

    jsonObj[paramToEdit] = newValue;
    std::ofstream(path) << std::setw(4) << jsonObj << std::endl;
}