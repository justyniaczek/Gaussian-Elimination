#include <iostream>
#include <cmath>

using namespace std;
int main(){
    double B[5] ={2.0, 2.0, 2.0, 2.0, 2.0};
    double A[5] ={0.0, -1.0, -1.0, -1.0, -1.0};
    double C[5] = { -1.0, -1.0, -1.0, -1.0, 0.0};
    double X[5] , Rho[5], Beta[5];
    double R[5] = {0.0, 1.0, 2.0, 3.0, 4.0};

    //calculate beta and rho
    Beta[0] = B[0];
    Rho[0] = R[0];

    for(int i =1; i<5; i++){
        Beta[i] = B[i] - (( A[i] / Beta[i-1]) * C[i-1]);
        Rho[i] = R[i] - ((A[i] / Beta[i-1]) * Rho[i-1]);

    }
    X[4] = Rho[4]/ Beta[4];

    //calculate x
    for( int j =1; j <5;j++){

        X[4-j] = (Rho[4-j] - C[4-j] * X[4 - j +1]) / Beta[4- j];
    }

    //write solution
    cout<< " Solution x:"<<endl;
    for( int i = 0; i< 5; i++){
        cout<< "x "<< i+1 <<"= "<<X[i]<<endl;
    }
    //Check solution
	cout<<"\nCheck solution (values of r):"<<endl;
	cout<<"r1= "<<B[0]*X[0]+C[0]*X[1]<<endl;
	cout<<"r2= "<<A[1]*X[0]+B[1]*X[1]+C[1]*X[2]<<endl;
	cout<<"r3= "<<A[2]*X[1]+B[2]*X[2]+C[2]*X[3]<<endl;
	cout<<"r4= "<<A[3]*X[2]+B[3]*X[3]+C[3]*X[4]<<endl;
	cout<<"r5= "<<A[4]*X[3]+B[4]*X[4]<<endl;

return 0;
}
