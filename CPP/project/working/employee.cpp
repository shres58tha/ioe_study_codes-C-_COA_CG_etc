#include <iostream>
#include <string>
using namespace std;

#include "human_.h"
#include "work_.h"

class Employee: public Human, public Work{  // inherit account  // inherit faculty.
protected:
    int index=0;
    char nat[5]={'\0','m','p','h','d'};
    const std::string nature[5]={"\0","full time ", "part time ", "temp_hr ","temp_day "} ;
    // automatize the nature of work in the work class too
    
public:
    void set_type_(){
        for ( int i=1; i<5;i++){ 
            std::cout<<i<<".) "<< nature[i]<<std::endl;
        }
        std::cout << std::endl;
        input_( "enter the type of employee by selecting above number : ", &index);
        
        Work::set_work_nature( nat[index]);
    }
    
};

int main(){
    Employee one;
    one.set_type_();
    one.display_work_nature();
return 0;
}
