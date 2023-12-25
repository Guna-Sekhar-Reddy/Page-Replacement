//page replacement using fifo
#include<iostream>

using namespace std;

struct frame
{
	int pno;					//page no
};
int main()
{
	int f,n,fault=0,temp,index,index1;
	cout<<"Enter the number of pages"<<endl;
	cin>>n;
	
	cout<<"Enter number of frames in memory"<<endl;
	cin>>f;
	
	int page[n];
	
	struct frame s[f];
	cout<<"Enter the reference string"<<endl;
	for(int i=0;i<n;i++)					//entering reference string
	{
		cin>>page[i];
	}
	
	
	for(int i=0;i<f;i++)					//initilalizing page no in frame as -1 
	{
		s[i].pno=-1;	
	}
	
	index=0;
	for(int i=0;i<n;i++)
	{
		temp=page[i];
		index1=0;
		
		for(int j=0;j<f;j++)						//checking weather page is in frame
		{	
			if(temp==s[j].pno)
			{
				index1=1;
				break;
			}		
		}
		
		if(index1==0)								//action to do when page is not in frame
		{
			fault++;
			s[index].pno=temp;
			//cout<<"frame content is "<<s[index].pno<<endl;
			index=(index+1)%f;
		}
		
	}
	
	cout<<"Number of page faults are "<<fault<<endl;
	
	
	
}
