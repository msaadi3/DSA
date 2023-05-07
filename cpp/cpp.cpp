#include <iostream>
#include <string> // string isn't a builtin data type
#include <fstream>
using namespace std;

// struct declaration outside main()
/*

 struct name {

        int year;
        string name;
        string brand;
        string color;

    };
*/

// FUNCTIONS

// RECURSION

/**
    int sum (int k){
        if(k > 0){
            return k + sum(k - 1 );
        } else {
            return 0;
        }

    }

    int factorial (int i) {
        if (i > 1) {
            return i * factorial (i - 1);
        } else {
            return 1;
        }
    }

    int fibonachi (int j){
        if (j < 2) {
            return 1;
        } else {
            return fibonachi(n - 2) + fibonachi(n - 1);
        }
    }

*/

/*
    void func () {
        cout << "hello func" << endl;
    }

    string funcReturn (string fname, string lname = "bin abi usama") {
        string name = fname + lname;
        cout << name;
        return name;
    }

    // call by refernece using pointers
    void swapWWithPointer(int* a, int* b ){
        int temp ;
        temp = *a;
        *a = *b;
        *b = temp ;

    }

    // swapping numbers withthe help of call by reference using refernce variable (&)
    void swapWithReference(int &c, int &d){
        int swap ;
        swap = c;
        c = d;
        d = swap;
    }

*/
// PASSING ARRAY AS AN ARG

/**
    void functionArr (int arr[5]) {
        for (int i = 0; i < 6; // sizeof(arr) / sizeof(int);  i++ ){
            cout << i << endl;
        }

    }

    // FUNCTIONS OVERLOADING

    int funcPlus(int a , int b , int c ){
        int resultIntPlus = a + b + c;
        cout << "resultIntPlus : " << resultIntPlus << endl;
        return resultIntPlus;
    }

    double funcPlus (double a , double b , double c) {
        double resultDoublePlus = a + b + c;
        cout << "resultDoublePlus : " << resultDoublePlus << endl;
        return resultDoublePlus;
    }

*/

// CLASSES / OBJECTS / OOPS

/**
    class firstClass {
        public:
        string name ;
        string brand ;
        int year ;

        void method () {
            cout << "firstClass" << name << brand << year << endl;
        }
    };

    class nameClass {
        public :
        string fname;
        string lname;
        int age ;

        void name ();

    };

    void nameClass :: name () {
        cout << "so you forgot your name huh! no problem i'll tell you what your name is. your name is " << fname << " " << lname << endl ;

    }


    // CONSTRUCTOR

    class constructorClass {
        public:
            string monitor ;
            string keyboard ;
            string laptop ;
            int age ;

            constructorClass (string x, string y,string z, int a) {
                monitor = x;
                keyboard = y ;
                laptop = z;
                age = a;
            };

            void constructorClassMethod();
    };

    void constructorClass :: constructorClassMethod () {
        cout << monitor << " "  << " " << keyboard << " " << laptop << " " << age << endl;
    }

    // ACCESS SPECIFIERS AND ENCAPSULATION

    class classPrivate {
        private :
            int salary ;
            string name ;
        public:
            int long getSalary(){
                return salary;
            }
            string getName(){
                return name ;
            }
            void setName (string n) {
                name = n ;       // variable should be on left side if you want to assign it a value and variable should be on right side who will assign value to left side variable
            }
            void setSalary (int s) {
                salary = s;       // variable should be on left side if you want to assign it a value and the variable who will assign it a value will be on right side
            }

    };

    // INHERITANCE

    class baseClass {
        private :
            int salary ;
        public :

            void setSalary (int s) {
                salary = s;
            }

            int getSalary () {
                return salary;
            }

    };

    class childClass : public baseClass {   //inheritance
        protected :
            string name ;
    };

    class grandChildClass : public childClass {     // multilevel inheritance

        public :

            void setName (string n) {
                name = n;
            }
            string getName () {
                return name;
            }

    }  ;

    // POLIMORPHISIM

    class animal {
        public:
        void animalSound () {
            cout << "animal sound" << endl;
        }
    };

    class dog : public animal {
        public:
        void animalSound () {
            cout << "dog sound" << endl ;

        }
    };

    class cat : public animal {
        public :
        void animalSound () {
            cout << "cat sound" << endl ;
        }
    };

*/
/*

    // swapping function call by refernce with pointers

    void swapWithPointers(int* a, int* b){    // a and b is called formnal parameters and arguments that get passed in function call are calles as actual parameters . a and b has a lcal function scope so we can reuse it these two variables outside this function
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    // swapping function call by refernce with refernce operator

    void swapWithRefer (int &a, int &b){
        int temp ;
        temp = a;
        a = b;
        b = temp;
    }

    // function returning refernce
    int & returnRefernce (int &a, int &b){
        int temp ;
        temp = a;
        a = b;
        b = temp;
        return b;
    }


    // function returning value/derefrence
    int returnValue (int *a, int *b){
        int temp ;
        temp = *a;
        *a = *b;
        *b = temp;
        return *b;
    }

*/

// enumeration / enum

enum icecream
{
    choclate = 100,
    vanilla = 101,
    butterscotch = 102,
    tuttifruti = 103
}; // changing default values
// enum icecream {choclate , vanilla , butterscotch , tuttifruti };

// UNION

union firstUnion
{
    /* data */
    int i;
    char c;
    float f;
};

// structure

typedef struct structure
{
    int a;
    string str;
    char character;
} struc;

// MAIN()
int main()

    // STRCUTURE

    struc gfg;
gfg.a = 8;
gfg.str = "string";
gfg.character = 'c';
cout << "structure"
     << " "
     << gfg.a
     << " "
     << gfg.str
     << " "
     << gfg.character
     << endl;
/**
    // UNION

    // union firstUnion var;
    firstUnion var;
    var.i = 10;
    var.c = 'c';
    var.f = 9.9;
    // cout << var.i << endl;
    // cout << var.c << endl;
    // cout << var.f << endl;

*/
// enumeration / enum

icecream myIcecream;
myIcecream = choclate;
cout << myIcecream << endl;
cout << choclate << endl;
cout << vanilla << endl;
cout << tuttifruti << endl;

/**
    // swapping with pointers

    int num1 = 5 , num2 = 10;
    swapWithPointers(&num1, &num2);  //num1 and num2 are called actual parameters
    cout << " num1 : " << num1 << " " << " num2 : " << num2 << endl;

    // swapping function with refernce operator

    int n1 = 10, n2 = 5;
    swapWithRefer(n1, n2);
    cout << " n1 : " << n1 << " n2 : " << n2 << endl;

    // function returning refernce

    int x = 2, y = 1;

    returnRefernce(x, y) = 3;
    cout << x << " " << y <<endl;

    // function returning value / drefernce
    int i = 2 , j = 1;
    returnPointer(&i , &j);
    cout << i << j;



*/

// WORKING WITH FILES // FSTREAM

/*


    ofstream create ("file.txt");
    create << "this is myfirst file";
    create.close();


    ofstream file ;
    file.open("another.txt");
    string txt = "jfhldfgdfkadjfhe jf kfk jjf juif 9r438uor 9  ikjflkef jr4u9rt 4tuut 94tu94 utjik iidfj ui4utfijf4rt8ugu fjehnc 89r";
    file << txt;
    file.close()


    ifstream read ("another.txt"); // opening file usinf constructor
    // read.open("file.txt");      // opening file using open() method of ifstream class
    string text;
    getline(read, text);           // method to read a complete line otherwise it would terminate at whitespace and won't read complete line

    cout << text;
    read.close()                    // close the file at the end as a good practise

    ifstream read ("another.txt");
    string text;
    while (read.eof() != 1){
        getline(read, text);
        cout << text;

    }
    read.close();

*/

// CLASSES / OJECTS / OOPS
// variables in classes are called attributes and functions in classes are called methods
// functions can be defined inside the class or outside the class but to define outside the class you have to first declare inside the class same as way constructor can also be defined inside the class or outside the class but to define outside the class we first have to declare inside the class then define the body outside the class, same way as methods

/**
    constructorClass mySystem("DELL", "DELL", "DELL", 1);
    cout << mySystem.laptop << " " << mySystem.monitor << " " << mySystem.keyboard << " " << mySystem.age << endl;
    mySystem.constructorClassMethod();

    firstClass car1 ;

    car1.name = "maclaren";
    car1.brand = "macleren";
    car1.year = 89;
    car1.method();

    nameClass myName ;
    myName.fname = "Saad";
    myName.lname = "bin abi usama";
    myName.name ();

    classPrivate employee ;
    employee.setSalary(350000);
    employee.setName("aubrey kate");

    cout << "there you go" << employee.getName() << " " << employee.getSalary() << endl;


    grandChildClass obj;
    obj.setSalary(6900000);
    obj.setName("Aubrey Kate");
    cout << "love of my life is : " << obj.getName() << " " << "and she earns " << obj.getSalary() << endl;

    animal myAnimal;
    myAnimal.animalSound();
    dog myDog ;
    myDog.animalSound();
    cat myCat;
    myCat.animalSound();

*/
// EXCEPTION HANDLING / TRY/CATCH/THROW SYNTAX

/**
    try {
        int age ;
        cout << "please enter your age";
        cin >> age;
        if(age > 18){
            cout << "Access Granted!";
        } else {
            throw "Access denied";
        }
    }catch ( char a) {
        cout << "catch block : " << a << endl;
    }
*/

// FUNCTIONS

// might be functions declarations should be outside main() or functions can be declared outside(above the main()) and functions definations can be below the main() (outside) and then functions get called inside main().
// when we declare function parameters they are called parameters and when we pass parammeter values during calling the function then they are called arguements. function can hava default parameters when we don't pass that arguement that default parameter is used and that default parameter is called optional parameter and it's value is called default value
// multiple functions can have the same name as long as their number of parameters/type of parameters are different and that is called function overloading

/**
    int resultSum = sum (5);
    cout << resultSum << endl;

    int resultFactorial = factorial(10);
    cout << resultFactorial << endl;

    int resultFibonachi = fibonachi(15);
    cout << resultFibonachi << endl;

*/

/**
    funcPlus(2,5,3);
    funcPlus(2.5, 2.5, 5.0);


    func () ;

    funcReturn("saad", "shafqat");

    int arr[5] = {1,2,3,4,5};
    functionArr(arr);
    //  call by reference


    // swapping two numbers with the help of call by refernce using pointer
    int x = 5;
    int y = 10;
    swapWWithPointer(&x,&y);
    cout << x << " " << y << endl;

    // swappping numbers with the help of call by refernce using refernce variables (&)

    int g = 10;
    int h = 5;
    swapWithReference(g, h);
    cout << g << " " << h << endl;

*/

// int ageInt = 22;
// float ageFloat = 22.3;
// double ageDouble = 22.3333333; // double is used for storing bigger decimal values than float , float is used for smaller decimal values
// string name =  "saad";
// char special = '@';
// bool boy = true ;

// cout<< "this guy's name is"<< name << "and he is " << ageInt << "old" << "and his favorite special character is" << special << "is he boy?"<< boy;

// DATA TYPES
/*
    string text = "my name is saad";
    cout<< "size of string \n" << sizeof (text) << "\n";

    const int constant = 3.14;
    cout<< "size of int \n" << sizeof (constant) << "\n";

    short int shortInt = 876;
    cout<< "size of short int \n" << sizeof (shortInt) << "\n";

    long int longInt  = 784392;
    cout<< "size of long int \n" << sizeof (longInt) << "\n";

    char character = '@';
    cout<< "size of char \n" << sizeof (character) << "\n";

    const float floatNum = 75.53;
    cout<< "size of float \n" << sizeof (floatNum) << "\n";

    double doubleNum = 253.083233;
    cout<< "size of double \n" << sizeof (doubleNum) << "\n";

    bool isSaadBoy = 1;
    cout<< "size of bool \n" << sizeof (isSaadBoy) << "\n";

    */

// OPERTAORS && MATH
/*
    int x = 5 ;
    x += 5 ; // x = x + 5
    cout<< x <<endl;
    x -= 5;  // x = x - 5
    cout<< x <<endl;
    x *= 5 ;  // x = x * 5
    cout<< x <<endl;
    x /= 5 ;  // x = x / 5
    cout<< x <<endl;
    x %= 5 ; // x = x % 5
    cout<< x <<endl;

*/
// STRINGS

// strings are objects (append (), length())

/*
    string name = "my name is saad ";
    cout<<name[0]<<endl; // access string's characters and we can also replace characters in strings like this name[0]="x"
    string age = "and my age is 22 ";
    string intro = text.append(age);  // intro = text + age // intro = text + " " + age ;
    cout << intro <<endl ;
    cout << intro.size()<<endl;
    cout << intro.length()<<endl;
    // size() and length() both are same in strings
    cout<< "hello my name is \"saad\" and it\'s my ide\\code editor \n";

    string yourName ;
    cout<<"hey man! what's your name \n";
    getline(cin, yourName);
    cout<<"your name is "<<yourName<<endl;

*/
// CONDITIONAL STATMENTS

// ternary operator

/*
    int y = 10;
    string ternary = (y=10) ? "y = 10" : "y != 10";
    cout<<ternary<<endl;

    // switch

    int day = 1;

    switch (day) {
        case 1:
        cout<<"monday"<<endl;
        break;

        case 2:
        cout<<"tuesday"<<endl;
        break;

        case 3:
        cout<<"wednesday"<<endl;
        break;

        case 4:
        cout<<"thursday"<<endl;
        break;

        case 5:
        cout<<"friday"<<endl;
        break;

        case 6:
        cout<<"saturday"<<endl;
        break;

        case 7:
        cout<<"sunday"<<endl;
        break;

        default:
        cout<<"time will be passed no matter what!";

    }
*/
// while && do/while

/*
    int num = 0;
    while(num < 10){
        cout<<num<<endl;
        num++;
    }

    int number = 0;
    do {
        cout<<number<<endl;
        number++;
    } while (number < 10);

*/
// FOR LOOP

// NESTED FOR LOOP
// have to learn about nested loops later
/*


    for(int i = 0 ; i<2; i++){
        cout<<i<<endl;

        for(int j = 0; j < 2; j++){
            cout<<j<<endl;
        }
    }

    // FOREACH LOOP FOR ARRAYS

    int arr[10]={10,20,30,40,50,60,70,80,90};
    for(int z : arr){
        cout<<z<<endl;
    }

*/
// BREAK AND CONTINUE IN FOR LOOP
/*
    for(int i = 0 ; i < 10 ; i++){
        if (i==5){
            break;
        }
        cout<<i<<endl;

    }

    for(int i = 0; i < 10 ; i++){
        if(i==5){
            continue;
        }
        cout<<i<<endl;
    }
*/
// BREAK AND CONTINUE WITH WHILE AND DO/WHILE LOOP

// int n = 0;
// while(n < 10){
//     if(n==7){
//         break;
//     }
//     cout<<n<<endl;
//     n++;

// }

// int d = 0;
// didn't execute as thought
// do {
//     if(d==7){
//         continue;
//     }
//     cout<<d<<endl;
//     d++;

// } while(d < 10);

// ARRAYS

/*
    string cars[5] = {"Rolls Royce", "Lamborghini", "Mercedes", "Audi", "Macleren"};

    for (int i = 0; i < 5; i++){
        cout << i << "=" << cars[i] << endl;
    }

    int numbersArray[10] = {10,20,30,40,50,60,70,80,90,100};

    for(int i = 0; i < 10; i++){
        cout << numbersArray[i] << endl;
    }

    string stringArr[] = {"Rolls Royce", "Lamborghini", "Mercedes", "Audi", "Macleren"};

    for (string i : stringArr){
        cout << i << endl;
    }


    // SIZEOF() ; sizeof() method on array will return the size of an array in bits/bytes but if we want the size of array according to it's elements we have to divide it by the sizeof its data type like sizeof(array) / sizeof(datatype of that array)

    string sizeofArr[] = {"Rolls Royce", "Lamborghini", "Mercedes", "Audi", "Macleren"};
    cout << sizeof(sizeofArr) << endl;
    int size = sizeof(sizeofArr) / sizeof(string);
    cout << size<<endl;


    string sizeofArrForLoop[] = {"Rolls Royce", "Lamborghini", "Mercedes", "Audi", "Macleren"};
    for (int i = 0; i <sizeof(sizeofArrForLoop) / sizeof(string); i++ ){
        cout << sizeofArrForLoop[i]<<endl;
    }

*/

// STRUCTURES / STRUCT
/*
    struct {
        string brand;
        string name;
        string color;
        int year;
    } variable1, variable2, variable3;

    variable1.name = "hjdksd";
    variable1.brand = "jdish";
    variable1.color = "hdjshd";
    variable1.year = 7832;

    variable2.brand = "jskhf";
    variable2.color = "jskhf";
    variable2.name =  "jskhf";


    variable3.brand="hfdk";
    variable3.color="hfdk";
    variable3.year=32;
    variable3.name =" dsf";

    cout << variable1.brand << endl << variable1.name << endl << variable1.year << endl << variable1.color<< endl;
    cout << variable2.brand << endl << variable2.name << endl << variable2.year << endl << variable2.color<< endl;
    cout << variable3.brand << endl << variable3.name << endl << variable3.year << endl << variable3.color<< endl;

*/

// struct declaration outside main()

/*
    name car1;

    car1.year = 322;
    car1.name = "hdjs";
    car1.brand = "jdks";
    car1.color = "hsdai";

    name car2;

    car2.year = 732;
    car2.name = "sjd";
    car2.brand = "hjdhs";
    car2.color = "ksdx";

    name car3;

    car3.year = 724;
    car3.name = "dswi";
    car3.brand = "jdkws";
    car3.color = "jdas";


    cout << car1.year << " " << car1.name << " " << car1.brand << " " << car1.color <<endl;
    cout << car2.year << " " << car2.name << " " << car2.brand << " " << car2.color <<endl;
    cout << car3.year << " " << car3.name << " " << car3.brand << " " << car3.color <<endl;

*/

// MEMORY MENEGMENT / ADDRESS

/*
    // REFERENCE
    string refer = "reference";
    string &anotherOne = refer;

    cout << refer << endl;
    cout << anotherOne << endl;

    // GET THE MEMORY ADDRESS OF THE VARIABLE

    int a = 53;
    cout << &a <<endl;
    // prepand appersand(&) sign to the variable to get the memory address of tha variable, memeory addresses are in hexadecimal form

    // POINTERS
    // A pointer is a variable that stores memory address as it's value . a pointer variable points to a data type of the same data type and is created with * operator. The address of the variable is assigned to the pointer variable

    string myName = "Saad";
    string* ptr = &myName;
    cout << myName << " " << ptr << " " << &myName << endl;

    // DEREFERENCING VARIABLE/POINTER

    cout << *ptr <<endl;

    // MODIFY POINTERS

    string modify = "modify";
    cout << modify;
    string* ptrModify = &modify;
    cout << ptrModify << " " << &modify << endl;
    cout << *ptrModify << endl;
    *ptrModify = "modified";
    cout << modify;
    cout << *ptrModify;
    cout << ptrModify << " " << &modify << endl;

*/

/**
    int num = 55e7;
    cout << num << endl;
    double numDoub = 5.5e2;
    cout << numDoub << endl;
    int long lo = 8932E2;
    cout << lo <<endl;

*/

// REMAINING PART

// int divisor = 5;
// int dividend = 15;
// int result = dividend + divisor;
// // int result = dividend/divisor;
// cout << result;

// MULTIDIMENSIONAL ARRAYS AND NESTED LOOPS

/**
    int twoArr[5][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};

    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout << " value at " << twoArr[i]  << " and " << twoArr[j] << " is "  << " : " << twoArr[i][j] <<endl;
        }
    }

    int dynamictwoArr[2][3];
    int a,b;
    cout << " enter any numbers to form a 2D array with 2 rows and 3 coloumns" << endl;
    for (a = 0; a < 2; a++){
        for(b = 0; b < 3; b++){
            cin >> dynamictwoArr[a][b];
        }
    }

    cout << "the elements of the array are : " << endl;
    for(a = 0; a < 2; a++) {
        for(b = 0; b < 3; b++){
            cout << dynamictwoArr[a][b] << endl;
        }
    }

*/

/*
    int arrs, rows, cols;
    int dynamicArr[arrs][rows][cols];

    int i , j , k , sum = 0;
    cout << "enter number of rows : " << endl ;
    cin >> rows;
    cout << "enter number of cols : " << endl;
    cin >> cols;
    cout << "enter number of arrays to be formed in 3D array : " << endl;
    cin >> arrs;

    cout << "enter number of elements in 3D array : " << endl;
    for (i = 0; i < arrs; i++){
        for (j = 0; j < rows; j++){
            for (k = 0; k < cols; k++){
                cin >> dynamicArr[i][j][k] ;
            }
        }
    }

    cout << "your array elements are : " << endl;
    for (i = 0; i < arrs; i++){
        for (j = 0; j < rows; j++){
            for (k = 0; k < cols; k++){
                cout << dynamicArr[i][j][k] << " " << endl;
            }
        }
    }

*/

/**


    int sumByRowsAndColsOfTwoArr[2][2];
    int v , w , sum = 0;
    cout << "Enter any numbers to form a 2D array and get sum of every row and coloums" << endl;
    for (v = 0; v < 2; v++){
        for(w = 0; w < 2; w++){
            cin >> sumByRowsAndColsOfTwoArr[v][w];
        }
    }

    cout << "Your elements of 2D array are : " << endl;
    for (v = 0; v < 2; v++){
        for (w = 0; w < 2; w++){
            cout << sumByRowsAndColsOfTwoArr[v][w] << endl;
        }
    }

    cout << "sum of rows are of this 2D array : " << endl;
    for(v = 0; v < 2; v++){
        for (w = 0; w < 2; w++){
            sum += sumByRowsAndColsOfTwoArr[v][w];
        }
        cout << sum << endl ;
        sum = 0 ;
    }

    cout << "sum of coloums of this 2D array : " << endl;
    for(w = 0; w < 2; w++){
        for(v = 0; v < 2; v++){
            sum += sumByRowsAndColsOfTwoArr[v][w];
        }
        cout << sum << endl;
        sum = 0;
    }


*/

/*
  int threeDArr[3][3][3] = {{{1,2,3},{1,2,3},{1,2,3}}, {{1,2,3},{1,2,3},{1,2,3}},{{1,2,3},{1,2,3},{1,2,3}}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cout << threeDArr[i][j][k] << " ";
            }
        }
    }

*/
/*

    int dynamicThreeDArr[3][2][2];

    cout << "Enter array elements : " << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                cin >> dynamicThreeDArr[i][j][k];
            }
        }
    }

    cout << "Elements of your arrays are : " << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                cout << dynamicThreeDArr[i][j][k] << " " << endl; ;
            }
        }
    }

    int sum = 0;

    cout << "sum of your three arrays's elements coloums by coloums and row by row are given below : " << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                sum += dynamicThreeDArr[i][j][k];
            }
            cout << sum << " ";
            cout << endl;
            sum = 0;
        }
    }

*/

// MATRIX

/*

    int a[2][2], b[2][2], c[2][2];

    cout << "enter elements for your 1st 2D array : " << endl;
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }

    cout << "enter array elements for your 2nd 2D array : " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cin >> b[i][j];
        }
    }

    cout << "elements of tour 1st 2D arrar are : " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++ ){
            cout << a[i][j] << " " << endl;
        }
    }

    cout << "elements of your 2nd 2D array are : " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << b[i][j] << " " << endl;
        }
    }

    // sum of two matrixes

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "sum of your two matrixes are : " << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << c[i][j] << " " << endl;
        }
    }

*/

// NESTED WHILE LOOP

/**
    int i = 0;
    while (i < 3){
        int j = 0;
        while (j < 5){
            cout << "*"<< " " ;
            j++;
        }
        i++;
    }

*/

/*
    // ADDITION OF MATRICES
    int arows, acols, brows, bcols, crows, ccols;
    int a[arows][acols], b[brows][bcols], c[crows][ccols];

    int i, j, k, sum = 0;
    cout << "enter the number of rows in first matrix : " << endl;
    cin >> arows;
    cout << "enter the number of rows in second matrix : " << endl; // think about the solution of this repetitive process
    cin >> brows;
    cout << "enter the number of cols in first matrix : " << endl;
    cin >> acols;
    cout << "enter the number of cols in second matrx : " << endl;
    cin >> bcols;

    cout << "enter the alements for first matrix : " << endl;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < acols; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "enter the elements for second matrix : " << endl;
    for (i = 0; i < brows; i++)
    {
        for (j = 0; j < bcols; j++)
        {
            cin >> b[i][j];
        }
    }

    cout << "addition of these two matrices is : " << endl;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < bcols; j++)
        {
            for (k = 0; k < brows; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    cout << c[i][j] << " ";

    // cout << "resultant matrix is : " << endl;
    // for(i = 0; i < crows; i++){
    //     for (j = 0; j < ccols; j++){
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }

*/

/*
    // BITWISE OPERATORS

        // 1. (AND) & : AND operator takes two numbers as operands and does AND on every bit of two numbers, the result of AND is 1 only when both bits are 1 otherwise 0

        int a = 55, b = 9;

        cout << "AND(&) of a and b is : " << (a & b) << endl;

        // 2. (OR) | : OR operator takes  two numbers as operands and does OR operation on every bit of two numbers , the result of OR is 1 if any of the bits is 1

        cout << "OR(|) of a and b is : " << (a | b) << endl;

        // 3. (NOT) ~ : NOT is a unary opertor that means it takes one number as operand and inverts all its bits. it bit is 0 it would convert it to 1 and if it is 1 it would covert it to 0

        cout << "NOT(~) of a is : " << (~a) << " " << "and NOT(~) of b is : " << (~b) << endl;

        // 4.(LEFT SHIFT) << : shifts the bits to left

        cout << "LEFT SHIFT(<<) of a is : " << (a << 2) << " " <<"LEFT SHIFT(<<) of b is : " << (b << 2) << endl;

        // 5.(RIGHT SHIFT) >> : shifts the bits to right

        cout << "RIGHT SHIFT (>>) of a is : " << (a >> 2) << " " << "RIGHT SHIFT (>>) of b is : " << (b >> 2) << endl;

        // 6.(EXCLUSIVE OR / XOR) ^ : there are two types of OR. INCLUSIVE OR and EXCLUSIVE OR. 1. INCLUSIVE OR is same as OR . 2. EXCLUSIVE OR takes two numbers as operands and does XOR on every bit of two numbers and results 0 if either both bits are 1 or both bits are zero  and results 1 if any of bits is 1

        cout << "EXCLUSIVE OR(^) / XOR (^) of a and b is : " << (a ^ b) << endl;



*/

/*    // POINTERS & ADDRESS

    // a pointer is a variable/data type/object of a data type which holds the memory address of other datatype/variable
    int num = 69;
    int* p = &num;  // p is a pointer variable of integer data type that holds the address of num variable of integer data type

    cout << "address of num " << p << "address of num " << &num << "derefrence/value at the address/num " << *p <<  endl;

    // POINTER TO POINTER
    // a pointer to pointer is a pointer variable/data type/objct that holds the address of other pointer

    int** pp = &p;  // pp is a pointer to pointer variable/datatype/object of integer data type that holds the address of another pointer

    cout << "address of p pointer " << pp << " " << "address of p pointer " << &p << " " << "derefrencing / value at address / num address" << *pp << "again derefrence / value at num " << **pp << endl;

    // REFERENCE / COMPARISON

    // refernce variable is just an alias of a variable and it is unspecified by c++ standard whether it requires actual storage or not
    string name = "Saad";
    string* pointer = &name;
    string &refer = name;
    string* referP = &refer;

    cout << " name " << name << " pointer " << pointer <<  " &name " << &name << " refer " << refer  << " " << &refer << " " << referP << endl ;

    cout << endl << endl << endl << endl << endl << endl;

    // ARRAYS WITH POINTERS & REFERENCES

    int arr[5] = {1,2,3,4,5};
    int* ptrArr = arr;
    cout << (ptrArr) << " " << (*ptrArr) << " " << (ptrArr + 1) << " " << *(ptrArr + 1) << " " << (ptrArr + 2) << " " << *(ptrArr + 2) << " " << (ptrArr + 3) << " " << *(ptrArr + 3) << " " << (ptrArr + 4) << " " << *(ptrArr + 4) <<  endl;

    cout << &arr << endl;
    cout << (arr) << endl;
    cout << (arr+1) << endl;
    cout << (arr+2) << endl;
    cout << (arr+3) << endl;
    cout << (arr+4) << endl;

*/

return 0;
}