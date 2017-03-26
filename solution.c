#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"
#include "parse.h"

#define FIRST_PARAM_INDEX 1
#define DIAGNOSTIC_FLAG "-v"
#define ERROR_MESSAGE "ERROR"

static bool checkParameters(int argc, char **argv) {
    if (argc > 1) {
        if (strcmp(argv[FIRST_PARAM_INDEX], DIAGNOSTIC_FLAG) != 0) {
            fprintf(stderr, ERROR_MESSAGE);
            exit(1);
        } else {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    bool diagnostic = checkParameters(argc, argv);
    TreePtr tree = makeEmptyTreePtr();

    runParsing(tree, diagnostic);
    freeTree(tree);

    return 0;
}