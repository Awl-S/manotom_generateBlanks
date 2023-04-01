//
// Created by orys on 31.03.23.
//

#ifndef MANOTOM_GENERATEBLANKS_READERTBL_H
#define MANOTOM_GENERATEBLANKS_READERTBL_H

#include "Reader.h"

class ReaderTBL : public Reader{
    tbl *data;
    std::string filename = "-1";

public:
    ReaderTBL(const std::string &filename);

    void ReadFile() override;

    void ReadJson() override;

    std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() override;

    void SetFilename(const std::string &path) override;
};


#endif //MANOTOM_GENERATEBLANKS_READERTBL_H
