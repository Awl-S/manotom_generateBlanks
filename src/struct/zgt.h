#ifndef MANOTOM_GENERATEBLANKS_ZGT_H
#define MANOTOM_GENERATEBLANKS_ZGT_H
#include "vector"
#include "array"

struct zgt
{
    double diameter;
    double center_hole_diameter;
    std::vector<double> mounting_holes;
    std::vector<double> marker_position;
    std::array<double, 2> font_serial_number{}; // добавить
    std::array<double, 3> stop_position{}; // добавить
    zgt(double diameter, double centerHoleDiameter, const std::vector<double> &mountingHoles,
        const std::vector<double> &markerPosition) : diameter(diameter), center_hole_diameter(centerHoleDiameter),
                                                     mounting_holes(mountingHoles), marker_position(markerPosition) {}
};
#endif //MANOTOM_GENERATEBLANKS_ZGT_H
