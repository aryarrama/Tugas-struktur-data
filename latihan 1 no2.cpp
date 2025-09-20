#include <iostream>
using namespace std;

int main() {
    float panjang, lebar;
    cout<<"Program menghitung persegi panjang"<<endl<<endl;
    cout<<"Masukkan panjang: ";
    cin>>panjang;
    cout<<"Masukkan lebar: ";
    cin>>lebar;

    float luas = panjang*lebar;
    float keliling = 2*(panjang + lebar);
    
    cout<<endl;
    cout<<"Hasil:"<<endl;
    cout<<"Luas dari persegi panjang: " <<luas<<endl;
    cout<<"Keliling dari persegi panjang: " << keliling<<endl;

    return 0;
}