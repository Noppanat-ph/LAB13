#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]){
    double max = a[0], min = a[0], sum = 0, Amean, SDevia, Gmean = 1, Hmean;
    
    for(int i=0; i<n; i++){
        sum = sum+a[i];
    }
    
    Amean = sum/n;
    
    for(int i=0; i<n; i++){
        SDevia = SDevia + pow(a[i]-Amean,2);
    }
    SDevia = sqrt(SDevia/n);

    for(int i=0; i<n; i++){
        Gmean = Gmean * a[i];
    }
    Gmean = pow(Gmean,1.0/n);
    
    for(int i=0; i<n; i++){
        Hmean = Hmean + 1/a[i];
    }
    Hmean = n/Hmean;

    for(int i=1; i<n; i++){
        if(a[i]>max) max = a[i];
        if(a[i]<min) min = a[i];
    }
    
    b[0]=Amean;
    b[1]=SDevia;
    b[2]=Gmean;
    b[3]=Hmean;
    b[4]=max;
    b[5]=min;
}