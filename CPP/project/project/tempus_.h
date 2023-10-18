#include <iostream>
#include <string>
#include <iomanip>
//tempus = time in latin

// planned to keep this public by public inheritance and directly accessed by input_() checking bounds and error implemented in input_() failed

#ifndef MY_TIME_H
#define MY_TIME_H
#include "input_.h"
#include <ctime>

class Tempus{               // strictly public inheritance
protected:
        int year=0;
        int month=0;        // to indicate date invalid
        int day=0;
        int weekday; // 0 = sun 6 = sat

        int week_day( int y, int m, int d){ // possible bug on irrelevant pass of data
            return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7 ;
            //https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
        }

        int days_in_month(int y, int m){  // possible bug on irrelevant pass of data
            const int month[]={29,31,28,31,30,31,30,31,31,30,31,30,31};   // m=0 is leap year feb
            if( m == 2){ m = (  (y%400==0) || (y%4==0 && y%100!=0)  ) ? 0 : 2 ; }  //for feb
        return month[m] ;
        }

        const std::string week_day_name[7] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

public:

    void current_date(){
        std::time_t t;
    // t=std::time (&t );
        t=std::time (NULL);
        std::tm* local_tm= std::localtime ( &t);
        year      = local_tm->tm_year +1900  ;
        month     = local_tm->tm_mon + 1     ;
        day       = local_tm->tm_mday        ;
        weekday   = local_tm->tm_wday        ;
    }

    void set_date(std::string str=""){
        std::cout << str << std::endl;     // display passed string argument
        int x, n, flag;

        do{ // year
            flag=0;
            input_(" enter the year ( 1920 - 2100 ) ", &x);
            if (1920<x && x<2100)
                year=x;
            else
                flag = 1;
        }while (flag);

        do{  // month
            flag=0;
            input_(" enter the month ( 1 - 12 )", &x);
            if (0<x && x<13)  // valid data 1 to 12
            month=x;
            else
                flag = 1;
        }while (flag);

        n=days_in_month( year,  month);

        do{  // day
            flag=0;
            std::cout<< "enter the day ( 1 - "<< n <<")";
            input_("", &x);
            if (0<x && x<=n)  // valid data 1 to 12
                day=x;
            else
                flag = 1;
        }while (flag);

        weekday= week_day(  year,  month,  day);
    }
    int get_year() { return year ;}
    int get_month() { return month ;}
    int get_day() { return day  ;}
    int get_weekday() { return weekday ;}


    void show_date(std::string str=""){  // argument to print the passed header of the date;
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

initiate both here;
*/
#endif //MY_TIME_H
