#include <vector>
#include <map>
using namespace std;

class MedianFinder {
private:
    pair<int, int> next(pair<int, int> position, map<int, int>& numbersCount) {
        map<int, int>::iterator it;
        if ( position.second ==  numbersCount[position.first] ) {
            it = numbersCount.find(position.first);
            it ++ ;
            position.first = it->first;
            position.second = 1;
        } else {
            position.second ++ ;    
        }
        return position;
    }

    pair<int, int> previous(pair<int, int> position, map<int, int>& numbersCount) {
        map<int, int>::iterator it;
        if ( position.second == 1 ) {
            it = numbersCount.find(position.first);
            it -- ;
            position.first = it->first;
            position.second = numbersCount[position.first];
        } else {
            position.second -- ;    
        }
        return position;
    }

public:
    map<int, int> numbersCount;
    map<int, int>::iterator it;
    pair<int, int> medianaPositionL;
    bool EqualInd;
    
    MedianFinder() {
        medianaPositionL = pair(INT_MIN, 0);
    }
    
    void addNum(int num) {
        it = numbersCount.find(num);
        if (it == numbersCount.end()) {
            numbersCount[num] = 1;
        } else {
            numbersCount[num] ++;
        }
        if (medianaPositionL.first == INT_MAX) {
            medianaPositionL.first = num;
            medianaPositionL.second = 1;
            EqualInd = true;
            return;
        }
        if ( medianaPositionL.first <= num ) {
            if ( !EqualInd ) {
                medianaPositionL = next(medianaPositionL, numbersCount);
            }
            EqualInd = !EqualInd;
        }
        if ( medianaPositionL.first > num ) {
            if ( EqualInd ) {
                medianaPositionL = previous(medianaPositionL, numbersCount);
            }
            EqualInd = !EqualInd;
        }
    }
    
    double findMedian() {
        double medianaValue;
        if ( medianaPositionL.second == numbersCount[medianaPositionL.first] ) {
            it = numbersCount.find(medianaPositionL.first);
            it ++;
            medianaValue = ( medianaPositionL.first + it->first ) / 2.0;
            return medianaValue;
        }
        medianaValue = medianaPositionL.first;
        return medianaValue;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */