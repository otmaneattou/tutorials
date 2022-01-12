
class Rectangle
{
private:
    double width, height;

public:
    Rectangle() : Rectangle(0.0, 0.0) {}
    Rectangle(double width, double height) : width(width), height(height) {}
    Rectangle(double width) : width(width), height(0.0) {} // Function overloading

    double computeArea() {}
    double computePerimeter() {}
    double getHeight() const {}
    double setHeight() const {}
    void setWidth(double width) {}
    ~Rectangle();
};
