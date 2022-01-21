add_library(
            singly-lib 
            singlyLinkedList.cpp
            singlyLinkedList.hpp
            )

target_include_directories(singly-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
