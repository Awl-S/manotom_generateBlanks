#include "ModelPointsReader.h"

std::unordered_map<int, std::pair<int, int>> ModelPointsReader::get_model_points(const std::string &model_name) {
    std::unordered_map<int, std::pair<int, int>> points_map;

    for (const auto& model : json_data["models"]) {
        if (model["name"] == model_name) {
            for (const auto& point : model["points"]) {
                int number = point["number"];
                int x = point["x"];
                int y = point["y"];
                points_map[number] = std::make_pair(x, y);
            }
            break;
        }
    }

    return points_map;
}

ModelPointsReader::ModelPointsReader(const std::string &filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        throw std::invalid_argument("Не удалось открыть файл: " + filename);
    }
    input_file >> json_data;
}
