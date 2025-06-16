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
