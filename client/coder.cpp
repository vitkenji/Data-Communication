#include "coder.hpp"

Coder* Coder::instance = nullptr;

Coder* Coder::getInstance()
{
    if(instance == nullptr) {instance = new Coder();}
    return instance;
}

Coder::Coder()
{

}

Coder::~Coder()
{

}

std::string Coder::encrypt_message(std::string message)
{
    std::string encrypted;
    encrypted.reserve(message.size());
    std::string key = "key";
    for (size_t i = 0; i < message.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(message[i]);
        unsigned char k = static_cast<unsigned char>(key[i % key.size()]);
        unsigned char e = c ^ k;
        encrypted.push_back(static_cast<char>(e));
    }

    return to_hex(encrypted);
}

std::string Coder::to_hex(const std::string& input) {
    std::ostringstream oss;
    for (unsigned char c : input) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return oss.str();
}

std::string Coder::encrypted_to_binary(std::string encrypted)
{
    std::unordered_map<char, std::string> hex_to_binary = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
        {'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}
    };

    std::string binary;

    for(char c : encrypted)
    {
        if (hex_to_binary.find(c) != hex_to_binary.end())
        {
            binary += hex_to_binary[c];
        }
    }

    return binary;
}

std::string Coder::b8zs(std::string binary)
{
    int polarity = 1;
    std::string result;

    for(int i = 0; i < binary.length(); i++)
    {
        if(i + 8 <= binary.length() && binary.substr(i, 8) == "00000000")
        {
            polarity == 1 ? result += "000-+0+-" : result += "000+-0-+";
            polarity *= -1;
            i += 7;
        }
        else
        {
            if(binary[i] == '0')
            {
                    result += "0";
            }
            else
            {
                polarity == 1 ? result += "+" : result += "-";
                polarity *= -1;
            }
        }
    }
    
    return result;

}

