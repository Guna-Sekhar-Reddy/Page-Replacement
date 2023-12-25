//page replacement using optimal algo(OPT)

#include<iostream>

using namespace std;

struct frame
{
	int pno;					//page no
	int flag;					//flag to predict which pg no is not used for long time flag->0 page not referencecd
								//for longer time and flag->1 means page will be referenced early
};
int main()
{
	int f,n,fault=0,temp,index,index1,count=0;
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
		s[i].flag=0;	
	}
	

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
				index=0;
				
				for(int j=0;j<f;j++)
				{
					if(s[j].pno==-1)
					{
						s[j].pno=temp;
						index=1;
						break;
					}	
				}	
			
				if(index==0)
				{	
				
				for(int j=i+1;j<n;j++)					//counting form next to present symbol in refernce string
				{
					for(int k=0;k<f;k++)
					{
						if(s[k].pno==page[j] && s[k].flag==0)
						{
							count++;
							s[k].flag=1;
							break;
						}
					}
					if(count==f-1)
						break;
				
				}
				
				for(int j=0;j<f;j++)
				{
					if(s[j].flag==0)
					{
						s[j].pno=temp;
						break;
					}
				}
		
			}
		}

		
		for(int j=0;j<f;j++)
		{
			s[j].flag=0;
			//cout<<"frame "<<j<<" contenet is "<<s[j].pno<<endl;
		}
		
	}
	
	cout<<"Number of page faults are "<<fault<<endl;
	
	
	
}
