class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i =0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>=2){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(x !=y){
                int ans = y-x;
                pq.push(ans);
            }
        }
        
        if(pq.size()==0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};