#include "func.h"

bool is_binary(char operator){
    char binary_chars[5] = {'+', '-', '*', '/', '^'};
    for (int i = 0; i < 5; ++i) {
        if (operator == binary_chars[i])
            return true;
    }
    return false;
} //Returns true if operator is Binary else false
bool is_unary(char operator){
    char unary_chars[4] = {'#', '%', '!','q'};
    for (int i = 0; i < 4; ++i) {
        if (operator == unary_chars[i])
            return true;
    }
    return false;
}  //Returns true if operator is Unary else false
