#include "project1.h"

int main(void) {
    run_calculator();
}

void scan_data(char *operator, double *operand)
{
    printf("Enter operator");
    while(1) {
        char tempchar;

        fflush(stdin); //Clears buffer to make sure scanf is not skipped

        if
        (scanf("%c%c", operator, &tempchar)!= 2 || tempchar != '\n' //Validates operator by making sure input is one char followed by enter
        || !is_binary(*operator) && !is_unary(*operator))  //then checks if input is one of the chars defined in is_binary and is_unary
        {
            printf("\nPlease enter valid operator:");
        }
        else if(is_binary(*operator)){
            printf("\nYou have entered the binary operator %c.\nPlease enter an operand:",*operator);
            scanf("%lf", operand);
            break;
        }
        else if(is_unary(*operator)){
            printf("\nYou have entered the unary operator %c \n",*operator);
            break;
        }
    }
}

void do_next_op(char operator, double operand, double *accumulator)
{
    switch(operator){
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
        default:
            break;
    }
}

void run_calculator()
{
    char operator;
    double operand;
    double accumulator = 0.0;
    while(1)
    {
        scan_data(&operator, &operand);
        if(operator == 'q')
            break;
        do_next_op(operator, operand, &accumulator);



        printf("Accumulator is currently at: %.2lf \n",accumulator);
    }
}