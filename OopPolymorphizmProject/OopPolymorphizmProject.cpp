#include <iostream>
#include <vector>

class IMovable
{
public:
    virtual void Move() = 0;
};

class Animal : public IMovable
{
    std::string name;
public:
    virtual void Say() = 0;

    void SetName(std::string name)
    {
        this->name = name;
    }

    std::string GetName()
    {
        return this->name;
    }

    void Move() override
    {
        std::cout << "Moving\n";
    }
};

class Cat : public Animal
{
public:
    void Say() override
    {
        std::cout << "Myau\n";
    }

    void Eat()
    {
        std::cout << "Eating\n";
    }
};

class Dog : public Animal
{
public:
    void Say() override
    {
        std::cout << "Gaff\n";
    }

    void Sleep()
    {
        std::cout << "Sliping\n";
    }
};



class Shape
{
protected:
    std::string name;
public:
    Shape() : name{ "Shape" } {};
    std::string Name() { return name; }

    virtual double Area() = 0;
    virtual double Perimetr() = 0;
};

class Shape2D : public Shape
{

};

class Rectangle : public Shape
{
    double width;
    double height;
public:
    Rectangle(double width, double height)
        : width{ width }, height{ height } 
    {
        name = "Rectangle";
    }

    double Area() override 
    {
        return width * height;
    }
    
    double Perimetr() override
    {
        return 2 * (width + height);
    }
};

class Circle : public Shape
{
    double radius;
public:
    Circle(double radius) : radius{ radius } 
    {
        name = "Circle";
    }

    double Area() override
    {
        return 3.14 * radius * radius;
    }

    double Perimetr() override
    {
        return 2 * 3.14 * radius;
    }
};

class Ellipse : public Circle
{
public:
    double Area() override
    {
        return 100;
    }

    double Perimetr() override
    {
        return 100;
    }
};

/*
class MyClass final
{

};
class MySecondClass : public MyClass
{

};
*/



class Unit
{
    //int* obj;
public:
    Unit()
    {
        //obj = new int;
        std::cout << "Unit construct\n";
    }

    virtual ~Unit() = default;
    //{
    //    //delete obj;
    //    std::cout << "Unit destruct\n";
    //}
};

class InfantryUnit : public Unit
{
    float* fobj;
public:
    InfantryUnit()
    {
        fobj = new float;
        std::cout << "InfantryUnit construct\n";
    }

    ~InfantryUnit() override
    {
        delete fobj;
        std::cout << "InfantryUnit destruct\n";
    }
};


class Base
{
public: 
    virtual std::string GetName()
    {
        return "Base";
    }
};

class Derived : public Base
{
public:
    std::string GetName() override
    {
        return "Derived";
    }
};


class A
{
public:
    virtual void Print()
    {
        std::cout << "A\n";
    }
};

class B : public A
{
public:
    void Print() override
    {
        std::cout << "B\n";
    }
};

class C : public B
{
public:
    
};

class D : public C
{
public:
    void Print() override
    {
        std::cout << "D\n";
    }
};





int main()
{
    srand(time(nullptr));

    /*
    Cat cat;
    cat.SetName("Barsik");
    Dog dog;
    dog.SetName("Sharik");

    cat.Say();
    cat.Eat();

    dog.Say();
    dog.Sleep();

    Animal animal;
    animal = cat;
    animal.Say();
    std::cout << animal.GetName() << "\n";

    animal = dog;
    animal.Say();
    std::cout << animal.GetName() << "\n";
    */

    
    Animal* animal; // = new Animal();
    //animal->Say();

    animal = new Cat();
    animal->Say();
    dynamic_cast<Cat*>(animal)->Eat();

    animal = new Dog();
    animal->Say();
    

    //Shape* shape = new Rectangle(3, 5);

    /*
    const int size{ 10 };
    Shape* shapes[size];

    for (int i = 0; i < size; i++)
    {
        if (rand() % 10 < 5)
            shapes[i] = new Rectangle(10 + rand() % 10, 10 + rand() % 10);
        else
            shapes[i] = new Circle(10 + rand() % 10);   
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << shapes[i]->Name() << "\n";
        std::cout << "Area = " << shapes[i]->Area() << "\n";
        std::cout << "Perimetr = " << shapes[i]->Perimetr() << "\n";
        std::cout << "\n";
    }
    */

    /*Rectangle rectangle(3, 4);
    Shape shape = rectangle;
    std::cout << shape.Name() << "\n";
    std::cout << shape.Area() << "\n";*/

    /*
    Unit* unit = new Unit();
    std::cout << "\n";

    InfantryUnit* infantry = new InfantryUnit();
    std::cout << "\n";

    delete unit;
    std::cout << "\n";

    delete infantry;
    std::cout << "\n";

    Unit* unitBad = new InfantryUnit();
    delete unitBad;
    */

    /*
    Base* base = new Derived();
    std::cout << base->GetName() << "\n";
    std::cout << base->Base::GetName() << "\n";
    */

    /*
    A* aptr = new A();
    aptr->Print();

    aptr = new B();
    aptr->Print();

    aptr = new C();
    aptr->Print();

    aptr = new D();
    aptr->Print();
    */
}
