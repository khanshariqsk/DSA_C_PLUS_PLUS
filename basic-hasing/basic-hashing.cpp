#include <bits/stdc++.h>
using namespace std;

// For only a-z small character
void small_character_hashing()
{
    string str = "abcbbcdvgbahjcvgbhskhd";
    int charac_hash[26] = {0};

    auto get_hashed_index = [](char ch)
    {
        return ch - 'a';
    };

    for (int i = 0; i < str.size(); i++)
    {
        charac_hash[get_hashed_index(str[i])]++;
    }

    char query_char = 'b';
    cout << charac_hash[get_hashed_index(query_char)];
}

// For all character ascii value to 255
void all_character_hashing()
{
    string str = "abcbbcdvgbahjcvgbhskhd16777876567778987777%%%%%$$$$#@@@";
    int charac_hash[256] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        charac_hash[str[i]]++;
    }

    char query_char = '@';
    cout << charac_hash[query_char];
}

void integer_hashing_using_map()
{
    int arr_size = 10;
    int arr[arr_size] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3};
    unordered_map<int, int> mpp; // always use unordered_map if its excceeds time limit then use map

    for (int i = 0; i < arr_size; i++)
    {
        mpp[arr[i]]++;
    }

    int search_num = 5;
    cout << mpp[search_num];
}

void all_characters_hashing_using_map()
{
    string str = "sbcjbsjbkbcksbdckdsk468r8r878r767%&%&^%^*&^*&^kkskjbkdjsbcksdbckdbck";

    unordered_map<int, int> mpp; // always use unordered_map if its excceeds time limit then use map

    for (int i = 0; i < str.size(); i++)
    {
        mpp[str[i]]++;
    }

    char search_char = 'b';
    cout << mpp[search_char];
}

int main()
{
    // small_character_hashing()
    // all_character_hashing()
    // integer_hashing_using_map();
    all_characters_hashing_using_map();
    return 0;
}