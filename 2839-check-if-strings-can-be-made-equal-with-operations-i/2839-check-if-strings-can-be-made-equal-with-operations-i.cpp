class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1 = s1,t2 = s1;
        if(s1 == s2) return true;
        swap(t1[0],t1[2]);
        if(t1 == s2) return true;
        swap(t1[1],t1[3]);
        if(t1 == s2) return true;
        swap(t2[1],t2[3]);
        if(t2 == s2) return true;
        swap(t2[0],t2[2]);
        if(t2 == s2) return true;

        return false;


    } 
};