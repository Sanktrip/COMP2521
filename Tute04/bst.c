#include <stdio.h>
#include <stdlib.h>

#define NOT_HEIGHT_BALANCED -99

typedef struct BSTNode *BSTree;
struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
};


int bstNumNodes(BSTree t) { 
    // base case
    if (t == NULL) return 0;
    // recursive case
    return bstNumNodes(t->right) + bstNumNodes(t->left) + 1;
}

int bstCountOdds(BSTree t) {
    // base case 
    if (t == NULL) return 0;

    // recursive case
    if (t->data % 2 != 0) {
        return bstCountOdds(t->right) + bstCountOdds(t->left) + 1;
    } else {
        return bstCountOdds(t->right) + bstCountOdds(t->left);
    }

}

int bstHeight(BSTree t) {
    // base case
    if (t == NULL) return -1;

    // recursive case
    int left = bstHeight(t->left) + 1;
    int right = bstHeight(t->right) + 1;
    return max(left, right);
}

int bstCountInternal(BSTree t) {
    // base case 
    if (t == NULL) {
        return 0;
    }
    if (t->right == NULL && t->left == NULL) {
        return 0;
    }

    // recursive case
    return bstCountGreater(t->right) + bstCountGreater(t->left) + 1;
    
}


int bstNodeLevel(BSTree t, int key) {
    // base case 
    if (t == NULL) {
        return -1;
    } 
    if (t->value == key) {
        return 0;
    }

    // recursive case
    if (key < t->value) {
        return bstNodeLevel(t->left, key) + 1;
    } else {
        return bstNodeLevel(t->right, key) +1;
    }

}

int bstCountGreater(BSTree t, int key) {
    // base case
    if (t == NULL) return 0;

    // recursive case
    if (key > t->value) {
        return bstCountGreater(t->right) + bstCountGreater(t->left) + 1;
    } else {
        return bstCountGreater(t->right);
    }
}

int isHeightBalanced(BSTree t) {
    // base case
    if (t == NULL) return -1;


    // recursive case
    int left = isHeightBalanced(t->left);
    int right = isHeightBalanced(t->right) ;
    if (left == NOT_HEIGHT_BALANCED || right == NOT_HEIGHT_BALANCED) {
        return NOT_HEIGHT_BALANCED;
    }

    return abs(left - right ) <= 1 ? left + right + 1 : NOT_HEIGHT_BALANCED;
}

int main(void) {
    return 0;
}