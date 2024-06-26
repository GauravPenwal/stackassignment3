#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n= arr.size();
        int nse[n];
        stack<int>st;
        nse[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()!=0 && arr[i]<=arr[st.top()])st.pop();
            if(st.size()==0)nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
    int pse[n];
        stack<int>gt;
        pse[0]=-1;
        gt.push(0);
        for(int i=1;i<n;i++){
            while(gt.size()!=0 && arr[i]<=arr[gt.top()])gt.pop();
            if(gt.size()==0)pse[i]=-1;
            else pse[i]=gt.top();
            gt.push(i);
        }
    
    int maxarea=0;
    for(int i=0;i<n;i++){
        int area =arr[i]*(nse[i]-pse[i]-1) ;
        maxarea = max(area,maxarea);
    }
    return maxarea;}


    int maximalRectangle(vector<vector<char>>& matrix) {
    int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;     
        vector<int>histo(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')histo[j]+=1;
                else histo[j]=0;
            }
            result =max(result,largestRectangleArea(histo));
        }
    return result;}
};


int main(){

}