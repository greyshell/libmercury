/*
 * author: greyshell
 * description: unittests case
 * */

#include <string.h>
#include "Unity/src/unity.h"
#include "../include/binary_heap_dynamic_array.h"

# define ARRAY_SIZE 5

// create the data structure
heap h_max;
heap h_min;

void setUp(void) {
    // initialize the data structure
    initialize_heap(&h_max, 1, HEAP_TYPE_MAX_HEAP);
    initialize_heap(&h_min, 1, HEAP_TYPE_MIN_HEAP);
}

void tearDown(void) {
    // delete the data structure
    delete_heap(&h_max);
    delete_heap(&h_min);
}

void test_case_1(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case_2(void){
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(3, get_heap_size(&h_max));
}

void test_case_3(void){
    TEST_ASSERT_EQUAL_INT(true, is_empty_heap(&h_max));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(false, is_empty_heap(&h_max));
}

void test_case_4(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);
}

void test_case_5(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 10));
    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);
}

void test_case_6(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 10));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case_7(void){
    int test_arr[ARRAY_SIZE] = {5, 2, 1, 3, 4};
    int exp_arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    heap_sort(test_arr, 5, true);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, test_arr, ARRAY_SIZE);
}

void test_case_8(void){
    int out_data = 0;
    int test_arr[7] = {10, 20, 30, 40, 150, 70, 160};
    int exp_arr[7] = {160, 150, 70, 40, 20, 10, 30};
    heap h;

    TEST_ASSERT_EQUAL_INT(true, build_heap(&h, true, test_arr, 7));
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, test_arr, 7);

    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(160, out_data);

    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(160, out_data);

    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);

    TEST_ASSERT_EQUAL_INT(true, delete_heap(&h));
}

void test_case_9(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(false, peek_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(false, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    TEST_ASSERT_EQUAL_INT(0, get_heap_size(&h_min));
}

void test_case_10(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 1));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 9));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 22));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 17));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 11));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 33));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 27));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 21));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 19));

    TEST_ASSERT_EQUAL_INT(true, pop_heap_by_index(&h_min, 5, &out_data));
    TEST_ASSERT_EQUAL_INT(33, out_data);

    TEST_ASSERT_EQUAL_INT(true, peek_heap_by_index(&h_min, 7, &out_data));
    TEST_ASSERT_EQUAL_INT(21, out_data);

    TEST_ASSERT_EQUAL_INT(true, peek_heap_by_index(&h_min, 2, &out_data));
    TEST_ASSERT_EQUAL_INT(19, out_data);

    TEST_ASSERT_EQUAL_INT(8, get_heap_size(&h_min));
}

void test_case_11(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 1));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 5));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 6));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 9));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 11));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 8));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 15));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 17));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 21));

    TEST_ASSERT_EQUAL_INT(true, pop_heap_by_index(&h_min, 1, &out_data));
    TEST_ASSERT_EQUAL_INT(5, out_data);

    TEST_ASSERT_EQUAL_INT(true, peek_heap_by_index(&h_min, 7, &out_data));
    TEST_ASSERT_EQUAL_INT(21, out_data);

    TEST_ASSERT_EQUAL_INT(true, peek_heap_by_index(&h_min, 4, &out_data));
    TEST_ASSERT_EQUAL_INT(11, out_data);

    TEST_ASSERT_EQUAL_INT(8, get_heap_size(&h_min));
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_case_1);
    RUN_TEST(test_case_2);
    RUN_TEST(test_case_3);
    RUN_TEST(test_case_4);
    RUN_TEST(test_case_5);
    RUN_TEST(test_case_6);
    RUN_TEST(test_case_7);
    RUN_TEST(test_case_8);
    RUN_TEST(test_case_9);
    RUN_TEST(test_case_10);
    RUN_TEST(test_case_11);

    return UNITY_END();
}