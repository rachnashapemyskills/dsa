#include<iostream>
using namespace std;
int linear_search(int arr[], int len, int key){
	if(len==0){
		return -1;
			}	
	else if(arr[len-1]==key){
		return len-1;
	}
	else{
		int ans = linear_search(arr, len - 1, key);
		return ans;
	}
}

int main(){
	
	int arr[]= {12,23,45,43,33,65};
	int ser_val, res;
	cout<<"\n Size of array : "<<sizeof(arr)/4<<"\n";
	int len =sizeof(arr)/4;
	for(int i=0; i<len; i++){
		cout<<" "<<arr[i]<<"\t";
	}
	cout<<"\n Enter the value : ";
	cin>>ser_val;
	
	res = linear_search(arr, len, ser_val);
	
	if(res==-1){
		cout<<"\n "<<ser_val<<" not found in the list ";
	}
	else{
		cout<<"\n "<<ser_val<<" is Found ";
	}	
}
