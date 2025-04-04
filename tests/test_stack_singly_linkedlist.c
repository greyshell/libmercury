/*
 * author: greyshell
 * description: unittests case
 * */

#include <string.h>
#include "Unity/src/unity.h"
#include "../include/stack_singly_linkedlist.h"

// create the data structure
stack s;

void setUp(void) {
    // initialize the data structure
    initialize_stack(&s);
}

void tearDown(void) {
    // delete the data structure
    delete_stack(&s);
}

void test_case01(void){
    /*
     * test ops: push -> push -> peek
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push(&s, 10));
    TEST_ASSERT_EQUAL_INT(true, push(&s, 90));
    TEST_ASSERT_EQUAL_INT(true, peek(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case02(void){
    /*
     * test ops: push -> push -> push -> pop -> peek
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push(&s, 10));
    TEST_ASSERT_EQUAL_INT(true, push(&s, 90));
    TEST_ASSERT_EQUAL_INT(true, push(&s, 50));
    TEST_ASSERT_EQUAL_INT(true, pop(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(50, out_data);
    TEST_ASSERT_EQUAL_INT(true, peek(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case03(void){
    /*
     * test ops: get_stack_size -> push -> push -> get_stack_size -> pop -> get_stack_size
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(0, get_stack_size(&s));
    TEST_ASSERT_EQUAL_INT(true, push(&s, 10));
    TEST_ASSERT_EQUAL_INT(true, push(&s, 90));
    TEST_ASSERT_EQUAL_INT(2, get_stack_size(&s));
    TEST_ASSERT_EQUAL_INT(true, pop(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(1, get_stack_size(&s));

}

void test_case04(void) {
    /*
     * test ops: peek -> pop
     */
    int out_data = 0;
    TEST_ASSERT_EQUAL_INT(false, peek(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
    TEST_ASSERT_EQUAL_INT(false, pop(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
}

void test_case05(void) {
    /*
     * test ops: pop -> peek
     */
    int out_data = 0;
    TEST_ASSERT_EQUAL_INT(false, pop(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
    TEST_ASSERT_EQUAL_INT(false, peek(&s, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_case01);
    RUN_TEST(test_case02);
    RUN_TEST(test_case03);
    RUN_TEST(test_case04);
    RUN_TEST(test_case05);
    return UNITY_END();
}