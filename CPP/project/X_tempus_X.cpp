#include "tempus_.h"

    void Tempus::current_date(){
        std::time_t t;
    // t=std::time (&t );
        t=std::time (NULL);
        std::tm* local_tm= std::localtime ( &t);  
        year      = local_tm->tm_year +1900  ;
        month     = local_tm->tm_mon + 1     ;
        day       = local_tm->tm_mday        ;
        weekday   = local_tm->tm_wday        ;
    }

    void Tempus::set_date(std::string str=""){
        std::cout << str << std::endl;     // display passed string argument
        int x, n, flag;
        
        do{ // year
            flag=0;
            input_(" enter the year ", &x);
            if (1920<x && x<2150)
                year=x;
            else 
                flag = 1;
        }while (flag);
        
        do{  // month
            flag=0;
            input_(" enter the month ", &x);
            if (0<x && x<13)  // valid data 1 to 12
            month=x;
            else 
                flag = 1;
        }while (flag);
        
        n=days_in_month( year,  month);
        
        do{  // day
            flag=0;
            input_(" enter the day ", &x);
            if (0<x && x<n)  // valid data 1 to 12
                day=x;
            else 
                flag = 1;
        }while (flag);
        
        weekday= week_day(  year,  month,  day);
    }
//    int get_year() { return year ;}
//    int get_month() { return month ;}
//    int get_day() { return day  ;}
//    int get_weekday() { return weekday ;}
    
    
    void Tempus::show_date(std::string str=""){  // argument to print the passed header of the date;
        std::cout <<     str \
             << "\nYYYY / MM / DD\n"   <<std::setfill('0')  // setfill need to be turned  off
             <<std::setw(4)<< year     <<" / " 
             <<std::setw(2)<< month    <<" / " 
             <<std::setw(2)<< day      <<" ; " 
             <<std::setw(2)<< week_day_name[weekday] 
             <<std::setfill(' ')<<std::endl ;                  //undo setfill
    }
    
    
};

/* plan to start following in the main 
Tempus current_d;
Tempus temp_time;            //temp_ name used somewhere i guess in ctime may be
temp_d.set_date();
current_d.current_date(); // local time should be better in the loop
std::time_t t=std::time (NULL);   // can be used as time stamp
*/
