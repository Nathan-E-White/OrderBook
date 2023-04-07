#include <list>
#include <map>
#include "BinarySearchTree.tcc"
#include "ErrorCodes.h++"

std::map< std::string, std::string > m;

template < class Record >
ErrorCode
BinarySearchTree< Record >::build_tree (const std::list< Record > & records) {

    auto code  = ErrorCode::SUCCESS;
    auto count = 0;
    Record x, last_x;
    std::list <BinarySearchTreeNode> none;


}