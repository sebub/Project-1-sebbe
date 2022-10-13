#include "func.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
int data_check(char operator);


void scan_data(char *operator, double *operand)
{
    printf("please enter an operator\n");
    while(1) {
        char tempchar;
        if(scanf(" %c%c", operator, &tempchar) != 2 || tempchar != '\n')
        {
            printf(" Please enter valid operator\n");
        }
        else if(data_check(*operator)==1)
        {
            printf(" You have entered a binary operator %c \n",*operator);
            //breaks the loop if the user enters an integer
            break;

        } else if(data_check(*operator)==0){
            printf("You have entered the unary operator %c. Please enter an operand\n",*operator);
            scanf("%lf", operand);
        }

        while(getchar() != '\n');
    }


}


int data_check(char operator) {
    char binary_chars[5] = {'+', '-', '*', '/', '^'};
    char unary_chars[3] = {'#', '%', '!'};

    for (int i = 0; i < 5; ++i) {
        if (operator == binary_chars[i])
            return 1;
    }

    for (int i = 0; i < 3; ++i) {
        if (operator == unary_chars[i])
            return 0;
    }
}

void do_next_op(char operator, double operand, double *accumulator)
{
    switch (operator) {
        case '+':
        {
            *accumulator += operand;
            break;

        }
        case '-':
        {
            *accumulator -= operand;
            break;
        }
        case '*':
        {
            *accumulator *= operand;
            break;
        }
        case '/':
        {
            *accumulator /= operand;
            break;
        }
        case '^':
        {
            *accumulator = pow(*accumulator, operand);
            break;
        }
        case '#': {
            *accumulator = sqrt(*accumulator);
            break;
        }
        case '%':
        {
            *accumulator *= -1;
            break;
        }
        case '!':
        {
            *accumulator = 1 / *accumulator;
        }

    }
}

void run_calculator()
{
    char operator;
    double operand;
    double accumulator;
    accumulator = 0;
    while(1)
    {
        scan_data(&operator, &operand);
        if(operator == 'q')
            break;
        do_next_op(operator, operand, &accumulator);
        getchar();


        printf("Accumulator is currently at: %.2lf \n",accumulator);
    }
}
