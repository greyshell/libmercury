/*
 * author: greyshell
 * description: dynamic array based implementation of heap, datatype: int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "../include/binary_heap_dynamic_array.h"

static void _swap_heap_nodes(heap *h, size_t i, size_t j) {
    /*
     * helper function: swap values between two nodes
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int temp = h->data_arr[i];
    h->data_arr[i] = h->data_arr[j];
    h->data_arr[j] = temp;
}

size_t get_heap_node_left_child_index(size_t parent_index) {
    /*
     * helper function: get the left child index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return 2 * parent_index + 1;
}

size_t get_heap_node_right_child_index(size_t parent_index) {
    /*
     * helper function: get the right child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return 2 * parent_index + 2;
}

size_t get_heap_node_parent_index(size_t child_index) {
    /*
     * helper function: get the parent index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return (child_index - 1) / 2;
}

bool has_heap_node_left_child(heap *h, size_t index) {
    /*
     * helper function: check if the current node has any left child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (get_heap_node_left_child_index(index) < h->size) {
        return true;
    }
    return false;
}

bool has_heap_node_right_child(heap *h, size_t index) {
    /*
     * helper function: check if the current node has any right child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (get_heap_node_right_child_index(index) < h->size) {
        return true;
    }
    return false;
}

bool has_heap_node_parent(size_t index) {
    /*
     * helper function: check if the current node has any parent
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (index != 0 && get_heap_node_parent_index(index) >= 0) {
        return true;
    }
    return false;
}

size_t get_heap_node_left_child(heap *h, size_t index) {
    /*
     * helper function: get the left child of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[get_heap_node_left_child_index(index)];
}

size_t get_heap_node_right_child(heap *h, size_t index) {
    /*
     * helper function: get the right child of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[get_heap_node_right_child_index(index)];
}

size_t get_heap_node_parent(heap *h, size_t index) {
    /*
     * helper function: get the parent of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[get_heap_node_parent_index(index)];
}

static bool _doubling_heap(heap *h) {
    /*
     * double up the size when it becomes full
     * note: when realloc() is unable to resized, then it creates a new memory block and
     * copy all the old data_arr into it.
     * note: too many doubling may cause memory overflow exception
     * time complexity: O(n) -> worst case
     * space complexity: O(1)
     */
    h->data_arr = realloc(h->data_arr, (h->current_capacity * 2) * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->current_capacity *= 2;
    return true;
}

static bool _halving_heap(heap *h) {
    /*
     * halving the size when half of the spaces are empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h->current_capacity == h->initial_capacity) {
        return false;
    }

    h->data_arr = realloc(h->data_arr, (h->current_capacity / 2) * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->current_capacity /= 2;
    return true;
}

void heapify_up(heap *h, size_t index) {
    /*
     * bottom up heapify / bubbling up
     * time complexity: O(log(n))
     * space complexity: O(1)
     */
    size_t p_index;

    if (h->type == HEAP_TYPE_MAX_HEAP) {
        // max heap logic
        while (has_heap_node_parent(index) &&
               (h->data_arr[index] > get_heap_node_parent(h, index))) {
            p_index = get_heap_node_parent_index(index);
            _swap_heap_nodes(h, p_index, index);
            index = get_heap_node_parent_index(index);
        }
    } else {
        // min heap logic
        while (has_heap_node_parent(index) &&
               (h->data_arr[index] < get_heap_node_parent(h, index))) {
            p_index = get_heap_node_parent_index(index);
            _swap_heap_nodes(h, p_index, index);
            index = get_heap_node_parent_index(index);
        }
    }
}

void heapify_down(heap *h, size_t index) {
    /*
     * top down heapify / bubbling down
     * time complexity: O(log(n))
     * space complexity: O(1)
     */
    if (h->type == HEAP_TYPE_MAX_HEAP) {
        // max heap logic
        while (has_heap_node_left_child(h, index)) {
            size_t greater_child_index = get_heap_node_left_child_index(index);

            if (has_heap_node_right_child(h, index) && (get_heap_node_right_child(h, index) >
                                                        get_heap_node_left_child(h, index))) {
                greater_child_index = get_heap_node_right_child_index(index);
            }

            if (h->data_arr[index] >= h->data_arr[greater_child_index]) {
                break;
            } else {
                _swap_heap_nodes(h, index, greater_child_index);
            }
            // move to the node we just swapped down
            index = greater_child_index;
        }
    } else {
        // min heap logic
        while (has_heap_node_left_child(h, index)) {
            size_t smaller_child_index = get_heap_node_left_child_index(index);

            if (has_heap_node_right_child(h, index) && (get_heap_node_right_child(h, index) <
                                                        get_heap_node_left_child(h, index))) {
                smaller_child_index = get_heap_node_right_child_index(index);
            }

            if (h->data_arr[index] <= h->data_arr[smaller_child_index]) {
                break;
            } else {
                _swap_heap_nodes(h, index, smaller_child_index);
            }
            // move to the node we just swapped down
            index = smaller_child_index;
        }
    }
}

bool initialize_heap(heap *h, size_t capacity, enum heap_type type) {
    /*
     * create and initialize the heap
     * time complexity: O(1)
     * space complexity: O(1)
     */
    h->data_arr = malloc(capacity * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->type = type; // non zero value means max heap
    h->initial_capacity = capacity;
    h->current_capacity = capacity;
    h->size = 0;
    h->build_heap_flag = false;
    return true;
}

bool is_empty_heap(heap *h) {
    /*
     * check if the heap is empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h->size == 0) {
        return true;
    }
    return false;
}

/*
 heap s;
 get_heap_size(s);
 // s is now source

*/

size_t get_heap_size(heap *h) {
    /*
     * get the heap size
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->size;
}

bool push_heap(heap *h, int data) {
    /*
     * insert an element in the heap
     * time complexity: O(log(n))
     * space complexity: O(1)
     */
    bool return_type;

    if (h->size == h->current_capacity) {
        return_type = _doubling_heap(h);
        if (return_type == false) {
            return false;
        }
    }
    // place the data at the last
    // from conceptual heap structure point of view: at the bottom far right
    h->data_arr[h->size] = data;
    h->size++;
    // restore the heap structure by bubbling up the element
    heapify_up(h, (h->size - 1));

    return true;
}

bool peek_heap(heap *h, int *out_data) {
    /*
     * peek the high priority element
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    return true;
}

bool pop_heap(heap *h, int *out_data) {
    /*
     * remove an element from the heap
     * time complexity: O(log(n))
     * space complexity: O(1)
     */
    bool return_type;
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    h->data_arr[0] = h->data_arr[h->size - 1];
    h->size--;
    heapify_down(h, 0);

    if (h->size < h->current_capacity / 2) {
        return_type = _halving_heap(h);
        if (return_type == false) {
            return false;
        }
    }
    return true;
}

void display_heap(heap *h) {
    /*
     * display heap elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    if (h != NULL) {
        size_t counter;
        for (counter = 0; counter < h->size; counter++) {
            printf("%d ", h->data_arr[counter]);
        }
    }
}

bool delete_heap(heap *h) {
    /*
     * delete the heap
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h != NULL) {
        if (h->build_heap_flag != true) {
            free(h->data_arr);
            // prevent to leak address from stack
            h->data_arr = NULL;
        }
        return true;
    }
    return false;
}

bool build_heap(heap *h, enum heap_type type, int *arr, size_t n) {
    /*
     * heapify an array, bottom up approach
     * start from bottom and check if that node and its children maintains the heap property
     * time complexity: O(n)
     * space complexity: O(1)
     */
    size_t i;

    if (h == NULL || arr == NULL) {
        return false;
    }

    h->build_heap_flag = true;
    h->data_arr = arr;
    h->type = type; // non zero value means max heap
    h->initial_capacity = n;
    h->current_capacity = n;
    h->size = n;

    // 1/2 elements are leaf nodes and those always satisfy the heap property, so discard those
    // start from the last level left most element and iterate to root
    // scanning from right to left, bottom to top
    for (i = (n - 1) / 2;; i--) {
        heapify_down(h, i);
        // i -> unsigned, integer overflow causes infinite loop
        // stop the heapify_down process and break out from loop when i = root
        if (i == 0) {
            break;
        }
    }
    return true;
}

static void _swap(int *a, int *b) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int *arr, size_t n, bool sort_type) {
    /*
     * use auxiliary data structure: max heap, sort_type: true -> asc
     * in-place sorting
     * time complexity: O(n + n*log(n))
     * space complexity: O(1)
     */
    size_t i;
    heap h;

    if (arr == NULL) {
        return;
    }

    // build the heap: O(n)
    build_heap(&h, sort_type, arr, n);

    for (i = n - 1; i > 0; i--) {
        _swap(&arr[0], &arr[i]);
        h.size--;
        // time complexity: O(log(n))
        heapify_down(&h, 0);
    }
    delete_heap(&h);
}

bool peek_heap_by_index(heap *h, size_t index, int *out_data) {
    /*
     * get heap element by index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (index < 0 || index > h->size) {
        return false;
    }
    *out_data = h->data_arr[index];
    return true;
}

bool pop_heap_by_index(heap *h, size_t index, int *out_data) {
    /*
     * remove random element from the heap by index
     * time complexity:
     * space complexity:
     */
    int return_type, parent;
    return_type = peek_heap_by_index(h, index, out_data);
    if (return_type == false) {
        return false;
    }
    // overwrite with the last element
    h->data_arr[index] = h->data_arr[h->size - 1];
    // reduce the size by 1
    h->size--;

    // get the parent of the swapped node
    parent = get_heap_node_parent(h, index);

    if (h->type == HEAP_TYPE_MAX_HEAP) {
        // max heap
        if (h->data_arr[index] > parent) {
            heapify_up(h, index);
        } else {
            heapify_down(h, index);
        }
    } else {
        // min heap
        if (h->data_arr[index] > parent) {
            heapify_down(h, index);
        } else {
            heapify_up(h, index);
        }
    }
    return true;
}