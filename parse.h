//
// Created by bartek on 18.03.17.
//

#ifndef PROJEKT_PARSE_H
#define PROJEKT_PARSE_H
#define WRONG_INSTRUCTION -1
#define ADD_NODE 0
#define RIGHTMOST_CHILD 1
#define DELETE_NODE 2
#define DELETE_SUBTREE 3
#define SPLIT_NODE 4
#define DELETE_DECIDING_LETTER_POSITION 7
#define MAX_LENGTH_INSTRUCTION 15
#define OK_MESSAGE "OK\n"
#define DIAGNOSTIC_MESSAGE "NODES: %d\n"

struct Tree;

typedef struct Tree *TreePtr;

void runParsing(TreePtr tree, bool diagnostic);

#endif //PROJEKT_PARSE_H
