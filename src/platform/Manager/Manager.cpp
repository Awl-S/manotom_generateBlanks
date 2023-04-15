#include "Manager.h"

 std::tuple<std::vector<tbl *>, cfm *, zgt *, nbr *> Manager::readFile(const path& pathdata, const std::string& path_tbl, const std::string& path_nbr) {
    std::vector<tbl*> data;
    for (const auto& entry : fs::directory_iterator(path_tbl)) {
        auto objectTBL = ReaderFactory::CreateReader(entry.path());
        data.push_back(std::get<tbl*>(objectTBL->GetData()));
        objectTBL->display();
    }

     if (data.empty()) {
         throw std::runtime_error("vector is empty");
     }

    auto objectCFM = ReaderFactory::CreateReader(search_directory(pathdata.cfm, data[0]->model + ".cfm"));
    auto dataCFM = std::get<cfm*>(objectCFM->GetData());
    objectCFM->display();

    auto objectZGT = ReaderFactory::CreateReader(search_directory(pathdata.zgt, dataCFM->blank + ".згт"));
    auto dataZGT = std::get<zgt*>(objectZGT->GetData());
    objectZGT->display();

    auto objectNBR = ReaderFactory::CreateReader(search_directory(pathdata.nbr, path_nbr));
    auto dataNBR = std::get<nbr*>(objectNBR->GetData());
    objectNBR->display();

    //Сортировка вектора по полю position
    std::sort(data.begin(), data.end(), [](const tbl* a, const tbl* b) {
        return a->position < b->position;
    });

    return {data, dataCFM, dataZGT, dataNBR};
}

std::string Manager::search_directory(const fs::path &dir_path, const std::string &file_name) {
    for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
        if (entry.is_regular_file()) {
            if(entry.path().filename() == file_name)
                return entry.path().string();
        }
    }
    return "-1";
}