#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout<<"Program menukar nilai"<<endl<<endl;
    cout<<"Masukkan nilai A: ";
    cin>>A;
    
    cout<<"Masukkan nilai B: ";
    cin>>B;
    
    int temp = A;
    A = B;
    B = temp;
    
    cout<<"Hasil:"<<endl;
    cout<<"A = "<< A <<endl;
    cout<<"B = "<< B <<endl;
    
    return 0;
}