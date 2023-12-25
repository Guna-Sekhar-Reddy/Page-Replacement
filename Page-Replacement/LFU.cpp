//least frequently used

#include<iostream>
#define N 20 									//lets say there are N different page no in reference string
using namespace std;

struct frame
{
	int pno;					//page no
	int count;					
};

struct dif									//to count each unique page frequency of repetation
{
	int pno;
	int count;
};

struct dif d[N];


void move_or_count(int temp)
{
	int ind=0;
	for(int i=0;i<N;i++)
	{
		if(temp==d[i].pno)
		{
			d[i].count++;
			ind=1;
			break;
		}
	}
	
	if(ind==0)
	{
		for(int i=0;i<N;i++)
		{
			if(d[i].pno==-1)
			{
				d[i].pno=temp;
				d[i].count++;
			}
		}
	}
}

int main()
{
	int f,n,fault=0,temp,index,index1,old_min,new_min,index2;

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
	cout<<"hii"<<endl;
	
	for(int i=0;i<f;i++)					//initilalizing page no in frame as -1 
	{
		s[i].pno=-1;
		s[i].count=0;
	}

	for(int i=0;i<N;i++)					//initializing different page no as -1
	{
		d[i].pno=-1;
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
				move_or_count(temp);
				break;
			}		
		}
		
		if(index1==0)								//action to do when page is not in frame
		{
			fault++;
			index=0;
			
			for(int j=0;j<f;j++)					//when frames are empty
			{
				if(s[j].pno==-1)
				{
					s[j].pno=temp;
					index=1;
					move_or_count(temp);		
					break;
				}	
			}
			
			if(index==0)						//when frames are full
			{
				old_min=0;
				for(int j=0;j<N;j++)
				{	
					if(d[j].count<=d[old_min].count)
					{
						for(int k=0;k<f;k++)
						{
							if(s[k].pno==d[j].pno)
							{
								new_min=j;
								break;
							}
						}
					}
					old_min=new_min;
				}
				
				index2=0;
				while(true)
				{
					if(s[index2].pno==d[new_min].pno)
					{
						s[index2].pno=temp;
						d[new_min].pno=-1;
						break;
					}
					index2=(index2+1)%f;
				}
				move_or_count(temp);
				
			}	
		}
	}
	
	cout<<"Number of page faults are "<<fault<<endl;
		
}
