#include <iostream>
using namespace std;

int main(){
   float s = 12.3412;
   int perfectSqaure = 0;
   int n = 0;
   for (int i = static_cast<int>(s); i > 0; i--) {
      for (int j = 1; j<i; j++){
         if (j*j == i){
            perfectSqaure = i;
            n = j;
            break;
         }
      }
      if (perfectSqaure > 0)
      break;
   }
   float d = s - perfectSqaure;
   float P = d/(2.0*n);
   float A = n+P;
   float rootOfs = A-((P*P)/(2.0*A));
   cout<<"The square root of "<<s<<" = "<<rootOfs;
   return 0;
}
