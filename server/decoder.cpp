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
    return "";
}

std::string Decoder::b8zs_decoder(std::string data)
{
    return "";
}
