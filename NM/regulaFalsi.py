#!/bin/python3

def regulaFalsi(f, x1, x2, N):
    '''Approximate solution of f(x)=0 on interval [x1,x2] by bisection method.

    Parameters
    ----------
    f     : function:- The function for which to approximate a solution f(x)=0.
    x1,x2 : numbers :- The interval to search for a solution,
            returns None if f(a)*f(b) >= 0 as solution isn't guaranteed.
    N     : The number of iterations.
    e     : error range # either N or e must be coded into code not implemnted

    Returns
    -------
    x0    : = x1 - f_x1*(x2 - x1)/{f(x2) -f(x11)} ie interplote for next guess in iteration,
                                                    sectact of interval point. next guess in iteration,
                                                    note logical decision not needed as in newtonRapson method
            

    Examples use
    --------
    f = lambda x: x**2 - 5*x + 6
    regulaFalsi(f,1,2.5,25)
    2.0000000074505806
    '''
    e=0.0001             # percision max 8
    # print(abs(e+1))
    # print(str(abs(e+1)))
    digits=len(str(abs(e+1)))-2 # digits(max 10) # -2 to rem 1 and .
    if digits+2 > 8:
        e=0.00000002
        digits = 8
    print ("no of digits" , digits)   
    f_x1 = f(x1)
    f_x2 = f(x2)
    if f_x1 * f_x2 >= 0:
        print   ("interval (", x1 ,",", x2,")| ", 'f_x1', f_x1, " | ", '%f_x2' ,f_x2)
        print("regFalsi method fails.")
        return None
    
    print("s/n |           x1  |             x2|            x0 |     logical decision             | range")
    range1=0
    range0=0
    for i in range(1, N + 1) :
        range0=abs(x1-x2)
        x0 = round((x1 - f_x1*(x2 - x1)/(f_x2-f_x1) ),digits)
        f_x0 = f(x0)
        if f_x1 * f_x0 < 0 :
            print   ('%3s'%i,"| ",'%12s'%x1,"| ",'%12s'%x2,"| ",'%12s'%x0,"| f(x1)*f(x0)<0 = TRUE :-> x2 = x0 |",range0)
            x2 = x0
            f_x2 = f_x0
        elif f_x2 * f_x0 < 0 :            
            print   ('%3s'%i,"| ",'%12s'%x1,"| ",'%12s'%x2,"| ",'%12s'%x0,"| f(x1)*f(x0)<0 = FALSE:-> x1 = x0 |",range0 )
            x1 = x0
            f_x1 = f_x0
        elif f_x0 == 0 :
            print("Found exact solution.")
            break 
        else:
            print("Bisection method fails.")
            return None
        if (range0 < e) or range1==range0 :    # should be redunctant thou
            print ("range0 < e or range1==range0")
            break
        else:
            range1=range0
    print("\n root =" , x0 , "range =", range0, "error =", e)
    return (x0)


