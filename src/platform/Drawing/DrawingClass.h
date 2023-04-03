//
// Created by orys on 03.04.23.
//

#ifndef MANOTOM_GENERATEBLANKS_DRAWINGCLASS_H
#define MANOTOM_GENERATEBLANKS_DRAWINGCLASS_H

#include <iostream>
#include <memory>
#include <vector>

class DrawingClass {
public:
    DrawingClass() = default;
    virtual ~DrawingClass() = default;

    void setData(const std::vector<int>& data) {
        m_data = std::make_shared<std::vector<int>>(data);
    }

    
    virtual void draw() const = 0;

protected:
    std::shared_ptr<std::vector<int>> m_data;
};


#endif //MANOTOM_GENERATEBLANKS_DRAWINGCLASS_H
