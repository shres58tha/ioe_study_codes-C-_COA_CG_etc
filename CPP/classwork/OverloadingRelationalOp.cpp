 /*
  *  write the relational operator to compare length meter and cm
  */
 
 #include <iostream>
 using namespace std;
 
 class length {
 private:
     int m, cm;
 public:
     length ( int a , int b): m(a), cm(b){}
     bool operator <( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1<temp2);
     }
     bool operator >( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1>temp2);
     }
     bool operator <=( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1<=temp2);
         
     } 
     bool operator >=( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1>=temp2);
     } 
     bool operator ==( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1==temp2);
         
     }
     bool operator !=( length& d) {
         int temp1, temp2;
         temp1= 100*m+cm;
         temp2= d.m*100 +d.cm;
         return (temp1!=temp2);
         
     }
 };
 int main (){
     length a(5,6), b(4,3);
     cout << std::boolalpha;
     cout <<" a<b "<<bool (a<b) <<endl;
     cout <<" a>b "<<bool (a>b) <<endl;
     cout <<" a<=b "<<bool(a<=b) <<endl;
     cout <<" a>=b "<<bool(a>=b) <<endl;
     cout <<" a==b "<<bool(a==b) <<endl;
     cout <<" a!=b "<<bool(a!=b) <<endl;
 }
 
