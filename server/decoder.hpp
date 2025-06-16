#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Decoder
{
private:
    static Decoder* instance;
    Decoder();

public:
    static Decoder* getInstance();
    ~Decoder();
    std::string encrypt_message(std::string message);
    std::string from_hex(const std::string& hex_input);
};