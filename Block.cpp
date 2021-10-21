#include <string>
#include <ctime>
#include <bitset>

#include "Hash.cpp"
#include "Block.hpp"
#include "TransactionData.hpp"

using namespace std;

Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

int Block::getIndex()
{
    return index;
}

size_t Block::generateHash()
{
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    bitset<256> a = 0; 
    string temp, ats;
    a = Hash(toHashS);
    temp = a.to_string();
    ats = ATS(temp);

    std::hash<std::string> tDataHash;
    std::hash<std::string> prevHash; 
    
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

