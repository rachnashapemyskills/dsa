#include<iostream>
    using namespace std;
    void merge(int a[], int beg, int mid, int end)
    {
        int i,j,k;
        int n1=mid-beg+1;
        int n2=end-mid;
        
        int LeftArray[n1],RightArray[n2];//temporaryarrays
        
        
        for(int i=0;i<n1;i++)
        {
        	LeftArray[i]=a[beg+i];	
        	cout<<"\n Left Array = "<<LeftArray[i]<<"\n";
        	
		}
        
        
        for(int j=0;j<n2;j++)
        {
        		RightArray[j]=a[mid+1+j];
        		cout<<"\n Right Array  = "<<RightArray[j]<<"\n";
		}
        
    
	        i=0;
	        j=0;
	        k=beg;
	    while(i<n1&&j<n2)
	        {
		        if(LeftArray[i]<=RightArray[j])
		        {   
		            a[k]=LeftArray[i];
		            cout<<"\nLeft  A[k] = "<<a[k]<<"\n";
		            i++;
		        }
	        else
	        {   
	            a[k]=RightArray[j];
	            cout<<"\nRight   A[k] = "<<a[k]<<"\n";
	            j++;
	   		 }
	    	k++;
	    }
	    while(i<n1)
	    {
		    a[k]=LeftArray[i];
		    i++;
		    k++;
	    }
	    
	    while(j<n2)
	    {
		    a[k]=RightArray[j];
		    j++;
		    k++;
	    }
    }
    
    
    
    
    
    void mergeSort(int a[],int beg,int end)
    {
	    if(beg<end)
	    {
		    int mid=(beg+end)/2;
		    cout<<"\n Mid Value  = "<<mid<<"\n";
		    mergeSort(a,beg,mid);
		    cout<<"\n******************************************\n";
		    
			mergeSort(a,mid+1,end);
		    cout<<"\n*************** Calling Merge ************************ \n";
		    
		    merge(a,beg,mid,end);
	    }
    }
    
    /*Functiontoprintthearray*/
    void printArray(int a[],int n)
    {
    int i;
    cout<<"\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    }
    
    
    int main()
    {
        int n;
        cout<<"\n Enter the number of Array : ";
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        printArray(arr , n);
        
        mergeSort(arr,0,n);
        printArray(arr,n);
        return 0;
        
        
        
        
        
    }
