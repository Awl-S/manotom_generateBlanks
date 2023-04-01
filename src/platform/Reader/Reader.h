//
// Created by orys on 31.03.23.
//

#ifndef MANOTOM_GENERATEBLANKS_READER_H
#define MANOTOM_GENERATEBLANKS_READER_H

#include <string>
#include <iostream>
#include <fstream>
#include <variant>
#include "../../struct/tbl.h"
#include "../../struct/cfm.h"
#include "../../struct/zgt.h"
#include "../../struct/nbr.h"
#include "../../struct/location.h"

class Reader
{
public:
    virtual void ReadFile() = 0;
    virtual void ReadJson() = 0;
    virtual std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() = 0;
    virtual void SetFilename(const std::string &path) = 0;
    virtual void display() = 0;
    virtual ~Reader() {}

protected:
    bool DetermineFileType(const std::string &filename);

    short DetermineFileOrJson(const std::string &filename);

    void preRead(const std::string &path);

    static std::string readLineString(std::ifstream &file);
};

#endif //MANOTOM_GENERATEBLANKS_READER_H
