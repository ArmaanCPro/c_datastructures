#pragma once

#include <stdlib.h>

typedef struct
{
    int value;
    void* next;
} node;


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