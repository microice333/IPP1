//
// Created by bartek on 15.03.17.
//

#ifndef PROJEKT_TREE_H
#define PROJEKT_TREE_H
#define MAX_SIZE (1<<19)
#define ROOT_NUMBER 0
#define STARTING_NODES_NUMBER 1
#define STARTING_LAST_ADDED_VALUE 0

struct ListElement;

typedef struct ListElement *List;

struct NodeElement;

typedef struct NodeElement *Node;

struct NodeElement {
    List childrenSentinel;
    List listElement;
};

struct Tree {
    Node nodes[MAX_SIZE];
    int lastAdded;
    int nodesNumber;
};

typedef struct Tree *TreePtr;

void addNode(TreePtr tree, int k);

void rightmostChild(TreePtr tree, int k);

void deleteNode(TreePtr tree, int k);

void deleteSubtree(TreePtr tree, int k);

void splitNode(TreePtr tree, int k, int w);

TreePtr makeEmptyTreePtr();

void freeTree(TreePtr tree);

#endif //PROJEKT_TREE_H
