#ifndef MANOTOM_GENERATEBLANKS_READERFACTORY_H
#define MANOTOM_GENERATEBLANKS_READERFACTORY_H

#include <memory>
#include "Reader.h"

class ReaderFactory : public Reader
{
private:
    static short DetermineFileType(const std::string &filename);
public:
    static std::unique_ptr<Reader> CreateReader(const std::string &filename);
};

#endif //MANOTOM_GENERATEBLANKS_READERFACTORY_H
