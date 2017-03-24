//
// Created by bartek on 15.03.17.
//

#include <stdbool.h>

#ifndef PROJEKT_LIST_H
#define PROJEKT_LIST_H
#define SENTINEL_VALUE -1

struct ListElement;

typedef struct ListElement* List;

struct ListElement {
    int number;
    List left, right;
};

List makeListElement(int number);

void insertChildrenBetween(List left, List right, List leftChild, List rightChild);

void connectTwoLists(List left, List right);

void insertAsRightmost(List elementToInsert, List sentinel);

void insertFirst(List firstElement, List sentinel);

void insertOnRight(List elementToInsert, List leftBrother, List fatherSentinel);

#endif //PROJEKT_LIST_H
