//
// Created by bartek on 15.03.17.
//
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

static bool isSentinel(List list) {
    return list->number == SENTINEL_VALUE;
}

List makeListElement(int number) {
    List element = (List) malloc(sizeof(struct ListElement));

    element->left = NULL;
    element->right = NULL;
    element->number = number;

    return element;
}

void insertListBetween(List left, List right, List leftEnd, List rightEnd) {
    if (isSentinel(right))
        right->right = rightEnd;
    else
        right->left = rightEnd;

    if (isSentinel(left))
        left->left = leftEnd;
    else
        left->right = leftEnd;

    leftEnd->left = left;
    rightEnd->right = right;
}

void insertAsRightmost(List elementToInsert, List sentinel) {
    sentinel->right->right = elementToInsert;
    elementToInsert->left = sentinel->right;
    elementToInsert->right = sentinel;
    sentinel->right = elementToInsert;
}

void insertFirst(List firstElement, List sentinel) {
    firstElement->right = sentinel;
    firstElement->left = sentinel;
    sentinel->right = firstElement;
    sentinel->left = firstElement;
}

void insertOnRight(List elementToInsert, List leftBrother, List fatherSentinel) {
    elementToInsert->right = fatherSentinel;
    fatherSentinel->right = elementToInsert;
    leftBrother->right = elementToInsert;
    elementToInsert->left = leftBrother;
}

void connectTwoLists(List leftBrother, List rightBrother) {
    if (isSentinel(leftBrother)) {
        leftBrother->left = rightBrother;
    } else {
        leftBrother->right = rightBrother;
    }

    if (isSentinel(rightBrother)) {
        rightBrother->right = leftBrother;
    } else {
        rightBrother->left = leftBrother;
    }
}
