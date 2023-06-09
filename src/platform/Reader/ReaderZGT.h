#ifndef MANOTOM_GENERATEBLANKS_READERZGT_H
#define MANOTOM_GENERATEBLANKS_READERZGT_H

#include <sstream>

#include "Reader.h"

class ReaderZGT  : public Reader{
    zgt *data;
    std::string filename = "-1";
public:
    explicit ReaderZGT(const std::string &filename);
    void ReadFile() override;
    void ReadJson() override;
    std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() override;
    void SetFilename(const std::string &path) override;
    void display() override;
};

#endif //MANOTOM_GENERATEBLANKS_READERZGT_H
