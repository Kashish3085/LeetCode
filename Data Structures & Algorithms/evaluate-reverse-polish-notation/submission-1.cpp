class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for (int i = 0; i < n; i++) {
            string c = tokens[i];
            if (tokens[i] == "+" || tokens[i] == "-" ||tokens[i] == "*" || tokens[i] == "/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int r;
                if(tokens[i]=="+"){
                    r=a+b;
                }
                if(tokens[i]=="-"){
                    r=b-a;
                }
                if(tokens[i]=="*"){
                    r=a*b;
                }
                if(tokens[i]=="/"){
                    r=b/a;
                }
                st.push(r);
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};