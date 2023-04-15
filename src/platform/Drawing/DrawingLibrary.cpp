//
// Created by orys on 03.04.23.
//

#include "DrawingLibrary.h"

#include <utility>
#include <cmath>
#include <iostream>

DrawingLibrary::DrawingLibrary(std::string filename,
                               const std::tuple<std::vector<tbl *>, cfm *, zgt *, nbr *> &dataTuple,  location* locationData,
                               const settings &data) : filename(std::move(filename)) {
    dataSetting = data;
    locData = locationData;
    cfmData = std::get<1>(dataTuple);
    zgtData = std::get<2>(dataTuple);
    nbrData = std::get<3>(dataTuple);
}





























//double convertMmToPx(double mm) {
//    double inches = mm / 25.4f; // 1 inch = 25.4 mm
//    double pixelsPerInch = 160.0f; // default density is 160 dpi (1x density)
//    std::cout << "mm: " << mm << " inches: " << inches << " pixelsPerInch: " << pixelsPerInch << std::endl;
//    std::cout << "result: " << std::round(inches * pixelsPerInch) << std::endl;
//    return std::round(inches * pixelsPerInch);
//}
//
//DrawingLibrary::~DrawingLibrary() {
//    HPDF_Free(pdf);
//}
//
//void DrawingLibrary::drawCircles(double x, double y, double radius) {
//        HPDF_Page_Circle(page, x, y, radius);
//        HPDF_Page_Stroke(page);
//}
//
//void DrawingLibrary::saveToFile() {
//    HPDF_SaveToFile(pdf, filename.c_str());
//}



//void DrawingLibrary::draw() {
//    double diameter_points = 144.0 * 2.8346;
//    double radius_points = diameter_points / 2.0;
//
//    double diameter_center = 6.0 * 2.8346;
//    double radius_center = diameter_center / 2.0;
//
//    // Координаты центров кругов
//    double centers[4][2] = {
//            {radius_points+10, radius_points+10},
//            {HPDF_Page_GetWidth(page) - radius_points-10, radius_points+10},
//            {radius_points+10, HPDF_Page_GetHeight(page) - radius_points-10},
//            {HPDF_Page_GetWidth(page) - radius_points-10, HPDF_Page_GetHeight(page) - radius_points-10}
//    };
//
//    for (auto const & center : centers) {
//        double x = center[0];
//        double y = center[1];
//        drawCircles(x, y, radius_points);
//        drawCircles(x, y, radius_center);
//    }
//}
//
//
////DrawingLibrary::DrawingLibrary(const std::string &filename, tbl *tblData, cfm *cfmData, zgt *zgtData, nbr *nbrData,
////                               location *locData) : filename(filename), tblData(tblData), cfmData(cfmData),
////                                                    zgtData(zgtData), nbrData(nbrData), locData(locData) {
////    pdf = HPDF_New(nullptr, nullptr);
////    if (!pdf) {
////        throw std::runtime_error("Error creating PDF document.");
////    }
////
////    page = HPDF_AddPage(pdf);
////    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A3, HPDF_PAGE_PORTRAIT);
////    HPDF_Page_SetLineWidth(page, 1.0);
////
//////    // Устанавливаем масштаб в миллиметрах.
//////    HPDF_Page_SetHeight(page, 420);
//////    HPDF_Page_SetWidth(page, 297);
////}
