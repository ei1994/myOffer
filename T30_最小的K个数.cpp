/*
*
* 面试题30：最小的K个数
* 输入n个整数，找出其中最小的K个数。
* 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.empty() || k<1 || input.size()<k)
            return result;
        priority_queue<int> pq;
        for(int i=0;i<input.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(input[i]);
            }
            else
            {
                int maxVal=pq.top();
                if(input[i]<maxVal)
                {
                    pq.pop();
                    pq.push(input[i]);
                }
            }
        }
        while(!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
        
    }
};