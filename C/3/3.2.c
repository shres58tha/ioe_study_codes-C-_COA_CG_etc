// program to calculate the roots of the quardratic equation

#include<stdio.h>
//#include<conio.h>
#include<math.h>
int main(){
	float a, b, c, flag=0;
	float dis , real , rt_dis; // root (-b +- Root (b*b-4ac))/2a; set rt_det (b*b-4ac)
	printf ("enter coeff. a b c of quardratic eq in order :");
	scanf ("%f %f %f", &a, &b, &c);
	dis=(b*b-4*a*c);
	if (dis<0)   // if discreminate is less than zero set the flag and make it positive
		{flag =1;
		dis= -1*dis;
		}
	real=-b/(2.0*a);  //real === whole part
	rt_dis=sqrt(dis)/(2*a);  //  rt_dis== part of dis

	if (dis==0)
		printf("two root are equal and it is %f",real);
	else if(flag==0){
			printf ("the roots of given quadratic equation are  %f    %f",real +rt_dis,real -rt_dis);
			}
			else{
			printf ("the roots of given quadratic equation are %f \t%f i \n\t\t\t\t\t  %f    %f i",real, +rt_dis,real, -rt_dis);
		}
	printf("\n\n");

}


