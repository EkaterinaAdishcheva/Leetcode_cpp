#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums1_qnt;
        map<int, int> nums2_qnt;
        map<int, int>:: iterator it1;
        map<int, int>:: iterator it2;

        vector<int> res;
        
        for (auto n: nums1) {
            nums1_qnt.emplace(n, 0);
            nums1_qnt[n] += 1;
        }        
        for (auto n: nums2) {
            nums2_qnt.emplace(n, 0);
            nums2_qnt[n] += 1;
        }
        it1 = nums1_qnt.begin();
        while (it1 != nums1_qnt.end()) {
            it2 = nums2_qnt.find(it1->first);
            if (it2 != nums2_qnt.end()) {
                for (int i = 0 ; i < min(it1->second, it2->second); i ++) {
                    res.push_back(it1->first);
                }
            }
            it1 ++ ;
        }
        return res;         
    }
};
