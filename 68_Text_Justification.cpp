#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> current_string_vector;

        current_string_vector.push_back(words[0]);
        int current_string_length = words[0].length();

        for(int i = 1 ; i < words.size() ; i ++ ) {
            int offset = 1;
            if (current_string_length + offset + words[i].length() <= maxWidth) {
                current_string_vector.push_back(words[i]);
                current_string_length += offset + words[i].length();
            } else {
                int additionalSpace = maxWidth - current_string_length;
                int main_space_length = current_string_vector.size() == 1 ? additionalSpace : additionalSpace/(current_string_vector.size() - 1);
                string main_space = "";
                for (int l = 0 ; l < main_space_length ; l ++ ) {
                    main_space += " ";
                }
                int extra_spaces_qnt = current_string_vector.size() == 1 ? 0 : additionalSpace % (current_string_vector.size() - 1);
                string current_string = current_string_vector[0];
                for (int w = 0; w < current_string_vector.size() - 1; w ++) {
                    string space = w < extra_spaces_qnt ? "  " : " ";
                    current_string += space + main_space + current_string_vector[w+1]; 
                }
                if (current_string_vector.size() == 1) {
                    current_string += main_space;
                }
                result.push_back(current_string);
                current_string_vector.clear();
                current_string_vector.push_back(words[i]);
                current_string_length = words[i].length();
            }
        }
        int additionalSpace = maxWidth - current_string_length;
        string end_space = "";
        for (int l = 0 ; l < additionalSpace ; l ++ ) {
            end_space += " ";
        }
        string current_string = current_string_vector[0];
        for (int w = 0; w < current_string_vector.size() - 1; w ++) {
            string space = " ";
            current_string += space + current_string_vector[w+1]; 
        }
        current_string += end_space;
        result.push_back(current_string);
        return result;
    }
};


void main () {
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    Solution solution;
    auto res = solution.fullJustify(words, maxWidth);
    for (auto str: res) {
        cout << str << "\n";
    }
}
