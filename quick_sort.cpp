#include<iostream>
#include<vector>
using namespace std;
/*
*����˼�룺������һ������Ϊ��׼(ͨ�������һ����);
*������С��pivot(��׼��)�����ƶ���ǰ�棬����pivot��������(�±�j���ڱ������飬�±�i���ڴ�ű�pivotС���������ս�pivot������±�i+1����)��
**/
class quick_sort
{
    public:
    int num[10]={10,9,8,7,6,5,4,3,2,1};
    
    void quick_merge(int num[],int low,int high)
    {
        if(low>=high)return ;
        int pivot=num[high];
        int i=low,j=low;
        while(j<=high-1)
        {
            if(num[j]<pivot){
                swap(num[i],num[j]);
                i++;
            }
            j++;
        }
      for(int cur=high;cur>=i;cur--)
      {
              num[cur]=num[cur-1];
      }
      num[i]=pivot;
      //�ݹ����
      quick_merge(num,low,i-1);
      quick_merge(num,i+1,high);
    

    }

};
int main(void)
{
    quick_sort test;
    test.quick_merge(test.num,0,9);
    for(int it:test.num)
    {
        cout<<it<<' ';
    }
}
