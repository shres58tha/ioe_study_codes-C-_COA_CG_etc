
// a very simple C++ program using the concept of Class and Objects (Optional Question)
#include<iostream>
using namespace std;
class Box{
	public:
	void display(){
		cout<< "the box's side are : l=" <<lenght<<", w="<<width<<", h="<<height<<endl;
		
	}
	void set(){
	    cout<< "enter lenght(float)" ; 
	    cin >> lenght;
	    cout << "enter width(float)";
	    cin >> width;
	    cout << "enter height(float)";
        cin >> height;
     }
     
    protected:
	float lenght;
	float height;
	float width;
};
class Box_1 : public  Box{
 public:
 	void display_vol(){
 		cout<<"volume is :"<<lenght*width*height<<endl;
    }
     void display_TSA(){
     	 cout<<"total surface area is :"<< 2* (lenght *width + width*height + height*lenght )<<endl;
    }
    void display_edge_lenght(){
     	 cout<<"total edge lenght is :" << 4*(lenght + width +height )<<endl;
    }
	
};
int main(){
	Box_1 x;
    x.set ();
	x.display ();
	x.display_vol();
	x.display_TSA();
	x.display_edge_lenght();
	return 0;
}


