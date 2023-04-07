//
// Created by Nathan White on 11/25/22.
//

#ifndef ORDERBOOK_SEARCHTREE_H
#define ORDERBOOK_SEARCHTREE_H


class SearchTree {

public:
    constexpr SearchTree() = default;

    constexpr SearchTree(const SearchTree& other) = default;

    constexpr SearchTree(SearchTree&& other) noexcept = default;

    constexpr SearchTree& operator=(const SearchTree& other) = default;

    constexpr SearchTree& operator=(SearchTree&& other) noexcept = default;

    constexpr virtual ~SearchTree() = default;


    virtual void insert() = 0;

    virtual void remove() = 0;

    virtual void find() = 0;


};


#endif
