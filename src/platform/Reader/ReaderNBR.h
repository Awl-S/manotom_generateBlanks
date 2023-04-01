//
// Created by orys on 31.03.23.
//

#ifndef MANOTOM_GENERATEBLANKS_READERNBR_H
#define MANOTOM_GENERATEBLANKS_READERNBR_H
#include "Reader.h"

class ReaderNBR  : public Reader{
    nbr *data = new nbr();
    std::string filename = "-1";

public:
    ReaderNBR(const std::string &filename);
    void ReadFile() override;
    void ReadJson() override;
    std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() override;
    void SetFilename(const std::string &path) override;

    void display() override{

    }
};


#endif //MANOTOM_GENERATEBLANKS_READERNBR_H
