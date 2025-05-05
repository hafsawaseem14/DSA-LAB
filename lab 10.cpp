#include<iostream>
using namespace std;
//class Animal {
//public:
//    
//    virtual void makeSound() {
//        cout << "Some generic animal sound!" << endl;
//    }
//};
//class Cat : public Animal {
//public:
//    
//    void makeSound() override {
//        cout << "Cat says Meowmeow" << endl;
//    }
//};	
//class Dog : public Animal {
//public:
//    void makeSound() override {
//        cout << "Dog says Woowoo" << endl;
//    }
//};
//class Tiger_Family : public Animal {
//public:
//    
//    void makeSound() override {
//        cout << "Tiger family says Roar" << endl;
//    }
//};
//class Deer : public Animal {
//public:
//    
//    void makeSound() override {
//        cout << "Deer says Bleat" << endl;
//    }
//};
//
//class Tiger : public Tiger_Family {
//public:
//    void makeSound() override {
//        cout << "Tiger says Roarrr" << endl;
//    }
//};
//
//class Lion : public Tiger_Family {
//public:
//    
//    void makeSound() override {
//        cout << "Lion says Roooar" << endl;
//    }
//};
//
//
//class Leopard : public Tiger_Family {
//public:
//
//    void makeSound() override {
//        cout << "Leopard says Growl" << endl;
//    }
//};
//
//int main() {
//    
//    Cat cat;
//    Dog dog;
//    Tiger tiger;
//    Lion lion;
//    Leopard leopard;
//    Deer deer;
//    Animal* animalPtr;
//    animalPtr = &cat;
//    animalPtr->makeSound();  
//    animalPtr = &dog;
//    animalPtr->makeSound();  
//    animalPtr = &tiger;
//    animalPtr->makeSound();  
//    animalPtr = &lion;
//    animalPtr->makeSound();  
//    animalPtr = &leopard;
//    animalPtr->makeSound();  
//    animalPtr = &deer;
//    animalPtr->makeSound();  
//
//    return 0;
//}
//class polygon{
//	public:
//	float length ;
//	float width;
//	public :
//	polygon (){
//	length=0;
//	width=0;
//						
//	}
//	polygon(float l,float w){
//		length=l;
//		width =w;
//	}
//	virtual float area();
//	virtual float perimeter();
//	virtual void display();
//};
//class square : public polygon{
//	public:
//		square () :polygon(){
//			
//		}
//	   square (float side) :polygon(side,side){
//	   	
//	   }
//	     float area() override {
//        return length * length;
//    }
//
//    float perimeter() override {
//        return 4 * length;
//    }
//
//    
//    void display() override {
//        cout << "Square: Area = " << area() << ", Perimeter = " << perimeter() << endl;
//    }
//};
//
//class Rectangle : public polygon {
//public:
//    
//    Rectangle() : polygon() {}
//
//    
//    Rectangle(float l, float w) : polygon(l, w) {}
//
//
//    float area() override {
//        return length * width;
//    }
//
//    float perimeter() override {
//        return 2 * (length + width);
//    }
//
//
//    void display() override {
//        cout << "Rectangle Area  " << area() << " Perimeter = " << perimeter() << endl;
//    }
//};
//
//
//class Triangle : public polygon {
//private:
//    float height;
//
//public:
//    
//    Triangle() : polygon(), height(0) {}
//
//    Triangle(float l, float w, float h) : polygon(l, w), height(h) {}
//
//    
//    float area() override {
//        return (length * width) / 2;
//    }
//
//    
//    float perimeter() override {
//        return length + width + height;
//    }
//
//    
//    void display() override {
//        cout << "Triangle: Area = " << area() << " Perimeter = " << perimeter() << endl;
//    }
//};
//
//int main() {
//    
//    square sq(5);              
//    Rectangle rec(10, 5);      
//    Triangle tri(6, 4, 5);     
//
//    
//    polygon* Bptr;
//    cout << "Static Binding:" << endl;
//    sq.display();   
//    rec.display();
//    tri.display();
//
//    
//    cout << "\nDynamic Binding:" << endl;
//    Bptr = &sq;
//    Bptr->display();  
//
//    Bptr = &rec;
//    Bptr->display();  
//
//    Bptr = &tri;
//    Bptr->display(); 
//
//    return 0;
//}

//class Polygon {
//public:
//    float length;
//    float width;
//
//    
//    Polygon() : length(0), width(0) {}
//
//    
//    Polygon(float l, float w) : length(l), width(w) {}
//
//   
//    virtual float area() = 0;       
//    virtual float perimeter() = 0;
//    virtual void display() = 0;   
//
//    virtual ~Polygon() {}         
//};
//
//
//class Square : public Polygon {
//public:
//   
//    Square() : Polygon() {}
//
//    
//    Square(float side) : Polygon(side, side) {}
//
//   
//    float area() override {
//        return length * length;
//    }
//
//    
//    float perimeter() override {
//        return 4 * length;
//    }
//
//   
//    void display() override {
//        cout << "Square: Area = " << area() << " Perimeter = " << perimeter() << endl;
//    }
//};
//
//
//class Rectangle : public Polygon {
//public:
//    
//    Rectangle() : Polygon() {}
//
//    
//    Rectangle(float l, float w) : Polygon(l, w) {}
//
//   
//    float area() override {
//        return length * width;
//    }
//
//   
//    float perimeter() override {
//        return 2 * (length + width);
//    }
//
//    
//    void display() override {
//        cout << "Rectangle Area = " << area() << " Perimeter = " << perimeter() << endl;
//    }
//};
//
//
//class Triangle : public Polygon {
//private:
//    float height; 
//public:
//    
//    Triangle() : Polygon(), height(0) {}
//
//   
//    Triangle(float l, float w, float h) : Polygon(l, w), height(h) {}
//
//   
//    float area() override {
//        return (length * height) / 2;
//    }

   
//    float perimeter() override {
//        return length + width + height;
//    }
//
//    
//    void display() override {
//        cout << "Triangle: Area = " << area() << " Perimeter = " << perimeter() << endl;
//    }
//};
//
//
//int main() {
//   
//    Square sq(9);               
//    Rectangle rec(16, 5);      
//    
//    Polygon* Bptr;
//
//    Triangle tri(6, 8, 3);      
//    
//    cout << "Static Binding:" << endl;
//    sq.display();   
//    rec.display(); 
//    tri.display(); 
//
//    
//    cout << "\nDynamic Binding:" << endl;
//    Bptr = &sq;
//    Bptr->display();  
//
//    Bptr = &rec;
//    Bptr->display();  
//
//    Bptr = &tri;
//    Bptr->display(); 
//
//    return 0; 
//}
class Person {
protected:
    string Name;
    string Bloodgroup;

public:
    
    Person(string name, string bloodgroup) : Name(name), Bloodgroup(bloodgroup) {}

    
    virtual void displayBloodgroup() = 0;

    
    virtual ~Person() {
        cout << "Destructor called for Person class" << endl;
    }
};


class A : public Person {
public:
   
    A(string name) : Person(name, "A") {}

   
    void displayBloodgroup() override {
        cout << "Person " << Name << " has blood group A" << endl;
    }

    
    ~A() {
        cout << "Destructor called for A class" << endl;
    }
};


class B : public Person {
public:
    
    B(string name) : Person(name, "B") {}

    
    void displayBloodgroup() override {
        cout << "Person " << Name << " has blood group B" << endl;
    }

   
    ~B() {
        cout << "Destructor called for B class" << endl;
    }
};


class C : public Person {
public:
   
    C(string name) : Person(name, "C") {}

   
    void displayBloodgroup() override {
        cout << "Person " << Name << " has blood group C" << endl;
    }

   
    ~C() {
        cout << "Destructor called for C class" << endl;
    }
};

int main() {
   
    Person* personA = new A("tooba");
    Person* personB = new B("maryam");
    Person* personC = new C("saba");

    
    personA->displayBloodgroup();
    personB->displayBloodgroup();
    personC->displayBloodgroup();

   
    delete personA;
    delete personB;
    delete personC;

    return 0;
}