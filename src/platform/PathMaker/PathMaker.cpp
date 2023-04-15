#include "PathMaker.h"

[[maybe_unused]] void PathMaker::editJsonFile(const std::string& paramToEdit) {
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

void PathMaker::editJsonFile(const std::string& path, const std::string& paramToEdit) {
    std::ifstream file(path);
    nlohmann::json jsonObj;
    file >> jsonObj;
    file.close();

    if (jsonObj.count(paramToEdit) == 0)
    {
        std::cerr << "Не существует объекта в файле \n";
        return;
    }
    std::string newValue;
    std::cout << "Введите новые значение для " << paramToEdit << ": ";
    std::cin >> newValue;

    jsonObj[paramToEdit] = newValue;
    std::ofstream(path) << std::setw(4) << jsonObj << std::endl;
}

path PathMaker::getDataStruct(const std::string& filename) {
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

[[maybe_unused]] void PathMaker::create() {
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

void PathMaker::create(std::string path) {
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

void PathMaker::createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon) {
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

void PathMaker::createJsonFile(std::string nbr, std::string zgt, std::string cfm, std::string pos, std::string icon,
                               std::string path) {
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
