/*
*
* 面试题64：数据流中的中位数
* 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
* 那么中位数就是所有数值排序之后位于中间的数值。
* 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
*
*/
class Solution {
public:
    //最大堆（维护小数），由大到小，队头元素最大
    priority_queue<int, vector<int>, less<int>>  maxHeap;
    //最小堆（维护大数），由小到大，队头元素最小
    priority_queue<int,vector<int>, greater<int>> minHeap;
    void Insert(int num)
    {
        if(!maxHeap.size() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        //维护两个堆的平衡，最大堆大小不小于最小堆，当然不能比最小堆大2个。
        if(maxHeap.size() == minHeap.size()+2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() == minHeap.size()-1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian()
    { 
        if(minHeap.size() == maxHeap.size())
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        else
            return maxHeap.top();
    }

};