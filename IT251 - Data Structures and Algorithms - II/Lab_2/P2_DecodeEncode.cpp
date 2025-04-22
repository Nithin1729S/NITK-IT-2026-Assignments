//This code only decodes given string as per the questions requirement using stacks

#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string convert(string n,string s){
        string temp="";
        for(int i=0;i<stoi(n);i++){
            temp+=s;
        }
        return temp;
    }

    string decodeString(string s) {
        stack<int>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string temp="";
                string n="";
                while(!st.empty() && !isdigit(st.top())){
                    if(st.top()=='[') {
                        st.pop();  //pop the teh element from stack
                        continue;
                    }
                    temp+=string(1,st.top());st.pop();
                }                
                while(!st.empty() && isdigit(st.top())){
                    n+=string(1,st.top());st.pop();
                }
                reverse(temp.begin(),temp.end());
                reverse(n.begin(),n.end());
                string z=convert(n,temp);   
                for(auto x:z){
                    st.push(x);
                }          
            }
        }
        while(!st.empty()){
            ans+=string(1,st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());  //reverser the obtained string before retunign 
        return ans;
    }

    
};


int main()
{
    Solution sol;
    string s;
    cout<<"Enter the string to be decoded";
    cin>>s;
    string res=sol.decodeString(s);
    cout<<res;
    return 0;
}