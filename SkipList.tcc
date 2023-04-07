//
// Created by Nathan White on 11/25/22.
//

#ifndef ORDERBOOK_SKIPLIST_TCC
#define ORDERBOOK_SKIPLIST_TCC


#include <cstddef>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <bit>


#define UINT long long unsigned int
#define open_db open64
#define lseek lseek
#define fstat fstat
#define fsync fdatasync
#define LSM_CREAT_FLAGS  (O_RDWR | O_TRUNC | O_CREAT | O_BINARY | O_LARGEFILE)
#define LSM_OPEN_FLAGS   (O_RDWR | O_BINARY | O_LARGEFILE)

typedef enum { ADD, DEL } op_t;

constinit const static std::size_t MAX_LEVEL = 15;

constinit const static std::size_t SKIP_KSIZE = 256;


class Slice {
    char * data;
    int len;
};


template < typename T, std::size_t skip_ksize = SKIP_KSIZE, std::size_t max_level = MAX_LEVEL >
class SkipNode {
public:
    std::array< T, skip_ksize > key;
    std::uint64_t               val;
    op_t                        opt;

    class SkipNode * fwd[1];

    class SkipNode * nxt;
};


template < std::size_t N >
auto random_level () {
    std::size_t level = 1;
    while (level < N && (std::rand () & 0xFFFF) < (0.25 * 0xFFFF)) {
        level++;
    }
    return level;
}


template < std::size_t N >
constexpr auto get_critical_bit (std::bitset< N > const & lhs, std::bitset< N > const & rhs) -> std::size_t {
    auto mid= std::bit_xor< std::bitset< N > > (lhs, rhs).to_ulong ();

    return std::bit_cast< std::size_t > (mid);
}


#endif //ORDERBOOK_SKIPLIST_TCC
