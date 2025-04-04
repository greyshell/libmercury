/*
* author: greyshell
 * description: heap
 * */

#ifndef BINARY_HEAP_DYNAMIC_ARRAY_H__
#define BINARY_HEAP_DYNAMIC_ARRAY_H__

#include <glob.h>
#include "stdbool.h"

enum heap_type {
    HEAP_TYPE_MIN_HEAP,
    HEAP_TYPE_MAX_HEAP,
};

typedef struct {
    int *data_arr;
    // used these variables to grow and shrink heap dynamically
    size_t initial_capacity;
    size_t current_capacity;
    // set this flag true when you create a max heap, for min heap set this flag false
    enum heap_type type;
    // set this flag true when you create the heap from build_heap() function
    bool build_heap_flag;
    size_t size;
} heap;

bool initialize_heap(heap *, size_t, enum heap_type);

bool is_empty_heap(heap *);

size_t get_heap_size(heap *);

bool has_heap_node_left_child(heap *, size_t);

size_t get_heap_node_left_child_index(size_t);

size_t get_heap_node_left_child(heap *, size_t);

bool has_heap_node_right_child(heap *, size_t);

size_t get_heap_node_right_child_index(size_t);

size_t get_heap_node_right_child(heap *, size_t);

bool has_heap_node_parent(size_t);

size_t get_heap_node_parent_index(size_t);

size_t get_heap_node_parent(heap *, size_t);

void heapify_down(heap *, size_t);

void heapify_up(heap *, size_t);

bool push_heap(heap *, int);

bool pop_heap(heap *, int *);

bool pop_heap_by_index(heap *, size_t, int *);

bool peek_heap(heap *, int *);

bool peek_heap_by_index(heap *, size_t, int *);

bool build_heap(heap *, enum heap_type, int *, size_t);

void heap_sort(int *, size_t, bool);

void display_heap(heap *);

bool delete_heap(heap *);

#endif
