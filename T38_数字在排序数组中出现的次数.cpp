/*
*
* 面试题38：数字在排序数组中出现的次数
* 统计一个数字在排序数组中出现的次数。如数组{1,2,3,3,3,3,4,5}和数字3,3出现了4次，则返回4
*
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int len=data.size();
        int first=getFirst(data,k,0,len-1);
        int last=getLast(data,k,0,len-1);
        if(first>-1 && last>-1)
            return last-first+1;
        return 0;
    }
private:
	//可以使用递归方法
	/*int getFirst(vector<int> data, int k, int start, int end)
	{
		if (start > end)
			return -1;
		int mid = (end + start)>>1;
		int midData = data[mid];
		if (midData>k)
		{
			return getFirst(data, k, start, mid - 1);
		}
		else if (midData<k)
		{
			return getFirst(data, k, mid + 1, end);
		}
		else if (mid > start && data[mid - 1] == k)
		{
			return getFirst(data, k, start, mid - 1);
		}
		else
			return mid;
	}*/
    int getFirst(vector<int> data,int k,int start,int end)
    {
        while(start<=end){
            int mid=(end+start)/2;
            int midData=data[mid];
            if(midData>k)
                end=mid-1;
            else if(midData<k)
                start=mid+1;
            else if(data[mid-1]==k && mid>start)
                end=mid-1;
            else
                return mid;
        }
        return -1;
        
    }
    
    int getLast(vector<int> data,int k,int start , int end)
    {
        while(start<=end)
        {
            int mid=(end+start)>>1;
            int midData=data[mid];
            if(midData>k)
            {
                end=mid-1;
            }
            else if(midData<k)
                start=mid+1;
            else if(data[mid+1]==k && (mid+1)<=end)
                start=mid+1;
            else
                return mid;
        }
        return -1;
    }
};