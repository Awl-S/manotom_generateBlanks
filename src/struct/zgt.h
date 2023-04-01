//
// Created by orys on 31.03.23.
//

#ifndef MANOTOM_GENERATEBLANKS_ZGT_H
#define MANOTOM_GENERATEBLANKS_ZGT_H
#include "vector"

struct zgt
{
    double diameter;
    double center_hole_diameter;
    std::vector<double> mounting_holes;
    std::vector<double> marker_position;

    zgt(double diameter, double centerHoleDiameter, const std::vector<double> &mountingHoles,
        const std::vector<double> &markerPosition) : diameter(diameter), center_hole_diameter(centerHoleDiameter),
                                                     mounting_holes(mountingHoles), marker_position(markerPosition) {}
};
#endif //MANOTOM_GENERATEBLANKS_ZGT_H
