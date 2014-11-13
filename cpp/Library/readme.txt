example of use:

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "ast.h"

using namespace std;

int main() {
    Node tree0_0 = {NUMBER, 0, 10, 0};
    Node tree0_1 = {NUMBER, 0, 20, 0};
    Node tree1_0 = {NUMBER, 0, 30, 0};
    Node tree2_0 = {NUMBER, 0, 40, 0};
    Node tree3_0 = {NUMBER, 0, 50, 0};
    Node tree0 = {OPERATOR, MULTIPLY, 0, 2, &tree0_1, &tree0_0};
    Node tree1 = {OPERATOR, DIVIDE, 0, 2, &tree0, &tree1_0};
    Node tree2 = {OPERATOR, ADD, 0, 2, &tree1, &tree2_0};
    Node tree3 = {OPERATOR, SUBSTRACT, 0, 2, &tree2, &tree3_0};
    cout<<evaluateAST(&tree3);
    return 0;
}

