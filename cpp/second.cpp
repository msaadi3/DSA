#include <iostream>
using namespace std;

// The -> (arrow) operator is used to access class, structure or union members using a pointer.

/*
// MORE ON CLASSES / OOPS
class Temp
{ // first letter of class name must be capital as it is a good practise

    int n;

public:
    Temp()
    { // it is a default construsctor as it accepts no arguements
        n = 0;
    }

    Temp(int a)
    { // it is a parameterized contructor as it accepts arguements
        n = a;
    }

    void display1()
    {
        cout << n << endl;
    }

    ~Temp()
    { // it is a destructor and destructor accepts no arguements and returns nothing
        cout << "destructor called, destructor is used for cleanups ";
    }
};


*/
/*

class Shop
{

    int itemIndex[50], itemPrice[50];
    int count;
    // int arrSize;
public:
    void setPrice();
    void display();
    void initCounter();
};

// function declarations outside of the class

void Shop :: initCounter () {
    count = 0;
}

void Shop :: setPrice(){

    cout << " enter the item index " << endl;
    cin >> itemIndex[count];
    cout << "enter the price of the item " << endl;
    cin >> itemPrice[count];
    count++;
}

void Shop ::display()
{
    for (int i = 0; i < count; i++)
    {
        cout << "price of the item at : " << itemIndex[i] << " is " << itemPrice[i] << endl;
    }
}


*/

// __________________________________________________________________________________________________________________________________________

/**
class Static {
    int id;
    static int count;   // static variable / variable's value remains same for every object

    public:
    void setId();
    void display();
    void functionCall();
};

int Static :: count = 1 ; // default value of static variable is zaro but can be changed in class or outside the class this way

// void Static :: setId (int i) {
//     id = i;
// }

void Static :: setId () {
    cout << "enter your id " << endl;
    cin >> id;
    display();
    count++;
}


void Static :: display () {
    cout << "your id is : " << id << " and your number is : " << count << endl;

}

void Static :: functionCall() {
    int call;
    cout << "how many employes are there " << endl;
    cin >> call;
    for (int i = 0; i < call; i++){
        setId();
    }

}

*/

// ________________________________________________________________________________________________________________________________________

/**
class Point
{
    int a, b;
    // default is private
public:
    Point(int x, int y);

    void display();
};

Point ::Point(int x, int y)
{
    a = x;
    b = y;
}

void Point ::display()
{
    cout << "A is : " << a << " and B is : " << b << endl;
}

*/

// __________________________________________________________________________________________________________________________________________

// passing objects as arguements  // remaining

// class SumComplex; // forward declaration

// class Complex
// { // it is a best practise to declare class name's first letter as cappital

//     int a, b;
//     int sum;

// public:
//     friend void SumComplex :: sumComplex(Complex , Complex );
//     Complex(int x, int y){
//         a = x;
//         b = y;
//     }

// };

// class SumComplex{
//     public:

// void sumComplex(Complex o1, Complex o2){
// sum = o1.a + o2.a;

// }
// };

/*
// constructor overloading

class ConstructorOverload
{
    int a, b;

public:
    inline ConstructorOverload(){}; // default contructor
    inline ConstructorOverload(int x);
    inline ConstructorOverload(int x, int y);
    void printNumber()
    {
        cout << a << " " << b << endl;
    }
};

ConstructorOverload ::ConstructorOverload(int x)
{
    a = x;
}

ConstructorOverload ::ConstructorOverload(int x, int y)
{
    a = x;
    b = y;
}

*/

/*
// copy constructor

class CopyConstructorByMe
{
    int a;

public:
    CopyConstructorByMe(int);
    CopyConstructorByMe(CopyConstructorByMe &);
    void display();
};

CopyConstructorByMe ::CopyConstructorByMe(int x)
{
    a = x;
}

CopyConstructorByMe ::CopyConstructorByMe(CopyConstructorByMe &obj)
{
    a = obj.a; // copy constructor
}

void CopyConstructorByMe ::display()
{
    cout << a << endl;
}

// again copy constructor

class CopyConstructor
{
    int a;

public:
    CopyConstructor(){}; // default constructor
    CopyConstructor(int);
    CopyConstructor(CopyConstructor &); // copy constructor
     void display()
    {
        cout << a << endl;
    }
};

CopyConstructor ::CopyConstructor(int x)
{
    a = x;
}

CopyConstructor ::CopyConstructor(CopyConstructor &obj)
{
    a = obj.a;
}

*/


/*
// objects arrays and initialization section / initialization list in constructor


class InitializationListInConstructor
{
    int a, b;

public:
    InitializationListInConstructor()
    {
        a = 0;
        b = 0;
    };                                                                 // default constructor as it takes no arguments
    InitializationListInConstructor(int x, int y) : a(x + 8), b(y + 9) // Initialization List In Constructor / initialization section 
    {
        // constructor body
    }
    InitializationListInConstructor(InitializationListInConstructor &);

    void display()
    {
        cout << " a : " << a << " b : " << b << endl;
    }
};

InitializationListInConstructor ::InitializationListInConstructor(InitializationListInConstructor &obj)
{
    a = obj.a;
    b = obj.b;
}

// same as above ( array of objects and InitializationListInConstructor / initialization section in constructor)

class ConstructorInitializationSection
{
    int a, b;

public:
    ConstructorInitializationSection() {}                                 // default constructor
    ConstructorInitializationSection(ConstructorInitializationSection &); // copy constructor
    ConstructorInitializationSection(int, int);
    void display();
};

ConstructorInitializationSection ::ConstructorInitializationSection(ConstructorInitializationSection &obj)
{
    a = obj.a;
    b = obj.b;
}

ConstructorInitializationSection ::ConstructorInitializationSection(int x, int y)
{
    a = x;
    b = y;
}

void ConstructorInitializationSection ::display()
{
    cout << " a : " << a << " b : " << b << endl;
}

*/


// NEW & DELETE & ARROW POINTER & POINTER TO OBJECTS

class Shop
{
    int id;
    int price;

public:
    void setData(int x, int y)
    {
        id = x;
        price = y;
    }
    void display()
    {
        cout << "id : " << id << " price : " << price << endl;
    }
    Shop(int x, int y)
    {
        id = x;
        price = y;
    }
    Shop() {}
    Shop(Shop &obj)
    {
        id = obj.id;
        price = obj.price;
    }
    ~Shop()
    {
        cout << "destructor called " << endl;
    }
};

// sequcence of calling constructor in inheritance

// class MultiInheritance1
// {
//     int a;

// public:
//     MultiInheritance1(int x)
//     {
//         a = x;
//     }
//     void getData1(){
//         cout << a;
//     }
// };

// class MultiInheritance2
// {
//     int b;

// public:
//     MultiInheritance2(int y)
//     {
//         b = y;
//     }
//     void getData2(){
//         cout << b;
//     }
// };

// class MultiInheritanc3 : public MultiInheritance1, public MultiInheritance2
// {
//     int c;

// public:
//     MultiInheritance3(int x, int y, int z) : MultiInheritance1(x), MultiInheritance2(y),
//     {
//         c = z;
//     }
//     void getData3(){
//         cout << c;
//     }
// };

int main()
{
    // MultiInheritanc3 mi(2,3,5);
    // mi.getData3();


    Shop *constructPtr = new Shop(2, 300); // initializing constructor
    constructPtr->display();
    Shop *constructPtr1[3];
    // constructPtr1[0] = Shop(3,33);
    constructPtr1[0]->setData(3, 3);
    constructPtr1[0]->display();


    int *i = new int(5);
    //    *(i+6) = 4;
    *(i + 3) = 3;
    *(i + 5) = 7;
    cout << *(i + 3) << endl;
    cout << *(i + 5) << endl;
    cout << *(i) << endl;
    // cout << *(i+6) << endl;
    int *integer = new int[55];
    integer[0] = 50;
    integer[3] = 3;
    integer[9] = 90;
    cout << *(integer) << endl;
    cout << *(integer + 9) << endl;
    cout << integer[9] << endl;
    cout << *(integer + 3) << endl;
    delete[] integer;

    char *character = new char[5];
    character[0] = 'c';
    character[1] = 's';
    *(character + 3) = 'a';
    cout << character[0] << endl;
    cout << *(character + 1) << endl;
    cout << *(character + 3) << endl;
    delete[] character;
    // cout << integer->integer[0] << endl;  // how to use arrow syntax in this case

    /*
    // creating object using new keyword and pointer
    Shop* ptr = new Shop;
    ptr->setData(2,200);
    ptr->display();
    delete ptr;

    Shop* anotherPtr = new Shop;
    anotherPtr->setData(3,9000000);
    anotherPtr->display();         // correct syntax
    delete anotherPtr;
    // {*(anotherPtr).setData(3,9000000);
    // *(anotherPtr).display();  } wrong : use arrow syntax instead

    */
    /*
    int size;
    cout << "how many items you have in your store " << endl;
    cin >> size;
    Shop* ptr = new Shop[size];
    Shop* ptr2 = ptr ; // copy
    int q, p;
    for(int i = 0; i < size; i++){
        cout << "enter the id and price of your item : " << endl;
        cin >> q >> p;
        // (*ptr).setData(i , p);  //  exactly same as below arrow syntax
        ptr->setData(q,p);    //  exactly same as above
        ptr++;
    }

    for (int i = 0; i < size; i++){
        // (*ptr2).display();  // is exactly same as below arrow syntax
        ptr2->display();   // is exactly same as above
        ptr2++;
    }
    */
    

    /*
      ConstructorInitializationSection obj[3];
      obj[0] = ConstructorInitializationSection(2, 2);
      obj[0].display();

      obj[1] = ConstructorInitializationSection(obj[0]);
      obj[1].display();


      InitializationListInConstructor objects[5];
      objects[0] = InitializationListInConstructor(1, 1);
      objects[0].display();
      objects[1] = InitializationListInConstructor(10, 11);
      objects[1].display();
      objects[2] = InitializationListInConstructor(objects[0]);
      objects[2].display();
  */
    /**

    CopyConstructorByMe object1(10);
    object1.display();
    CopyConstructorByMe object2 = CopyConstructorByMe(object1);
    object2.display();
    CopyConstructorByMe object3 = object2;
    object3.display();

    CopyConstructor newObj(20);
    newObj.display();
    CopyConstructor newObj2 = CopyConstructor(newObj);
    newObj2.display();
    CopyConstructor newObj3 = newObj2;
    newObj3.display();
    */

    /*
    // implicit  calls
    // ConstructorOverload newObj (2,33);
    // ConstructorOverload newObj ;
    // ConstructorOverload newObj(2) ;
    // newObj.printNumber();

    // explicit calls

    // ConstructorOverload obj = ConstructorOverload();
    // ConstructorOverload obj = ConstructorOverload(2);
    // ConstructorOverload obj = ConstructorOverload(2,9);
    // obj.printNumber();


    */

    /**
        // implicit constructor call
        Point x(2, 7);
        x.display();

        // expliciti constructor call
        Point y = Point(-1, 5);
        y.display();

    */
    /*
    Static employee;
    Static employee2;
    Static employee3;
    employee.functionCall();
    employee2.functionCall();
    employee3.functionCall();
    */

    /*
        Temp obj(5);
        obj.display1();

        Shop myShop;
        myShop.initCounter();
        myShop.setPrice();
        myShop.setPrice();
        myShop.setPrice();
        myShop.setPrice();
        myShop.display();

    */

/**
    // FOR RANGE LOOP 
   int arr[] = {1,2,3,4,5};
   for(const int& i : arr){   // best practise to access from address rather than copy 
    cout << i << endl;
   } 

   for (const int& i : {55,32,54,})
   {
    cout << i << endl;
   }
   
   string greet = " hello, world!! ";
   for(auto& ch : greet){
    ch = toupper(ch);
   }
    cout << greet;

    int punc = 0;
    for(auto j : greet){
        if(ispunct(j)){
            ++punc;
        }
        cout << punc;
    }

*/
    return 0;
}
