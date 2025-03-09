#include<iostream>
using namespace std;
    int node (int arr[],int n){
    	int max=arr[0];
    	for(int i=1;i<n;i++){
    		if(arr[i]>max){
    			max=arr[i];
			}else{
				cout<<"invalid value"<<endl;
			}
		}
		return max;
	}
int main()

{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n =sizeof(arr)/sizeof(arr[0]);
	cout<<"max value = "<<node(arr,n)<<endl;
	
	
}