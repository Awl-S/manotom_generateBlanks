#ifndef MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H
#define MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H

#include <stdexcept>
#include <utility>
#include <vector>
#include <tuple>
#include "string"
#include "hpdf.h"
#include "../../struct/tbl.h"
#include "../../struct/zgt.h"
#include "../../struct/cfm.h"
#include "../../struct/nbr.h"
#include "../../struct/location.h"
#include "../../struct/settings/settings.h"

class DrawingLibrary{
public:
    // Название файла, тбл данные, сфм, zgt, nbr
    DrawingLibrary(std::string  filename, const std::tuple<std::vector<tbl *>, cfm *, zgt *, nbr *>& dataTuple, location *locationData, const settings& data);

    ~DrawingLibrary();

//    void drawCircles(double x, double y, double radius);
//    void saveToFile();
//
//    void draw();

private:
    HPDF_Doc pdf{};
    HPDF_Page page{};
    std::string filename;
    std::vector<double>elem;
    tbl* tblData{};
    cfm* cfmData{};
    zgt* zgtData{};
    nbr* nbrData{};
    location* locData{};

    settings dataSetting;
};

#endif //MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H
