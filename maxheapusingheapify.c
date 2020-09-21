// max and min heap using heapify
//insertion

#include<stdio.h>
#define max 50

int arr[max] = {10,25,20,30,35,70,7} ;

void maxheapify(int index,int size)
{
	int i=index;
	int leftchild;
	int rightchild;
	int large,temp;

	while(i<size)
	{
        leftchild= (2*i + 1); // write inside loop , i changes
	    rightchild= (2*i +2); // because updation is necessary
		large=i; // initializing index i as large in starting

		if(leftchild<size && arr[leftchild]> arr[i])
		{
			 large = leftchild; // if leftchild is larger then index , store its index
		}
		if(rightchild<size && arr[rightchild]>arr[large])
		{
			large = rightchild; // if rightchild is larger then index , store its index
		}
		if(large!=i)
		{
			temp=arr[i];
			arr[i]=arr[large];
			arr[large]=temp;
		}
		else
		{
			break;
		}
		i=large; // update i
    }
}

void minheapify(int index,int size)
{
	int i=index;
	int leftchild;
	int rightchild;
	int small,temp;

	while(i<size)
	{
        leftchild= (2*i + 1); // write inside loop , i changes
	    rightchild= (2*i +2); // because updation is necessary
		small=i; // initializing index i as large in starting

		if(leftchild<size && arr[leftchild]< arr[i])
		{
			 small = leftchild; // if leftchild is larger then index , store its index
		}
		if(rightchild<size && arr[rightchild]>arr[small])
		{
			small = rightchild; // if rightchild is larger then index , store its index
		}
		if(small!=i)
		{
			temp=arr[i];
			arr[i]=arr[small];
			arr[small]=temp;
		}
		else
		{
			break;
		}
		i=small; // update i
    }
}


void maxheap(int size)
{
	//int size= sizeof(arr); // wrong to count size --- output=28
	
	int lastnode=size-1;
	int parent = (lastnode-1)/2;
	int i;
	for(i=parent;i>=0;i--)
	{
		maxheapify(i,size);
	}	
}

void insertion(int* size)
{
	int ele,i;
	printf("enter the element to be inserted\n");
	scanf("%d",&ele);
	*size=*size+1;
	int lastnode=*size-1;
	arr[lastnode]=ele;
	
	for(i=lastnode;i>=0;i--) //instead of writinf for loop twice, function create kr sakte hai
	{
		int parent= (i-1)/2;
		if(arr[parent]<arr[i])
		{
			int temp;
			temp=arr[parent];
			arr[parent]=arr[i];
			arr[i]=temp;
		}
	}
	for(i=lastnode;i>=0;i--)
	{
		int parent= (i-1)/2;
		if(arr[parent]<arr[i])
		{
			int temp;
			temp=arr[parent];
			arr[parent]=arr[i];
			arr[i]=temp;
		}
	}
}

void minheap(int size)
{
	int lastnode=size-1;
	int parent = (lastnode-1)/2;
	int i;
	for(i=parent;i>=0;i--)
	{
		minheapify(i,size);
	}	
}

void minheapsort(int size)
	{
		int i,temp;
		minheap(size);
		for(i=size-1;i>=0;i--)
		{
			temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
			//size=size-1;
			minheapify(0,i);
		}
		
	}

void main()
{
	//int arr[7] = {10,25,20,30,35,70,7} ;
    //printf("\n%d\n",sizeof(arr)/sizeof(arr[0]));
	int n = 7;
	int j,k;
	//heapsort(&arr,n);
	while(1)
	{
		printf("enter 1)max heap 2)insert 3)min heap 4)minheapsort\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1: 
				maxheap(n);
				for(j=0;j<n;j++)
				{
					printf("%d\n",arr[j]);
				}
				break;
				
			case 2:
				insertion(&n);
				for(j=0;j<n;j++)
				{
					printf("%d\n",arr[j]);
				}
				break;
				
			case 3:
				minheap(n);
				break;
				
			case 4:
				minheapsort(n);
				break;
		}
	}
	
}
