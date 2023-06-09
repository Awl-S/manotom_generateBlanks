#ifndef MANOTOM_GENERATEBLANKS_READERCFM_H
#define MANOTOM_GENERATEBLANKS_READERCFM_H

#include "Reader.h"
#include <sstream>
#include "../../struct/cfm.h"

class ReaderCFM : public Reader {
    cfm *data;
    std::string filename;
public:
    ReaderCFM(const std::string &filename);
    void ReadFile() override;
    void ReadJson() override;
    std::variant<tbl *, cfm *, zgt *, nbr *, location *> GetData() override;
    void SetFilename(const std::string &path) override;
    void display() override;
};

#endif //MANOTOM_GENERATEBLANKS_READERCFM_H
