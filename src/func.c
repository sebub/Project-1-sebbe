#include "func.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
int data_check(char operator);


void scan_data(char *operator, double *operand)
{
    printf("Enter operator");
    while(1) {
        fflush(stdin);
        char tempchar;
        if(scanf("%c%c", operator, &tempchar) != 2 || tempchar != '\n' || data_check(*operator) == -1)
        {
            printf("\nPlease enter valid operator:");
        }
        else if(data_check(*operator)==1)
        {
            printf("\nYou have entered the binary operator %c.\nPlease enter an operand:",*operator);
            scanf("%lf", operand);
            break;

        } else if(data_check(*operator)==0||*operator=='q'){
            printf("\nYou have entered the unary operator %c \n",*operator);
            break;
        }
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
    return -1;
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
            if(operand>0) {
                *accumulator /= operand;
                break;
            } else
            {
                printf("cant divide by 0\n");
                break;
            }
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
            if(*accumulator > 0){
            *accumulator = 1 / *accumulator;
            break;
            } else
            {
                printf("cant divide by 0\n");
                break;
            }
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



        printf("Accumulator is currently at: %.2lf \n",accumulator);
    }
}
