/* wap to add two matrices by overloading + operator*/
#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

class matrix{
    int mat[ROW][COL];
public:
    matrix ( ){       //making sure that all the elements in matrix are 0 on creation
        for (int i=0; i< ROW ; i++){
            for (int j=0; j<COL; j++){
                mat[i][j]=0;
            }
        }
    }
    matrix (int val[][COL]){    // implicit overloading of =
        for (int i=0; i< ROW ; i++){
            for (int j=0; j<COL; j++){
                mat[i][j]=val[i][j];
            }
        }
    }
    matrix operator +(matrix);   // declaration
    
    void display()const{
        for (int i=0; i< ROW ; i++){
            cout <<endl;
            for (int j=0; j<COL; j++){
                cout <<"\t"<<mat[i][j];
            }
        }
        cout <<endl;
    }
    
};

matrix matrix::operator +(matrix m1){  //definition needs the scope resolution operator
    matrix ret;
    for (int i=0; i< ROW ; i++){
            for (int j=0; j<COL; j++){
                ret.mat[i][j] = this->mat[i][j] + m1.mat[i][j];
            }
        }
    return ret;
}

int main(){
    int v1[][3]={{1,2,3},{4,5,6},{7,8,9}};
    matrix m1(v1), m2, m3;  //default constructor invoked only if no brackets are there somehow m1()!= m1  
    // presense of empty ()  ie m1() is not valid somehow
    //error: non-class type matrix() 
    m2=v1;
    m3 = m1 + m2;
    m3.display();
    m1.display();
return 0;
}
