/*
*
* ������34������
* ��ֻ��������2��3��5��������������Ugly Number����
* ����6��8���ǳ�������14���ǣ���Ϊ����������7��
* ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)  //С��7�Ķ��ǳ�����ֱ�ӷ���
            return index;
        vector<int> result(index);
        int m2=0,m3=0,m5=0;  //��Ӧ���±�λ��
        result[0]=1;
        for(int i=1;i<index;i++)
        {
            result[i]=min(result[m2]*2, min(result[m3]*3, result[m5]*5));
            //result�г�������С��������ģ��������ϵ������С���������ģ�
			//�ǿ϶����ǳ���,������Ӧ��һ
			while((result[m2]*2)<=result[i])  
                m2++;
            while((result[m3]*3)<=result[i])
                m3++;
            while((result[m5]*5)<=result[i])
                m5++;
        }
        return result[index-1];
    }
};