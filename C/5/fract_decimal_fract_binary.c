
//C code for fractional decimal to binary converter: 
//copied from the https://www.cquestions.com/2011/07/c-program-for-fractional-decimal-to.html
//NOTE modify it to make it universal


#include<stdio.h>

int main(){
   
    long double fraDecimal,fraBinary,bFractional = 0.0,dFractional,fraFactor=0.1;
    long int dIntegral,bIntegral=0;
    long int intFactor=1,remainder,temp,i;

    printf("Enter any fractional decimal number: ");
    scanf("%Lf",&fraDecimal);
   
    dIntegral = fraDecimal;
    dFractional =  fraDecimal - dIntegral;

    while(dIntegral!=0){
         remainder=dIntegral%2;
         bIntegral=bIntegral+remainder*intFactor;
         dIntegral=dIntegral/2;
         intFactor=intFactor*10;
    }

   for(i=1;i<=20;i++){
      
       dFractional = dFractional * 2;
       temp =  dFractional;
        
       bFractional = bFractional + fraFactor* temp;
       if(temp ==1)
             dFractional = dFractional - temp;

       fraFactor=fraFactor/10;
   }
  
   fraBinary =  bIntegral +  bFractional;
   printf("Equivalent binary value: %Lf\n",fraBinary);
   
   return 0;
}
