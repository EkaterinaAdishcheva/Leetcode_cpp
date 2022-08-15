#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t == "") return "";
        std::vector<int> map(128, 0);
        for (char c: t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = std::numeric_limits<int>::max();
        int head = -1;
        while (end < s.size()) {
            if ((map[s[end]]--) > 0) {
                counter--;
            }
            end++;
            while (counter == 0) {
                if (d > end - begin) {
                    head = begin;
                    d = end - begin;
                }
                if ((map[s[begin]]++) >= 0) {
                    counter++;
                }
                begin++;
            }
        }
        return head == -1 ? "" : s.substr(head, d);
    }
};