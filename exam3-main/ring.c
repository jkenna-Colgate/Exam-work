/*****
 * Exam 3 Take-home
 * COSC 208, Introduction to Computer Systems, Spring 2023
 *****/

#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int value;
};

/*
 * Remove the first node encountered with the given value from the ring, 
 * starting with the given node.  Return the original start node, or the 
 * next node in the ring if start is removed, or NULL if no nodes remain
 * in the ring.
 */
struct node *ring_remove(struct node *start, int value) {


}

int main() {
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    one->next = two;
    one->value = 1;
    two->next = three;
    two->value = 2;
    three->next = one;
    three->value = 3;
    struct node *ring = ring_remove(three, 2);
    assert(ring == three);
    assert(ring->next == one);
}
