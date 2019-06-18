// Copyright 2019 Trenina Elizaveta

#include "include/huffman_alg_app.h"
#include <string>

std::string HuffmanAlgApplication::operator()(int argc, const char** argv) {
    std::string result = "";
    std::string in_filename = "";
    std::string out_filename = "";
    std::string operation = "";

    if (argc > 3) {
        in_filename = argv[1];
        out_filename = argv[2];
        operation = argv[3];

        if (operation == "EN") {
            result = EncodeFile(in_filename, out_filename);
        }

        if (operation == "DE") {
            result = DecodeFile(in_filename, out_filename);
        }

        if (operation != "DE" && operation != "EN") {
            result = GetHelpMessage();
        }

    }
    else {
        result = GetHelpMessage();
    }

    if (result == "") {
        result = GetHelpMessage();
    }

    return result;
}

std::string HuffmanAlgApplication::GetHelpMessage() {
    std::string help_message;
    help_message =
        "\nThis application encrypts/decrypts the contents of the file.\n";
    help_message += "Please provide arguments in the following format:\n";
    help_message += "1: File name(string) for operation;\n";
    help_message += "2: File name(string) to save the result;\n";
    help_message += "3: The operation(string): EN to Encrypt or DE to Decrypt;\n";
    return help_message;
}

std::string HuffmanAlgApplication::DecodeFile(std::string in_filename,
    std::string out_filename) {
    filetext_ = "";

    if (table.empty()) filetext_ = "\ntable is empty\nplease encode first";
    else if (ReadFile(in_filename)) {
        filetext_ = decode(table, filetext_);
        WriteFile(out_filename);
    }
    return filetext_;
}

std::string HuffmanAlgApplication::EncodeFile(std::string in_filename,
    std::string out_filename) {
    filetext_ = "";
    if (ReadFile(in_filename)) {
        encode(filetext_);
        for (unsigned int i = 0; i < filetext_.size(); i++) {
            filetext_ += table[filetext_[i]];
        }
        WriteFile(out_filename);
    }
    return filetext_;
}

bool HuffmanAlgApplication::ReadFile(std::string in_filename) {
    std::ifstream in_file(in_filename);
    if (!in_file.is_open()) {
        return false;
    }
    else {
        filetext_.assign((std::istreambuf_iterator<char>(in_file.rdbuf())),
            std::istreambuf_iterator<char>());
        in_file.close();
    }
    return true;
}

void HuffmanAlgApplication::WriteFile(std::string out_filename) {
    std::ofstream out_file(out_filename);
    out_file << filetext_;
    out_file.close();
}

