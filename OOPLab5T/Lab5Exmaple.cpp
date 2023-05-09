#include <fstream>
#include <iostream>
#include "Lab5Exmaple.h"
#include <string>
#include <cassert>

using namespace std;

//------------------------------------TASK 1-----------------------------------------
/*
class Transport { // базовий клас "Транспортний засiб"
protected:
    string brand;
    string model;
    int weight; // в кг
    int max_speed; // в км/год

public:
    Transport(string brand, string model, int weight, int max_speed)
    {
        this->brand = brand;
        this->model = model;
        this->weight = weight;
        this->max_speed = max_speed;
        cout << brand << " " << model << " створено." << endl;
    }

    virtual void printInfo()
    {
        cout << brand << " " << model << " важить " << weight << " кг i може розвивати швидкiсть до " << max_speed << " км/год." << endl;
    }

    ~Transport()
    {
        cout << brand << " " << model << " вилучено." << endl;
    }
};

class Car : public Transport { // похiдний клас "Легковий автомобiль"
protected:
    int seats;

public:
    Car(string brand, string model, int weight, int max_speed, int seats) : Transport(brand, model, weight, max_speed)
    {
        this->seats = seats;
        cout << "Це автомобiль з " << seats << " мiсцями." << endl;
    }

    void printInfo() override
    {
        cout << brand << " " << model << " важить " << weight << " кг i може розвивати швидкiсть до " << max_speed << " км/год. Це автомобiль з " << seats << " мiсцями." << endl; 
    }

    ~Car()
    {
        cout << brand << " " << model << " вилучено." << endl;
    }
};

class Truck : public Transport { // похiдний клас "Вантажний автомобiль"
protected:
    int capacity;

public:
    Truck(string brand, string model, int weight, int max_speed, int capacity) : Transport(brand, model, weight, max_speed)
    {
        this->capacity = capacity;
        cout << "Це вантажiвка з вантажопiдйомнiстю " << capacity << " кг." << endl;
    }

    void printInfo() override
    {
        cout << brand << " " << model << " важить " << weight << " кг i може розвивати швидкiсть до " << max_speed << " км/год. Це вантажiвка з вантажопiдйомнiстю " << capacity << " кг." << endl;
    }

    ~Truck()
    {
        cout << brand << " " << model << " вилучено." << endl;
    }
};

class Steamship : public Transport { // похiдний клас "Пароплав"
protected:
    int max_passengers; // максимальна кiлькiсть пасажирiв

public:
    Steamship(string brand, string model, int weight, int max_speed, int max_passengers) : Transport(brand, model, weight, max_speed)
    {
        this->max_passengers = max_passengers;
        cout << "Це пароплав, який може перевезти до " << max_passengers << " пасажирiв." << endl;
    }

    void printInfo() override
    {
        cout << brand << " " << model << " важить " << weight << " кг i може розвивати швидкiсть до " << max_speed << " км/год. Це пароплав, який може перевезти до " << max_passengers << " пасажирiв." << endl;
    }

    ~Steamship()
    {
        cout << brand << " " << model << " вилучено." << endl;
    }
};

class Plane : public Transport { // похiдний клас "Лiтак"
protected:
    int max_altitude; // максимальна висота польоту

public:
    Plane(string brand, string model, int weight, int max_speed, int max_altitude) : Transport(brand, model, weight, max_speed)
    {
        this->max_altitude = max_altitude;
        cout << "Це лiтак, який може летiти на висотi до " << max_altitude << " метрiв." << endl;
    }

    void printInfo() override
    {
        cout << brand << " " << model << " важить " << weight << " кг i може розвивати швидкiсть до " << max_speed << " км/год. Це лiтак, який може летiти на висотi до " << max_altitude << " метрiв." << endl;
    }

    ~Plane()
    {
        cout << brand << " " << model << " вилучено." << endl;
    }
};

int mainExample1()
{
    cout << "!Test:";
    cout << endl;
    Car car1("Toyota", "Corolla", 1200, 180, 5);
    car1.printInfo();
    cout << endl;
    Car car2("Audi", "A4", 1520, 220, 4);
    car2.printInfo();
    cout << endl;
    Truck truck1("MAN", "TGA", 7000, 120, 12000);
    truck1.printInfo();
    cout << endl;
    Steamship steamship1("Queen Mary", "2", 200000, 30, 2000);
    steamship1.printInfo();
    cout << endl;
    Plane plane1("Boeing", "737", 35000, 900, 10000);
    plane1.printInfo();
    cout << endl;
    cout << "!Test ended." << endl;

    int n;
    cout << "Введiть кiлькiсть транспортних засобiв: ";
    cin >> n;
    Transport** arr = new Transport * [n];

    for (int i = 0; i < n; i++) {
        int type;
        string brand, model;
        int weight, max_speed;

        cout << endl << "Введiть данi про транспортний засiб " << i + 1 << ":" << endl;
        cout << "Марка: ";
        cin >> brand;
        cout << "Модель: ";
        cin >> model;
        cout << "Вага: ";
        cin >> weight;
        cout << "Максимальна швидкiсть: ";
        cin >> max_speed;
        cout << "Тип транспорту:" << endl;
        cout << "1) Легковий автомобiль" << endl;
        cout << "2) Вантажний автомобiль" << endl;
        cout << "3) Пароплав" << endl;
        cout << "4) Лiтак" << endl;
            cout << "Виберiть тип: ";
        cin >> type;

        switch (type) {
        case 1:
            int seats;
            cout << "Кiлькiсть мiсць: ";
            cin >> seats;
            arr[i] = new Car(brand, model, weight, max_speed, seats);
            break;
        case 2:
            int capacity;
            cout << "Вантажопiдйомнiсть: ";
            cin >> capacity;
            arr[i] = new Truck(brand, model, weight, max_speed, capacity);
            break;
        case 3:
            int max_passengers;
            cout << "Максимальна кiлькiсть пасажирiв: ";
            cin >> max_passengers;
            arr[i] = new Steamship(brand, model, weight, max_speed, max_passengers);
            break;
        case 4:
            int max_altitude;
            cout << "Максимальна висота полету: ";
            cin >> max_altitude;
            arr[i] = new Plane(brand, model, weight, max_speed, max_altitude);
            break;
        default:
            cout << "Невiрний тип транспорту." << endl;
            i--;
            break;
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i]->printInfo();
    }

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
    /*Transport* arr[4]; // створюємо масив вказiвникiв на базовий клас "Транспортний засiб"

    arr[0] = new Car("Toyota", "Corolla", 1200, 200, 5);
    arr[1] = new Truck("Volvo", "FH16", 15000, 150, 20000);
    arr[2] = new Steamship("Queen Mary", "2", 80000, 50, 2000);
    arr[3] = new Plane("Boeing", "747", 450000, 900, 13000);

    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        arr[i]->printInfo();
    }

    for (int i = 0; i < 4; i++)
    {
        delete arr[i];
    }

    return 0;
}
*/

//------------------------------------TASK 2 ----------------------------------------
/*
class Wheel {
private:
    int radius;
public:
    Wheel(int r) : radius(r) {
        cout << "Колесо створено з радiусом " << r << " см." << endl;
    }
    virtual ~Wheel() {
        cout << "Колесо знищено." << endl;
    }

    int getRadius() {
        return radius;
    }
};

class Bicycle {
private:
    int numWheels;
    Wheel* wheels[2];
public:
    Bicycle(int n, int r) : numWheels(n) {
        for (int i = 0; i < n; i++) {
            wheels[i] = new Wheel(r);
        }
        cout << "Велосипед створено з " << n << " колесами." << endl;
    }
    virtual ~Bicycle() {
        for (int i = 0; i < numWheels; i++) {
            delete wheels[i];
            wheels[i] = nullptr;
        }
        cout << "Велосипед знищено." << endl;
    }

    void ride() {
        cout << "Їдемо на велосипедi з колесами радiусом " << wheels[0]->getRadius() << " см." << endl;
    }
};

class Car {
private:
    int numWheels;
    Wheel* wheels[4];
public:
    Car(int n, int r) : numWheels(n) {
        for (int i = 0; i < n; i++) {
            wheels[i] = new Wheel(r);
        }
        cout << "Автомобiль створено з " << n << " колесами." << endl;
    }
    virtual ~Car() {
        for (int i = 0; i < numWheels; i++) {
            delete wheels[i];
            wheels[i] = nullptr;
        }
        cout << "Автомобiль знищено." << endl;
    }
};

void testCode() {
    Wheel w(10);
    cout << "Радiус колеса: " << w.getRadius() << " см." << endl;

    Bicycle b(2, 20);
    b.ride();

    Car c(4, 30);
    
    int numWheelsB, radiusB, numWheelsC, radiusC;
    cout << "Введiть кiлькiсть колiс та радiус для велосипеда:\n";
    cin >> numWheelsB >> radiusB;
    Bicycle BI(numWheelsB, radiusB);
    b.ride();
    cout << "Введiть кiлькiсть колiс та радiус для автомобiля:\n";
    cin >> numWheelsC >> radiusC;
    Car Ca(numWheelsC, radiusC);
}

int mainExample2() { 
    testCode();
    return 0;
}
*/

//------------------------------------TASK 3-----------------------------------------

class Vector{
protected:
    int size;
    int* data;

public:
    Vector(int size_) : size{size_}, data{new int[size_]} {
        cout << "Vector created" << endl;
    }

    Vector(const Vector& other) : size{other.size}, data{new int[size]} {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Vector copied" << endl;
    }

    virtual ~Vector() {
        delete[] data;
        cout << "Vector destroyed" << endl;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            size = other.size;
            delete[] data;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        cout << "Vector assigned" << endl;
        return *this;
    }

    int getSize() const { return size; }

    virtual int get(int i) const { return data[i]; }

    virtual void set(int i, int value) { data[i] = value; }

    friend ostream& operator<<(ostream& os, const Vector& vec) {
        for (int i = 0; i < vec.getSize(); i++) {
            os << vec.get(i) << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Vector& vec) {
        for (int i = 0; i < vec.getSize(); i++) {
            int value;
            is >> value;
            vec.set(i, value);
        }
        return is;
    }
};

class SafeVector : public Vector {
protected:
    int lowerBound;
    int upperBound;
    int r{ 0 };

public:
    SafeVector(int size_, int lowerBound_, int upperBound_) :
        Vector{ size_ }, lowerBound{ lowerBound_ }, upperBound{ lowerBound_+size_ } {
        cout << "SafeVector created" << endl;
    }

    SafeVector(const SafeVector& other) :
        Vector{ other }, lowerBound{ other.lowerBound }, upperBound{ other.upperBound } {
        cout << "SafeVector copied" << endl;
    }

    ~SafeVector() override {
        cout << "SafeVector destroyed" << endl;
    }

    SafeVector& operator=(const SafeVector& other) {
        if (this != &other) {
            Vector::operator=(other);
            lowerBound = other.lowerBound;
            upperBound = other.upperBound;
        }
        cout << "SafeVector assigned" << endl;
        return *this;
    }

    int getLowerBound() const { return lowerBound; }

    int getUpperBound() const { return upperBound; }

    int get(int i) const override {
        if (i < lowerBound || i > upperBound) {
            cerr << "Index out of bounds" << endl;
            return this->r;
        }
        return data[i-lowerBound];
    }

    void set(int i, int value) override {
        cout << "SafeVector Generated: " << i << value << endl;
        if (value < lowerBound || value > upperBound) {
            cerr << "Index out of bounds" << endl;
            //exit(1); 
            return;
        }
        data[i] = value;
    }

    friend istream& operator>>(istream& is, SafeVector& vec) {
        int type;
        cout << "Enter type of input:\n1. Keyboard input\n2. Random input\n";
        cin >> type;
        switch (type) {
        case 1: {
            cout << "Enter values for SafeVector:\n";
            for (int i = 0; i < vec.getSize(); i++) {
                int value;
                cin >> value;
                vec.set(i, value);
            }
            cout << "SafeVector Generated: " << vec << endl;
            break;
        }
        case 2: {
            srand(0);
            for (int i = 0; i < vec.getSize(); i++) {
                int value = rand();
                vec.set(i, value);
            }
            cout << "Random SafeVector Generated: " << vec << endl;
            break;
        }
        default: {
            cerr << "Invalid input" << endl;
            exit(1);
        }
        }
        return is;
    }
};

int mainExample3() {
    // Creating Vector with keyboard input
    int size;
    cout << "Enter size of Vector: ";
    cin >> size;
    Vector vec1{ size };
    cout << "Enter values for Vector:\n";
    cin >> vec1;
    cout << "vec1: " << vec1 << endl;

    // Creating SafeVector with file input
    ifstream file{ "input.txt" };
    int lowerBound, upperBound;
    file >> size >> lowerBound >> upperBound;
    SafeVector vec2{ size, lowerBound, upperBound };
    file >> vec2;
    file.close();
    cout << "vec2: " << vec2 << endl;

    // Creating SafeVector with user input
    SafeVector vec3{ size, lowerBound, upperBound };
    cin >> vec3;
    cout << "vec3: " << vec3 << endl;

    // Copying and assigning SafeVector
    SafeVector vec4{ vec3 };
    cout << "vec4 (copied from vec3): " << vec4 << endl;
    vec4 = vec2;
    cout << "vec4 (assigned from vec2): " << vec4 << endl;

    return 0;
}




