class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1;
        queue<int> q2;
        int n = senate.size();
        for(int i =0;i<senate.size();i++){
            if(senate[i] == 'R'){
                q1.push(i);
            }
            else if(senate[i] == 'D'){
                q2.push(i);
            }
        }
        
        while(!q1.empty() && !q2.empty()){
            int Rs = q1.front();
            int Ds = q2.front();
            q1.pop();
            q2.pop();
            
            if(Rs>Ds){
                q2.push(Ds+n);
            }
            else{
                q1.push(Rs+n);
            }
        }
        
        if(!q1.empty()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    
    }
};
    
    
    