// program create a structure and calculation if time

typedef struct time_0{
        int hour;
        int minute;
        int second;
    } stm;
/// use typedef for reducing and  making code easier

stm read_time_0(void){
       stm ret_val;
       int t;
       long tmp_sec=0;
       printf(" Enter a hour  :");scanf("%d",&t);   tmp_sec += t*3600; // accumulate in Terms in sec
       printf(" Enter a minute  :");scanf("%d",&t); tmp_sec += t*60;   // accumulate in Terms in sec
       printf(" Enter a second  :");scanf("%d",&t); tmp_sec += t;      // accumulate in Terms in sec

            ret_val.hour = tmp_sec/3600;  tmp_sec -= ret_val.hour*3600;
            ret_val.minute = tmp_sec/60;  tmp_sec -= ret_val.minute*60;
            ret_val.second = tmp_sec;

        return (ret_val);
     }
                                           
void print_time_0(struct time_0 p){
       if (p.second<0)
       printf("- %d : %d : %d",-p.hour,-p.minute,-p.second);
       else
       printf("  %d : %d : %d",p.hour,p.minute,p.second);
     }


stm sum_time_0(stm p,stm t){
      stm ret_val;
         long tmp_sec=0;
                tmp_sec=(p.hour + t.hour)*3600 + (p.minute + t.minute)*60 +  p.second + t.second;
                ret_val.hour = tmp_sec/3600;  tmp_sec -= ret_val.hour*3600;
                ret_val.minute = tmp_sec/60;  tmp_sec -= ret_val.minute*60;
                ret_val.second = tmp_sec;

            return ret_val;

    }
stm diff_time_0(struct time_0 p,struct time_0 t){
      stm ret_val;
      long tmp_sec;
                tmp_sec=(p.hour - t.hour)*3600+(p.minute - t.minute)*60+p.second - t.second;
                ret_val.hour = tmp_sec/3600;  tmp_sec -= ret_val.hour*3600;
                ret_val.minute =tmp_sec/60;   tmp_sec -= ret_val.minute*60;
                ret_val.second = tmp_sec;

            return ret_val;

    }


int main(){

        stm time1, time2, time_diff, time_sum;
        printf("\ntime 1 =\n");
            time1=read_time_0();
        printf("\ntime 2 =\n");
            time2=read_time_0();

        time_diff=diff_time_0(time1,time2);
        time_sum=sum_time_0(time1, time2);
        
        printf("\ntime 1 = ");print_time_0(time1);
        printf("\ntime 2 = ");print_time_0(time2);
        printf("\ntime difference = ");print_time_0(time_diff);
        printf("\ntotal time      = ");print_time_0(time_sum); 
        printf("\n");
        
return 0;

}
