/*
 * author: greyshell
 * description: unittests case
 * */

#include <string.h>
#include "Unity/src/unity.h"
#include "../include/queue_singly_linkedlist.h"

// create the data structure
queue q;

void setUp(void) {
    // initialize the data structure
    initialize_queue(&q);
}

void tearDown(void) {
    // delete the data structure
    delete_queue(&q);
}

void test_case01(void){
    /*
     * test ops: enque -> enque -> peek_at_front -> peek_at_rear
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, enqueue(&q, 10));
    TEST_ASSERT_EQUAL_INT(true, enqueue(&q, 20));

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(true, peek_at_front(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(true, peek_at_rear(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(20, out_data);

}

void test_case02(void){
    /*
     * test ops: enqueue -> dequeue -> peek_at_front -> peek_at_rear
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, enqueue(&q, 10));

    TEST_ASSERT_EQUAL_INT(true, dequeue(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, peek_at_front(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, peek_at_rear(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
}

void test_case03(void){
    /*
     * test ops: get_queue_size -> enqueue -> get_stack_size -> dequeue -> is_empty_queue
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(0, get_queue_size(&q));

    TEST_ASSERT_EQUAL_INT(true, enqueue(&q, 10));
    TEST_ASSERT_EQUAL_INT(1, get_queue_size(&q));

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(true, dequeue(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);

    TEST_ASSERT_EQUAL_INT(0, get_queue_size(&q));
    TEST_ASSERT_EQUAL_INT(true, is_empty_queue(&q));

}

void test_case04(void) {
    /*
     * test ops: peek_at_front -> dequeue -> peek_at_rear -> dequeue
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(false, peek_at_front(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, dequeue(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, peek_at_rear(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, dequeue(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);
}

void test_case05(void) {
    /*
     * test ops: deque -> peek_at_front => peek_at_rear
     */
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(false, dequeue(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    out_data = 0;  // clear out_data
    TEST_ASSERT_EQUAL_INT(false, peek_at_front(&q, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    TEST_ASSERT_EQUAL_INT(false, peek_at_rear(&q, &out_data));
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