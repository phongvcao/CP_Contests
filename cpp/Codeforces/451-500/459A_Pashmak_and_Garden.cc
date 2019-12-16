#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


template <typename T>
class Point {
    public:
        Point();
        Point(T x, T y);
        virtual ~Point();

        T getDistance(const Point<T>& point);

        T x;
        T y;
};


template <typename T>
Point<T>::Point() :
    x(),
    y()
{

}


template <typename T>
Point<T>::Point(T x, T y) :
    x(x),
    y(y)
{

}


template <typename T>
Point<T>::~Point() {

}


template <typename T>
T Point<T>::getDistance(const Point<T>& point) {
    return (T)std::sqrt(std::pow(point.x - this->x, 2) + std::pow(point.y - this->y, 2));
}


int main(int argc, char **argv) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    std::cin >> x1 >> y1 >> x2 >> y2;

    Point<int> point1(x1, y1);
    Point<int> point2(x2, y2);
    Point<int> point3;
    Point<int> point4;

    if ((point1.x == point2.x) && (point1.y == point2.y)) {
        std::cout << -1;
        return 0;
    }

    else if (point1.x == point2.x) {
        int distance = point1.getDistance(point2);

        if (point1.x + distance <= 100) {
            point3.x = point1.x + distance;
            point4.x = point1.x + distance;
        }

        else {
            point3.x = point1.x - distance;
            point4.x = point1.x - distance;
        }

        point3.y = point1.y;
        point4.y = point2.y;
    }

    else if (point1.y == point2.y) {
        int distance = point1.getDistance(point2);

        if (point1.y + distance <= 100) {
            point3.y = point1.y + distance;
            point4.y = point1.y + distance;
        }

        else {
            point3.y = point1.y - distance;
            point4.y = point1.y - distance;
        }

        point3.x = point1.x;
        point4.x = point2.x;

    }

    else {
        if (std::abs(point1.x - point2.x) == std::abs(point1.y - point2.y)) {
            point3.x = point1.x;
            point3.y = point2.y;
            point4.x = point2.x;
            point4.y = point1.y;
        }

        else {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << point3.x << " " << point3.y << " " << point4.x << " " << point4.y;

    return 0;
}
