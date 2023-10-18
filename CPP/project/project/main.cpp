#include <iostream>
#include "input_.h"
#include "tempus_.h"
#include "institute_.h"
#include "work_.h"
#include "human_.h"
//#include "faculty_.h"
#include "employee.cpp"
#include "worktime_.cpp"
using namespace std;

int main(){
Work ram;
ram.start.set_date("\n start date :");
//ram.current.current_date();
//ram.current.show_date("\n current date :");


//ram.input_work_nature();
ram.input_work_rec();
ram.display_work_rec();

Employee one;
    one.set_type_();
    one.display_work_nature();
    one.input_work_rec();
    one.get_work_rec();
    one.edit_work_rec();
    one.input_work_nature();
    one.display_work_rec();  // invalid time set caused segmentation fault here fix it later
    one.get_work_rec();
    one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
one.get_work_rec();
  //  one.set_work_nature();
return 0;
}
