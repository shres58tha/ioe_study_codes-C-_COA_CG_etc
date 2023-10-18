#include <iostream>
#include <string>

// not sure how to handle the file may need to make a separate function in the main.. just for handling the file.

#ifndef MY_WORK_H
#define MY_WORK_H
#include "input_.h"
#include "tempus_.h"
#include <ctime>
#include <vector>

class Work{                 // strictly public inheritance
protected:

    char work_nature;     //d=week_day h=hr  p=period  m=monthly

    int recorded_y=-1; // year in the record as y=0 is valid argument
    int recorded_m=0;
    std::vector<std::vector<int> > work_rec; // for storing the work info for each month in int array [y][m]

//   int grand_total;// functions (sum of all work_time till current time);// not implemented yet
public:
Tempus start, end, current;  //put current and temp in the global universal accessible structure
void set_work_nature(char ch){work_nature=ch;}
void input_work_nature(){
    char x;
        while (1) {
        input_("choose work type    \
            \n\t d for day          \
            \n\t h for hr           \
            \n\t p for period       \
            \n\t m for monthly\n:" , &x);
        if ( x=='d'||x=='h'||x=='p'||x=='m') { work_nature = x; break;}
        }
}

// call these function from here or from the object of class work as obj.start.set_date();
// start.set_date();  start.show_date();  start.get_year(); start.get_month(); start.get_day(); start.get_day(); start.get_weekday();

void input_work_rec(std::string str="") {// here str is just put as a placeholder so to distinguishable when they are called from diff location
    std::cout << str << std::endl;     // display passed string argument
    int temp;
    current.current_date();current.show_date("\n current date :");
    int y , m ;

    std::cout<<"start time YYYY/MM"<<start.get_year()<<" / "<< start.get_month()<<std::endl;

    if (start.get_year()==0){std::cout<<"start time not set\nproperly initialize the person/employee\n"; return ;} //safeguarding
    y=current.get_year()-start.get_year();   // y {0 to n}; 1st index to vector array
    m=current.get_month();//-start.get_month(); // month varies from 1 to 12
    //m+=12;                                   // making sure m is always +ve
    //m%=12;   //here m varies from 0 to 11 and acts as the 2nd index to vector array
    if (recorded_y < y){
        std::vector<int> v;  //just a place holder
        work_rec.push_back( v );
        work_rec[y].resize(12);             // vector is great somehow it works ..
        recorded_y=y;
    }
    input_("enter no of work units :", &temp);
    work_rec[y][m-1]=temp;
}

char get_work_nature(){return work_nature;}
int  get_recorded_y(){return recorded_y;}

int  get_work_rec(){
    current.current_date();current.show_date("\n current date :");
    if (start.get_year()==0){std::cout<<"start time not set\nproperly initialize the person/employee\n"; return 1;} //safeguarding
    int y,m, temp_y,temp_m, ret_val, count_loop=5;
    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){ break; }
        }
         while (1){
            input_( "enter the month :",&m);
            if (0<m && m<13){ break; }
        }
        //////////////////////////////
        //correction
        std::cout<<"the data for  year : " << y <<" & month : "<<m<<std::endl;
        temp_y=y-start.get_year();   // temp_y varies from 0 to n act as 1st index to vector array
        temp_m=start.get_month(); // month varies from 1 to 12
       // temp_m+=12;                                   // making sure m is always +ve
       // temp_m%=12;   //here temp_m varies from 0 to 11 and acts as the 2nd index to vector array
        if (temp_y>=0 &&y <=current.get_year() ){  // m is always valid and returns 0 to uninitialized months so no worries
            ret_val=work_rec[y][temp_m-1];
            return ( ret_val);
            }
        else
            //std::cout << " entered year before start year; remaining try :"<< count_loop <<std::end;

        count_loop--;
        if (count_loop<1)break;  // this should be never executed unless
    }
    return 0;
}
void display_work_nature(){
    std::cout<<"work_nature :"<<work_nature<<std::endl;

}
void display_work_rec(std::string str=""){
    if (start.get_year()==0){std::cout<<"start time not set\nproperly initialize the person/employee\n"; return ;} //safeguarding

    int y,m, temp_y,temp_m, count_loop=5;
    int start_y=start.get_year();
    int current_y=current.get_year();
    std::cout << str << std::endl;     // display passed string argument
    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){break; }
        }

        std::cout<<"the data for  year " << y <<std::endl;
        temp_y=y-start_y;   // temp_y varies from 0 to n act as 1st index to vector array
       //**************temp_m=start.get_month(); // month varies from 1 to 12
        //**************temp_m+=12;                                   // making sure m is always +ve
        //*******temp_m%=12;   //here temp_m varies from 0 to 11 and acts as the 2nd index to vector array

        /// correction
        if (temp_y>=0 && y <= current_y) {  // m is always valid and returns 0 to uninitialized months so no worries
            std::cout  <<" month :";
            for ( int i=1 ; i<13 ; i++)       { std::cout<<std::setw(4)<< i ; } std::cout  <<std::endl;

            std::cout  <<" work "<<work_nature<<":";
            for ( auto& x : work_rec[temp_y])   { std::cout<<std::setw(4)<< x ; } std::cout  <<std::endl;
            break;
            }
        else {
            std::cout <<" invalid out of range year ; (max "<<count_loop<<" time)"<<std::endl;
            std::cout <<" valid range is " <<start_y<<"to "<<current_y  <<std::endl;
        }
        count_loop--;
        if (count_loop<1)break;  // this should be never executed unless
        }
}

void edit_work_nature (){ input_work_nature();}  //alias
void edit_work_rec(){
    current.current_date();current.show_date(" \n current date :");  //not necessary here for calc
    if (start.get_year()==0){std::cout<<"start time not set\nproperly initialize the person/employee\n"; return ;} //safeguarding

    int y,m, temp_y,temp_m,count_loop=5;
    bool val;

    // if year not initilized intilized it
    // if pointer to the work_rec[5] == nullpointer cout<< "year" << year not set";
;    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){break; }
        }
        while (1){
            input_( "enter the month :",&m);
            if (0<m && m<13){break; }
        }

        std::cout<<"the data to be changed is for year :" << y <<"and month "<<m<<std::endl;
        std::cout<<"to continue press y else any key :"<<std::endl;

        temp_y=y-start.get_year();   // temp_y varies from 0 to n act as 1st index to vector array
        //temp_m=m-start.get_month(); // month varies from 1 to 12
        temp_m-=1;                                   // making sure m is always +ve
        temp_m%=12;   //here temp_m varies from 0 to 11 and acts as the 2nd index to vector array
        if (temp_y>=0){  // m is always valid and returns 0 to uninitialized months so no worries
            input_(&val);
            if (val){
                int temp;
                input_( "enter the new value of work_rec :", &temp);
                work_rec[temp_y][temp_m]=temp;
                break;
            }
            else
                break;
        }
        else
          //  std::cout << " enter start.year first (max "<<count_loop<<" time)"<<std::end;


    count_loop--;
    if (count_loop<1)break;  // this should be never executed unless
    }
}

// call these function from here or from the object of class work as obj.start.set_date();
// start.set_date();  start.show_date();  start.get_year(); start.get_month(); start.get_day(); start.get_day(); start.get_weekday();

// end.set_date();
// current.set_date();


};

#endif //MY_TIME_H
