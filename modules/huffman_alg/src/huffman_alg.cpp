// Copyright 2019 Trenina Elizaveta

#include <map>
#include <queue>
#include <string>
#include <vector>

#include "include/huffman_alg.h"

std::map<char, std::string >  table;  // table - codes
std::map<char, int> m;  // amount

Node::Node(const std::string & value, unsigned amount, Node * left,
      Node * right) {
    this->value = value;
    this->code = "";
    this->amount = amount;
    this->left = left;
    this->right = right;
}

bool Node::operator()(const Node & x, const Node & y) const {
    return x.amount > y.amount;
}

const bool is_eq_value(const Node &x, const Node &y) {
    return x.value == y.value;
}

const bool is_eq_code(const Node &x, const Node &y) {
     return x.code == y.code;
}

const bool is_eq_amount(const Node &x, const Node &y) {
     return x.amount == y.amount;
}

Node * Node::join(Node x) {
    return new Node(x.value + value, x.amount + amount, new Node(x), this);
}

void Node::traversal_code(std::string code) {
    this->code = code;

    if (left != 0 || right != 0) {
        left->traversal_code(code + "1");
        right->traversal_code(code + "0");
    } else {
        table[value[0]] = code;
    }
}

Node * Node::builder(std::priority_queue<Node, std::vector<Node>, Node> graph) {
    while (graph.size() > 1) {
        Node *n = new Node(graph.top());
        graph.pop();
        graph.push(*n->join(*new Node(graph.top())));
        graph.pop();
    }
    return new Node(graph.top());
}

void encode(std::string s) {
    for (auto i : s) m[i]++;
    std::priority_queue<Node, std::vector<Node>, Node> graph;
    for (std::map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr) {
        graph.emplace(s = itr->first, itr->second);
    }
    Node *n = Node::builder(graph);
    n->traversal_code("");
}

std::string decode(std::map<char, std::string> table, std::string str) {
    std::string res = "";
    std::string tmp = "";
    for (unsigned int i = 0; i < str.length(); i++) {
        tmp += str[i];

        for (std::map<char, std::string>::iterator itr = table.begin();
            itr != table.end(); ++itr) {
            if (itr->second == tmp) {
                res += itr->first;
                tmp.clear();
                break;
            }
        }
    }
    return res;
}

