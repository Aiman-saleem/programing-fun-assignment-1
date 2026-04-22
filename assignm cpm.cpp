#include<iostream>
#include<fstream>//file handling
using namespace std;
//function prototype
void inputArray(int arr[],int size);
void displayArray(int arr[],int size);
int calculateSum(int arr[],int size);
void write_to_file(int arr[],int size);
void read_from_file(int arr[],int size);
//part(A):input function
void inputArray(int arr[],int size){
	for(int i=0;i<size;i++)
	{
		cout<<"enter element"<<i+1<<":";
		cin>>arr[i];
	}
}
//part(B):display
void displayArray(int arr[],int size){
	cout<<"array element:";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//part(B):sum function
int calculateSum(int arr[],int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=arr[i];
	}
	return sum;
}
//part(C):write to file
void write_to_file(int arr[],int size){
	ofstream out_file("array.txt");
	if(out_file.is_open()){
		for(int i=0;i<size;i++){
			out_file<<arr[i]<<" ";
		}
		out_file.close();
		cout<<"data written to file succesfully\n";
	}
	else{
		cout<<"error opening file\n";
	}
}
//part(D):read from file
void read_from_file(int arr[],int size){
	ifstream in_file("array.txt");
	if(in_file.is_open()){
		for(int i=0;i<size;i++)
		{
			in_file>>arr[i];
		}
in_file.close();
cout<<"data read from file:\n";
displayArray(arr,size);
}
else{
	cout<<"error opening file\n";
}
}
//main function
int main(){
	const int SIZE=10;
	int arr[SIZE];
	//part(A)
	inputArray(arr,SIZE);
	//part(B)
	displayArray(arr,SIZE);
	//part(E):sum display
	int sum=calculateSum(arr,SIZE);
	cout<<"sum of array elements:"<<sum<<endl;
	//part(C)
	write_to_file(arr,SIZE);
	//part(D)
	read_from_file(arr,SIZE);
	return 0;
}

