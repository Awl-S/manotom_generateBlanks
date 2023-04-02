#include "ReaderZGT.h"

ReaderZGT::ReaderZGT(const std::string &filename) : filename(filename)
{
    data = new zgt(0, 0, {}, {});
    ReadFile();
}

void ReaderZGT::ReadFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    size_t count = 1;
    std::string line;
    while (std::getline(file, line)) {
        if (count == 2) {
            std::istringstream(line) >> data->diameter;
        } else if (count == 4) {
            std::istringstream(line) >> data->center_hole_diameter;
        } else if (count == 6) {
            std::istringstream iss(line);
            double temp;
            while (iss >> temp) {
                data->mounting_holes.push_back(temp);
            }
        } else if (count == 8) {
            std::istringstream iss(line);
            double temp;
            while (iss >> temp) {
                data->marker_position.push_back(temp);
            }
        } else if (count == 10) {
            std::istringstream(line) >> data->font_serial_number[0] >> data->font_serial_number[1];
        } else if (count == 12) {
            std::istringstream(line) >> data->stop_position[0] >> data->stop_position[1] >> data->stop_position[2];
        }
        count++;
    }
}

void ReaderZGT::ReadJson()
{
    std::cout << "tblJ" << std::endl;
}

std::variant<tbl *, cfm *, zgt *, nbr *, location *> ReaderZGT::GetData()
{
    return data;
}

void ReaderZGT::SetFilename(const std::string &path)
{
    filename = path;
    preRead(filename);
}

void ReaderZGT::display() {
    std::cout << std::endl;
    std::cout << "диаметр заготовки:: " << data->diameter << std::endl;
    std::cout << "диаметр центрального отверстия:: " << data->center_hole_diameter << std::endl;
    std::cout << "крепежные отверстия (положение x,y от центра и диаметры):\n";
    for (const auto &i : data->mounting_holes)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "расположение мест для значков (в [мм] от центра, +y вниз, +x вправо, тип 1-середина низа,2-центр,3-по радиусу(?), место для класса точности указывается первым (нулевым)):\n";
    for (const auto &i : data->marker_position)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "Размер шрифта серийного номера\n";
    std::cout << data->font_serial_number[0] << "\t" << data->font_serial_number[1] << std::endl;
    std::cout << "положение упора r[мм], fi[град] относительно отметки 0, d[мм] диаметр упора\n";
    std::cout << data->stop_position[0] << "\t" << data->stop_position[1] << "\t" << data->stop_position[2] << std::endl;
}