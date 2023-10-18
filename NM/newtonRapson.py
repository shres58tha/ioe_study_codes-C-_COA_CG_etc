#!/bin/python3

def newtonRapson(f, df, x, N):
    '''Approximate solution of f(x)=0 on interval [x1,x2] by bisection method.

    Parameters
    ----------
    f     : function:- The function for which to approximate a solution f(x)=0.
    fd    : derivative of the function needed to get next iterative. ie df is slope at the current iter
    x1    : numbers :- The interval to search for a solution,
            returns None if f(a)*f(b) >= 0 as solution isn't guaranteed.
    N     : The number of iterations.
    e     : error range # either N or e must be coded into code not implemnted

    Returns
    -------
    x0    : = x - (f_x/df_x) ie next guess in iteration,
                             
            
    Examples use
    --------
    f = lambda x: x**3 +5*x*x + 6*x +100
    df= lambda x: 3*x*x  +5*x +6
    newtonRapson(f,df,50000000000000000,120)
    root = -6.464679 error = -0.0
    -6.464679
    '''
    e=0.000001             # percision max 8
    # print(abs(e+1))
    # print(str(abs(e+1)))
    digits=len(str(abs(e+1)))-2 # digits(max 10) # -2 to rem 1 and .
    if digits+2 > 8:
        e=0.00000002
        digits = 8
    print ("no of digits" , digits)   
    f_x = f(x)
    df_x = df(x)
    h1=1000000000000        #huge positive number
    print("s/n |           x   |           f(x)|          df(x)|            x0 | corrective h ")
    
    for i in range(1, N + 1) :
        if df_x==0 :
            print ("newton Rapson method fails")
            return None
        
        h=round(f_x/df_x, digits)   # y=mx+c   where m is the slope=df_x => x=y/m - c
        x0 = round(x - h , digits)  # x=y/m - c
        f_x0 = f(x0)
        df_x0 = df(x0)
        print   ('%3s'%i,"| ",'%12s'%x,"| ",'%12s'%round(f_x,digits),"| ",'%12s'%round(df_x,digits),"| ",'%12s'%x0,"|", h)

        h0=abs(h)
        if f_x0 == 0 :
            print("Found exact solution.")
            break
        if (h0<e):
            break
        if ( h0>h1):
            print("\n iteration diverges at provided initial guess")
        if (i==N):
            print("\n warning exhaustive iteration root might not be valid")
        
        h1=h0
        x=x0
        f_x=f_x0
        df_x=df_x0
         
    print("\n root =" , x0, "error =", h )
    return (round(x0,digits))


