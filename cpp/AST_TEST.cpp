
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define MAX_CHILDREN 50

#define ADD 0
#define SUBSTRACT 1
#define MULTIPLY 2
#define DIVIDE 3
#define SUM 4

#define NUMBER 10
#define STRING 11
#define OPERATOR 12

struct Node {
    int type;
    int oper;
    float number;
    int childrenLength;
    Node *arguments[MAX_CHILDREN];
};

float functions (int oper, float *args, int length) {
    switch ( oper ) {
        case ADD:
            return args[0] + args[1];
            break;
        case SUBSTRACT:
            return args[0] - args[1];
            break;
        case MULTIPLY:
            return args[0] * args[1];
            break;
        case DIVIDE:
            return args[0] / args[1];
            break;
        case SUM: {
            float sum = 0;
            for (int i = 0; i < length; i++) {
	            sum = sum + args[i];
            }
            return sum;
        }
		default:
        break;
    }
    return 0.1;
};

float evaluateAST(Node *Tree) {
    float args[500];
    int oper;
    if (Tree->arguments[0]) {
        oper = Tree->oper;
        switch (Tree->type) {
            case NUMBER: {
            	return Tree->number;
                break;
            }
            case OPERATOR: {
                for (int i = 0; i < Tree->childrenLength; i++) {
                    args[i] = evaluateAST(Tree->arguments[i]);
                }
                return functions(oper, args, Tree->childrenLength);
                break ;
            }
        }
    } else {
        switch (Tree->type) {
            case NUMBER: {
                return Tree->number;
                break;
            }
        }
    }
}



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

    Node tree4_0 = {NUMBER, 0, 20, 0};
    Node tree4_1 = {NUMBER, 0, 30, 0};
    Node tree5_0 = {NUMBER, 0, 40, 0};
    Node tree6_0 = {NUMBER, 0, 50, 0};
    Node tree7_0 = {NUMBER, 0, 60, 0};
    Node tree4 = {OPERATOR, MULTIPLY, 0, 2, &tree4_1, &tree4_0};
    Node tree5 = {OPERATOR, DIVIDE, 0, 2, &tree4, &tree5_0};
    Node tree6 = {OPERATOR, ADD, 0, 2, &tree5, &tree6_0};
    Node tree7 = {OPERATOR, SUBSTRACT, 0, 2, &tree6, &tree7_0};

    Node tree8_0 = {NUMBER, 0, 30, 0};
    Node tree8_1 = {NUMBER, 0, 40, 0};
    Node tree9_0 = {NUMBER, 0, 50, 0};
    Node tree10_0 = {NUMBER, 0, 60, 0};
    Node tree11_0 = {NUMBER, 0, 70, 0};
    Node tree8 = {OPERATOR, MULTIPLY, 0, 2, &tree8_1, &tree8_0};
    Node tree9 = {OPERATOR, DIVIDE, 0, 2, &tree8, &tree9_0};
    Node tree10 = {OPERATOR, ADD, 0, 2, &tree9, &tree10_0};
    Node tree11 = {OPERATOR, SUBSTRACT, 0, 2, &tree10, &tree11_0};

    Node tree12_0 = {NUMBER, 0, 40, 0};
    Node tree12_1 = {NUMBER, 0, 50, 0};
    Node tree13_0 = {NUMBER, 0, 60, 0};
    Node tree14_0 = {NUMBER, 0, 70, 0};
    Node tree15_0 = {NUMBER, 0, 80, 0};
    Node tree12 = {OPERATOR, MULTIPLY, 0, 2, &tree12_1, &tree12_0};
    Node tree13 = {OPERATOR, DIVIDE, 0, 2, &tree12, &tree13_0};
    Node tree14 = {OPERATOR, ADD, 0, 2, &tree13, &tree14_0};
    Node tree15 = {OPERATOR, SUBSTRACT, 0, 2, &tree14, &tree15_0};

    Node tree = {OPERATOR, SUM, -99, 4,&tree3, &tree7, &tree11, &tree15};

    long tt = clock();
    float sum;
    for (long int i = 0; i < 100000; i++) {
	    sum += evaluateAST(&tree);
    }
    cout<< "Sum: " << sum << endl;
    cout << "time: " << (clock() - tt)/1000 << endl;

    return 0;
}
