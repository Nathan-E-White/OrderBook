#ifndef ORDERBOOK_EXPRESSION_TCC
#define ORDERBOOK_EXPRESSION_TCC

#include <any>
#import "ExpressionCodes.h++"


namespace Expression::Class {

    class Expression {
    private:
    public:
        using Value = std::any;


        Codes::ExpressionCode evaluate_prefix (Value & result);

        Codes::ExpressionCode get_token (Value & result);


    };

}

#endif
