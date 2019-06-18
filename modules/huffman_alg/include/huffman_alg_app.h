// Copyright 2019 Trenina Elizaveta

#ifndef MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_APP_H_
#define MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_APP_H_

#include <iostream>
#include <fstream>
#include <string>
#include "include/huffman_alg.h"

  //std::map<char, std::string >  table;  // table - codes
  //std::map<char, int> m;  // amount

class HuffmanAlgApplication {
private:
	bool ReadFile(std::string in_filename);
	void WriteFile(std::string out_filename);
	std::string filetext_;
	Node HuffmnAlg;

public:
	std::string operator()(int argc, const char** argv);
	std::string GetHelpMessage();
	std::string DecodeFile(std::string in_filename, std::string out_filename);
		//std::map<char, std::string> table);
	std::string EncodeFile(std::string in_filename, std::string out_filename);
		//int key);
};
#endif  // MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_APP_H_
