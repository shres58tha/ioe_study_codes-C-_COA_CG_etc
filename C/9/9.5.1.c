// program create a structure array and sort the array based on different basis refined
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

typedef struct time_0{
        double sec;  // just a tewak to make calculation more effecient;
        int hour;
        int minute;
        float second;
    } stm;
/// use typedef for reducing and  making code easier

stm read_time_0(void){
       stm ret_val;
       float t;
       double tmp_sec=0;
       printf(" \n this program should handle time enterd in any format either hr:mn:sec.00 | hr.00 | mins.00 |seconds \n ");
       printf(" Enter a hour  :");scanf("%f",&t);   tmp_sec += t*3600; // accumulate in Terms in sec
       printf(" Enter a minute  :");scanf("%f",&t); tmp_sec += t*60;   // accumulate in Terms in sec
       printf(" Enter a second  :");scanf("%f",&t); tmp_sec += t;      // accumulate in Terms in sec

            ret_val.sec=tmp_sec;
            ret_val.hour = (int)(tmp_sec/3600);  tmp_sec -= ret_val.hour*3600;
            ret_val.minute = (int)tmp_sec/60;    tmp_sec -= ret_val.minute*60;
            ret_val.second = tmp_sec;

        return (ret_val);
     }
/***** looks like format specifier mismatch in the printing of value of pointer or member or struct causes a several headace and sleepless night bug
                                             be very careful on this .

                                             ****************/
void print_time_0(struct time_0 *p){
        if ((*p).sec >=0) printf("  %d hr :   %d mn :  %.3f s \t\"OR\"  %d:%d:%.3f",(*p).hour,(*p).minute,(*p).second,(*p).hour,(*p).minute,(*p).second);
        //printf(" %d hr :  %d mn : %.3f s ",(*p).hour,(*p).minute,(*p).second);  // refering to the loaction at which the  real data is stored
        else {printf(" %d hr :  %d mn : %.3f s ",(*p).hour,(*p).minute,(*p).second);
              int hr=-(*p).hour,mn=-(*p).minute;
              float sc=-(*p).second;
              printf("\t\"OR\" -%d:%d:%.3f",hr,mn,sc);

             }
}


stm sum_time_0(struct time_0 *p,struct time_0 *t){
      stm ret_val;
         double tmp_sec=0;
                //tmp_sec=(p->hour + t->hour)*3600 + (p->minute + t->minute)*60 +  p->second + t->second;
                tmp_sec= p->sec + t->sec;
                ret_val.sec=tmp_sec;
                ret_val.hour = (int)(tmp_sec/3600);  tmp_sec -= ret_val.hour*3600;
                ret_val.minute = (int)tmp_sec/60;    tmp_sec -= ret_val.minute*60;
                ret_val.second = tmp_sec;

            return ret_val;

    }
stm diff_time_0(struct time_0 *p,struct time_0 *t){
      stm ret_val;
         double tmp_sec=0;
                //tmp_sec=(p->hour - t->hour)*3600+(p->minute - t->minute)*60+p->second - t->second;
                tmp_sec= p->sec - t->sec;
                ret_val.sec=tmp_sec;
                ret_val.hour = (int)(tmp_sec/3600);  tmp_sec -= ret_val.hour*3600;
                ret_val.minute = (int)tmp_sec/60;    tmp_sec -= ret_val.minute*60;
                ret_val.second = tmp_sec;

            return ret_val;

    }


int main(){

        stm time1, time2, time_diff, time_sum;
        time1=read_time_0();
        time2=read_time_0();
        time_diff=diff_time_0(&time1,&time2);
        time_sum=sum_time_0(&time1, &time2);
        printf("\n");
        printf("time 1 =");print_time_0(&time1); printf("\n");
        printf("time 2 =");print_time_0(&time2); printf("\n");
        printf("time difference = ");print_time_0(&time_diff); printf("\n");
        printf("total time      = ");print_time_0(&time_sum); printf("\n");
        printf("\n");


return 0;

}
