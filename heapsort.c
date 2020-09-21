	#include<stdio.h>
	
	int arr[7] = {10,25,20,30,35,70,7} ;
	
	/*void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b=temp;
	}*/
	
	void heapify(int index,int size)
	{
		int i=index;
		int leftchild;
		int rightchild;
		int large;
		while(i<size)
		{
			leftchild= (2*i + 1);
			rightchild= (2*i +2);
			large=i;
			if(leftchild<size && arr[leftchild]> arr[i])
			{
				 large = leftchild;
			}
			if(rightchild<size && arr[rightchild]>arr[large])
			{
				large = rightchild;
			}
			int temp;
			if(large!=i)
			{
				int temp=arr[i];
				arr[i]=arr[large];
				arr[large]=temp;
				
				heapify(large,size);
			}
			else
			{
				break;
			}
			i=large;
	}
	}
	
	void maxheap(int size)
	{
		//int size= sizeof(arr);
		
		int lastnode=size-1;
		int parent = (lastnode-1)/2;
		int i;
		for(i=parent;i>=0;i--)
		{
			heapify(i,size);
		}	
	}
	
	
	void heapsort(int size)
	{
		int i,temp;
		maxheap(size);
		for(i=size-1;i>=0;i--)
		{
			temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
			//size=size-1;
			heapify(0,i);
		}
		
	}
	
	void main()
	{
		//int arr[7] = {10,25,20,30,35,70,7} ;
		int n = sizeof(arr)/sizeof(arr[0]) ;
		int j;
		heapsort(n);
		//maxheap(n);
		//printf("\n%d\n",sizeof(arr)/sizeof(arr[0]));
		//arr[0]++;
		for(j=0;j<n;j++)
		{
			printf("%d\n",arr[j]);
		}
	//return;	
	}

