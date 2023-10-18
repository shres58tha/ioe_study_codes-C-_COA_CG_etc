/* code for 
 * if odd print weird
 * if even and in inclusive range of 2 to 5 print not weird
 * if even and in inclusive range of 6 to 20 print weird
 * if even and is greater than 20 print not weird
 */  
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
   
    /*if ( !(n>=6 && n<=20) && ( !(n%2) && ( n>20 ||(n>=2 && n<=5) ) ) )
        // comment very immportant ! operator works immediately on the right hand side variable
        cout << "not weird \n";
    else 
        cout << "weird \n" ;
    */
    
    /*logicx
     * simplify using boolean algebra
     * !(n>=6 && n<=20) equal n<6||n<20
     * (n>=2 && n<=5) is included in case n>1 && n<6 
     * 
     */
    //if (!(n%2) && ( n<6 || n>20 ) )
    /*
    if (!(n%2) && ( (n>1 && n<6) || n>20 )  )   
        cout << "not weird \n";
    else 
        cout << "weird \n" ;
    */
    //using boolean algebra to remove inverse
    if ((n%2) || ( (n<1 || n>6) && n<20 )  )   
        cout << "weird \n";
   else 
        cout << "not weird \n" ;
return 0;
}
        

