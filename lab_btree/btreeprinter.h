// #include <string>
// #include <vector>
// #include "btree.h"
//
// template <class A, class B>
// class BTreePrinter
// {
//    struct NodeInfo
//    {
//       std::string text;
//       unsigned text_pos, text_end;  // half-open range
//    };
//
//    typedef std::vector<NodeInfo> LevelInfo;
//
//    std::vector<LevelInfo> levels;
//
//    std::string node_text (std::vector<int> const keys, unsigned key_count);
//
//    void before_traversal ()
//    {
//       levels.resize(0);
//       levels.reserve(10);   // far beyond anything that could usefully be printed
//    }
//
//    void visit (typename BTree<A,B>::BTreeNode const *node, unsigned level = 0, unsigned child_index = 0);
//
//    void after_traversal ();
//
// public:
//    void print (BTree<A,B> const &tree)
//    {
//       before_traversal();
//       visit(tree.root);
//       after_traversal();
//    }
// };
