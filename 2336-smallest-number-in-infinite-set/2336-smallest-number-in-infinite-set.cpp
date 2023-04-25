class SmallestInfiniteSet {
public:
    priority_queue<int , vector<int> , greater<int> > pq;
    
    SmallestInfiniteSet() {
        // because of constraints
        for(int i =1;i<=1000;i++){
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    bool contains(int num){
        priority_queue<int, vector<int>, greater<int> > pq2 = pq;
        
        while(!pq2.empty() && pq.top()<=num){
            if(pq2.top()==num){
                return true;
            }
            pq2.pop();
        }
        return false;
    }
    void addBack(int num) {
        if(contains(num)){
            return;
        }
        else{
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */