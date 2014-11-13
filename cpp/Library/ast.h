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

float evaluateAST(Node *Tree);
