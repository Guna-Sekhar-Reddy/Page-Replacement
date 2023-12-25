//page replacement using second chance algorithm 

#include<iostream>

using namespace std;

struct frame
{
	int pno;
	int ref;
};


int main()
{
	int f,n,fault=0,temp,index,index1,old_max,new_max,ind=0;
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
		s[i].ref=1;							//initializing all references with 1	
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
				s[j].ref=1;
				//cout<<"frame "<<j<<" having content "<<s[j].pno<<endl;
				break;
			}		
		}
		
		if(index1==0)								//action to do when page is not in frame
		{
			fault++;
			index=0;
				
			for(int j=0;j<f;j++)					//if frame is empty
			{
				if(s[j].pno==-1)
				{
					s[j].pno=temp;
					index=1;
					s[j].ref=0;
					//cout<<"frame "<<j<<" having content "<<s[j].pno<<endl;
					break;
				}	
			}
			
			if(index==0)							//if frame is full
			{
				while(true)						//if all references are 1,then after visiting f frames all references are 0
				{								//so, at f+1 visit the referenc is 0,so we can replace the page
					if(s[ind].ref==0)
					{
						s[ind].pno=temp;
						ind=(ind+1)%f;
						//cout<<"frame "<<ind<<" having content "<<s[ind].pno<<endl;
						break;
					}
					
					else if(s[ind].ref==1)
					{
						s[ind].ref=0;
					}
					ind=(ind+1)%f;
				}
			}
				
		}
	
	}
		
	cout<<"Number of page faults are "<<fault<<endl;

}
