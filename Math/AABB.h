#pragma once

namespace AABB {
    template<typename T>
    static bool inside(T x, T y, T width, T height, T checkX, T checkY){
        return checkX > x && checkY > y && checkX < x + width && checkY < y + height;
    }
}