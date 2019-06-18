// Copyright 2019 Trenina Elizaveta

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include"include/huffman_alg_app.h"

//using ::testing::internal::RE;
//using std::vector;
//using std::string;

class HuffmanAlgApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("HuffmanAlgApplication");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_EQ(expected, output_);
    }

 private:
    HuffmanAlgApplication app_;
    std::string output_;
};


TEST_F(HuffmanAlgApplicationTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert(
        "\nThis application encrypts/decrypts the contents of the file.\n"
        "Please provide arguments in the following format:\n"
        "1: File name(string) for operation;\n"
        "2: File name(string) to save the result;\n"
        "3: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}

//TEST_F(HuffmanAlgApplicationTest, Can_Put) {
//	vector<string> args = { "put", "6243" };
//
//	Act(args);
//
//	Assert("");
//}
TEST_F(HuffmanAlgApplicationTest, Throws_On_Invalid_FileName) {
	// Arrange
	std::vector<std::string> args = { "InvalidName", "SaveFile", "EN" };

	Act(args);

	Assert(
		"\nThis application encrypts/decrypts the contents of the file.\n"
		"Please provide arguments in the following format:\n"
		"1: File name(string) for operation;\n"
		"2: File name(string) to save the result;\n"
		"3: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}

TEST_F(HuffmanAlgApplicationTest, Throws_On_Invalid_Operation) {
	// Arrange
	std::vector<std::string> args = { "Encrypt.txt", "Decrypt.txt",
	 "InvalidOperation" };

	Act(args);

	Assert(
		"\nThis application encrypts/decrypts the contents of the file.\n"
		"Please provide arguments in the following format:\n"
		"1: File name(string) for operation;\n"
		"2: File name(string) to save the result;\n"
		"3: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}
//TEST_F(QueueApplicationTest, Can_Put_Several_Times) {
//	vector<string> args = { "put", "33", "put", "44", "put", "-1" };
//
//	Act(args);
//
//	Assert("");
//}
//
//TEST_F(QueueApplicationTest, Can_Get) {
//	vector<string> args = { "put", "201", "get" };
//
//	Act(args);
//
//	Assert("Gotten element = 201");
//}
//
//TEST_F(QueueApplicationTest, Can_Top) {
//	vector<string> args = { "put", "-23445", "top" };
//
//	Act(args);
//
//	Assert("The top element = -23445");
//}
//
//TEST_F(QueueApplicationTest, Can_Get_Several_Times) {
//	vector<string> args = { "put", "1", "put", "-2", "get", "get" };
//
//	Act(args);
//
//	Assert("Gotten element = -2");
//}
//
//TEST_F(QueueApplicationTest, Can_Top_Several_Times) {
//	vector<string> args = { "put", "-1", "put", "2", "top", "top" };
//
//	Act(args);
//
//	Assert("The top element = -1");
//}
//
//TEST_F(QueueApplicationTest, Can_Detect_Wrong_Format_Of_Operations) {
//	vector<string> args = { "put", "100", "Push", "2", "top" };
//
//	Act(args);
//
//	Assert("Argument error");
//}

