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
#define DEFAULT_W_VALUE 0
#define MAX_LENGTH_INSTRUCTION 15

struct Instruction {
    int instructionCode;
    int k;
    int w;
};

typedef struct Instruction Instruction;

Instruction parse(char instructionName[]);

#endif //PROJEKT_PARSE_H
