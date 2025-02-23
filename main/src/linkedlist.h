#pragma once

#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
// weird syntax but necessary for self-referential struct
typedef struct node node;

typedef struct 
{
    node* head;
} linked_list;

void ll_init(linked_list* ll_in, int head_val)
{
    node* head_node = (node*)malloc(sizeof(node));
    head_node->value = head_val;
    ll_in->head = head_node;
}

void ll_push(linked_list* ll_in, int val)
{
    node* tracker = ll_in->head;

    while (tracker->next != NULL)
    {
        tracker = tracker->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    tracker->next = new_node;
}

// returns the value of the popped node.
int ll_pop(linked_list* ll_in)
{
    node* tracker = ll_in->head;
    while (tracker->next->next != NULL)
    {
        tracker = tracker->next;
    }

    int rval = tracker->next->value;
    free (tracker->next);
    tracker->next = NULL;
    return rval;
}

// ll_in will NOT become null after this, but all the nodes will.
void ll_free_nodes(linked_list* ll_in)
{
    node* tracker = ll_in->head;

    while (tracker->next != NULL)
    {
        node* old = tracker;
        tracker = tracker->next;
        old->next = NULL; // may not be necessary
        free(old);
    }

    free(tracker);
}