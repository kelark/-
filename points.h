#ifndef POINTS_H
#define POINTS_H
class points
{
    private:
        int x;int y;
    public:
    points (const int x,const int y);
    void print();
    void printcircle();
    void clear();
    void changeposition(const int x,const int y);
    bool operator==(const points &point){return point.x==this->x&&point.y==this->y;};
    int get_x(){return this->x;};
    int get_y(){return this->y;};


};
#endif