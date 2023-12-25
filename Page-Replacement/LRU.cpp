//page replacement using LRU(least recently used)

#include<iostream>

using namespace std;

struct frame
{
	int pno;					//page no
	int count;
};

void counter(struct frame s[],int j,int f)			//counter -> makes the reference page counter  to 0 and 
{													//other pages counter increments, so most count page is replaced
	for(int i=0;i<f;i++)
	{
		if(i!=j)
		{
			s[i].count++;
		}
		
		else
		{
			s[j].count=0;
		}
	}
}
int main()
{
	int f,n,fault=0,temp,index,index1,old_max,new_max;
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
				counter(s,j,f);
				cout<<"frame page is"<<s[j].pno<<" frame no is "<<j<<endl;
				break;
			}		
		}
		
		if(index1==0)								//action to do when page is not in frame
		{
			fault++;
			index=0;
				
			for(int j=0;j<f;j++)
			{
				if(s[j].pno==-1)							//if frames are not full
				{
					s[j].pno=temp;
					index=1;
					counter(s,j,f);
					cout<<"frame page is "<<s[j].pno<<" frame no is "<<j<<endl;
					break;
				}	
			}
			
			if(index==0)								//if frames are full
			{
				old_max=0;
				for(int j=0;j<f;j++)
				{
					if(s[j].count>=s[old_max].count)
					{
						new_max=j;
					}
					old_max=new_max;
				}
				
				s[new_max].pno=temp;
				counter(s,new_max,f);
				cout<<"frame page is "<<s[new_max].pno<<" frame no is "<<new_max<<endl;
			}	
		}
	}
	
	cout<<"Number of page faults are "<<fault<<endl;
		
}
