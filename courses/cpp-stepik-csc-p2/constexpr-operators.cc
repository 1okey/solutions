// Напишите constexpr бинарные операторы +, - и * (скалярное произведение) для структуры Point.
// определение структуры Point уже подключено
/* struct Point
{
    constexpr Point(double x, double y) 
        : x(x), y(y) 
    {}

    double x = 0;
    double y = 0;
};
*/

// сложение
constexpr Point operator+(const Point& p1, const Point& p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// вычитание
constexpr Point operator-(const Point& p1, const Point& p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

// скалярное произведение
constexpr double operator*(const Point& p1, const Point& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
