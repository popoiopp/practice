#include<iostream>
#include<vector>
using namespace std;
/*
*排序思想：先先择一个数作为基准(通常是最后一个数);
*把所有小于pivot(基准数)的数移动到前面，大于pivot的数跳过(下标j用于遍历数组，下标i用于存放比pivot小的数，最终将pivot存放在下标i+1即可)。
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
      //递归调用
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
