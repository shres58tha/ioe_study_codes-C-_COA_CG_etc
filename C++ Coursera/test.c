#include <iostream>
#include <iterator>
#include <algorithm>
// by reference
template<class T>
void demo1(const T& a) {
    for(const auto& row: a) {
        for(const auto& n: row) std::cout << n << ' ';
        std::cout << '\n';
    }        
}
// as an iterator pair
template<class I>
void demo2(I beg, I end) {
    std::for_each(beg, end, [](const auto& row) {
        for(const auto& n: row) std::cout << n << ' ';
        std::cout << '\n';
    });
}
int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    demo1(a);
    demo2(std::begin(a), std::end(a));
}


/*
 * #include <iostream>

template<typename T, std::size_t N, std::size_t M>
void increment_2D(T (&a)[N][M])
{
    for(std::size_t n = 0; n < N; ++n)
        for(std::size_t m = 0; m < M; ++m)
            ++a[n][m];
}

int main()
{
    int a[4][2] = {1,2,3,4,5,6,7,8};
    increment_2D(a);
    for(auto& r: a) {
        for(int n: r)
           std::cout << n << ' ';
        std::cout << '\n';
    }
}
*/
/*
 * Multi-dimensional arrays are not very well supported by the built-in components of C and C++. You can pass an N-dimension array only when you know N-1 dimensions at compile time:

calculateDeterminantOfTheMatrix( int matrix[][123])
However, the standard library supplies std::vector container, that works very well for multi-dimension arrays: in your case, passing vector<vector<int> > &matrix would be the proper way of dealing with the task in C++.

int calculateDeterminantOfTheMatrix(vector<vector<int> > &matrix) {
    int res = 0;
    for (int i = 0 ; i != matrix.size() ; i++)
        for(int j = 0 ; j != matrix[i].size() ; j++)
            res += matrix[i][j];
    return res;
}
As an added bonus, you wouldn't need to pass dimensions of the matrix to the function: matrix.size() represents the first dimension, and matrix[0].size() represents the second dimension.

 ------------------------------------------------------------------------------------------------------

I would write a simple class wrapper for the matrix with column and row defined.

template <typename T>
class Mat {
  std::size_t _row;
  std::size_t _col;

  T *_mat_elem;
public:
  Mat(std::size_t r, std::size_t c)
   :  _row(r), _col(c), _mat_elem(new T[r*c] {}
  ~Mat() {}///*remember to do delete [] here }

  // element access, for example
  T& at(std::size_t r, std::size_t c)
  {
    return *(_mat_elem+r*_col+c);
  }
};
But actually you are re-inventing the wheels. There are good libraries for matrix handling out there.

------------------------------------------------------------------------------------
The Best way to use 2D array in the function that I have found so far is to use Mapping Function. As in the example below , I have use the mapping function to print 2D array

void Print2D(int x[],int ROWS,int COLS)
{
    for(int i=0;i<ROWS;i++)
{
    for(int j=0;j<COLS;j++)
    cout << x[i*COLS+j] << ' ';
    cout << endl;

}
}
Here it is how to use it in main

int main(){

    int x[3][3];
    Print2D(&x[0],3,3);

}
Here &x[0] is the starting address of the First Row of 2D array or more precisely Starting address of 2D array

*/
