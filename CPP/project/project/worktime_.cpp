
// reference https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
// weekday= (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7
// where    d == day of month; // value not perserved
//          m=month (1-12)
//          y= year (####)
//          weekday ( 0 to 6)

#include "work_.h"
#include "tempus_.h"
#include "input_.h"
// function

/*
int main(){
Work ram;
ram.start.set_date("\n start date :");
//ram.current.current_date();
//ram.current.show_date("\n current date :");


//ram.input_work_nature();
ram.input_work_rec();
ram.display_work_rec();


}
*/
