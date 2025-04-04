cmake_minimum_required(VERSION 3.28)
project(libmercury C)
set(CMAKE_C_STANDARD 99)

# Library - combine all source files into one library target
add_library(mercury STATIC
        src/stack_singly_linkedlist.c
        src/queue_singly_linkedlist.c
        src/binary_heap_dynamic_array.c
)
target_include_directories(mercury PUBLIC include)

# Examples - stack
add_executable(example_stack_singly_linkedlist examples/example_stack_singly_linkedlist.c)
target_include_directories(example_stack_singly_linkedlist PRIVATE include)
target_link_libraries(example_stack_singly_linkedlist mercury)

# Examples - queue
add_executable(example_queue_singly_linkedlist examples/example_queue_singly_linkedlist.c)
target_include_directories(example_queue_singly_linkedlist PRIVATE include)
target_link_libraries(example_queue_singly_linkedlist mercury)

# Examples - binary heap using dynamic array
add_executable(example_binary_heap_dynamic_array examples/example_binary_heap_dynamic_array.c)
target_include_directories(example_binary_heap_dynamic_array PRIVATE include)
target_link_libraries(example_binary_heap_dynamic_array mercury)

# Enable testing
enable_testing()

# Unity test framework
set(UNITY_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/Unity/src)
add_library(unity STATIC
        ${UNITY_SRC_DIR}/unity.c
)
target_include_directories(unity PUBLIC ${UNITY_SRC_DIR})

# Add test executables with unique names - stack
add_executable(test_stack_singly_linkedlist tests/test_stack_singly_linkedlist.c)
target_include_directories(test_stack_singly_linkedlist PRIVATE
        include
        ${UNITY_SRC_DIR}
)
target_link_libraries(test_stack_singly_linkedlist mercury unity)

# Add test executables with unique names - queue
add_executable(test_queue_singly_linkedlist tests/test_queue_singly_linkedlist.c)
target_include_directories(test_queue_singly_linkedlist PRIVATE
        include
        ${UNITY_SRC_DIR}
)
target_link_libraries(test_queue_singly_linkedlist mercury unity)

# Add test executables with unique names - binary_heap_dynamic_array
add_executable(test_binary_heap_dynamic_array tests/test_binary_heap_dynamic_array.c)
target_include_directories(test_binary_heap_dynamic_array PRIVATE
        include
        ${UNITY_SRC_DIR}
)
target_link_libraries(test_binary_heap_dynamic_array mercury unity)

# Register tests with unique names
add_test(NAME StackUnitTests COMMAND test_stack_singly_linkedlist)
add_test(NAME QueueUnitTests COMMAND test_queue_singly_linkedlist)
add_test(NAME HeapDAUnitTests COMMAND test_binary_heap_dynamic_array)