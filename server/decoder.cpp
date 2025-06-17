#include "decoder.hpp"

Decoder* Decoder::instance = nullptr;

Decoder* Decoder::getInstance()
{
    if (instance == nullptr){instance = new Decoder();}
    return instance;
}

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

std::string Decoder::encrypt_message(std::string message)
{
    message = from_hex(message);
    std::string encrypted;
    encrypted.reserve(message.size());
    std::string key = "key";
    for (size_t i = 0; i < message.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(message[i]);
        unsigned char k = static_cast<unsigned char>(key[i % key.size()]);
        unsigned char e = c ^ k;
        encrypted.push_back(static_cast<char>(e));
    }

    return encrypted;
}

std::string Decoder::from_hex(const std::string& hex_input)
{
    std::string output;
    if (hex_input.length() % 2 != 0) {
        throw std::invalid_argument("hex string has invalid length");
    }

    for (size_t i = 0; i < hex_input.length(); i += 2) {
        std::string byte_string = hex_input.substr(i, 2);
        char byte = static_cast<char>(std::stoi(byte_string, nullptr, 16));
        output.push_back(byte);
    }

    return output;

}

std::string Decoder::binary_to_encrypted(std::string binary)
{
    std::unordered_map<std::string, char> binary_to_hex = {
        {"0000", '0'}, {"0001", '1'},{"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'},{"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'},{"1010", 'a'}, {"1011", 'b'},
        {"1100", 'c'}, {"1101", 'd'},{"1110", 'e'}, {"1111", 'f'}
    };

    std::string hex_string;

    for(int i = 0; i < binary.length(); i += 4)
    {
        std::string group_4bits = binary.substr(i, 4);
        while(group_4bits.length() < 4)
        {
            group_4bits = "0" + group_4bits;
        }

        if(binary_to_hex.find(group_4bits) != binary_to_hex.end())
        {
            hex_string += binary_to_hex[group_4bits];
        }
    }

    return hex_string;
}

std::string Decoder::b8zs_decoder(std::string data)
{
    std::string result = "";
        int current_polarity = 1;

        for (int i = 0; i < data.length(); ++i)
        {
            if (i + 8 <= data.length() && data.substr(i, 8) == "000-+0+-")
            {
                result += "00000000";
                i += 7;
                current_polarity *= -1;
            }
            else if (i + 8 <= data.length() && data.substr(i, 8) == "000+-0-+")
            {
                result += "00000000";
                i += 7;
                current_polarity *= -1;
            }
            else if (data[i] == '0')
            {
                result += "0";
            }
            else if (data[i] == '+' || data[i] == '-')
            {
                result += "1";
                current_polarity *= -1;
            }
            else
            {
                std::cerr << "error" << data[i] << std::endl;
            }
        }
        return result;
}
