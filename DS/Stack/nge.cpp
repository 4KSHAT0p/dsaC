#include <bits/stdc++.h>
using namespace std;

// vector<int> NGEL(vector<int> &nums)
// {
//     int n=nums.size();
//     vector<int> nge(n);
//     stack<int> st;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (st.empty())
//         {
//             nge[i] = -1;
//             st.push(nums[i]);
//         }
//         else if (nums[i] < st.top())
//         {
//             nge[i] = st.top();
//             st.push(nums[i]);
//         }
//         else
//         {
//             while (!st.empty() and st.top() < nums[i])
//             {
//                 st.pop();
//             }
//             if (!st.empty())
//             {
//                 nge[i] = st.top();
//                 st.push(nums[i]);
//             }
//             else
//             {
//                 st.push(nums[i]);
//                 nge[i] = -1;
//             }
//         }
//     }
//     return nge;
// }
vector<int> NGEL(vector<int> &nums) //more efficient
{
    int n=nums.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() and nums[i]>st.top())
        {
            st.pop();
        }
        if(st.empty())
            nge[i]=-1;
        else
            nge[i]=st.top();
        
        st.push(nums[i]);
    }
    return nge;
}
int main()
{

    vector<int> nums1 = {1,2,3,4,3};
    vector<int> rev=NGEL(nums1);
    for(auto&it:rev)
    {
        cout<<it<<" ";
    }
    return 0;
}