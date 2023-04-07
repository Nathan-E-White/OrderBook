//
// Created by Nathan White on 11/25/22.
//

#ifndef ORDERBOOK_BINARYSEARCHTREE_TCC
#define ORDERBOOK_BINARYSEARCHTREE_TCC


#include <cstddef>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <bit>
#include <stack>
#include <memory>

#include "BinarySearchTreeNode.tcc"
#include "ErrorCodes.h++"


template <class Record>
class BinarySearchTree: public SearchTree<Record> {

private:    /* Private Types */

public:     /* Public Types */


private:    /* Private Data */

    std::allocator< BinarySearchTreeNode > m_node_allocator;

public:     /* Public Data */

public:   /* Default Constructor */
    constexpr BinarySearchTree () = default;

    constexpr BinarySearchTree (BinarySearchTree const &) = default;

    constexpr BinarySearchTree (BinarySearchTree &&) noexcept = default;

    constexpr virtual ~ BinarySearchTree () = default;

    constexpr BinarySearchTree & operator = (BinarySearchTree const &) = default;

    constexpr BinarySearchTree & operator = (BinarySearchTree &&) noexcept = default;


public:     /* Getters */

public:     /* Setters */


private:    /* Private Methods */

public:     /* Public Methods */


    ErrorCode build_tree (const std::list< Record > & records);
};


#endif //ORDERBOOK_BINARYSEARCHTREE_TCC
