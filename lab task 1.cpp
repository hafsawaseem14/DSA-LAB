#include <iostream>
using namespace std;
int main() {
    int var=30;
    int*ptr=&var;
    cout<<"initial value of var="<<var<<endl;
    cout<<"initial value of *ptr="<<*ptr<<endl;
    *ptr=40;
    cout<<"modify value of var="<<var<<endl;
    cout<<"modify value of *ptr="<<*ptr<<endl;
}

	
