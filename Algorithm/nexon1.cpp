#include <bits/stdc++.h>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


/*
 * Complete the 'finalState' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts 2D_INTEGER_ARRAY operations as parameter.
 */

struct Data
{
    unordered_set<bool> hash(false);
};

vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays)
{

    vector<int> out(bitArrays.size());
    vector<Data> maxHeaps(bitArrays.size());

    for (int i = 0; i < bitArrays.size(); ++i)
    {
        maxHeaps[i].Idx = i;
        for (int j = 0; j < bitArrays[i].size(); ++j)
        {
            maxHeaps[i].Value.push(bitArrays[i][j]);
        }
    }

    sort(maxHeaps.begin(), maxHeaps.end(), [&](Data& left, Data& right)
        {
            while (left.Value.top() == right.Value.top())
            {
                if(!left.Value.empty())
                    left.Value.pop();
                if (!right.Value.empty())
                    right.Value.pop();
            }

            return left.Value.top() > right.Value.top();
        });

    for (int i = 0; i < maxHeaps.size(); ++i)
    {
        out[i] = maxHeaps[i].Idx;
    }

    return out;
}

int main()
{
    ofstream fout;//(getenv("OUTPUT_PATH"));

    string bitArrays_rows_temp;
    getline(cin, bitArrays_rows_temp);

    int bitArrays_rows = stoi(ltrim(rtrim(bitArrays_rows_temp)));

    string bitArrays_columns_temp;
    getline(cin, bitArrays_columns_temp);

    int bitArrays_columns = stoi(ltrim(rtrim(bitArrays_columns_temp)));

    vector<vector<int>> bitArrays(bitArrays_rows);

    for (int i = 0; i < bitArrays_rows; i++) {
        bitArrays[i].resize(bitArrays_columns);

        string bitArrays_row_temp_temp;
        getline(cin, bitArrays_row_temp_temp);

        vector<string> bitArrays_row_temp = split(rtrim(bitArrays_row_temp_temp));

        for (int j = 0; j < bitArrays_columns; j++) {
            int bitArrays_row_item = stoi(bitArrays_row_temp[j]);

            bitArrays[i][j] = bitArrays_row_item;
        }
    }

    vector<int> result = sortBinaryNumbers(bitArrays);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

//long out = 0;
//long bits = 0;
//long maxIdx = 0;
//int size = operations.size();
//
//vector<bool> arrayResult(7);
//if (size > 7)
//{
//    arrayResult.resize(size);
//}
//
//for (int i = 0; i < size; ++i)
//{
//    int leftIdx = operations[i][0] - 1;
//    int rightIdx = operations[i][1] - 1;
//
//    if (leftIdx > rightIdx)
//    {
//        int tmp = leftIdx;
//        leftIdx = rightIdx;
//        rightIdx = tmp;
//    }
//
//    int leftsum = leftIdx * (leftIdx + 1) / 2;
//    int rightsum = rightIdx * (rightIdx + 1) / 2;
//
//
//    out += rightsum - leftsum;
//
//    for (int j = leftIdx; j <= rightIdx; ++j)
//    {
//        arrayResult[j] == false ? arrayResult[j] = true : arrayResult[j] = false;
//
//        arrayResult[j] == false ? out -= j + 1 : out += j + 1;
//    }
//
//long finalState(vector<vector<int>> operations) {
//    long out = 0;
//    long bits = 0;
//    long maxIdx = 0;
//    int size = operations.size();
//
//    vector<bool> arrayResult(100000);
//
//    for (int i = 0; i < size; ++i)
//    {
//        int leftIdx = operations[i][0] - 1;
//        int rightIdx = operations[i][1] - 1;
//
//        if (leftIdx > rightIdx)
//        {
//            int tmp = leftIdx;
//            leftIdx = rightIdx;
//            rightIdx = tmp;
//        }
//
//
//
//        for (int j = leftIdx; j <= rightIdx; ++j)
//        {
//            arrayResult[j] == false ? arrayResult[j] = true : arrayResult[j] = false;
//
//            arrayResult[j] == false ? out -= j + 1 : out += j + 1;
//        }
//
//    }
//
//
//
//    return out;