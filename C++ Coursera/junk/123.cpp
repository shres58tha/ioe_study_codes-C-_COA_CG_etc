#include <iostream>
using namespace std;
int main()
{
int grade;
char letter_grade = 'Z';
// from 0 to 100
// A, B, C, D, F, or Z
cout << "Enter Your Number Score:" << endl;
cin >> grade;
grade = (grade > 100) ? 1000 :grade;
switch (grade/10) {
case 10: cout << " First in Class!\n";
letter_grade = 'A';
break;
case 9: cout << " Congratulations!\n";
letter_grade = 'A';
break;
case 8: cout << " Very Good\n";
letter_grade = 'B';
break;
case 7: cout << " Okay\n";
letter_grade = 'C';
break;
case 6: cout << " Work harder\n";
letter_grade = 'D';
break;
case 5: case 4: case 3: case 2: case 1: case 0:
cout << " Sorry you failed\n";
letter_grade = 'F';
break;
default: cout << " Not a recognizable grade"
<< endl;
}
cout << "Your grade was " << letter_grade
<< endl;
}
