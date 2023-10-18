//program that can add and subtract two time units. 

#include <iostream>
#include <iomanip>
using namespace std;
class time_class{
private:
        int hr=0;
        int min=0;
        int sec=0;
        bool sign = 0;    // 0 = +ve time ; 1 = -ve time
        //long long tot_sec=0;
public:
        time_class( int h=0, int m=0, int s=0){
            if ( h<0 || m<0 || s<0 || s>60 || m>60 ){
                cout<< "Invalid arguments passed";
                exit(1);                                            // 1st error exit
            }
            hr=h; min=m; sec=s;
        }
        // inline member methods by default
        int get_hr() {return hr; }
        int get_min(){return min;}
        int get_sec(){return sec;}
        void set_hr (int h){ 
            if (h <0 ){
                cout<< "Error! in input"<<endl;
                exit (2);                   // diff error values for debug
            }
            hr = h;
        }
        void set_min(int m){
            if (m<0 || m>60){
                cout<< "Error! in input"<<endl;
                exit (3);
            }                              // diff error values for debug
            min = m;
        }
        void set_sec(int s){
            if (s<0 || s>60){
                cout<< "Error! in input"<<endl;
                exit (4);                  // diff error values for debug
            }
            sec = s;
        }
        void display (){
            cout<< "HH:MM:SS = ";
            if (sign ==1 )
                cout<< "- ";
            cout<<"( "<<hr<<":"
                << setfill('0') << setw(2) << min <<":"
                << setfill('0') << setw(2) << sec << ")"<<endl;
        }
        // declarations
        void input_time();
        time_class add (time_class);
        time_class sub (time_class);
        
};

void  time_class::input_time(void){
            int temp;
            cout<< "Enter hour :";
            cin >> temp;
            set_hr(temp);
            cout<< "Enter min : ";
            cin >> temp;
            set_min(temp);
            cout<< "Enter sec : ";
            cin >> temp;
            set_sec(temp);
     }

time_class time_class::add (time_class time1){
    time_class ret_val;
    long tmp_sec=0;
        tmp_sec=( (this->hr+time1.hr)*60 +(this->min+time1.min) )*60 + this->sec+time1.sec;
        ret_val.hr  = tmp_sec/3600;  tmp_sec =  tmp_sec%3600;;
        ret_val.min = tmp_sec/60;    tmp_sec =  tmp_sec%60;;
        ret_val.sec = tmp_sec;
return ret_val;    
}
time_class time_class::sub (time_class time1){
    time_class ret_val;
    long tmp_sec=0;
        tmp_sec=( (this->hr-time1.hr)*60 +(this->min-time1.min) )*60 + this->sec-time1.sec;
        if (tmp_sec<0){
            ret_val.sign=1;  // set time sign to -ve
            tmp_sec=-tmp_sec;
        }
        ret_val.hr  = tmp_sec/3600;  tmp_sec -= ret_val.hr*3600;
        ret_val.min = tmp_sec/60;    tmp_sec -= ret_val.min*60;
        ret_val.sec = tmp_sec;
return ret_val;    
}

int main(){

        time_class time1(1,30,50);
        time_class time2, time_diff, time_sum;
        time2.input_time();
        time_sum =time1.add(time2);
        time_diff=time1.sub(time2);
        
        cout<<("time 1 = ");time1.display();
        cout<<("time 2 = ");time2.display();
        cout<<("time_sum = "); time_sum.display();
        cout<<("time_diff= ");time_diff.display();
        
return 0;

}
 
