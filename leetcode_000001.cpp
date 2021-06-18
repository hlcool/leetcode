//
// Created by cooper on 2021/6/18.
// Email:cooper.zhang@ubtrobot.com
//
/*
    给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值 target的那两个整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    //hash表的方法
    vector<int> twoSum_1(vector<int> &nums, int target)
    {
        int length = static_cast<int>(nums.size());
        unordered_map<int, int> hashTable;
        for(int i=0; i<length; i++)
        {
            auto it = hashTable.find(target-nums[i]);
            if(it != hashTable.end())
            {
                return {it->second, i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }

    //暴力匹配方法
    vector<int> twoSum_2(vector<int> &nums, int target)
    {
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

int main(int argc, char * argv[])
{
    vector<int> src = {2, 7, 0, 15};
    int target = 17;

    Solution solution;
    vector<int> res = solution.twoSum_2(src, target);

    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << "  ";
    }
    cout << endl;

    return 0;
}


