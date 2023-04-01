#ifndef MANOTOM_GENERATEBLANKS_CFM_H
#define MANOTOM_GENERATEBLANKS_CFM_H

#include <vector>
#include "string"
#include "array"

struct cfm
{
    std::string header;        // настройки для прибора МП3:
    std::string blank;         // М3ВУ
    std::vector<double> marks; // отметки
    std::array<int, 2> format{};
    int diameter{};                       // диаметр шкалы
    std::array<double, 2> small_tick{};   // малая риска
    std::array<double, 2> big_tick{};     // большая риска
    std::array<double, 4> digital_tick{}; // цифровая риска
    int digit_height{};                   // высота цифр
    int label_height{};                   // высота класса точности
    std::string tick_mask;                // маска

    cfm(const std::string &header, const std::string &blank, const std::vector<double> &marks, const std::array<int, 2> &format,
        int diameter, const std::array<double, 2> &smallTick, const std::array<double, 2> &bigTick,
        const std::array<double, 4> &digitalTick, int digitHeight, int labelHeight, const std::string &tickMask)
            : header(header), blank(blank), marks(marks), format(format), diameter(diameter), small_tick(smallTick),
              big_tick(bigTick), digital_tick(digitalTick), digit_height(digitHeight), label_height(labelHeight),
              tick_mask(tickMask) {}
};
#endif //MANOTOM_GENERATEBLANKS_CFM_H
