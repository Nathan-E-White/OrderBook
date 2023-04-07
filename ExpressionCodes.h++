#ifndef ORDERBOOK_EXPRESSION_CODES_H
#define ORDERBOOK_EXPRESSION_CODES_H

namespace Expression::Codes {

    enum class ExpressionCode {
          SUCCESS,
          FAILURE,
          UNKNOWN,
          UNEXPECTED_TOKEN,
          NULL_CODE
        , INVALID_TOKEN
        , UNEXPECTED_END
        , INVALID_EXPRESSION
        , PARSE_ERROR
    };
}



#endif
