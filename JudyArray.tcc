//
// Created by Nathan White on 11/25/22.
//

#ifndef ORDERBOOK_JUDYARRAY_TCC
#define ORDERBOOK_JUDYARRAY_TCC

#include <cstddef>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <bit>
#include <stack>
#include <array>
#include <memory>
#include <boost/container/set.hpp>
#include <set>
#include <boost/flyweight.hpp>



// create a shorthand for the boost container namespace
namespace bst::con = boost::container;

// create a shorthand for the boost container set



template < typename Record >
class JudyArray {

private:    /* Private Types */
public:     /* Public Types */

private:    /* Private Data */
    std::array< Record, 1024 >           m_array = {0};
    std::stack< Record >                 m_stack = std::stack< Record > ();
    boost::container::flat_set< Record > m_tree  = boost::container::flat_set< Record > ();

public:     /* Public Data */



public:   /* Default Constructor */
    constexpr JudyArray () = default;

    constexpr JudyArray (JudyArray const &) = default;

    constexpr JudyArray (JudyArray &&) noexcept = default;

    constexpr virtual ~ JudyArray () = default;

    constexpr JudyArray & operator = (JudyArray const &) = default;

    constexpr JudyArray & operator = (JudyArray &&) noexcept = default;


public:     /* Getters */

public:     /* Setters */


private:    /* Private Methods */

public:     /* Public Methods */




};

enum class OrderType {
    Limit, Market, Stop, StopLimit, TrailingStop, TrailingStopLimit, FillOrKill, ImmediateOrCancel, MarketOnClose,
    MarketOnOpen, MarketWithLeftOverAsLimit, Pegged, PeggedLimit, PeggedStop, PeggedStopLimit, PeggedTrailingStop,
    PeggedTrailingStopLimit, PeggedFillOrKill, PeggedImmediateOrCancel, PeggedMarketOnClose, PeggedMarketOnOpen,
    PeggedMarketWithLeftOverAsLimit, Unknown
};

enum class WhichNode { LHS, RHS, Unknown };

// Class for a decision tree
template < typename Record >
class DecisionTree {

private:    /* Private Types */
public:     /* Public Types */
private:    /* Private Data */
    const std::shared_ptr< DecisionTree< Record>> m_root   = std::shared_ptr< DecisionTree< Record>> (this);
    std::shared_ptr< DecisionTree< Record>>       m_parent = nullptr;
    std::shared_ptr< DecisionTree< Record>>       m_left   = nullptr;
    std::shared_ptr< DecisionTree< Record>>       m_right  = nullptr;

public:     /* Public Methods *
 *



    constexpr void add_node (Record const & record, WhichNode const & which_node) const {
        /* Add a node to the tree */
        switch (which_node) {
            case WhichNode::LHS:

                m_left = std::make_shared< DecisionTree< Record>> (record);
                m_left->m_parent = std::make_shared< DecisionTree< Record>> (this);
                m_left->m_root   = std::copy (this->m_root);
                m_left->m_left   = nullptr;
                m_left->m_right  = nullptr;

                break;

            case WhichNode::RHS:
                m_right = std::make_shared< DecisionTree< Record>> (record);
                m_right->m_parent = std::make_shared< DecisionTree< Record>> (this);
                m_right->m_root   = std::copy (this->m_root);
                m_right->m_right  = nullptr;
                m_right->m_left   = nullptr;

                break;

            default:
                break;
        }
    }

public:     /* Default Constructor */
    constexpr DecisionTree () = default;

    constexpr DecisionTree (DecisionTree const &) = default;

    constexpr DecisionTree (DecisionTree &&) noexcept = default;

    constexpr virtual ~ DecisionTree () = default;

    constexpr DecisionTree & operator = (DecisionTree const &) = default;

    constexpr DecisionTree & operator = (DecisionTree &&) noexcept = default;


};


#endif //ORDERBOOK_JUDYARRAY_TCC
