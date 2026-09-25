class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>m(26,0);
        int c=s1.size(),l=0;
        if(s1.size()>s2.size()) return false;
        for(int i=0;i<s1.size();i++){
            char c1=s1[i];
            m[c1-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            char c2=s2[i];
            if(m[c2-'a']>0){
                c--;
            }
            m[c2-'a']--;
            if(i-l+1>s1.size()){
                int s=s2[l]-'a';
                if(m[s]>=0){
                    c++;
                }
                m[s]++;
                l++;
                
            }
            if(c==0) return true;
        }
        return false;
    }
};
