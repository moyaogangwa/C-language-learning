#ifndef __SUFFIX_H__
#define __SUFFIX_H__ 1



//º¯ÊýÉùÃ÷
int operatorPriority(int op);

int comparePriority(int op1,int op2);

void InfixToSuffix(char *tp,char *InfixExpression);

int calculate(int num1,int num2,char sym);

int getvalue(char *InfixExpression);


#endif  //Suffix.h