#include <iostream>
#include <vector>

using namespace std;

std::vector<int> digits(int n)
{
    std::vector<int> num_digits;
    while (n) {
        int next_n = n / 10;
        int last_digit = n - next_n * 10;
        num_digits.push_back(last_digit);
        n = next_n;
    }
    return num_digits;
}

int sum_digits_square(std::vector<int>& num_digits)
{
    int res = 0;
    for (int i = 0 ; i < num_digits.size(); i ++ )
    {
        res += num_digits[i] * num_digits[i];
    }
    return res;
}

class Solution {
public:
    bool isHappy(int n) {
        std::vector<int> squares;
        while (true)
        {
            std::vector<int> n_digits = digits(n);
            int sq = sum_digits_square(n_digits);
            if (sq == 1 ){
                return true;
            }
            if (std::count(squares.begin(), squares.end(), sq)) {
                return false;
            }
            squares.push_back(sq);
            n = sq;
        }       
    }
};