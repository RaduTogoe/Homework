#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

class Shape
{
protected:
    int side;
public:
    Shape(int side)
    {
        this->side = side;
    }
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void print() = 0;
};

class Triangle : public Shape
{
public:
    Triangle(int side) : Shape(side) {}
    double area() override
    {
        return side * side * sqrt(3) / 4;
    }
    double perimeter() override
    {
        return side * 3;
    }
    void print() override
    {
        std::cout << "Triangle with side = " << side;
    }
};

class Square : public Shape
{
public:
    Square(int side) : Shape(side) {}
    double area() override
    {
        return side * side;
    }
    double perimeter() override
    {
        return side * 4;
    }
    void print() override
    {
        std::cout << "Square with side = " << side;
    }
};

class Hexagon : public Shape
{
public:
    Hexagon(int side) : Shape(side) {}
    double area() override
    {
        return side * side * sqrt(3) / 2;
    }
    double perimeter() override
    {
        return side * 6;
    }
    void print() override
    {
        std::cout << "Hexagon with side = " << side;
    }
};

class ShapeFactory
{
    static std::shared_ptr<Shape> create_shape(int side, int nrOfSides);
};

std::shared_ptr<Shape> ShapeFactory::create_shape(int side, int nrOfSides)
{
    switch (nrOfSides)
    {
        case 3:
            return std::make_shared<Triangle>(side);
        break;
        case 4:
            return std::make_shared<Square>(side);
        break;
        case 6:
            return std::make_shared<Hexagon>(side);
        break;
        default:
            return nullptr;
    }
}

int main()
{

}