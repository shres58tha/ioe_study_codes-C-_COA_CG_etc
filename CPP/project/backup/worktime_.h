#include <iostream>
#include <string>

// planned to keep this public by public inheritance and directly accessed by input_() checking bounds and error implemented in input_()

#ifndef MY_WORKTIME_H
#define MY_WORKTIME_H
#include "input_.h"
#include <ctime>

class worktime{                 // strictly public inheritance 
protected:
    char x;     //d=week_day
                //h=hr
                //p=period
                //m=monthly
    union {  // public in structure access data by work.day
        int day;
        int hr; 
        int period;        
    }work_duration;
    
    int total_work_duration;
    
    struct{
        int year;
        int month;
        int day;
    }
    struct { //public in structure access data by work.day
        int year=0;
        int month=0;        // to indicate date invalid
        int day=0;
        int weekday; // 0 = sun 6 = sat
    }start, current, end;

int week_day( int y, int m, int d){  // no other function other than this need to access this function
    return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7 ;  
    //https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
    // calculate day of the week
}


int days_in_month(int y, int m){
    int x;
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    x=month[m-1];
    if( m == 2){ x=  (  (y%400==0) || (y%4==0 && y%100!=0)  ) ? 29 : 28 ; }  //for feb 
return x ;
}

public:
    
//*
void input_work_duratiion(){  //overloading general function
                            // argument is dummy just for scope resolution of overloading as the members are public and directly accessed below
    int loop;
    char x;
    do {
        input_("choose work type    \
            \n\t d for day          \
            \n\t h for hr           \
            \n\t p for period       \
            \n\t m for monthly" , &x);
        loop=0;
        switch(x){
            case 'd' : 
                input_( "enter the days worked", work_duration->day );
                break;
            case 'h' :
                input_( "enter the hours worked", work_duration->hr );
                break;
            case 'p' :
                input_( "enter the period taken", work_duration->period );
                break;
            case 'm' :
                std::cout <<" monthly "<<std::endl;
                break;
            default:
                std::cout << " invalid selection "<<std::endl;
                loop=1;
            }
        }while (loop);
}
//*/


void current_date(){
	std::time_t t;
   // t=std::time (&t );
    t=std::time (NULL);
    std::tm* local_tm= std::localtime ( &t);  
    current.year      = local_tm->tm_year +1900  ;
    current.month     = local_tm->tm_mon + 1     ;
    current.day       = local_tm->tm_mday        ;
    current.weekday   = local_tm->tm_wday        ;
}

void set_start_date(){
    int x, n, flag;
    
    do{ // year
        flag=0;
        input_(" enter the year ", &x);
        if (1920<x && x<2150)
            start.year=x;
        else 
            flag = 1;
    }while (flag);
    
    do{  // month
        flag=0;
        input_(" enter the month ", &x);
        if (0<x && x<13)  // valid data 1 to 12
            start.month=x;
        else 
            flag = 1;
    }while (flag);
    
    n=days_in_month( start.year,  start.month);
    
    do{  // day
        flag=0;
        input_(" enter the year ", &x);
        if (0<x && x<n)  // valid data 1 to 12
            start.day=x;
        else 
            flag = 1;
    }while (flag);
    
    start.weekday= week_day(  start.year,  start.month,  start.day);
}

void set_end_date(){
    int x, n, flag;
    
    do{ // year
        flag=0;
        input_(" enter the year ", &x);
        if (1920<x && x<2150)
            end.year=x;
        else 
            flag = 1;
    }while (flag);
    
    do{  // month
        flag=0;
        input_(" enter the month ", &x);
        if (0<x && x<13)  // valid data 1 to 12
            end.month=x;
        else 
            flag = 1;
    }while (flag);
    
    n=days_in_month( end.year,  end.month);
    
    do{  // day
        flag=0;
        input_(" enter the year ", &x);
        if (0<x && x<n)  // valid data 1 to 12
            end.day=x;
        else 
            flag = 1;
    }while (flag);
    
    end.weekday= week_day(  end.year,  end.month,  end.day);
}
        
   
};

#endif //MY_TIME_H
