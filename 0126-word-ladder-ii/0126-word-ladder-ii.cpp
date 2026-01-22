class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>depth;
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        depth[beginWord] = 1;

        while(!q.empty()){
            string word = q.front();
            q.pop();
            int steps = depth[word];
            if(word == endWord) break;
            for(int i=0;i<word.size();i++){
                char ori = word[i];
                for(char a='a';a<='z';a++){
                    word[i] = a;
                    if(st.count(word)){
                        q.push(word);
                        depth[word] =steps+1;
                        st.erase(word);
                    }
                }
                word[i] = ori;
            }
        }


        if(depth.count(endWord)){
            vector<string>res = {endWord};
            dfs(endWord,beginWord,res,depth,ans,st);
        }

        return ans;
    }

    void dfs(string word,string startWord,vector<string>&res,unordered_map<string,int>&depth,vector<vector<string>>&ans,unordered_set<string>&st){
        if(word==startWord){
            reverse(res.begin(),res.end());
            ans.push_back(res);
            reverse(res.begin(),res.end());
            return;
        }

        int steps = depth[word];
        for(int i=0;i<word.size();i++){
            char aa = word[i];
            for(char c='a';c<='z';c++){
                word[i] = c;
                if(depth.count(word) && depth[word]+1 == steps){
                    res.push_back(word);
                    dfs(word,startWord,res,depth,ans,st);
                    res.pop_back();
                }
            }
            word[i] = aa;
        }

    }
};