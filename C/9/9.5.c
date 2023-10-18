
// program create a structure array and sort the array based on different basis
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#define Sz 5
#define MAX_LIMIT 50
/************   oth approach reject any misvalid data entered by the user but still we have to deal with overflows in case of addition or subs


                three approachs are possible to deal with the multiple interlinked value in the time struct.
                1st always make sure the data contained in the struct is in standard format and reflect what the actual value of hr min and sec is always
                        cumbersome and inefficeint while doing mathmatical operation in the data
                2nd get the whatever value enterred or provided in floating point and store it as it is until the end do mathmatical operation in raw data
                ie 3 floating point variables and on program terminates of print convert that to standard format once.
                3rd store all the data in the floating point lets say min and return the appropriate part ie hr and sec when print is requested else operate
                on the single floating point data.// this will be the most appropriate based on no of steps required in the calculation but will require
                internal fuction and private data which is domain of c++
                **********************************************************************************************************************************************/

                /****here approach 1st is done lot of headache and sleepless hr to complete and understand all this****/
                /****no debug info or information regarding this in the book or internet, needed to workout all steps and error points ****/
                /***    by umesh kr. shrestha  ************/
                /*** note : do not modify any part of this code *******/

/// error typedef struct time_0 stime; // defined here to avoid typing struct time_0 every time  //  stime already defined in time.h

struct time_0{

        int hour;
        int minute;
        float second;
    };
/// use typedef for reducing and  making code easier

void put_tm_in_std(struct time_0 *p); // prototype cause it is hard to get track of dependency of function now or do not want to change all the functions position


void read_time_0(struct time_0 *p){
       float hr=0,mn=0,sc=0, temp; int temp1,temp2,x;
       printf(" \n this program should handle time enterd in any format either hr:mn:sec.00 | hr.00 | mins.00 |seconds \n ");
       printf(" Enter a hour  :");scanf("%f",&temp);
            temp1=(int) temp;
            hr=temp1;
           // printf("temp1  %f temp  %f ",temp1 , temp);
            if (temp1!= temp) {mn=(temp-temp1)*60;}
            
       printf(" Enter a minute  :");scanf("%f",&temp);
            temp=temp+mn; // add whatever value that mn got from fractional part from hr now temp contains all the val in min
            temp1=(int) temp;  // extract the int part
            if (temp1!= temp) {sc=(temp-temp1)*60;}          // if mn has decimal part put that into sc multiplied by 60
            
            if (temp1/60>0) {x=temp1/60;hr+=x; mn=temp1-x*60;} // if the integral part of min is greater than 60 adjust into hr then mn
            else {mn=temp1;}
            
       printf(" Enter a second  :");scanf("%f",&temp);
            temp=temp+sc; // add wahtever value that sc got from fractional part of mn now temp contains all the val in sec
            temp1=(int) temp;  // extract the int part
            
            if (temp1/60>0) {x=temp1/60;mn+=x; sc=temp-x*60;} // if the integral part of sc > 60 adjust into mn & rem is sc 
            else {sc=temp;}  
            
            //following line are neededto check to see if mn has overflown 60 if so adjust and put it in hr 
            if (mn>60){x=mn/60; hr+=x;mn=mn-x*60;}//  mn should should be int only so no need to check for decimal part 
           
    
    // initializing the struct elements
        p->hour = (int)hr;
         p->minute = (int)mn;
        p->second = sc;
/**************************************************
        printf("\n hr :%f",hr);
        printf("\n mn  :%f",mn);
        printf("\n sc  :%f\n",sc);

        printf("\n hour  :%d",p->hour);
        printf("\n minute  :%d",p->minute);
        printf("\n second  :%f \n\n",p->second);


       printf("hour : %d  ",(*p).hour);  // refering to the loaction at which the data real is stored
       printf("minutes: %d  ",(*p).minute);
       printf("seconds: %f  ", (*p).second);
       //*************************************************/

     }
/***** looks like format specifier mismatch in the printing of value of pointer or member or struct causes a several headace and sleepless night bug
                                             be very careful on this .

                                             ****************/
void print_time_0(struct time_0 *p){
       printf(" %.d hour ",(*p).hour);  // refering to the loaction at which the data real is stored
       printf(": %d min ",(*p).minute);
       printf(": %.2f sec ", (*p).second);
     }



struct time_0 diff_time_0(struct time_0 *p,struct time_0 *t){
      struct time_0 ret_tm;
            ret_tm.hour=p->hour - t->hour;
            ret_tm.minute=p->minute - t->minute;
            ret_tm.second=p->second - t->second;
            put_tm_in_std(&ret_tm);

            return ret_tm;

    }

void put_tm_in_std(struct time_0 *p){
        /********************this code is heavy and complicated but should work only half part is done realized that there is a easy way around******************
        int tmp;
        if (p->hour >0){ //if (p->minute >60||p->minute<60)
                       //{p->hour=p->hour + (p->minute/60);p->minute=p->minute%60;}
                        tmp=(p->minute/60); if (tmp!=0) {p->hour +=tmp;p->minute -=tmp*60;} // better code due less test of logic and math function used

                        }
        if (p->minute >0){
                        tmp=(int)(p->second/60); if (tmp!=0) { if (tmp!=0) {p->minute +=tmp;p->second -=tmp*60;}
                                                               if (tmp>60) {p->hour +=tmp/60;p->minute -=tmp*60;}
                                                                }

                            }

        if (p->second>60||p->second<60){ tmp= (int)(p->minute/60); p->minute = p->minute + tmp;
                                        if (p->second>0)p->second = p->second - tmp*60;
                                        else p->second = tmp*60-p->second;}
        if (p->minute >60||p->minute<60){p->hour=p->hour + (p->minute/60);p->minute=p->minute%60;}


        else printf("p->minute :  %d\n",p->minute );

    } ***************************************************/// would fi it some day
    
        
    ///*// convert allto seconds   
    long double sec;
        sec= 3600*p->hour +  60*p->minute  +  p->second ;

        p->hour=(int) (sec /3600); sec=sec -3600*p->hour;
        p->minute= (int) (sec/60); sec=sec -60*p->minute;
        p->second=sec;
     ///////*/   

}
/******************MAIN*****************************/

int main(){

        struct time_0 time1, time2, time_diff ;
        read_time_0(&time1);
        read_time_0(&time2);
        time_diff=diff_time_0(&time1,&time2);
        /********************************
        printf("\n hour aa :%d",time1.hour); // looks like format specifier mismatch in the printing of value of pointer or member or struct causes a several headace and sleepless night bug
                                            // be very careful on this .
        printf("\n minute aa :%d",time1.minute);
        printf("\n second  aa:%f\n\n",time1.second);
        *************************************/
        printf("\n");
        print_time_0(&time1); printf("\n");
        print_time_0(&time2); printf("\n");
        print_time_0(&time_diff); printf("\n");
        printf("\n");


return 0;

}
