#include "ast.h"
#include <iostream>
#include <time.h>

using namespace std;

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


