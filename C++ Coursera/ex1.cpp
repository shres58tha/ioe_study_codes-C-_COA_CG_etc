/*
2D vector
int no_of_cols = 5;
int no_of_rows = 10;
int initial_value = 0;

std::vector<std::vector<int>> matrix;
matrix.resize(no_of_rows, std::vector<int>(no_of_cols, initial_value));

// Read from matrix.
int value = matrix[1][2];
*/

#include <iostream>
using namespace std;

class point{
public:
    point(double a=0.0, double b=0.0) {x = a; y = b;}
    double getx() {return x;}
    void setx(double z) {x = z;}
    double gety() {return y;}
    void sety(double z) {y = z;}
private:
    double x, y;
};

point operator+(point &a, point &b) {
    point c(a.getx()+b.getx(), a.gety()+b.gety());
    return c;
}
ostream& operator<<(ostream& out, point &p) {
    out << "( " << p.getx() << ", " << p.gety() << " )";
    return out;
}

int main() {
    point a(2.5, 4.5);
    point b(2.5, 4.5);
    point c;
    cout << "a = " << a << ", b = " << b << endl;
    c = a + b;
    cout << "sum = " << c << endl;
}
