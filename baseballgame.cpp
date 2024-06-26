#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& op) {
        int ans=0;
        int n=op.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(op[i]=="+"){
                int x=  st.top();
                st.pop();
                int y=st.top();
                st.pop();
                //st.push(x+y);
                st.push(y);
                st.push(x);
                st.push(x+y);
            }
            else if(op[i]=="D"){
                st.push(2*st.top());
            }
            else if(op[i]=="C")st.pop();
            else {
                int x = stoi(op[i]);
                st.push(x);
            }
        }
    while(!st.empty()){
        ans +=st.top();
        st.pop();
    }
 return ans;   }
};

int main(){

}