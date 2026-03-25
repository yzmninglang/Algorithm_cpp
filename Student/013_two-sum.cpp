#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
// #include<pair>

struct two_num
{
    int num1;
    int num2;
    two_num(int val1,int val2):num1(val1),num2(val2){};
};




std::vector<two_num*> two_sum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int,int> hash;
    std::vector<two_num*> varied_num;
    
    for (int i = 0; i < nums.size()-2; i++)
    {
       for (int j = i+1; j < nums.size()-1; j++)
       {
            if(target==nums[i]+nums[j])
            {
                two_num* tmp = new two_num(i,j);
                varied_num.push_back(tmp);
            }
       }
    }
    return varied_num;
}



std::vector<std::pair<int,int>> two_sum_two_point(const std::vector<int>& nums1, int target)
{
    std::vector<std::pair<int,int>> result;
    int left = 0;
    std::vector<int> nums= nums1;
    std::sort(nums.begin(),nums.end());
    int right = nums.size()-1;
    while (left<right)
    {
        if(nums[left]+nums[right]==target)
        {
            result.push_back({nums[left],nums[right]});
            while(nums[left+1]==nums[left]) left++;
            while(nums[right-1]==nums[right]) right--;
            left++;
            right--;
        }
        else if(nums[left]+nums[right]<target)left++;
        else if(nums[left]+nums[right]>target)right--;
    }
    return result;

}


int main()
{
    // std::vector<int> test = {1,2,3,4,5,6,7,9};
    std::vector<int> test = {1,2,2,2,3,4,5,6,7,7,7,8};
    // std::vector<two_num*> two_num_sum = two_sum(test,9);
    std::vector<std::pair<int,int>> two_sum_sum= two_sum_two_point(test,9);
    for (int i = 0; i < two_sum_sum.size(); i++)
    {
        // std::cout<<"first:"<<two_num_sum[i]->num1;
        // std::cout<<" second:"<<two_num_sum[i]->num2<<std::endl;
        std::cout<<"first:"<<two_sum_sum[i].first;
        std::cout<<" second:"<<two_sum_sum[i].second<<std::endl;
        // std::cout<<
    }

    return 0;
    
}