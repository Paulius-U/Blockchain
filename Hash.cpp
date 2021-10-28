#include "Hash.h"
#include <bitset>
#include <string>

int rand1[] = {129, 163, 44, 158, 178, 8, 161, 140, 59, 184, 240, 124, 245, 231, 167, 57, 115, 40, 222, 243, 209, 182, 128, 175, 82, 219, 215, 3, 206, 207, 230, 172, 114, 220, 185, 145, 22, 200, 227, 95, 1, 39, 188, 62, 56, 192, 6, 119, 69, 68, 236, 100, 205, 18, 5, 121, 116, 170, 41, 27, 241, 187, 67, 190, 255, 229, 99, 94, 148, 130, 111, 28, 251, 98, 147, 120, 55, 210, 127, 152, 226, 193, 165, 156, 43, 72, 80, 89, 83, 244, 4, 71, 7, 81, 169, 186, 141, 223, 97, 2, 201, 24, 155, 21, 191, 138, 248, 162, 131, 225, 45, 77, 204, 104, 19, 86, 224, 93, 211, 253, 61, 29, 10, 137, 91, 160, 70, 144, 37, 176, 103, 50, 157, 75, 213, 63, 16, 221, 208, 181, 32, 183, 149, 9, 112, 198, 23, 146, 134, 159, 249, 189, 42, 202, 135, 150, 96, 14, 105, 247, 139, 31, 212, 53, 132, 54, 154, 199, 17, 232, 0, 33, 109, 214, 133, 237, 25, 84, 88, 177, 79, 254, 125, 102, 92, 51, 64, 151, 49, 252, 228, 47, 15, 87, 174, 110, 76, 233, 13, 113, 216, 217, 46, 143, 122, 196, 108, 218, 101, 203, 194, 30, 126, 73, 11, 195, 52, 48, 90, 142, 171, 166, 180, 234, 60, 118, 12, 168, 74, 65, 66, 246, 20, 153, 38, 26, 136, 164, 85, 242, 173, 238, 197, 106, 35, 117, 250, 239, 107, 58, 78, 36, 179, 123, 34, 235};
int rand2[] = {184, 182, 100, 43, 212, 118, 84, 106, 107, 137, 130, 143, 144, 13, 181, 82, 113, 194, 198, 165, 28, 48, 91, 159, 67, 101, 63, 94, 190, 81, 231, 52, 10, 120, 131, 89, 221, 15, 253, 112, 121, 168, 85, 134, 98, 12, 228, 254, 241, 105, 5, 136, 108, 148, 183, 40, 191, 217, 246, 42, 201, 163, 76, 70, 92, 34, 64, 176, 60, 255, 111, 49, 116, 55, 50, 180, 205, 72, 233, 39, 122, 216, 31, 151, 45, 149, 22, 172, 135, 234, 117, 95, 152, 197, 59, 24, 86, 33, 248, 247, 235, 177, 96, 185, 87, 192, 0, 20, 30, 175, 103, 110, 97, 37, 179, 164, 204, 157, 2, 140, 133, 174, 51, 99, 200, 218, 109, 211, 243, 150, 88, 26, 14, 77, 220, 240, 7, 9, 169, 142, 162, 245, 223, 66, 167, 202, 32, 19, 236, 35, 102, 155, 154, 251, 222, 78, 83, 69, 58, 170, 123, 171, 114, 147, 250, 47, 53, 219, 16, 73, 242, 44, 161, 229, 11, 237, 17, 153, 252, 158, 187, 146, 8, 79, 56, 27, 90, 38, 129, 119, 249, 224, 1, 214, 124, 215, 3, 68, 239, 196, 213, 126, 145, 41, 125, 138, 80, 209, 62, 128, 61, 29, 238, 46, 36, 104, 203, 71, 230, 210, 195, 65, 6, 115, 57, 74, 54, 173, 178, 225, 226, 156, 23, 132, 232, 127, 21, 188, 227, 25, 189, 193, 160, 206, 186, 139, 4, 93, 207, 199, 208, 75, 18, 141, 244, 166};

std::bitset<256> Hash(std::string inp)
{
    if (inp == "")inp = "absdthu45th389wi";
    std::bitset<256> hash;
    for (int a = 0; a < inp.length(); a++)
    {
        for (int i = 0; i < 32; i++)
        {
            std::bitset<256> temp;
            int randomiser = rand1[(((int)inp[a] * 5 + i + a) % 256)] % 30;
            if(randomiser <= 7)
            {
                temp = inp[a];
                temp <<= randomiser;
                temp <<= (i * 8);
                hash ^= temp;
            }
            else if(randomiser <= 14)
            {
                temp = ~inp[a];
                temp <<= (randomiser - 8);
                temp <<= (i * 8);          
                hash ^= temp;
            }
            else{
                temp = rand2[(((int)inp[a] * 17 + i + a) % 256)];
                temp <<=(i * 8);
                hash ^= temp;
                temp = rand1[(((int)inp[a] * 3 + i + a) % 256)] % 30;
                hash ^= temp;
            }
        }
    }
    return hash;
}

std::string ATS(std::string temp)
{
    std::string a = "";
    for(int i = 0; i < 64; i++)
    {
        std::bitset <4> bss1( temp.substr (i * 4, (i + 1) * 4) );
        std::string out = "";
        if(bss1.to_ulong() <= 9)
        {
            out += bss1.to_ulong() + '0';
        }
        else
        {
            out += bss1.to_ulong() + 'a' - 10;
        }
        a += out;
    }
    return a;
}