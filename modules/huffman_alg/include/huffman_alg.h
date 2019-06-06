// Copyright 2019 Trenina Elizaveta

#ifndef MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_
#define MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_

#include <map>
#include <queue>
#include <string>
#include <vector>

extern std::map<char, std::string >  table;  // table - codes
extern std::map<char, int> m;  // amount

class Node {
 private:
    std::string value, code;
    unsigned amount;
    Node * left;
    Node * right;

 public:
    explicit Node(const std::string& value = "", unsigned amount = 0,
        Node * left = nullptr, Node * right = nullptr);

    // compare
    bool operator() (const Node& x, const Node& y) const;

    // join tree
    Node * join(Node x);

    // generate code
    void traversal_code(std::string code);

    // build huffman tree
    static Node * builder(std::priority_queue<Node,
        std::vector<Node>, Node> graph);

    friend const bool is_eq_value(const Node &x, const Node &y);
    friend const bool is_eq_code(const Node &x, const Node &y);
    friend const bool is_eq_amount(const Node &x, const Node &y);
};

void encode(std::string s);

std::string decode(std::map<char, std::string > table, std::string str);

#endif  // MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_



