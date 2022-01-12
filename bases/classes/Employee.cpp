#include <iostream>

using namespace std;

class Employee
{
private:
    string name;

public:
    Employee(string name) : name{name}
    {
        cout << "Constructor: " << name << endl;
    }
    ~Employee()
    {
        std::cout << "Destructor:  " << name << std::endl;
    }
};

int main(int argc, const char **argv)
{
    static Employee belal("Belal");
    Employee most("Mostafa");
    if (true)
        Employee("Mona");
    static Employee Asmaa("Asmaa");
    return 0;
    // static variables are the last destructed variables with a stack  architecture
}