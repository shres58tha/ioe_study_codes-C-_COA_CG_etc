#include <iostream>
#include<vector>// used vector header file to convert array into vector
using namespace std;
const int N = 40;
template <class , class M>// To create generic class
inline  sum(M &sum, int n, vector<T> d)// inline function definition with vector as argument
{
int i;

	for (i = 0; i < n; ++i)

	sum += d[i];
}
int main()
{
int i;

	int accum = 0;

	vector<int> data;

	for (i = 0; i < N; ++i)
	data.push_back(i);// to insert new element in end of vector
sum<int, void>(accum, N, data);
	
cout<<"sum is "<< accum;// used c++ io
	
return 0;
}
