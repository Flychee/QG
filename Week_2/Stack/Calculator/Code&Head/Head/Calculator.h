#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "LinkStack.h"
#include <stdio.h>
#include <string.h>

void change(char *p);/*中缀表达式转化为后缀表达式*/
int calculate(char *p);/*计算*/

#endif