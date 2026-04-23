#include <iostream>
using namespace std;

class LivingBeing {
public:
    bool isAlive;

    void breathe() {
        cout << "Breathing..." << endl;
    }
};

class Animal : public LivingBeing {
public:
    string animalType;

    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    string breed;

    void bark() {
        cout << "Barking!" << endl;
    }
};

int main() {
    Dog d;

    d.isAlive = true;
    d.animalType = "Mammal";
    d.breed = "Labrador";

    d.breathe();
    d.eat();
    d.bark();

    return 0;
}