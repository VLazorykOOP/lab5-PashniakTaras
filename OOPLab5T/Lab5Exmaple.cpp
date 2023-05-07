#include <fstream>
#include <iostream>
#include "Lab5Exmaple.h"
#include <string>
#include <cassert>

using namespace std;

/*
3) Створити iєрархiю класiв вектор i безпечний вектор з перевiркою виходу за
межi.Безпечний вектор визначає змiннi нижня й верхня межа Перевизначити вивiд у
потiк i введення з потоку, конструктор копiювання, оператор присвоювання через
вiдповiднi функцiї базового класу.
*/

//task3
/* Vector{
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

public:
    SafeVector(int size_, int lowerBound_, int upperBound_) :
        Vector{size_}, lowerBound{lowerBound_}, upperBound{upperBound_} {
        cout << "SafeVector created" << endl;
    }

    SafeVector(const SafeVector& other) :
        Vector{other}, lowerBound{other.lowerBound}, upperBound{other.upperBound} {
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
            exit(1);
        }
        return data[i];
    }

    void set(int i, int value) override {
        cout << "SafeVector Generated: " << i << value << endl;
        if (value < lowerBound || value > upperBound) {
            cerr << "Index out of bounds" << endl;
            //exit(1);
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
    Vector vec1{size};
    cout << "Enter values for Vector:\n";
    cin >> vec1;
    cout << "vec1: " << vec1 << endl;

    // Creating SafeVector with file input
    ifstream file{"input.txt"};
    int lowerBound, upperBound;
    file >> size >> lowerBound >> upperBound;
    SafeVector vec2{size, lowerBound, upperBound};
    file >> vec2;
    file.close();
    cout << "vec2: " << vec2 << endl;

    // Creating SafeVector with user input
    SafeVector vec3{size, lowerBound, upperBound};
    cin >> vec3;
    cout << "vec3: " << vec3 << endl;

    // Copying and assigning SafeVector
    SafeVector vec4{vec3};
    cout << "vec4 (copied from vec3): " << vec4 << endl;
    vec4 = vec2;
    cout << "vec4 (assigned from vec2): " << vec4 << endl;

    return 0;
}*/

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














/*class Vector {
public:
    string Name;
    float Magnitude;

    Vector() {
    }
    Vector(string name, float magnitude) {
        this->Name = name;
        this->Magnitude = magnitude;

    }

    Vector& operator=(Vector& a) {
        this->Name = a.Name;
        this->Magnitude = a.Magnitude;
        return *this;
    }

    Vector(const Vector& ref_Point)
    {
        this->Name = ref_Point.Name;
        this->Magnitude = ref_Point.Magnitude;
    }
};

ostream& operator<<(ostream& os, Vector& n) {
    cout << " Name of Vector : " << n.Name << endl << " Magnitude: " << n.Magnitude;
    return os;
}
istream& operator>>(istream& iso, Vector& n) {
    cin >> n.Name >> n.Magnitude;
    return iso;
}

class SafeVector : public Vector {
public:
    float LowerBound, UpperBound;

    SafeVector() {
    }
    SafeVector(float lowerBound, float upperBound, string name, float magnitude) {
        this->Name = name;
        this->Magnitude = magnitude;
        this->LowerBound = lowerBound;
        this->UpperBound = upperBound;
    }

};
ostream& operator<<(ostream& os, SafeVector& n) {
    cout << "Name of Vector: " << n.Name << endl << " Magnitude: " << n.Magnitude << endl;
    cout << " Lower Bound: " << n.LowerBound << endl << " UpperBound: " << n.UpperBound << endl;
    return os;
}
istream& operator>>(istream& iso, SafeVector& n) {
    cin >> n.Name >> n.Magnitude >> n.LowerBound >> n.UpperBound;
    return iso;
}

int mainExample3() {
    float lbound, ubound;
    cout << endl << "Set lower bound of the vector:";
    cin >> lbound;
    cout << endl << "Set upper bound of the vector:";
    cin >> ubound;

    Vector obj1 = Vector("AB", 23.4);
    cout << "1: " << obj1 << endl;
    cout << endl << "New values:" << endl;
    cin >> obj1;
    cout << "New 1: " << endl << obj1 << endl;

    

    SafeVector obj2 = SafeVector(lbound, ubound, "BC", 17);
    cout << "2: " << obj2;
    cout << endl << "New values:" << endl;
    cin >> obj2;
    cout << "New 2: " << obj2 << endl;

    Vector obj3 = Vector(obj2);
    cout << "3: " << obj3 << endl;

    SafeVector obj4 = SafeVector(5, 19, "KM", 15);
    obj4 = obj4;
    cout << "New 3: " << obj3;
    return 0;
*/









    /*Vector obj1 = Vector("AB", 23.4);
    cout << "1: " << obj1 << endl;
    cout << endl << "New values:" << endl;
    cin >> obj1;
    cout << " New 1: " << obj1 << endl;

    SafeVector obj2 = SafeVector(8, 12, "BC", 17);
    cout << "2: " << obj2;
    cout << endl << "New values:" << endl;
    cin >> obj2;
    cout << "New 2: " << obj2 << endl;

    Vector obj3 = Vector(obj2);
    cout << "3: " << obj3 << endl;

    SafeVector obj4 = SafeVector(5, 19, "KM", 15);
    obj4 = obj4;
    cout << "New 3: " << obj3;
    return 0;
} */

/* namespace Exp4 {
    class Base {
        int pv;
        void fpv() {
            cout << " Base::fpv()  " << endl;
        }
    protected:
        int pt;
        void fpt() {
            cout << " Base::fpt()   " << endl;
        }
    public:
        int pb;
        void fpb() {
            cout << " Base::fpb()   " << endl;
        }
    public:
        Base() :pv(1), pb(2), pt(3) {}
        Base(int a, int b, int c) :pv(a), pb(b), pt(c) {}

        void f() {
            pv = 10;
            pt = 11;
            pb = 12;
            fpv();
            fpt();
            fpb();
        }
    };

    class Drv : public Base {    // 1)  public  2) protected 
        int dpv;
        void fdpv() {
            cout << " Drv::fdpv()   " << endl;
        }
    protected:
        int dpt;
        void fdpt() {
            cout << " Drv::fdpt()   " << endl;
        }
    public:
        int dpb;
        void fdpb() {
            cout << " Drv::fdpt()   " << endl;
        }

        Drv() : dpb(1), dpt(2), dpv(3) {}
        Drv(int a, int b, int c) :Base(a, b, c), dpv(a), dpb(b), dpt(c) {}

        void f_drv() {
            // Base
            // pv = 10; Помилка	C2248	Base::pv: неможливо звернутися до private член, оголошений  в класi "Base"	
            // fpv();   Помилка  C2248	Base::pv: неможливо звернутися до private член, оголошений  в класi "Base"	
            pt = 11;
            fpt();
            pb = 12;
            fpb();
            // Drv  -- this 
            dpv = 16;
            fdpv();
            dpt = 16;
            fdpt();
            dpb = 16;
            fdpb();
        }

    };

    class D2 : public  Drv {
        int d2pv;
        void fd2pv() {
            cout << " D2::fd2pv()   " << endl;
        }
    protected:
        int d2pt;
        void fd2pt() {
            cout << " D2::fd2pt()   " << endl;
        }
    public:
        int d2pb;
        void fd2pb() {
            cout << " D2::fd2pt()   " << endl;
        }
        D2() : d2pb(1), d2pt(2), d2pv(3) {}
        D2(int a, int b, int c) :Drv(a, b, c), d2pv(a), d2pb(b), d2pt(c) {}

        void f_d2() {
            // Base
            // pv = 10; Помилка	C2248	Base::pv: неможливо звернутися до private член, оголошений  в класi "Base"	
            // fpv();   Помилка  C2248	Base::pv: неможливо звернутися до private член, оголошений  в класi "Base"	
            pt = 11;   //  D2 : public Drv : private  Base   Помилка	C2248	Base::pt: неможливо звернутися до недоступный член, оголошений  в класi "Base"	
            fpt();     //  D2 : public Drv : private  Base   Помилка	C2248	Base::fpt: неможливо звернутися до недоступный член, оголошений  в класi "Base"		
            pb = 12;  //   D2 : public Drv : private  Base	Помилка	C2247	немає доступу до  "Base::pb", оскiльки "Drv" використовує "private" для спадкування з "Base"	
            fpb();    //   D2 : public Drv : private  Base	Помилка	C2247	немає доступу до  "Base::fpb", оскiльки "Drv" використовує "private" для спадкування з "Base"
            // Drv  
        //	dpv = 16;   Помилка	C2248	Drv::dpv: неможливо звернутися до private, объявленному в классе "Drv"	 
        //	fdpv();     Помилка	C2248	Drv::fdpv: неможливо звернутися до private, объявленному в классе "Drv"	  
            dpt = 16;
            fdpt();
            dpb = 16;
            fdpb();
        }

    };

    int Exp4main()
    {
        cout << " Base \n";
        Base obj;
        //	obj.pv = 13;	Помилка	C2248	Base::pv: неможливо звернутися до private член, оголошений  в класi "Base"	
        //	obj.fpv();  	Помилка	C2248	Base::fpv: неможливо звернутися до private член, оголошений  в класi "Base"	
        //	obj.pt = 14; 	Помилка	C2248	Base::pt: неможливо звернутися до protected член, оголошений  в класi "Base"	
        // 	obj.fpt();		Помилка	C2248	Base::fpv: неможливо звернутися до protected член, оголошений  в класi "Base"	
        obj.pb = 15;
        obj.fpb();
        cout << " f() : \n";
        obj.f();
        cout << "  end f() \n";
        cout << " Drv : public Base \n";
        Drv dobj;
        dobj.pb = 100;   // Drv : protected  Помилка	C2247	немає доступу до  "Base::pb", оскiльки "Drv" використовує "protected" для спадкування з "Base"	
        dobj.fpb();      // Drv : protected  Помилка	C2247	немає доступу до  "Base::fpb", оскiльки "Drv" використовує "protected" для спадкування з "Base"	  
        dobj.dpb = 101;
        dobj.fdpb();
        //  dobj.pv, dobj.pt, dobj.fpv(), dobj.fpt()     Помилка	C2248	Base::pv, Base::pt , ...  : неможливо звернутися до private | protected  член, оголошений  в класi "Base" 
        //	dobj.dpt = 103;  dobj.fdpt();  dobj.dpv = 103;  dobj.fdpv(); 	Помилка	C2248	Drv::dpv, ***: неможливо звернутися до private | protected член, оголошений  в класi "Drv"	
        cout << " f_drv() : \n";
        dobj.f_drv();
        cout << "  end f_drv() \n";

        cout << " D2 : public Drv \n";
        D2 d2obj;
        d2obj.pb = 200;		// Drv : protected  Помилка	C2247	немає доступу до  "Base::pb", оскiльки "Drv" використовує "protected" для спадкування з "Base"
        // D2 : public Drv : private  Base		Помилка	C2247	немає доступу до  "Base::pb", оскiльки "Drv" використовує "private" для спадкування з "Base"
        d2obj.fpb();		// Drv : protected  Помилка	C2247	немає доступу до  "Base::fpb", оскiльки "Drv" використовує "protected" для спадкування з "Base"
        //  D2 : public Drv : private  Base		Помилка	C2247	немає доступу до  "Base::fpb", оскiльки "Drv" використовує "private" для спадкування з "Base"
        d2obj.dpb = 201;    //  D2 : protected Drv : private  Base  , D2 : private Drv : private  Base
        d2obj.fdpb();       //  D2 : protected Drv : private  Base  , D2 : private Drv : private  Base 
        d2obj.d2pb = 202;
        d2obj.fd2pb();
        //  d2obj.pv, dobj.pt, d2obj.fpv(), d2obj.fpt()     Помилка	C2248	Base::pv, Base::pt , ...  : неможливо звернутися до private | protected  член, оголошений  в класi "Base" 
        //	d2obj.dpt = 103;  d2obj.fdpt();  d2obj.dpv = 103;  d2obj.fdpv(); 	Помилка	C2248	Drv::dpv, ***: неможливо звернутися до private | protected член, оголошений  в класi "Drv"	
        //	d2obj.d2pt = 103;  d2obj.fd2pt();  d2obj.d2pv = 103;  d2obj.fd2pv(); 	Помилка	C2248	D2::d2pv, ***: неможливо звернутися до private | protected член, оголошений  в класi "D2"	
        cout << " f_d2() : \n";
        d2obj.f_d2();
        cout << "  end f_d2() \n";
        return 0;
    }

}

namespace Exp5 {
    class Base {
        int data_base;
    public:
        Base() {
            cout << " Base Ctor " << endl;
        }
        Base(Base& s) {
            data_base = s.data_base;
            cout << " Base copy Ctor " << endl;
        }
        Base(int in) : data_base(in) {
            cout << " Base Ctor " << endl;
        }
        void Show() {
            cout << " Base Show " << endl;
        }
        Base& operator=(const Base& s) {
            data_base = s.data_base;
            return *this;
        }

        virtual ~Base() {
            cout << " Base Dtor " << endl;
        }
    };

    class Drv : public Base {    // 1)  public  2) protected 
        int data_drv;
    public:
        Drv() {
            cout << " Drv Ctor " << endl;
        }
        Drv(Drv& s) {
            cout << " Drv copy Ctor " << endl;
        }
        void Show() {
            cout << " Drv Show " << endl;
        }
        ~Drv() {
            cout << " Drv Dtor " << endl;
        }
        Drv& operator=(const Base& s) {
            this->Base::operator=(s);
            data_drv = 0;
            return *this;
        }

    };
    class D2 : public Drv {
        int data_drv;
    public:
        D2() {
            cout << " D2 Ctor " << endl;
        }
        D2(D2& s) {
            cout << " D2 vcopy Ctor " << endl;
        }
        void Show() {
            cout << " D2 Show " << endl;
        }
        ~D2() {
            cout << " D2 Dtor " << endl;
        }
    };
    void Proc(Base a)
    {
        a.Show();
    }
    void Proc(Base&& a)
    {
        a.Show();
    }
    void Proc(Base* a)
    {
        a->Show();
    }


    int Exp5main()
    {
        cout << " Test: The sequence of the call to \n the designers and destructors! \n";
        cout << " Createting  D2  obj \n";
        Base* pobj;
        pobj = new D2;
        cout << " D2  obj (new) is craete \n";
        cout << " Call Proc(pobj);  \n";
        Proc(pobj);
        delete pobj;
        D2 obj;
        cout << " D2  obj  is craete \n";
        cout << " Call Proc(obj);  \n";
        Proc(obj);

        cout << "\n\n Test call function  \n\n";
        Base b, * bp = &b;
        Drv  d, * dp = &d;
        D2   d2, * d2p = &d2;
        cout << "b \n";
        Proc(b);
        Proc(bp);
        cout << "d \n";
        Proc(d);
        Proc(dp);
        cout << "d2 \n";
        Proc(d2);
        Proc(d2p);
        d = b;
        return 0;
    }

}

namespace Exp2 {
    // Створити клас людина(Person), що має поля:  ПiБ(прiзвище, iм'я, по-батьковi), вiк, вага. 
// Визначити конструктори, деструктор,функцiю друку та iншi сервiснi функцiї. 
// Створити похiдний клас – повнолiтнiй(Adult), що має поле номер паспорта. 
// Визначити конструктори за замовчуванням та iз рiзним числом параметрiв, деструктори, функцiю друку. 
// Визначити функцiї перепризначення вiку та номера паспорта. 
// Написати програму тестування всiх можливостей цього класу. 
    using namespace std;
    struct PIB
    {
        string fname;
        string name;
        string lname;
        PIB() {
            fname = "NoFirstName";
            name = "NoName";
            lname = "NoLastName";
            cout << "Default constructor PIB \n";
        }
        PIB(string fn) {
            fname = "NoFirstName";
            name = fn;
            lname = "NoLastName";
            cout << "Constructor PIB(string fn) \n";
        }
        PIB(string fn[3]) {
            fname = fn[0];
            name = fn[1];
            lname = fn[2];
            cout << "Constructor PIB(string fn[]) \n";
        }
        PIB(const PIB& s) {
            fname = s.fname;
            name = s.name;
            lname = s.lname;
            cout << "Constructor Copy PIB(const PIB &) \n";
        }
        PIB(PIB&& s) {
            fname = s.fname;
            name = s.name;
            lname = s.lname;
            cout << " Constructor Move PIB(PIB &&) \n";
            s.fname = "NoFirstName";
            s.name = "NoName";
            s.lname = "NoLastName";
        }
        PIB(const char* fn, const char* n, const char* ln) {
            fname = fn;
            name = n;
            lname = ln;
            cout << " Constructor  PIB(const char * ... ) \n";
        }
        ~PIB() {
            cout << "Destructor ~PIB() \n";
        }
        PIB& operator=(const PIB& s)
        {
            fname = s.fname;
            name = s.name;
            lname = s.lname;
            cout << " PIB operator=(PIB &) \n";
            return *this;
        }

        string toString() {
            string ts = "PIB: " + fname + "  " + name + "  " + lname + " ";
            return ts;
        }
        bool operator==(PIB& b) {
            return 	name == b.name &&
                fname == b.fname && lname == b.lname ? true : false;

        }
        void Input() {
            cout << "Input fname "; cin >> fname;
            cout << "Input name ";  cin >> name;
            cout << "Input lname "; cin >> lname;
        }
        friend ostream& operator<<(ostream& os, PIB& a);
        friend istream& operator>>(istream& os, PIB& a);
    };

    ostream& operator<<(ostream& os, PIB& a) {
        os << a.fname << endl;
        os << a.name << endl;
        os << a.lname << endl;
        return os;
    }
    istream& operator>>(istream& is, PIB& a) {
        is >> a.name;
        is >> a.fname;
        is >> a.lname;
        return is;
    }

    class Person
    {
    protected:
        int age, weight;
        PIB name;
    public:
        Person() {
            age = 0;
            weight = 0;
            cout << " Default constructor   Person() \n";
        }
        Person(int a, int w, string n) {
            age = a;
            weight = w;
            name = n;
            cout << " Constructor  Person(int a, int w, string n) \n";
        }
        Person(int a, int w, PIB& n) {
            age = a;
            weight = w;
            name = n;
            cout << " Constructor  Person(int a, int w, PIB n) \n";
        }
        ~Person()
        {
            cout << "\tDestructor Person\n";
        }
        void setAge(int a) {
            if (a >= 0 && a <= 200)
                age = a;
            else
                cout << "Age " << a << " not allow,  age is " << age << endl;;
        }
        void setWeight(int w) {
            if (w <= 0 || w > 300)
                weight = w;
            else
                cout << "Weight " << w << " not exist,  weight is " << weight << endl;;
        }
        string toString() {
            string r, a, w;
            a = to_string(age);
            w = to_string(weight);
            r = name.toString() + " age: " + a + " weight: " + w;
            return r;
        }
        void Input() {
            name.Input();
            cout << "Input age ";  while (!(cin >> age) || (age < 0 || age > 200)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input age is 1 to 200 \n";
            };
            cout << "Input weight ";  while (!(cin >> weight) || (weight < 0 || weight > 300)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input weight is 1 to 300 \n";
            };
        }

        friend ostream& operator<<(ostream& os, Person& a);
        friend istream& operator>>(istream& os, Person& a);
    };

    ostream& operator<<(ostream& os, Person& a) {
        os << a.name;
        os << a.age << endl;
        os << a.weight << endl;
        return os;
    }
    istream& operator>>(istream& is, Person& a) {
        is >> a.name;
        is >> a.age;
        is >> a.weight;
        return is;
    }

    class Adult : public Person {
        long long ID;
    public:
        Adult() {
            ID = 0;
            cout << " Default constructor   Adult() \n";
        }
        Adult(int a, int w, string n, long long i) :
            Person(a, w, n) {
            ID = i;
            cout << " Constructor  Adult(int a, int w, string n, long long i) \n";
        }
        Adult(int a, int w, PIB& pib, long long i) :
            Person(a, w, pib) {
            ID = i;
            cout << " Constructor  Adult(int a, int w, PIB& pib, long long i) \n";
        }
        ~Adult() {
            cout << "\tDestructor Adult\n";
        }

        void setID(long long i) {
            if (i > 0) 	ID = i;
            else ID = 0;
        }
        string toString() {
            string sID;
            sID = to_string(ID);
            string s = Person::toString() + " ID: " + sID + ".\n ";
            return s;
        }
        void Input() {
            Person::Input();
            cout << "Input ID ";
            while (!(cin >> ID) || ID < 0) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input ID  \n";
            };
        }
        void Output() {
            cout << toString() << endl;
        }

        friend ostream& operator<<(ostream& os, Adult& a);
        friend istream& operator>>(istream& os, Adult& a);
    };

    ostream& operator<<(ostream& os, Adult& a) {
        os << a.name;
        os << a.age << endl;
        os << a.weight << endl;
        os << a.ID << endl;
        return os;
    }
    istream& operator>>(istream& is, Adult& a) {
        is >> a.name;
        is >> a.age;
        is >> a.weight;
        is >> a.ID;
        return is;
    }

    int Exp2main() {
        setlocale(LC_CTYPE, "ukr");  // для виведення умови задачi 
        cout << "Приклад задачi для лаб. роботи №5 \n";
        cout << "Створити клас людина(Person), що має поля: \n";
        cout << "  ПiБ(прiзвище, iм'я, по-батьковi), вiк, вага. \n";
        cout << " Визначити конструктори, деструктор,функцiю друку \n";
        cout << "  та iншi сервiснi функцiї. \n";
        cout << " Створити похiдний клас – повнолiтнiй(Adult),\n";
        cout << "  що має поле номер паспорта. \n";
        cout << " Визначити конструктори за замовчуванням та iз \n";
        cout << "  рiзним числом параметрiв, деструктори, функцiю друку. \n";
        cout << " Визначити функцiї перепризначення вiку та номера паспорта. \n";
        cout << "Написати програму тестування всiх можливостей цього класу. \n";

        char Choice = 'n';
        do {
            cout << "\n\n\n Main menu \n";
            cout << "1 - Default constructor Adult \n";
            cout << "2 - Default constructor Adult input  \n";
            cout << "3 - Constructor Adult  Adult(int a, int w, PIB pib, long long i)   \n";
            cout << "4 - Set age   \n";
            cout << "5 - Set ID   \n";
            cout << "6 - Input from file   \n";
            cout << "7 - Input array of  Adult and save file   \n";
            cout << "q - Quit  \n";
            cout << "Ваш вибiр (you choice ): ";
            cin >> Choice;
            switch (Choice)
            {
            case '1': {
                Adult test;
                cout << test.toString() << "  \n";
            }
                    break;
            case '2': {
                Adult test;
                cout << " Введiть :  Прiзвище iмя По-батьковi вiк вага ID  (ПiБ - Англ. мовою)  \n";
                test.Input();
                cout << " Введено " << test.toString() << "  \n";
            }
                    break;
            case '3': {
                PIB pib("Zuzak", "Boris", "Petrovich");
                Adult t(30, 50, pib, 2323190);
                string rez = t.toString();
                cout << rez;
            }
                    break;
            case '4': {
                PIB pib("Zuzak", "Boris", "Petrovich");
                Adult t(30, 50, pib, 2323190);
                t.toString();
                cout << t.toString() << endl;
                cout << " Input new age Boris  ";
                int newAge;
                while (!(cin >> newAge)) {
                    cin.clear();
                    cin.ignore(MAXSHORT, '\n');
                    fflush(stdin);
                    cout << "bad  input  \n";
                };
                t.setAge(newAge);
                cout << " New recoeds " << t.toString() << endl;
            }
                    break;
            case '5': {
                PIB pib("Zuzak", "Boris", "Petrovich");
                Adult t(30, 50, pib, 2323190);
                t.toString();
                cout << t.toString() << endl;
                cout << " Input new Id Boris  ";
                long long newId;
                while (!(cin >> newId)) {
                    cin.clear();
                    cin.ignore(MAXSHORT, '\n');
                    fflush(stdin);
                    cout << "bad  input  \n";
                };
                t.setID(newId);
                cout << " New recoeds " << t.toString() << endl;
            }
                    break;
            case '6': {
                ifstream fileAdult("fileAdult.txt");
                int n, i;
                fileAdult >> n;
                if (n > 0)
                {
                    Adult* pMas;
                    pMas = new Adult[n];
                    for (i = 0; i < n; i++)
                        fileAdult >> pMas[i];
                    cout << "Adult in file \n";
                    for (i = 0; i < n; i++)
                        cout << pMas[i].toString() << endl;
                    cout << " delete \n";
                    delete[] pMas;
                }
            }
                    break;
            case '7': {
                ofstream fileAdult("fileAdult1.txt");
                int n, i;
                cout << " Input num Adult ";
                while (!(cin >> n) || n < 0) {
                    cin.clear();
                    cin.ignore(MAXSHORT, '\n');
                    fflush(stdin);
                    cout << "bad  input num  \n";
                };

                Adult* pMas;
                pMas = new Adult[n];

                for (i = 0; i < n; i++)
                    pMas[i].Input();

                cout << "Adult in input e \n";
                for (i = 0; i < n; i++)
                    cout << pMas[i].toString() << endl;

                fileAdult << n << endl;
                for (i = 0; i < n; i++)
                    fileAdult << pMas[i];
                cout << "Adult save in file \n";
                cout << " delete \n";
                delete[] pMas;
            }
            case 'q': break;
            default:
                cout << " ???  Choice {1,2, ..., 7 or q}  \n";
            }
        } while (Choice != 'q');
        cout << " Exit from test! Bye! \n";
        return 0;
    }

}

int ObjInner::n_objinner = 0;
int Base::InnerBase::n_innerbase = 100;

int mainExample1() {

    /// <summary>
    /// 
    ///         
    ///        
    /// </summary>
    /// <returns></returns>
    cout << " Test: The sequence of the call to \n the designers and destructors! \n";
    ObjInner inobj;
    ObjInner2 inobj2;
    ObjInner3 inobj3;
    cout << " Createting  base  o \n";
    Base o(inobj3, inobj, inobj2);
    cout << " Createting  D2  obj \n";
    D2 obj(inobj, inobj2);
    cout << " D2  obj  is craete \n";
    return 2;
}
    /// <summary>
    /// Приклад задачi 2-3  для лаб. роботи №5       
    /// </summary>
    /// <returns></returns>

int mainExample2() {
    setlocale(LC_CTYPE, "ukr");  // для виведення умови задачi 
    cout << "Задача 2" << endl;
    cout << "Приклад задачi 2-3  для лаб. роботи №5\n";
    cout << " Створити клас людина(Person), що має  динамiчне поле \n";
    cout << " - ПiБ(прiзвище, iм'я, по-батьковi) та поля : вiк, вага. \n";
    cout << " Створити похiдний клас – повнолiтнiй(Adult), ";
    cout << "  що має поле номер паспорта, кiлькiсть дiтей, \n";
    cout << " динамiчне поле iмена дiтей. \n";
    cout << " Визначити конструктори за замовчуванням, \n";
    cout << "  конструктори iз рiзним числом параметрiв, \n";
    cout << " Визначити конструктори за замовчуванням та iз \n";
    cout << "  конструктори копiювання та перенесення, \n";
    cout << " оператори та  присвоювання та перенесення\n";
    cout << " , деструктори, 	функцiю друку та  iншi сервiснi функцiї. \n";
    cout << "Написати програму тестування всiх можливостей цього класу. \n";

    char Choice = 'n';
    do {
        cout << "\n \n \n  Main menu \n";
        cout << "1 -  Default constructor Adult \n";
        cout << "2 -  Default constructor Adult input  \n";
        cout << "3 -  Constructor Adult  Adult(int a, int w, PIB pib, long long i)   \n";
        cout << "4 -  Set age   \n";
        cout << "5 -  Set ID   \n";
        cout << "6 -  Input from file   \n";
        cout << "7 -  Input array of  Adult and save file   \n";
        cout << "8 -  Consructor Copy & operator=   \n";
        cout << "9 -  Consructor Move & move operator=  \n";
        cout << "q -   вихiд  \n";
        cout << "Ваш вибiр (you choice ): ";
        cin >> Choice;
        switch (Choice)
        {
        case '1': {
            Adult test;
            cout << test.toString() << "  \n";
        }
                break;
        case '2': {
            Adult test;
            cout << " Введiть :  Прiзвище iмя По-батьковi вiк вага ID  (ПiБ - Англ. мовою)  \n";
            test.Input();
            cout << " Введено " << test.toString() << "  \n";
        }
                break;
        case '3': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            string nameC[] = { "Masha","Sacha","Dasha" };
            Adult t(30, 50, pib, 2323190, 3, nameC);
            cout << t.toString() << endl;

        }
                break;
        case '4': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            string nameC[] = { "Masha","Sacha","Dasha" };
            Adult t(30, 50, pib, 2323190, 3, nameC);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new age Boris  ";
            int newAge;
            while (!(cin >> newAge)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input  \n";
            };
            t.setAge(newAge);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;
        case '5': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            string nameC[] = { "Masha","Sacha","Dasha" };
            Adult t(30, 50, pib, 2323190, 3, nameC);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new Id Boris  ";
            long long newId;
            while (!(cin >> newId)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input  \n";
            };
            t.setID(newId);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;
        case '6': {
            ifstream fileAdult("fileAdultChild.txt");
            int n, i;
            fileAdult >> n;
            if (n > 0)
            {
                Adult* pMas;
                pMas = new Adult[n];
                for (i = 0; i < n; i++)
                    fileAdult >> pMas[i];
                cout << "Adult in file \n";
                for (i = 0; i < n; i++)
                    cout << pMas[i].toString() << endl;
                cout << " delete \n";
                delete[] pMas;
            }
        }
                break;
        case '7': {
            ofstream fileAdult("fileAdultChild1.txt");
            int n, i;
            cout << " Input num Adult ";
            while (!(cin >> n) || n < 0) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad  input num  \n";
            };

            Adult* pMas;
            pMas = new Adult[n];
            for (i = 0; i < n; i++)
                pMas[i].Input();

            cout << "Adult in input e \n";
            for (i = 0; i < n; i++)
                cout << pMas[i].toString() << endl;
            //
            fileAdult << n << endl;
            for (i = 0; i < n; i++)
                fileAdult << pMas[i];
            cout << "Adult save in file \n";
            cout << " delete \n";
            delete[] pMas;
            break;
        }
        case '8': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            string nameC[] = { "Masha","Sacha","Dasha" };
            Adult t(30, 50, pib, 2323190, 3, nameC);
            cout << t.toString() << endl;
            cout << " Test constructor copy \n";
            Adult nB(t);
            cout << nB.toString() << endl;
            Adult r;

            cout << " Test operator =  \n";
            r = nB;
            cout << r.toString() << endl;
        }
                break;
        case '9': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            string nameC[] = { "Masha","Sacha","Dasha" };
            Adult t(30, 50, pib, 2323190, 3, nameC);
            cout << t.toString() << endl;
            Adult q;
            Adult r;
            cout << " Test constructor move py \n";
            r = (Adult)t;
            cout << r.toString() << endl;
            cout << " operator +  && \n";
            r = t + 3;
            cout << r.toString() << endl;
        }
        case 'q':
            break;
        default:
            cout << " ??? \n";
        }
    } while (Choice != 'q');
    cout << " Exit from test! Bye! \n";
    return 3;
}
int mainExample3() {
    Exp4::Exp4main();
    return 4;
}
int mainExample4() {
    Exp5::Exp5main();
    return 5;
}
int mainExample5() {
    Exp2::Exp2main();
    return 5;
}

ostream& operator<<(ostream& os, PIB& a) {
    os << a.fname << endl;
    os << a.name << endl;
    os << a.lname << endl;
    return os;
}
istream& operator>>(istream& is, PIB& a) {
    is >> a.name;
    is >> a.fname;
    is >> a.lname;
    return is;
}

ostream& operator<<(ostream& os, Person& a) {
    os << a.name;
    os << a.age << endl;
    os << a.weight << endl;
    return os;
}
istream& operator>>(istream& is, Person& a) {
    if (a.name == nullptr) a.name = new PIB;
    is >> *(a.name);
    is >> a.age;
    is >> a.weight;
    return is;
}

ostream& operator<<(ostream& os, Adult& a) {
    if (a.name == nullptr)  os << " No P \n  No N \n No F\n ";
    os << *(a.name);
    os << a.age << endl;
    os << a.weight << endl;
    os << a.ID << endl;
    os << a.numChild << endl;
    if (a.numChild > 0)
        for (int i = 0; i < a.numChild; i++)
            os << a.nameChild[i] << endl;
    return os;
}
istream& operator>>(istream& is, Adult& a) {
    if (a.name == nullptr) a.name = new PIB;
    is >> *(a.name);
    is >> a.age;
    is >> a.weight;
    is >> a.ID;
    is >> a.numChild;
    if (a.numChild > 0)
        if (a.nameChild == nullptr) a.nameChild = new string[a.numChild];
    for (int i = 0; i < a.numChild; i++)
        is >> a.nameChild[i];
    return is;
}
*/