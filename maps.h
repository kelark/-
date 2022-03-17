#ifndef MAP_H
#define MAP_H
#include<vector>
#include"points.h"
class maps{
    private:
        std::vector<points>initmap;
    public:
        maps();
        void printinitmap();
};
#endif