//
// Created by bartek on 18.03.17.
//

#include <stdio.h>
#include <stdbool.h>
#include "parse.h"
#include "tree.h"

static int deleteFunction(char instruction[]) {
    char decidingLetter = instruction[DELETE_DECIDING_LETTER_POSITION];
    int deleteInstructionNumber;

    if (decidingLetter == 'N') {
        deleteInstructionNumber = DELETE_NODE;
    } else if (decidingLetter == 'S') {
        deleteInstructionNumber = DELETE_SUBTREE;
    } else {
        deleteInstructionNumber = WRONG_INSTRUCTION;
    }

    return deleteInstructionNumber;
}

static int parseInstruction(char instruction[]) {
    char firstLetter = instruction[0];
    int instructionNumber;

    if (firstLetter == 'A') {
        instructionNumber = ADD_NODE;
    } else if (firstLetter == 'S') {
        instructionNumber = SPLIT_NODE;
    } else if (firstLetter == 'R') {
        instructionNumber = RIGHTMOST_CHILD;
    } else if (firstLetter == 'D') {
        instructionNumber = deleteFunction(instruction);
    } else {
        instructionNumber = WRONG_INSTRUCTION;
    }

    return instructionNumber;
}

void runParsing(TreePtr tree, bool diagnostic) {
    char instructionName[MAX_LENGTH_INSTRUCTION];

    while ((scanf("%s", instructionName)) != EOF) {
        int instruction = parseInstruction(instructionName);
        int k;
        int w;
        scanf("%d", &k);

        if (instruction != WRONG_INSTRUCTION) {
            if (instruction == RIGHTMOST_CHILD) {
                rightmostChild(tree, k);
            } else {
                if (instruction == ADD_NODE) {
                    addNode(tree, k);
                } else if (instruction == DELETE_NODE) {
                    deleteNode(tree, k);
                } else if (instruction == DELETE_SUBTREE) {
                    deleteSubtree(tree, k);
                } else if (instruction == SPLIT_NODE) {
                    scanf("%d", &w);
                    splitNode(tree, k, w);
                }

                printf(OK_MESSAGE);
            }

            if (diagnostic)
                fprintf(stderr, DIAGNOSTIC_MESSAGE, tree->nodesNumber);
        }
    }
}

