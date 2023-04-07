//
// Created by Nathan White on 11/25/22.
//

#ifndef ORDERBOOK_MAGMACATEGORY_TCC
#define ORDERBOOK_MAGMACATEGORY_TCC

#include <functional>
#include <variant>
#include <optional>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <any>
#include <memory_resource>
#include <cstdlib>
#include <cstdint>
#include <memory>
#include <limits>
#include <concepts>
#include <typeindex>
#include <type_traits>
#include <utility>
#include <algorithm>
#include <iterator>
#include <scoped_allocator>
#include <initializer_list>


template < typename Ob, std::size_t N = 1 >
class MagmaCategory {

private:    /* Private Types */
public:     /* Public Types */

private:
    std::function< Ob (Ob, Ob) >                                         m_bop;

public:

    constexpr MagmaCategory () = default;

    constexpr MagmaCategory (MagmaCategory< Ob, N > const &) = default;

    constexpr MagmaCategory (MagmaCategory< Ob, N > &&) noexcept = default;

    constexpr virtual ~ MagmaCategory () = default;

    constexpr MagmaCategory< Ob, N > & operator = (MagmaCategory< Ob, N > const &) = default;

    constexpr MagmaCategory< Ob, N > & operator = (MagmaCategory< Ob, N > &&) noexcept = default;

    constexpr MagmaCategory< Ob, N > & operator = (MagmaCategory< Ob, N >) = default;


    constexpr bool operator == (const MagmaCategory< Ob, N > & rhs) const {
        return std::tie (m_bop) == std::tie (rhs.m_bop);
    }

    constexpr bool operator != (const MagmaCategory< Ob, N > & rhs) const {
        return rhs != * this;
    }

    constexpr explicit MagmaCategory (const std::function< Ob (Ob, Ob) > & b_op) :
            m_bop (b_op) {}


public:     /* Setters */

    constexpr void set_bop (const std::function< Ob (Ob, Ob) > & b_op) {
        this->m_bop = b_op;
    }

public:     /* Getters */

    constexpr auto get_bop () const -> std::function< Ob (Ob, Ob) > & {
        return this->m_bop;
    }

};


template < typename Ob, std::size_t N = 1 >
class FreeMagmaCategory : public MagmaCategory< Ob, N > {

private:    /* Private Types */
public:     /* Public Types */

private:
    using node_ptr_t = std::shared_ptr< FreeMagmaCategory< Ob, N > >;
    using node_t = std::variant< std::monostate, Ob, node_ptr_t >;

    node_t m_node;

public:
    template <typename std::size_t M = 2>
    using tree_lvl_t = std::array< node_t, M>;

    std::array< std::optional< std::array< std::optional< Ob >, 2>>, 1 > tree;


protected: /* Default Constructor */
    constexpr FreeMagmaCategory () = default;

protected: /* Copy Constructor */
    constexpr FreeMagmaCategory (FreeMagmaCategory< Ob, N > const &) = default;

protected: /* Move Constructor */
    constexpr FreeMagmaCategory (FreeMagmaCategory< Ob, N > &&) noexcept = default;

protected: /* Destructor */
    constexpr ~ FreeMagmaCategory () override = default;

protected: /* Copy Assignment */
    constexpr FreeMagmaCategory< Ob, N > & operator = (FreeMagmaCategory< Ob, N > const &) = default;

protected: /* Move Assignment */
    constexpr FreeMagmaCategory< Ob, N > & operator = (FreeMagmaCategory< Ob, N > &&) noexcept = default;

protected: /* Move Assignment */
    constexpr FreeMagmaCategory< Ob, N > & operator = (FreeMagmaCategory< Ob, N >) = default;


};


#endif //ORDERBOOK_MAGMACATEGORY_TCC
