#ifndef MANOTOM_GENERATEBLANKS_TBL_H
#define MANOTOM_GENERATEBLANKS_TBL_H

#include <string>
#include <vector>

struct tbl
{
    int position;
    std::string model;                             // модель
    std::vector<std::vector<double>> measurements; // данные

    tbl(int position, const std::string &model, const std::vector<std::vector<double>> &measurements) : position(
            position),
                                                                                                        model(model), measurements(measurements) {}
};

#endif //MANOTOM_GENERATEBLANKS_TBL_H
