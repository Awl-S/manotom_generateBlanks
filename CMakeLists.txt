cmake_minimum_required(VERSION 3.25)
project(manotom_generateBlanks)

set(CMAKE_CXX_STANDARD 20)
set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

add_executable(${PROJECT_NAME}
        main.cpp
        src/struct/cfm.h
        src/struct/tbl.h
        src/struct/nbr.h
        src/struct/zgt.h
        src/struct/location.h
        src/struct/settings/path.h
        src/platform/Converter/Converter.cpp
        src/platform/Converter/Converter.h
        src/platform/Reader/Reader.cpp
        src/platform/Reader/Reader.h
        src/platform/Reader/ReaderCFM.cpp
        src/platform/Reader/ReaderCFM.h
        src/platform/Reader/ReaderFactory.cpp
        src/platform/Reader/ReaderFactory.h
        src/platform/Reader/ReaderNBR.cpp
        src/platform/Reader/ReaderNBR.h
        src/platform/Reader/ReaderTBL.cpp
        src/platform/Reader/ReaderTBL.h
        src/platform/Reader/ReaderZGT.cpp
        src/platform/Reader/ReaderZGT.h
        src/platform/PathMaker/PathMaker.cpp
        src/platform/PathMaker/PathMaker.h
        src/platform/Manager/Manager.cpp
        src/platform/Manager/Manager.h
        src/struct/settings/settings.h
        start.h
        test.h
        src/platform/Drawing/DrawingLibrary.cpp
        src/platform/Drawing/DrawingLibrary.h
        test.h
        src/HELP_TEXT.h
        src/platform/Reader/ModelPointsReader.cpp src/platform/Reader/ModelPointsReader.h)

#JSON
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}  PRIVATE nlohmann_json::nlohmann_json)
#Конвертация
find_package(Iconv REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Iconv::Iconv)
#PDF
find_package(unofficial-libharu CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::libharu::hpdf)

# Установка имени создаваемого файла
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "blank")