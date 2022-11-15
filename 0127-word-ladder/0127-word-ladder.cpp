class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // we put all ewords of wordList in a set
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        // we push the begin word in queue
        q.push({beginWord,1});
        
        // now i have to reach to endWord to reach the endWord  i chenge every letter of the starting word
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord){
                return steps;
            }
            for(int i =0;i<word.size();i++){
                int letter = word[i];
                for(char ch = 'a'; ch<= 'z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = letter;
            }
        }
        return 0;
    }
};