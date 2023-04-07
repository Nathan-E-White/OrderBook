#ifndef ORDERBOOK_EXPRESSION_TOKEN_TYPE_H
#define ORDERBOOK_EXPRESSION_TOKEN_TYPE_H

namespace Expression::Types {

    enum class ExpressionToken {
          OPERAND,
          UNARY_OPERATOR,
          BINARY_OPERATOR,
          OPEN_PARENTHESIS,
          CLOSE_PARENTHESIS,
          COMMA,
          UNKNOWN,
        NULL_TYPE
        , NUMBER
        , PLUS
        , MINUS
        , MULTIPLY
        , DIVIDE
        , END
        , ERROR
        , NONE
        , UNEXPECTED_TOKEN
    };
}

#endif
