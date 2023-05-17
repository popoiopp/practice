#include<iostream>
#include<vector>
using namespace std;
/*
*heapify函数维护当前下标为i及以下的二叉树元素的堆排序的性质
*下标为i的父节点，左孩子下标为i*2+1,右孩子下标为i*2+2;
*下标为i的孩子节点，其父节点的下标为i/2-1;
**/
void heapify(vector<int>&arr,int n,int i)
{
  int largest=i;
  int left=i*2+1;
  int right=i*2+2;
  if(left<n&&arr[left]>arr[largest]){//如果left>n,则表示左孩子下标超出了数组范围，即不存在。
    largest=left;//这是一个大顶堆，父节点元素必须大于左右孩子结点元素，如果小于，则交换父节点与（左或右）孩子节点;
  }
  if(right<n&&arr[right]>arr[largest]){
    largest=right;
  }
  if(i!=largest){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
  }//交换之后，以被交换的孩子节点作为父节点的堆已经被破坏，递归重新维护大顶堆的性质。
}
vector<int>& heap_sort(vector<int>&arr,vector<int>&cur,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    //建堆过程.
    //从最后一个元素开始建堆(自底部向上)
    cur=arr;
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);//把堆顶元素和当前下标为i的元素进行交换，同时堆的元素数量减一。(因为堆顶元素一定是当前这个堆的最大值)
        heapify(arr,i,0);//从堆顶元素开始重新维护这个堆.
    }
    return arr;
    
}
int main(void)
{
    int num;
    cin>>num;
    vector<int>arr(num);
    vector<int>cur(num,0);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
   for(int i=0;i<num;i++)
   { 
    if(i!=num-1)
    {
      cout<<arr[i]<<',';
    }
    else{
      cout<<arr[i];
    }

   }

    cout<<endl;
    arr=heap_sort(arr,cur,num);
    for(int i=0;i<num;i++)
   { 
    if(i!=num-1)
    {
      cout<<cur[i]<<',';
    }
    else{
      cout<<cur[i];
    }

   }
    cout<<endl;
   for(int i=0;i<num;i++)
   { 
    if(i!=num-1)
    {
      cout<<arr[i]<<',';
    }
    else{
      cout<<arr[i];
    }

   }
}