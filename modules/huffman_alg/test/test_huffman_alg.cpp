// Copyright 2019 Trenina Elizaveta

#include <iostream>

#include <map>
#include <queue>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "include/huffman_alg.h"

TEST(node, can_create_node_without_parametrs) {
    // Act & Assert
    ASSERT_NO_THROW(Node n);
}

TEST(node, can_create_node_with_parametrs) {
    // Act & Assert
    ASSERT_NO_THROW(Node n("abc", 3, 0, 0));
}

TEST(node, can_create_node ) {
    // Arrange
    Node x("abc", 3, 0, 0);

    // Act & Assert
    ASSERT_NO_THROW(Node(x));
}

TEST(node, can_compare) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("");

    // Act & Assert
    ASSERT_NO_THROW(x(x, y));
}

TEST(node, can_compare_right) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("d", 1, 0, 0);

    // Act
    bool res = x(x, y);

    // Assert
    ASSERT_EQ(res, true);
}

TEST(node, can_join_node) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("d", 1, 0, 0);

    // Act & Assert
    ASSERT_NO_THROW(x.join(y));
}

TEST(node, is_eq_value_works_right) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("abc", 1, 0, 0);

    // Act & Assert
    ASSERT_EQ(is_eq_value(x, y), true);
}

TEST(node, is_eq_code_works_right) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("d", 1, 0, 0);

    // Act & Assert
    ASSERT_EQ(is_eq_code(x, y), true);
}

TEST(node, is_eq_amount_works_right) {
    // Arrange
    Node x("abc", 3, 0, 0);
    Node y("d", 3, 0, 0);

    // Act & Assert
    ASSERT_EQ(is_eq_amount(x, y), true);
}


TEST(node, can_join_node_right) {
    // Arrange
    Node *n1 = new Node("abc", 3, 0, 0);
    Node *n2 = new Node ("d", 1, 0, 0);
    Node res("dabc", 4, 0, 0);

    // Act
    Node n = *n1->join(*n2);
    delete n1;
    delete n2;
    // Assert
    ASSERT_EQ(is_eq_code(res, n), true);
    ASSERT_EQ(is_eq_value(res, n), true);
    ASSERT_EQ(is_eq_amount(res, n), true);
}

TEST(node, can_builder) {
    // Arrange
    std::priority_queue<Node, std::vector<Node>, Node> graph;
    Node x1("a", 1, 0, 0);
    Node x2("b", 1, 0, 0);
    Node res("ba", 2, 0, 0);

    // Act
    graph.emplace(x1);
    graph.emplace(x2);
    Node act = *x2.builder(graph);

    // Assert
    ASSERT_EQ(is_eq_value(res, act), true);
    ASSERT_EQ(is_eq_amount(res, act), true);
}

TEST(node, can_traversal_code) {
    // Arrange
    std::priority_queue<Node, std::vector<Node>, Node> graph;
    std::string s1 = "a", s2 = "b";
    Node x(s1, 2, 0, 0);
    Node y(s2, 3, 0, 0);

    // Act
    graph.emplace(x);
    graph.emplace(y);
    Node* res = Node::builder(graph);

    res->traversal_code("");

    // Assert
    ASSERT_EQ(table[s1[0]], "0");
    ASSERT_EQ(table[s2[0]], "1");
}

TEST(node, can_encode) {
    // Arrange
    std::priority_queue<Node, std::vector<Node>, Node> graph;
    std::string s = "somanymensomanyminds";

    // Act
    table.clear();
    m.clear();

    // Assert
    ASSERT_NO_THROW(encode(s));
}


TEST(node, can_decode) {
    // Arrange
    std::string in = "beep boop beer!";
    std::string s = "00111110111010";
    std::string c = "beer!";

    // Act
    table.clear();
    m.clear();

    encode(in);

    // Assert
    ASSERT_NO_THROW(decode(table, s));
}

TEST(node, can_decode_right) {
    // Arrange
    std::string in = "beep boop beer!";
    std::string c = "beer";
    std::string s = table['b'] + table['e'] + table['e'] + table['r'];

    // Act
    table.clear();
    m.clear();

    encode(in);
    std::string res = decode(table, s);

    // Assert
    ASSERT_EQ(res, c);
}
