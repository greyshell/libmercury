/*
 * author: greyshell
 * description: queue
 * */

#ifndef QUEUE_SINGLY_LINKEDLIST_H__
#define QUEUE_SINGLY_LINKEDLIST_H__

#include <glob.h>
#include "stdbool.h"

typedef struct singly_linked_list {
    int data;
    struct singly_linked_list *next;
} node;

typedef struct {
    node *front;
    node *rear;
    size_t size;
} queue;

void initialize_queue(queue *);

bool is_empty_queue(queue *);

size_t get_queue_size(queue *);

bool enqueue(queue *, int);

bool dequeue(queue *, int *);

bool peek_at_front(queue *, int *);

bool peek_at_rear(queue *, int *);

bool delete_queue(queue *);

void display_queue(queue *);

#endif
