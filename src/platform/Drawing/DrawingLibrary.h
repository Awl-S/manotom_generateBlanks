#ifndef MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H
#define MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H

#include "DrawingClass.h"

class DrawingLibrary : public DrawingClass {
public:
    DrawingLibrary() = default;
    ~DrawingLibrary() override = default;

    void draw() const override {
        if (m_data == nullptr) {
            std::cout << "No data to draw\n";
            return;
        }

        // Use C++ library to draw data
        std::cout << "Drawing data using the C++ library\n";
        for (const auto& datum : *m_data) {
            std::cout << datum << " ";
        }
        std::cout << "\n";
    }
};


#endif //MANOTOM_GENERATEBLANKS_DRAWINGLIBRARY_H
