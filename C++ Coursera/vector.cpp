#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	// input array
	int src[] = { 1, 2, 45, 4, 5 };
	int n = sizeof(src) / sizeof(src[0]);

	std::vector<int> dest(src, src + n);

	for (int i: dest) {
		std::cout << i << " ";
	}
        std::cout <<endl;
	return 0;
}
