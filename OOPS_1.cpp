#include <iostream>
//? we can also import and use classes from other CPP files like this;
#include "importedClass.cpp"
using namespace std;

//? classes are user defined data types. This is how you define a class in CPP;
class Hero
{
    //* properties of a hero. all properties of a class are private by default;

public:
    string name;
    int health;
    char level;

    //? normal constructor
    Hero()
    {
        cout << "normal constructor" << endl;
    }

    //? this is called parameterised constructor and
    //? can be used to initialize objects easily
    Hero(string name, int health, char level)
    {
        cout << "constructor called" << endl;
        this->name = name;
        this->health = health;
        this->level = level;
    }

    void printName()
    {
        cout << "Your name is : " << name << endl;
    }

    void printHealth()
    {
        cout << "Your health is : " << health << endl;
    }

    //? destructor is defined using ~
    ~Hero()
    {
        cout << "destructor called" << endl;
    }
};

int main()
{
    //! static declaration of objects
    // Hero h1;
    // ImportedClass i1;

    // h1.name = "Bheem";
    // h1.health = 100;

    // h1.printHealth();
    // h1.printName();

    // //! dynamic declaration of objects
    // //* this section will be useful while learning linkedlists
    Hero *h2 = new Hero; // In this case what we have is a pointer that points to the address of h2

    // dynamically allocated objects can be dereferenced in two ways;
    (*h2).name = "Sreejith";
    h2->health = 100;
    h2->printName();

    Hero h3("Bruce Wayne", 100, 'A');
    h3.printName();

    //? copy constructor
    Hero h4(h3); // now, h4 has the same properties of that of h3
    h4.printName();

    //? dynamically initialized objects have to be deleted manually as well. This
    //? This will invoke the destructor of the class of the object.
    delete h2;

    return 0;
}