#include <iostream>
#include <string>
using namespace std;
#include <iostream>
// S has one non-static data member (tag), three enumerator members, 
// and three variant members (c, n, d)
struct S
{
    enum {CHAR, INT, DOUBLE} tag;
    union {
        char c;
        int n;
        double d;
    };
};
 
void print_s(const S& s)
{
    switch(s.tag)
    {
        case S::CHAR: std::cout << s.c << '\n'; break;
        case S::INT: std::cout << s.n << '\n'; break;
        case S::DOUBLE: std::cout << s.d << '\n'; break;
    }
}
int main()
{
    S s = {S::CHAR, 'a'};
    print_s(s);
    s.tag = S::INT; s.n = 123;
    print_s(s);
}
