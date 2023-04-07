#include <iostream>
#include <algorithm>
#include <atomic>
#include <mutex>
#include <thread>
#include <hash_map>
#include <hash_set>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <array>
#include <execution>
#include <decimal/decimal>


#define ND [[nodiscard]]
#define MU [[maybe_unused]]
#define NR [[noreturn]]


template < typename K, std::less< K > C, std::allocator< K > A >
class Test : std::set< K > {


public:

private:
    Test () = default;
};


template < std::size_t Num_Exchanges >
class Instrument;

template < std::size_t Num_Exchanges >
class Exchange;

class Price;

class Quote;


class OrderBook;


template < typename data, template < typename > typename hash >
concept IsHashableQ = requires (data dset, hash< data > hash_fn) {
    requires hash< data >::value;
    requires true;
};

template < typename data, template < typename > typename pred >
concept IsPredicatableQ = requires (data dset, pred< data > pred_fn) {
    typename pred< data >::value;
    requires true;
};

template < typename data, template < typename > typename allo >
concept IsAllocatableQ = requires (data dset, allo< data > allo_fn) {
    typename allo< data >::value;
    requires true;
};


template <
        typename EClass,
        template < typename > typename Hash = std::hash,
        template < typename > typename Predicate = std::equal_to,
        template < typename > typename Allocator = std::allocator
> requires IsAllocatableQ< EClass, Allocator > && requires{ requires IsPredicatableQ< EClass, Predicate >; } &&
           requires{ requires IsHashableQ< EClass, Hash >; }
class EnumSet {
private:

    using tab_dat = EClass;
    using hash_fn = Hash< EClass >;
    using pred_fn = Predicate< EClass >;
    using allo_fn = Allocator< EClass >;

    std::unordered_set< tab_dat, hash_fn, pred_fn, allo_fn > m_hashtable;

    void load_set () {
        for (
            auto item: EClass::members
                ) {

        }
    }

public:


};


enum class AssetClass {
    Equity, FixedIncome, FX, Commodity, Derivative, NullAssetClass
};


// value, hash, pred, alloc
// template < typename Fn, typename ... Args >
// std::predicate< std::function< bool (Args...) >, Args... > pf;

// std::unordered_set< AssetClass > AssetClasses {AssetClass::All};

enum class OrderType {
    Market, Limit, Stop, StopLimit, NullOrderType
};

enum class OrderSide {
    Buy, Sell, NullOrderSide
};

enum class OrderStatus {
    New, PartiallyFilled, Filled, Cancelled, Rejected, NullOrderStatus
};

enum class OrderValidity {
    Day, GTC, IOC, FOK, NullOrderValidity
};

enum class OrderExecution {
    ImmediateOrCancel, FillOrKill, Auction, NullOrderExecution
};

enum class OrderTimeInForce {
    Day, GTC, IOC, FOK, NullOrderTimeInForce
};


namespace Types::OrderTrigger {

    enum class OrderTrigger {
        Immediate, Stop, StopLimit, NullOrderTrigger
    };

    constinit static const auto NumOrderTriggerTypes = std::plus<> () (
            static_cast< std::size_t >(OrderTrigger::NullOrderTrigger),
            static_cast<std::size_t>(0x1)
    );

    constinit static const
    std::array< const std::bitset< NumOrderTriggerTypes >, NumOrderTriggerTypes >
            OrderTriggerTypes = {
            std::bitset< NumOrderTriggerTypes > (0x1 << static_cast< std::size_t >(OrderTrigger::Immediate)),
            std::bitset< NumOrderTriggerTypes > (0x1 << static_cast< std::size_t >(OrderTrigger::Stop)),
            std::bitset< NumOrderTriggerTypes > (0x1 << static_cast< std::size_t >(OrderTrigger::StopLimit)),
            std::bitset< NumOrderTriggerTypes > (0x1 << static_cast< std::size_t >(OrderTrigger::NullOrderTrigger))
    };

    auto dispatch_order_trigger_type (OrderTrigger trigger) -> std::bitset< NumOrderTriggerTypes > {
        return OrderTriggerTypes[static_cast< std::size_t >(trigger)];
    }


}

namespace Types::ListingStatus {
    enum class ListingStatus {
        Active, Inactive, Suspended, Delisted, Expired, Withdrawn, Pending, NullListingStatus
    };
}

enum class OrderBookType {
    Limit, Market, Stop, StopLimit, NullOrderBookType
};
constinit static const auto NumOrderBookTypes = std::plus<> () (
        static_cast< std::size_t >(OrderBookType::NullOrderBookType),
        static_cast<std::size_t>(0x1)
);

// create a std::bitset with the same length as enum class OrderBookType
constinit static const
std::array< const std::bitset< NumOrderBookTypes >, NumOrderBookTypes >
        OrderBookTypes = {
        std::bitset< NumOrderBookTypes > (static_cast< std::size_t >(OrderBookType::Limit)),
        std::bitset< NumOrderBookTypes > (static_cast< std::size_t >(OrderBookType::Market)),
        std::bitset< NumOrderBookTypes > (static_cast< std::size_t >(OrderBookType::Stop)),
        std::bitset< NumOrderBookTypes > (static_cast< std::size_t >(OrderBookType::StopLimit)),
        std::bitset< NumOrderBookTypes > (static_cast< std::size_t >(OrderBookType::NullOrderBookType))
};

auto dispatch_order_book_type (OrderBookType type) -> std::bitset< NumOrderBookTypes > {
    return OrderBookTypes[static_cast< std::size_t >(type)];
}

enum class EquityType : std::uint8_t {
    Common, Preferred, Warrant, Right, Convertible, Index, ETF, MutualFund, Other, NULL_EquityType
};


enum class FixedIncomeType : std::uint8_t {
    Bond, Note, Bill, Convertible, Index, ETF, MutualFund, Other, NULL_FIXED_INCOME_TYPE
};

enum class FXType : std::uint8_t {
    Spot, Forward, Swap, Option, Future, Index, ETF, MutualFund, Other, NULL_FX_TYPE
};

enum class CommodityType : std::uint8_t {
    Spot, Forward, Swap, Option, Future, Index, ETF, MutualFund, Other, NULL_COMMODITY_TYPE
};

enum class DerivativeType : std::uint8_t {
    Option, Future, Index, ETF, MutualFund, Other, NULL_DERIVATIVE_TYPE
};

enum class ExchangeType : std::uint8_t {
    Equity, FixedIncome, FX, Commodity, Derivative, NULL_EXCHANGE_TYPE
};

enum class ExchangeStatus : std::uint8_t {
    Active, Inactive, Suspended, Delisted, NULL_EXCHANGE_STATUS
};

enum class Exchanges : std::uint8_t {
    NYSE, NASDAQ, BATS, CBOE, CME, ICE, LSE, EUREX, SGX, HKEX, TSE, SSE, SZSE, BSE, NSE, JSE, ASX, TSX, CSE, TSXV, OTC,
    OTCBB, OTCQB, OTCQX, OTCMKTS, OTCMKT, OTCMKTG, OTCMKTW, OTCMKTX, OTCMKTZ, OTCMKTQ, OTCMKTU, NullExchange
};


auto constexpr inline u8_to_u32 (std::uint8_t const u8) noexcept -> std::uint32_t {
    return static_cast< std::uint32_t >( u8 );
}

auto constexpr inline u8_to_u16 (std::uint8_t const u8) noexcept -> std::uint16_t {
    return static_cast< std::uint16_t >( u8 );
}

auto constexpr inline u8_to_u64 (std::uint8_t const u8) noexcept -> std::uint64_t {
    return static_cast< std::uint64_t >( u8 );
}

template < class EClass >
auto constexpr inline enum_to_u8 (EClass const e_mem) noexcept -> std::uint8_t {
    return static_cast< std::uint8_t >( e_mem );
}

template < typename EClass >
auto constexpr inline enum_as_size_t (const EClass e_mem) noexcept -> std::size_t {
    return static_cast< std::size_t >( enum_to_u8< EClass > (e_mem));
}

template < typename N > requires std::is_integral_v< N > and std::is_arithmetic_v< N >
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantParameter"
auto constexpr inline as_size_t (const N n) noexcept -> std::size_t {
#pragma clang diagnostic pop
    return static_cast< std::size_t >( n );
}

// get the index of the null exchange
constexpr std::size_t null_exchange_index = enum_as_size_t (Exchanges::NullExchange);

// Define the number of exchanges
constinit static const std::size_t
        N_EXCHANGES =
        std::plus<> () (enum_as_size_t (Exchanges::NullExchange), as_size_t (0x1));


MU constinit static const
std::size_t N_ASSET_CLASSES = std::plus<> () (
        enum_as_size_t (AssetClass::NullAssetClass),
        as_size_t (0x1)
);

MU constinit static const
std::size_t N_ORDER_TYPES = std::plus<> () (
        enum_as_size_t (OrderType::NullOrderType), as_size_t (0x1)
);

MU constinit static const
std::size_t N_ORDER_SIDES = std::plus<> () (
        enum_as_size_t (OrderSide::NullOrderSide), +as_size_t (0x1)
);

MU constinit static const
std::size_t                 N_ORDER_STATUSES = std::plus<> () (
        enum_as_size_t (OrderStatus::NullOrderStatus), as_size_t (0x1)
);

constinit static const
std::size_t N_ORDER_VALIDITIES = std::plus<> () (
        enum_as_size_t (OrderValidity::NullOrderValidity), as_size_t (0x1)
);

constinit static const
std::size_t N_ORDER_EXECUTIONS = std::plus<> () (
        enum_as_size_t (OrderExecution::NullOrderExecution), as_size_t (0x1)
);

constinit static const
std::size_t N_ORDER_TIME_IN_FORCES = std::plus<> () (
        enum_as_size_t (OrderTimeInForce::NullOrderTimeInForce), as_size_t (0x1)
);

constinit static const
std::size_t N_ORDER_TRIGGERS = std::plus<> () (
        enum_as_size_t (Types::OrderTrigger::OrderTrigger::NullOrderTrigger), as_size_t (0x1)
);

constinit static const
std::size_t N_LISTING_STATUSES = std::plus<> () (
        enum_as_size_t (Types::ListingStatus::ListingStatus::NullListingStatus), as_size_t (0x1)
);

constinit static const
std::size_t N_ORDER_BOOK_TYPES = std::plus<> () (
        enum_as_size_t (OrderBookType::NullOrderBookType), as_size_t (0x1)
);

constinit static const
std::size_t N_EQUITY_TYPES = std::plus<> () (
        enum_as_size_t (EquityType::NULL_EquityType), as_size_t (0x1)
);

constinit static const
std::size_t N_FIXED_INCOME_TYPES = std::plus<> () (
        enum_as_size_t (FixedIncomeType::NULL_FIXED_INCOME_TYPE), as_size_t (0x1)
);

constinit static const
std::size_t N_FX_TYPES = std::plus<> () (
        enum_as_size_t (FXType::NULL_FX_TYPE), as_size_t (0x1)
);

constinit static const
std::size_t N_COMMODITY_TYPES = std::plus<> () (
        enum_as_size_t (CommodityType::NULL_COMMODITY_TYPE), as_size_t (0x1)
);

constinit static const
std::size_t N_DERIVATIVE_TYPES = std::plus<> () (
        enum_as_size_t (DerivativeType::NULL_DERIVATIVE_TYPE), as_size_t (0x1)
);

constinit static const std::size_t N_EXCHANGE_TYPES = std::plus<> () (
        enum_as_size_t (ExchangeType::NULL_EXCHANGE_TYPE), as_size_t (0x1)
);


constinit static const std::size_t N_EXCHANGE_STATUSES = std::plus<> () (
        enum_as_size_t (ExchangeStatus::NULL_EXCHANGE_STATUS), as_size_t (0x1)
);


static const constinit
std::bitset< N_EXCHANGES > empty_exchange_membership;

static const constinit
std::bitset< N_ASSET_CLASSES > empty_asset_class_membership;

static const constinit
std::bitset< N_LISTING_STATUSES > empty_listing_status_membership;


template < std::size_t Num_Exchanges >
class ExchangeMembership {
private:

    std::bitset< Num_Exchanges > m_exchanges = {};

public:

    void define_memberships () {

    }
};

template <
        std::size_t Num_Exchanges
>
class Instrument {

private:
    std::u32string                      m_name        = U"UNKNOWN";
    std::u32string                      m_symbol      = U"UNKNOWN";
    AssetClass                          m_asset_class = AssetClass::NullAssetClass;
    ExchangeMembership< Num_Exchanges > m_exchange_membership;

public:
    std::uint64_t m_name_hash = std::numeric_limits< std::uint64_t >::max ();
    std::uint64_t m_sym_hash  = std::numeric_limits< std::uint64_t >::max ();


public:

};


class OrderSpec {

private:

    OrderSide                         m_side          = OrderSide::NullOrderSide;
    OrderType                         m_type          = OrderType::NullOrderType;
    OrderValidity                     m_validity      = OrderValidity::NullOrderValidity;
    OrderTimeInForce                  m_time_in_force = OrderTimeInForce::NullOrderTimeInForce;
    Types::OrderTrigger::OrderTrigger m_trigger       = Types::OrderTrigger::OrderTrigger::NullOrderTrigger;
    OrderExecution                    m_execution     = OrderExecution::NullOrderExecution;
    OrderStatus                       m_status        = OrderStatus::NullOrderStatus;

public: /* Default constructor */
    constexpr OrderSpec () = default;

public: /* Copy constructor */
    constexpr OrderSpec (const OrderSpec &) = default;

public: /* Move constructor */
    constexpr OrderSpec (OrderSpec &&) noexcept = default;

public: /* Virtual Destructor */
    constexpr virtual ~OrderSpec () = default;

public: /* Copy assignment operator */
    constexpr OrderSpec & operator = (OrderSpec const &) noexcept = default;

public: /* Move assignment operator */
    constexpr OrderSpec & operator = (OrderSpec &&) noexcept = default;

public: /* Equality operator */
    constexpr bool operator == (OrderSpec const & rhs) const noexcept = default;

public: /* Inequality operator */
    constexpr bool operator != (OrderSpec const & rhs) const noexcept = default;

};


class OrderBook {

private:
    OrderBookType m_type = OrderBookType::NullOrderBookType;

    /* The order book is a collection of orders. */
    //std::vector< Order > m_orders;

    /* The order book is a collection of order executions. */
    //std::vector< OrderExecution > m_executions;

    /* The order book is a collection of order cancellations. */
    //std::vector< OrderCancellation > m_cancellations;

    /* The order book is a collection of order modifications. */
    //std::vector< OrderModification > m_modifications;

    /* The order book is a collection of order rejections. */
    //std::vector< OrderRejection > m_rejections;

    /* The order book is a collection of order fills. */
    //std::vector< OrderFill > m_fills;

    /* The order book is a collection of order partial fills. */
    //std::vector< OrderPartialFill > m_partial_fills;

    // the largest 4 bit unsigned integer is 15
    // the largest 5 bit unsigned integer is 31
    // the largest 6 bit unsigned integer is 63
    // the largest 7 bit unsigned integer is 127
    // the largest uint8_t value is 255
    // the largest uint16_t value is 65535
    // the largest uint32_t value is 4,294,967,295
    // the largest uint64_t value is 18,446,744,073,709,551,615

    using PriceLevel = uint16_t;
    using LevelInformation = std::vector< uint8_t >;

    /* Open Interest */


public:
    constexpr OrderBook () noexcept = default;

    constexpr OrderBook (const OrderBook &) noexcept = default;

    constexpr OrderBook (OrderBook &&) noexcept = default;

    constexpr auto operator = (const OrderBook &) noexcept -> OrderBook & = default;

    constexpr auto operator = (OrderBook &&) noexcept -> OrderBook & = default;

    constexpr virtual ~OrderBook () noexcept = default;

    constexpr auto operator == (const OrderBook &) const noexcept -> bool = default;

    constexpr auto operator != (const OrderBook &) const noexcept -> bool = default;

    constexpr auto operator <=> (const OrderBook &) const noexcept -> std::strong_ordering = default;

    constexpr auto operator < (const OrderBook &) const noexcept -> bool = default;

    constexpr auto operator > (const OrderBook &) const noexcept -> bool = default;

    constexpr auto operator <= (const OrderBook &) const noexcept -> bool = default;

    ND MU constexpr auto operator >= (const OrderBook &) const noexcept -> bool = default;


    /* Member Functions */

    /* GETTERS */
    ND MU constexpr auto get_type () const noexcept -> OrderBookType {
        return m_type;
    }

    /* SETTERS */
    MU constexpr auto set_type (const OrderBookType & type) noexcept -> void {
        m_type = type;
    }


};


int main () {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
