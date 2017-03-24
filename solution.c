#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"
#include "parse.h"
#define FIRST_PARAM_INDEX 1

void run(TreePtr tree, bool err) {
    char instructionName[MAX_LENGTH_INSTRUCTION];
    while ((scanf("%s", instructionName)) != EOF) {
        Instruction currentInstruction = parse(instructionName);
        int instruction = currentInstruction.instructionCode;
        int k = currentInstruction.k;
        int w = currentInstruction.w;

        if (instruction != WRONG_INSTRUCTION) {
            if (instruction == ADD_NODE) {
                addNode(tree, k);
                printf("OK\n");
            } else if (instruction == RIGHTMOST_CHILD) {
                rightmostChild(tree, k);
            } else if (instruction == DELETE_NODE) {
                deleteNode(tree, k);
                printf("OK\n");
            } else if (instruction == DELETE_SUBTREE) {
                deleteSubtree(tree, k);
                printf("OK\n");
            } else if (instruction == SPLIT_NODE) {
                splitNode(tree, k, w);
                printf("OK\n");
            }
            if (err)
                fprintf(stderr, "NODES: %d\n", tree->nodesNumber);
        }
    }
}

int main(int argc, char **argv) {
    bool err = false;

    if (argc > 1) {
        if (strcmp(argv[FIRST_PARAM_INDEX], "-v") != 0) {
            fprintf(stderr, "ERROR");
            exit(1);
        } else {
            err = true;
        }
    }

    TreePtr tree = makeEmptyTreePtr();
    run(tree, err);
    freeTree(tree);
    return 0;
}