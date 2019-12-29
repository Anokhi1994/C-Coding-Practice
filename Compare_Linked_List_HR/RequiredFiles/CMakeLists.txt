set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ReqLib SinglyLinkedList.cpp singlyLinkedListNode.cpp)
target_include_directories(ReqLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
