#include "work_.h"
// short function inline hence commented out here
//void Work::set_work_nature(char ch){work_nature=ch;}
void Work::input_work_nature(){
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

void  Work::input_work_rec(std::string str="") {
    std::cout << str << std::endl;     // display passed string argument
    int temp;
    current.current_date();current.show_date("\n current date :");
    int y , m ;
    
    std::cout<<"start.get_year()"<<start.get_year()<< start.get_month()<<std::endl;
    
    if (start.get_year()==0){std::cout<<"start time not set\nproperly initialize the person/employee\n"; return ;}
    y=current.get_year()-start.get_year();   // y {0 to n}; 1st index to vector array
    m=current.get_month()-start.get_month(); // month varies from 1 to 12
    m+=12;                                   // making sure m is always +ve
    m%=12;   //here m varies from 0 to 11 and acts as the 2nd index to vector array 
    if (recorded_y < y){
        std::vector<int>v;  //just a place holder
        work_rec.push_back( v );
        work_rec[y].resize(12);             // vector is great somehow it works ..
        recorded_y=y;
    }
    input_("enter no of work units :", &temp);
    work_rec[y][m]=temp;
}

//char  Work::get_work_nature(){return work_nature;}
//int   Work::get_recorded_y(){return recorded_y;}
int   Work::get_work_rec(){
    current.current_date();current.show_date("\n current date :");
    int y,m, temp_y,temp_m, ret_val, count_loop=5;
    bool val;
    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){ break; }
        }
         while (1){
            input_( "enter the month :",&m);
            if (0<m && m<13){ break; }
        }
        std::cout<<"the data for  year : " << y <<" & month : "<<m<<std::endl;        
        temp_y=y-start.get_year();   // temp_y varies from 0 to n act as 1st index to vector array
        temp_m=m-start.get_month(); // month varies from 1 to 12
        temp_m+=12;                                   // making sure m is always +ve
        temp_m%=12;   //here temp_m varies from 0 to 11 and acts as the 2nd index to vector array 
        if (temp_y>=0 &&y <=current.get_year() ){  // m is always valid and returns 0 to uninitialized months so no worries
            ret_val=work_rec[y][m];
            return ( ret_val);
            }
        else 
            //std::cout << " entered year before start year; remaining try :"<< count_loop <<std::end;
        
        count_loop--;
        if (count_loop<1)break;  // this should be never executed unless
    }
}
//void  Work::display_work_nature(){ std::cout<<"work_nature :"<<work_nature<<std::endl; }
void  Work::display_work_rec(std::string str=""){
    int y,m, temp_y,temp_m, count_loop=5;
    int start_y=start.get_year();
    int current_y=current.get_year();
    bool val;
    std::cout << str << std::endl;     // display passed string argument
    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){break; }
        }
   
        std::cout<<"the data for  year " << y <<std::endl;        
        temp_y=y-start_y;   // temp_y varies from 0 to n act as 1st index to vector array
        temp_m=m-start.get_month(); // month varies from 1 to 12
        temp_m+=12;                                   // making sure m is always +ve
        temp_m%=12;   //here temp_m varies from 0 to 11 and acts as the 2nd index to vector array 
        if (temp_y>=0 && y <= current_y) {  // m is always valid and returns 0 to uninitialized months so no worries
            std::cout  <<" month :";
            for ( int i=1 ; i<13 ; i++)       { std::cout<<std::setw(4)<< i ; } std::cout  <<std::endl;
            
            std::cout  <<" work "<<work_nature<<":";
            for ( int x : work_rec[temp_y])   { std::cout<<std::setw(4)<< x ; } std::cout  <<std::endl;
            break;
            }
        else {         
            std::cout << " invalid out of range year ; (max "<<count_loop<<" time)"<<std::endl;
            std::cout <<" valid range is " <<start_y<<"to "<<current_y  <<std::endl;
        }
        count_loop--;
        if (count_loop<1)break;  // this should be never executed unless 
        }
}



//void  Work::edit_work_nature (){ input_work_nature();}  //alias

void  Work::edit_work_rec(){
    current.current_date();current.show_date(" \n current date :");  //not necessary here for calc
    int y,m, temp_y,temp_m,count_loop=5;
    bool val;
    while (1){
        while (1){
            input_( "enter the year :",&y);
            if (1920<y && y<2150){break; }
        }
        while (1){
            input_( "enter the year :",&m);
            if (0<m && m<13){break; }
        }
    
        std::cout<<"the data to be changed is for year :" << y <<"and month "<<m<<std::endl;
        std::cout<<"to continue press y else any key :"<<std::endl;
        
        temp_y=y-start.get_year();   // temp_y varies from 0 to n act as 1st index to vector array
        temp_m=m-start.get_month(); // month varies from 1 to 12
        temp_m+=12;                                   // making sure m is always +ve
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
