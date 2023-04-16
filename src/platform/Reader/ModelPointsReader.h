#ifndef MANOTOM_GENERATEBLANKS_MODELPOINTSREADER_H
#define MANOTOM_GENERATEBLANKS_MODELPOINTSREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ModelPointsReader {
public:
    explicit ModelPointsReader(const std::string& filename);

    std::unordered_map<int, std::pair<int, int>> get_model_points(const std::string& model_name);

private:
    json json_data;
};

#endif //MANOTOM_GENERATEBLANKS_MODELPOINTSREADER_H

/*
    int main() {
    try {
        ModelPointsReader reader("models.json");
        auto points_map = reader.get_model_points("МП3-У");

        for (const auto& point : points_map) {
            cout << "Номер: " << point.first << ", x: " << point.second.first << ", y: " << point.second.second << endl;
        }
    } catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
    }

    return 0;
}
 */