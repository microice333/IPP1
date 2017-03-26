#include <stdlib.h>
#include "list.h"
#include "tree.h"
#include <stdio.h>
#include <stdbool.h>

static Node makeNewNode(int number) {
    Node node = (Node) malloc(sizeof(struct NodeElement));
    node->childrenSentinel = makeListElement(SENTINEL_VALUE);
    connectTwoLists(node->childrenSentinel, node->childrenSentinel);
    node->listElement = makeListElement(number);
    return node;
}

static List getLeftChild(Node node) {
    return node->childrenSentinel->left;
}

static List getRightChild(Node node) {
    return node->childrenSentinel->right;
}

static bool haveChildren(Node node) {
    return node->childrenSentinel->left != node->childrenSentinel;
}

void addNode(TreePtr tree, int k) {
    int newNodeNumber = tree->lastAdded + 1;
    Node newNode = makeNewNode(newNodeNumber);
    Node father = tree->nodes[k];

    if (!haveChildren(tree->nodes[k])) {
        insertFirst(newNode->listElement, father->childrenSentinel);
    } else {
        insertAsRightmost(newNode->listElement, father->childrenSentinel);
    }

    tree->nodes[newNodeNumber] = newNode;
    (tree->lastAdded)++;
    (tree->nodesNumber)++;
}

TreePtr makeEmptyTreePtr() {
    TreePtr tree = malloc(sizeof(struct Tree));
    tree->lastAdded = STARTING_LAST_ADDED_VALUE;
    tree->nodesNumber = STARTING_NODES_NUMBER;
    Node root = makeNewNode(ROOT_NUMBER);
    tree->nodes[ROOT_NUMBER] = root;

    return tree;
}

void rightmostChild(TreePtr tree, int k) {
    List rightChild = getRightChild(tree->nodes[k]);
    int rightmostChildNumber = rightChild->number;

    printf("%d\n", rightmostChildNumber);
}

void deleteNode(TreePtr tree, int k) {
    Node nodeToDelete = tree->nodes[k];
    (tree->nodesNumber)--;

    if (haveChildren(nodeToDelete)) {
        List leftChild = getLeftChild(nodeToDelete);
        List rightChild = getRightChild(nodeToDelete);
        insertListBetween(nodeToDelete->listElement->left, nodeToDelete->listElement->right, leftChild, rightChild);
    } else if (k != ROOT_NUMBER) {
        connectTwoLists(nodeToDelete->listElement->left, nodeToDelete->listElement->right);
    }

    free(nodeToDelete->childrenSentinel);
    free(nodeToDelete->listElement);
    free(nodeToDelete);
}

void deleteSubtree(TreePtr tree, int k) {
    Node nodeToDelete = tree->nodes[k];
    List rightChild = getRightChild(nodeToDelete);

    while (rightChild != nodeToDelete->childrenSentinel) {
        int childToDelete = rightChild->number;
        deleteSubtree(tree, childToDelete);
        rightChild = getRightChild(nodeToDelete);
    }

    deleteNode(tree, k);
}

void splitNode(TreePtr tree, int k, int w) {
    int newNodeNumber = tree->lastAdded + 1;
    Node newNode = makeNewNode(newNodeNumber);
    Node leftBrother = tree->nodes[w];
    Node father = tree->nodes[k];
    List leftChild = leftBrother->listElement->right;
    List rightChild = getRightChild(father);

    insertOnRight(newNode->listElement, leftBrother->listElement, father->childrenSentinel);

    if (leftChild != father->childrenSentinel) {
        insertListBetween(newNode->childrenSentinel, newNode->childrenSentinel, leftChild, rightChild);
    }

    tree->nodes[newNodeNumber] = newNode;
    (tree->lastAdded)++;
    (tree->nodesNumber)++;
}

void freeTree(TreePtr tree) {
    deleteSubtree(tree, ROOT_NUMBER);
    free(tree);
}


