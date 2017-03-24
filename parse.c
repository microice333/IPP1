//
// Created by bartek on 18.03.17.
//

#include <stdio.h>
#include "parse.h"

static int deleteFunction(char instruction[]) {
    char decidingLetter = instruction[DELETE_DECIDING_LETTER_POSITION];
    if (decidingLetter == 'N') {
        return DELETE_NODE;
    } else if (decidingLetter == 'S') {
        return DELETE_SUBTREE;
    } else {
        return WRONG_INSTRUCTION;
    }
}

static int getInstruction(char instruction[]) {
    char firstLetter = instruction[0];
    if (firstLetter == 'A') {
        return ADD_NODE;
    } else if (firstLetter == 'S') {
        return SPLIT_NODE;
    } else if (firstLetter == 'R') {
        return RIGHTMOST_CHILD;
    } else if (firstLetter == 'D') {
        return deleteFunction(instruction);
    } else {
        return WRONG_INSTRUCTION;
    }
}

Instruction parse(char instructionName[]) {
    Instruction instruction;
    int instructionValue;
    int k;
    int w = DEFAULT_W_VALUE;

    instructionValue = getInstruction(instructionName);

    scanf("%d", &k);

    if (instructionValue == SPLIT_NODE)
        scanf("%d", &w);

    instruction.instructionCode = instructionValue;
    instruction.k = k;
    instruction.w = w;

    return instruction;
}

