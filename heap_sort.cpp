#include<iostream>
#include<vector>
using namespace std;
/*
*heapify����ά����ǰ�±�Ϊi�����µĶ�����Ԫ�صĶ����������
*�±�Ϊi�ĸ��ڵ㣬�����±�Ϊi*2+1,�Һ����±�Ϊi*2+2;
*�±�Ϊi�ĺ��ӽڵ㣬�丸�ڵ���±�Ϊi/2-1;
**/
void heapify(vector<int>&arr,int n,int i)
{
  int largest=i;
  int left=i*2+1;
  int right=i*2+2;
  if(left<n&&arr[left]>arr[largest]){//���left>n,���ʾ�����±곬�������鷶Χ���������ڡ�
    largest=left;//����һ���󶥶ѣ����ڵ�Ԫ�ر���������Һ��ӽ��Ԫ�أ����С�ڣ��򽻻����ڵ��루����ң����ӽڵ�;
  }
  if(right<n&&arr[right]>arr[largest]){
    largest=right;
  }
  if(i!=largest){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
  }//����֮���Ա������ĺ��ӽڵ���Ϊ���ڵ�Ķ��Ѿ����ƻ����ݹ�����ά���󶥶ѵ����ʡ�
}
vector<int>& heap_sort(vector<int>&arr,vector<int>&cur,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    //���ѹ���.
    //�����һ��Ԫ�ؿ�ʼ����(�Եײ�����)
    cur=arr;
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);//�ѶѶ�Ԫ�غ͵�ǰ�±�Ϊi��Ԫ�ؽ��н�����ͬʱ�ѵ�Ԫ��������һ��(��Ϊ�Ѷ�Ԫ��һ���ǵ�ǰ����ѵ����ֵ)
        heapify(arr,i,0);//�ӶѶ�Ԫ�ؿ�ʼ����ά�������.
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