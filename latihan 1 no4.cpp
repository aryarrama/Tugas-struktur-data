#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    
    cout<<"Menghitung jarak antara A dan B"<<endl<<endl;
    
    cout<<"Masukkan koordinat titik A (x1 y1): ";
    cin>>x1>>y1;
    cout<<"Masukkan koordinat titik B (x2 y2): ";
    cin>>x2>>y2;
    
    double jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    cout<<fixed << setprecision(2);
    cout<<"============================================"<<endl;
    cout<<"Hasil jarak antara A dan B: "<<jarak<< endl;
    
    return 0;
}