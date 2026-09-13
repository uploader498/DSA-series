class MedianFinder {
public:
    priority_queue<int>leftq;
    priority_queue<int,vector<int>,greater<int>>rightq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftq.empty()){
            leftq.push(num);
        }else if(num>leftq.top()){
            rightq.push(num);
        }else{
            leftq.push(num);
        }
        balance();
    }
    void balance(){
        if(rightq.size()>leftq.size()){
            leftq.push(rightq.top());
            rightq.pop();
        }else{
            if(rightq.size()<leftq.size()-1){
                rightq.push(leftq.top());
                leftq.pop();
            }
        }
    }
    double findMedian() {
        if(leftq.size()>rightq.size()){
            return leftq.top();
        }
        double ans = leftq.top()+rightq.top();
        ans /= 2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */