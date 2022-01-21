add_executable(linkedList linkedlist.cpp)

target_compile_definitions(linkedList PUBLIC LINKED_LIST_VERSION=1)
target_link_libraries(linkedList PRIVATE singly-lib)
