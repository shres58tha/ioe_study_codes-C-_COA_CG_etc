#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getInput(char * in) {
 printf("> ");
 fgets(in, 256, stdin);
}

int isLeftParantheses(char p) {
if (p == '(') return 1;
else return 0;
}

int isRightParantheses(char p) {
if (p == ')') return 1;
else return 0;
}

int isOperator(char p) {
if (p == '+' || p == '-' || p == '*' || p == '/') return p;
else return 0;
}

int performOperator(int a, int b, char p) {
 switch(p) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/':
        if (b == 0) { printf("Can't divide by 0, aborting...n"); exit(1); }  // now we dont want the world to expload here do we.
        return a/b;
    default:
       puts("Bad value in switch.n"); // A replacement which was mentioned in the thread- better have a default response just in case something goes wrong.
       break;
 }
return 0;
 }


char isDigit(char p) {
if (p >= '0' && p <= '9') return 1;
else return 0;
}

int charToDigit(char p) {
if (p >= '0' && p <= '9') return p - '0';
else return 0;
}

int isNumber(char * p) {
while(*p) {
    if (!isDigit(*p)) return 0;
    p++;
}
return 1;
}

int len(char * p)
{
 return (int) strlen(p); // This was bugged in the source, so I fixed it like the thread advised.
}

int numOfOperands(char * p) {
int total = 0;
while(*p) {
    if (isOperator(*p)) total++;
    p++;
}
return total+1;
}

int isMDGRoup(char *p)
{

for(; *p; p++) // used to be a while loop in the source, but this is better imho. more readable, also mentioned on the thread itself.
{
    if (!isDigit(*p) && *p != '/' && *p != '*') return 0;
}
return 1;
}
int getLeftOperand(char * p, char * l) {
// Grab the left operand in p, put it in l,
//and return the index where it ends.
int i = 0;

// Operand is part of multi-*/ group
if (isMDGRoup(p)) {
    while(1) {
        if (*p == '*' || *p == '/') break;
        l[i++] = *p++;
    }
    return i;
}

// Operand is in parantheses (so that's how you write it! sorry for my bad english :)
if(isLeftParantheses(*p)) {
    int LeftParantheses = 1;
    int RightParantheses= 0;
    p++;
    while(1) {
        if (isLeftParantheses(*p))  LeftParantheses++;
        if (isRightParantheses(*p)) RightParantheses++;

        if (isRightParantheses(*p) && LeftParantheses == RightParantheses)
            break;
        l[i++] = *p++;
    }
    // while (!isRightParantheses(*p)) {
    //  l[i++] = *p++;
    // }
    l[i] = '\0';
    return i+2;
}

// Operand is a number
while (1) {
    if (!isDigit(*p)) break;
    l[i++] = *p++;
}
l[i] = '\0';
return i;
}

int getOperator(char * p, int index, char * op) {
*op = p[index];
return index + 1;
}

int getRightOperand(char * p, char * l) {
// Grab the left operand in p, put it in l,
//and return the index where it ends.
while(*p && (isDigit(*p) || isOperator(*p) ||
             isLeftParantheses(*p) || isRightParantheses(*p))) {
    *l++ = *p++;
}
*l = '\0';

return 0;
}

int isEmpty(char * p) {
// Check if string/char is empty
if (len(p) == 0) return 1;
else return 0;
}

int calcExpression(char * p) {
// if p = #: return atoi(p)
//
// else:
//  L = P.LeftSide
//  O = P.Op
//  R = P.RightSide
//  return PerformOp(calcExpression(L), calcExpression(R), O)

// ACTUAL FUNCTION

// if p is a number, return it
if (isNumber(p)) return atoi(p);

// Get Left, Right and Op from p.
char leftOperand[256] = ""; char rightOperand[256]= "";
char op;

int leftOpIndex   = getLeftOperand(p, leftOperand);
int operatorIndex = getOperator(p, leftOpIndex, &op);
int rightOpIndex  = getRightOperand(p+operatorIndex, rightOperand);

printf("%s, %c, %s", leftOperand, op, rightOperand);
getchar();

if (isEmpty(rightOperand)) return calcExpression(leftOperand);

return performOperator(
    calcExpression(leftOperand),
    calcExpression(rightOperand),
    op
);
}

int main()
{
char in[256];
while(1) {
    // Read input from user
    getInput(in);
    if (strncmp(in, "quit", 4) == 0) break;

    // Perform calculations
    int result = calcExpression(in);
    printf("%dn", result);
}
}
