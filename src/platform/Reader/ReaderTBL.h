#ifndef MANOTOM_GENERATEBLANKS_READERTBL_H
#define MANOTOM_GENERATEBLANKS_READERTBL_H

#include "Reader.h"

class ReaderTBL : public Reader{
    tbl *data;
    std::string filename{};
public:
    ReaderTBL(const std::string &filename);
    void ReadFile() override;
    void ReadJson() override;
    std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() override;
    void SetFilename(const std::string &path) override;
    void display() override;
};
#endif //MANOTOM_GENERATEBLANKS_READERTBL_H
