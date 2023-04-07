//
// Created by Nathan White on 11/25/22.
//

#include <vector>
#include <map>
#include <string>
#include <variant>
#include <any>
#include <optional>
#include <list>
#include "ExpressionCodes.h++"
#include "ExpressionTokenType.h++"
#include "Expression.tcc"


struct TokenRecord {
    std::u32string m_name;
    std::any m_value;
    Expression::Types::ExpressionToken m_type;
    std::uint8_t m_priority;
};

struct Lexicon {

    /* Data */
    std::uint32_t m_count;
    std::map<std::size_t, TokenRecord> m_lexicon;
    // we want a index code array with length equal to the hash size
    std::vector<std::uint32_t> m_index;


    Lexicon() = default;
    Lexicon(Lexicon const &) = default;
    Lexicon(Lexicon &&) noexcept = default;
    virtual ~Lexicon() = default;
    Lexicon & operator = (Lexicon const &) = default;
    Lexicon & operator = (Lexicon &&) noexcept = default;

    [[nodiscard]] static constexpr auto hash(std::u32string const & str) -> std::size_t {
        return std::hash<std::u32string>{}(str);
    }

    [[nodiscard]] static constexpr auto hash(std::u32string && str) -> std::size_t {
        return std::hash<std::u32string>{}(str);
    }

    [[nodiscard]] static constexpr auto hash(std::u32string_view const & str) -> std::size_t {
        return std::hash<std::u32string_view>{}(str);
    }

    [[nodiscard]] static constexpr auto hash(std::u32string_view && str) -> std::size_t {
        return std::hash<std::u32string_view>{}(str);
    }

};

class Token {
public:

    /* Add shit here */
private:
    std::uint32_t code;
    static Lexicon sym_tab;
    static std::list<uint32_t> par_tab;

};


namespace Expression::Class {

    enum class ValueMapPosition {
        Px0000                                                                                 = 0x0000, Px0001, Px0002,
        Px0003, Px0004, Px0005, Px0006, Px0007, Px0008, Px0009, Px000A, Px000B, Px000C, Px000D, Px000E, Px000F, Px0010,
        Px0011, Px0012, Px0013, Px0014, Px0015, Px0016, Px0017, Px0018, Px0019, Px001A, Px001B, Px001C, Px001D, Px001E,
        Px001F, Px0020, Px0021, Px0022, Px0023, Px0024, Px0025, Px0026, Px0027, Px0028, Px0029, Px002A, Px002B, Px002C,
        Px002D, Px002E, Px002F, Px0030, Px0031, Px0032, Px0033, Px0034, Px0035, Px0036, Px0037, Px0038, Px0039, Px003A,
        Px003B, Px003C, Px003D, Px003E, Px003F, Px0040, Px0041, Px0042, Px0043, Px0044, Px0045, Px0046, Px0047, Px0048,
        Px0049, Px004A, Px004B, Px004C, Px004D, Px004E, Px004F, Px0050, Px0051, Px0052, Px0053, Px0054, Px0055, Px0056,
        Px0057, Px0058, Px0059, Px005A, Px005B, Px005C, Px005D, Px005E, Px005F, Px0060, Px0061, Px0062, Px0063, Px0064,
        Px0065, Px0066, Px0067, Px0068, Px0069, Px006A, Px006B, Px006C, Px006D, Px006E, Px006F, Px0070, Px0071, Px0072,
        Px0073, Px0074, Px0075, Px0076, Px0077, Px0078, Px0079, Px007A, Px007B, Px007C, Px007D, Px007E, Px007F, Px0080,
        Px0081, Px0082, Px0083, Px0084, Px0085, Px0086, Px0087, Px0088, Px0089, Px008A, Px008B, Px008C, Px008D, Px008E,
        Px008F, Px0090, Px0091, Px0092, Px0093, Px0094, Px0095, Px0096, Px0097, Px0098, Px0099, Px009A, Px009B, Px009C,
        Px009D, Px009E, Px009F, Px00A0, Px00A1, Px00A2, Px00A3, Px00A4, Px00A5, Px00A6, Px00A7, Px00A8, Px00A9, Px00AA,
        Px00AB, Px00AC, Px00AD, Px00AE, Px00AF, Px00B0, Px00B1, Px00B2, Px00B3, Px00B4, Px00B5, Px00B6, Px00B7, Px00B8,
        Px00B9, Px00BA, Px00BB, Px00BC, Px00BD, Px00BE, Px00BF, Px00C0, Px00C1, Px00C2, Px00C3, Px00C4, Px00C5, Px00C6,
        Px00C7, Px00C8, Px00C9, Px00CA, Px00CB, Px00CC, Px00CD, Px00CE, Px00CF, Px00D0, Px00D1, Px00D2, Px00D3, Px00D4,
        Px00D5, Px00D6, Px00D7, Px00D8, Px00D9, Px00DA, Px00DB, Px00DC, Px00DD, Px00DE, Px00DF, Px00E0, Px00E1, Px00E2,
        Px00E3, Px00E4, Px00E5, Px00E6, Px00E7, Px00E8, Px00E9, Px00EA, Px00EB, Px00EC, Px00ED, Px00EE, Px00EF, Px00F0,
        Px00F1, Px00F2, Px00F3, Px00F4, Px00F5, Px00F6, Px00F7, Px00F8, Px00F9, Px00FA, Px00FB, Px00FC, Px00FD, Px00FE,
        Px00FF, Px0100, Px0101, Px0102, Px0103, Px0104, Px0105, Px0106, Px0107, Px0108, Px0109, Px010A, Px010B, Px010C,
        Px010D, Px010E, Px010F, Px0110, Px0111, Px0112, Px0113, Px0114, Px0115, Px0116, Px0117, Px0118, Px0119, Px011A,
        Px011B, Px011C, Px011D, Px011E, Px011F, Px0120, Px0121, Px0122, Px0123, Px0124, Px0125, Px0126, Px0127, Px0128,
        Px0129, Px012A, Px012B, Px012C, Px012D, Px012E, Px012F, Px0130, Px0131, Px0132, Px0133, Px0134, Px0135, Px0136,
        Px0137, Px0138, Px0139, Px013A, Px013B, Px013C, Px013D, Px013E, Px013F, Px0140, Px0141, Px0142, Px0143, Px0144,
        Px0145, Px0146, Px0147, Px0148, Px0149, Px014A, Px014B, Px014C, Px014D, Px014E, Px014F, Px0150, Px0151, Px0152,
        Px0153, Px0154, Px0155, Px0156, Px0157, Px0158, Px0159, Px015A, Px015B, Px015C, Px015D, Px015E, Px015F, Px0160,
        Px0161, Px0162, Px0163, Px0164, Px0165, Px0166, Px0167, Px0168, Px0169, Px016A, Px016B, Px016C, Px016D, Px016E,
        Px016F, Px0170, Px0171, Px0172, Px0173, Px0174, Px0175, Px0176, Px0177, Px0178, Px0179, Px017A, Px017B, Px017C,
        Px017D, Px017E, Px017F, Px0180, Px0181, Px0182, Px0183, Px0184, Px0185, Px0186, Px0187, Px0188, Px0189, Px018A,
        Px018B, Px018C, Px018D, Px018E, Px018F, Px0190, Px0191, Px0192, Px0193, Px0194, Px0195, Px0196, Px0197, Px0198,
        Px0199, Px019A, Px019B, Px019C, Px019D, Px019E, Px019F, Px01A0, Px01A1, Px01A2, Px01A3, Px01A4, Px01A5, Px01A6,
        Px01A7, Px01A8, Px01A9, Px01AA, Px01AB, Px01AC, Px01AD, Px01AE, Px01AF, Px01B0, Px01B1, Px01B2, Px01B3, Px01B4,
        Px01B5, Px01B6, Px01B7, Px01B8, Px01B9, Px01BA, Px01BB, Px01BC, Px01BD, Px01BE, Px01BF, Px01C0, Px01C1, Px01C2,
        Px01C3, Px01C4, Px01C5, Px01C6, Px01C7, Px01C8, Px01C9, Px01CA, Px01CB, Px01CC, Px01CD, Px01CE, Px01CF, Px01D0,
        Px01D1, Px01D2, Px01D3, Px01D4, Px01D5, Px01D6, Px01D7, Px01D8, Px01D9, Px01DA, Px01DB, Px01DC, Px01DD, Px01DE,
        Px01DF, Px01E0, Px01E1, Px01E2, Px01E3, Px01E4, Px01E5, Px01E6, Px01E7, Px01E8, Px01E9, Px01EA, Px01EB, Px01EC,
        Px01ED, Px01EE, Px01EF, Px01F0, Px01F1, Px01F2, Px01F3, Px01F4, Px01F5, Px01F6, Px01F7, Px01F8, Px01F9, Px01FA,
        Px01FB, Px01FC, Px01FD, Px01FE, Px01FF, Px0200, Px0201, Px0202, Px0203, Px0204, Px0205, Px0206, Px0207, Px0208,
        Px0209, Px020A, Px020B, Px020C, Px020D, Px020E, Px020F, Px0210, Px0211, Px0212, Px0213, Px0214, Px0215, Px0216,
        Px0217, Px0218, Px0219, Px021A, Px021B, Px021C, Px021D, Px021E, Px021F, Px0220, Px0221, Px0222, Px0223, Px0224,
        Px0225, Px0226, Px0227, Px0228, Px0229, Px022A, Px022B, Px022C, Px022D, Px022E, Px022F, Px0230, Px0231, Px0232,
        Px0233, Px0234, Px0235, Px0236, Px0237, Px0238, Px0239, Px023A, Px023B, Px023C, Px023D, Px023E, Px023F, Px0240,
        Px0241, Px0242, Px0243, Px0244, Px0245, Px0246, Px0247, Px0248, Px0249, Px024A, Px024B, Px024C, Px024D, Px024E,
        Px024F, Px0250, Px0251, Px0252, Px0253, Px0254, Px0255, Px0256, Px0257, Px0258, Px0259, Px025A, Px025B, Px025C,
        Px025D, Px025E, Px025F, Px0260, Px0261, Px0262, Px0263, Px0264, Px0265, Px0266, Px0267, Px0268, Px0269, Px026A,
        Px026B, Px026C, Px026D, Px026E, Px026F, Px0270, Px0271, Px0272, Px0273, Px0274, Px0275, Px0276, Px0277, Px0278,
        Px0279, Px027A, Px027B, Px027C, Px027D, Px027E, Px027F, Px0280, Px0281, Px0282, Px0283, Px0284, Px0285, Px0286,
        Px0287, Px0288, Px0289, Px028A, Px028B, Px028C, Px028D, Px028E, Px028F, Px0290, Px0291, Px0292, Px0293, Px0294,
        Px0295, Px0296, Px0297, Px0298, Px0299, Px029A, Px029B, Px029C, Px029D, Px029E, Px029F, Px02A0, Px02A1, Px02A2,
        Px02A3, Px02A4, Px02A5, Px02A6, Px02A7, Px02A8, Px02A9, Px02AA, Px02AB, Px02AC, Px02AD, Px02AE, Px02AF, Px02B0,
        Px02B1, Px02B2, Px02B3, Px02B4, Px02B5, Px02B6, Px02B7, Px02B8, Px02B9, Px02BA, Px02BB, Px02BC, Px02BD, Px02BE,
        Px02BF, Px02C0, Px02C1, Px02C2, Px02C3, Px02C4, Px02C5, Px02C6, Px02C7, Px02C8, Px02C9, Px02CA, Px02CB, Px02CC,
        Px02CD, Px02CE, Px02CF, Px02D0, Px02D1, Px02D2, Px02D3, Px02D4, Px02D5, Px02D6, Px02D7, Px02D8, Px02D9, Px02DA,
        Px02DB, Px02DC, Px02DD, Px02DE, Px02DF, MAX_PARSE_SIZE                                 = 0xFFFF, };

    Codes::ExpressionCode Expression::evaluate_prefix (Expression::Value & result) {
        Types::ExpressionToken              token;
        std::map< ValueMapPosition, Value > value_map;
        auto                                loop_idx = 0;


        while (true) {

            /* Get the next few position tokens. */
            auto           ptk = ( ValueMapPosition ) (loop_idx + 0);
            decltype (ptk) ptk_p1, ptk_p2, ptk_p3;

            if (loop_idx < ( decltype (loop_idx)) ValueMapPosition::MAX_PARSE_SIZE) {
                ptk_p1 = ( ValueMapPosition ) (loop_idx + 1);
                if (loop_idx < ( decltype (loop_idx)) ValueMapPosition::MAX_PARSE_SIZE - 1) {
                    ptk_p2 = ( ValueMapPosition ) (loop_idx + 2);
                    if (loop_idx < ( decltype (loop_idx)) ValueMapPosition::MAX_PARSE_SIZE - 2) {
                        ptk_p3 = ( ValueMapPosition ) (loop_idx + 3);
                    }
                }
            } else {
                ptk_p1 = ptk_p2 = ptk_p3 = MAX_PARSE_SIZE;
            }

            if (loop_idx++ > ( decltype (loop_idx)) ValueMapPosition::MAX_PARSE_SIZE) {
                return Codes::ExpressionCode::PARSE_ERROR;
            }


            // Get the first token
            Codes::ExpressionCode code = get_token (reinterpret_cast<Class::Expression::Value &>(token));
            switch (token) {

                case Types::ExpressionToken::NUMBER:
                    if (evaluate_prefix (arg) != Codes::ExpressionCode::SUCCESS) {
                        return Codes::ExpressionCode::INVALID_EXPRESSION;
                    }

                case Types::ExpressionToken::PLUS:
                case Types::ExpressionToken::MINUS:
                case Types::ExpressionToken::MULTIPLY:
                case Types::ExpressionToken::DIVIDE:
                case Types::ExpressionToken::OPERAND:
                case Types::ExpressionToken::UNARY_OPERATOR:
                case Types::ExpressionToken::BINARY_OPERATOR:
                case Types::ExpressionToken::OPEN_PARENTHESIS:
                case Types::ExpressionToken::CLOSE_PARENTHESIS:
                case Types::ExpressionToken::COMMA:
                case Types::ExpressionToken::UNKNOWN:

                case Types::ExpressionToken::END:
                    return Codes::ExpressionCode::UNEXPECTED_END;

                case Types::ExpressionToken::ERROR:
                    return Codes::ExpressionCode::INVALID_TOKEN;

                case Types::ExpressionToken::NONE:
                    return Codes::ExpressionCode::UNKNOWN;

                case Types::ExpressionToken::NULL_TYPE:
                    return Codes::ExpressionCode::NULL_CODE;

                case Types::ExpressionToken::UNEXPECTED_TOKEN;

                default:
                    return Codes::ExpressionCode::UNKNOWN;
            }

            return Codes::ExpressionCode::FAILURE;
        }
    }
