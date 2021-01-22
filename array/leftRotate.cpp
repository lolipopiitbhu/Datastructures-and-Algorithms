#include <iostream>
using namespace std;
/*Fuction to get gcd of a and b*/
int gcd(int a, int b){
	if (b == 0) 
    return a; 
  else
    return gcd(b, a % b); 
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
	/* To handle if d >= n */
	d = d % n; 
	int g_c_d = gcd(d, n); 
	for (int i = 0; i < g_c_d; i++) { 
		/* move i-th values of blocks */
		int temp = arr[i]; 
		int j = i; 

		while (1) { 
			int k = j + d; 
			if (k >= n) {
				k = k - n; 
			}
			if (k == i) {
				break; 
			}
			arr[j] = arr[k]; 
			j = k; 
		} 
		arr[j] = temp; 
	} 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,d,i;
		cin>>n>>d;

		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];

		leftRotate(a,d,n);
		
		for(i=0;i<n;i++)
		cout << a[i] << " ";
		cout<<endl;
	}
	return 0;
}