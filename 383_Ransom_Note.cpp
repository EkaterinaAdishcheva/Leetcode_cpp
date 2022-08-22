#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransomNoteQnt(26, 0);
        int nunique = 0;
        for (int i = 0 ; i < ransomNote.size(); i ++ ) {
            ransomNoteQnt[ransomNote[i] - 'a'] ++;
            if (ransomNoteQnt[ransomNote[i] - 'a'] == 1) {
                nunique ++;
            }
        }
        for (int i = 0 ; i < magazine.size(); i ++ ) {
            ransomNoteQnt[magazine[i] - 'a'] --;
            if (ransomNoteQnt[magazine[i] - 'a'] == 0) {
                nunique --;
            }
        }
        if (nunique == 0 ) {
            return true;
        }
        return false;
    }
};