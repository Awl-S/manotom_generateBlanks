//
// Created by orys on 16.04.23.
//

#ifndef MANOTOM_GENERATEBLANKS_READERPOINT_H
#define MANOTOM_GENERATEBLANKS_READERPOINT_H

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

std::vector<std::vector<double>> read_points_from_json(std::string filename, std::string name) {
    // Открытие файла
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    // Парсинг JSON данных
    json data;
    file >> data;

    // Поиск точек по названию
    std::vector<std::vector<double>> points;
    for (auto& item : data["points"]) {
        if (item["name"] == name) {
            double x = item["x"];
            double y = item["y"];
            points.push_back({x, y});
        }
    }

    // Закрытие файла и возврат точек
    file.close();
    return points;
}

//std::vector<std::vector<double>> points = read_points_from_json("data.json", "МП3-У");
#endif //MANOTOM_GENERATEBLANKS_READERPOINT_H
