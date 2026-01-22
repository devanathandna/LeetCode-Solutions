class Solution {
public:
const char arr[4] = {'A','C','T','G'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        unordered_set<string>st(bank.begin(),bank.end());
        q.push({startGene,0});
        st.erase(startGene);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endGene) return steps;

            for(int i=0;i<word.size();i++){
                char a = word[i];
                for(int j=0;j<4;j++){
                    word[i] = arr[j];
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = a;
            }
        }

        return -1;
    }
};