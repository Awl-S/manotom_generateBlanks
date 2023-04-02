#ifndef MANOTOM_GENERATEBLANKS_MANAGER_H
#define MANOTOM_GENERATEBLANKS_MANAGER_H

#include <string>
#include <filesystem>
#include <algorithm>
#include "../Reader/ReaderFactory.h"
#include "../Reader/Reader.h"
#include "../../struct/settings/path.h"

namespace fs = std::filesystem;

class Manager {
    static std::string search_directory(const fs::path &dir_path, const std::string &file_name) {
        for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
            if (entry.is_regular_file()) {
                if(entry.path().filename() == file_name)
                    return entry.path().string();
            }
        }
        return "-1";
    }

public:
    static std::tuple<std::vector<tbl*>, cfm*, zgt*, nbr*> readFile(path pathdata, std::string path_tbl){

        //Включить, если все scale уникальны
//        for (const auto& entry : fs::directory_iterator(path_tbl)) {
//            auto objectTBL = ReaderFactory::CreateReader(entry.path());
//            auto dataTBL = std::get<tbl*>(objectTBL->GetData());
//            objectTBL->display();
//
//            auto objectCFM = ReaderFactory::CreateReader(search_directory(pathdata.cfm, dataTBL->model + ".cfm"));
//            auto dataCFM = std::get<cfm*>(objectCFM->GetData());
//            objectCFM->display();
//
//            auto objectZGT = ReaderFactory::CreateReader(search_directory(pathdata.zgt, dataCFM->blank + ".згт"));
//            auto dataZGT = std::get<zgt*>(objectZGT->GetData());
//            objectZGT->display();
//
//            //Отключено на время, пока не реализован класс наборов
////                std::cout << search_directory(pathdata.nbr, dataCFM->blank + ".нбр") << std::endl;
////                std::cout << dataTBL->model << std::endl;
////                auto objectNBR = ReaderFactory::CreateReader(search_directory(pathdata.nbr, dataCFM->blank + ".нбр"));
////                auto dataNBR = std::get<nbr*>(objectNBR->GetData());
//            //    objectNBR->display();
//        }

        std::vector<tbl*> data;
        for (const auto& entry : fs::directory_iterator(path_tbl)) {
            auto objectTBL = ReaderFactory::CreateReader(entry.path());
            data.push_back(std::get<tbl*>(objectTBL->GetData()));
        }

        if(data.empty() == true)
            throw std::runtime_error("vector is empty");

        auto objectCFM = ReaderFactory::CreateReader(search_directory(pathdata.cfm, data[0]->model + ".cfm"));
        auto dataCFM = std::get<cfm*>(objectCFM->GetData());

        auto objectZGT = ReaderFactory::CreateReader(search_directory(pathdata.zgt, dataCFM->blank + ".згт"));
        auto dataZGT = std::get<zgt*>(objectZGT->GetData());

        nbr* dataNBR;
        //Отключено на время, пока не реализован класс наборов
//                std::cout << search_directory(pathdata.nbr, dataCFM->blank + ".нбр") << std::endl;
//                std::cout << dataTBL->model << std::endl;
//                auto objectNBR = ReaderFactory::CreateReader(search_directory(pathdata.nbr, dataCFM->blank + ".нбр"));
//                auto dataNBR = std::get<nbr*>(objectNBR->GetData());
        //    objectNBR->display();

        //Сортировка вектора по полю position
        std::sort(data.begin(), data.end(), [](const tbl* a, const tbl* b) {
            return a->position < b->position;
        });

        return {data, dataCFM, dataZGT, dataNBR};
    }
};

#endif //MANOTOM_GENERATEBLANKS_MANAGER_H
