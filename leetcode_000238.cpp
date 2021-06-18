//
// Created by cooper on 2021/6/18.
// Email:cooper.zhang@ubtrobot.com
//

//给你一个长度为n的整数数组nums，其中n > 1，返回输出数组output，其中output[i]等于nums中除nums[i]之外其余各元素的乘积。

#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> L(length, 0);
        vector<int> R(length, 0);
        vector<int> answers(length, 0);

        L[0] = 1;
        for(int i=1; i<length; i++)
        {
            L[i] = L[i-1] * nums[i-1];
        }

        R[length-1] = 1;
        for(int j=length-2; j>=0; j--)
        {
            R[j] = R[j+1] * nums[j+1];
        }

        for(int k=0; k<length; k++)
        {
            answers[k] = L[k] * R[k];
        }

        return answers;
    }
};


int main(int argc, char *argv[])
{
    vector<int> a = {1, 2, 3, 4};

    Solution solution;
    vector<int> res = solution.productExceptSelf(a);

    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
