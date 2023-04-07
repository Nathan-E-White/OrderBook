CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
PROJECT(OrderBook)

SET(CMAKE_CXX_STANDARD 23)

# Let's call the cmake module to handle boost c++ libraries
FIND_PACKAGE(Boost 1.80.0 REQUIRED)

# Now let's add the include directories
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Let's add the library directories
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})


ADD_EXECUTABLE(OrderBook main.cpp MagmaCategory.tcc SkipList.c++ SkipList.tcc JudyArray.c++ JudyArray.tcc BinarySearchTree.c++ BinarySearchTree.tcc BinarySearchTreeNode.c++ BinarySearchTreeNode.tcc SearchTree.c++ SearchTree.h++ ErrorCodes.h++ ExpressionCodes.h++ ExpressionTokenType.h++ Expression.c++ Expression.tcc)

# Let's add the libraries
TARGET_LINK_LIBRARIES(OrderBook ${Boost_LIBRARIES})
