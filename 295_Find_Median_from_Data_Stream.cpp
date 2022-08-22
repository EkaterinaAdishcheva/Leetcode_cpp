#include <vector>
using namespace std;

class MedianFinder {

public:
    vector<int> numbers;
    vector<int> numbersCumCount;
    int medianaPosition;
    
    MedianFinder() {
        for(int i = 0 ; i < 20000; i ++) {
            numbersCumCount.push_back(0);
            medianaPosition = 0;
        }
    }
    
    void addNum(int num) {
        numbers.push_back(num);
        for(int i = num + 10000; i < 2*10000; i ++ ) {
            numbersCumCount[i] += 1;
        }
    }
    
    double findMedian() {
        double res;
        if(numbers.size() % 2 == 0) {
            res = numbers[numbers.size()/2 - 1] + numbers[numbers.size()/2];
            res /= 2;
        } else {
            res = numbers[numbers.size()/2];
        }
        return res;        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */