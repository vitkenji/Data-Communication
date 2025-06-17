#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <unordered_map>

class Coder
{
private:
    static Coder* instance;
    Coder();
    
public:
    ~Coder();
    static Coder* getInstance();
    std::string encrypt_message(std::string message);
    std::string to_hex(const std::string& input);
    std::string encrypted_to_binary(std::string encrypted);
    std::string b8zs(std::string binary);

};