class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(secondHalf.empty()) secondHalf.push(num);
        else if(num < secondHalf.top()) firstHalf.push(num);
        else secondHalf.push(num);

        if (secondHalf.size() > firstHalf.size() + 1){
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
        else if (secondHalf.size() < firstHalf.size()){
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
    }
    
    double findMedian() {
        if(secondHalf.size() > firstHalf.size()) return secondHalf.top();
        else return static_cast<double>(secondHalf.top() + firstHalf.top()) / 2;
    }
    private: 
        priority_queue<int> firstHalf;
        priority_queue<int, vector<int>, greater<int>> secondHalf;
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
