#ifndef MANOTOM_GENERATEBLANKS_SETTINGS_H
#define MANOTOM_GENERATEBLANKS_SETTINGS_H

#include <string>

struct settings{
    std::string accuracy;
    double color;
    bool temperature;
    bool contour;

    settings(const std::string &accuracy, bool temperature, double color, bool contour) : accuracy(accuracy),
                                                                                          temperature(temperature),
                                                                                          color(color),
                                                                                          contour(contour) {}
};

#endif //MANOTOM_GENERATEBLANKS_SETTINGS_H
