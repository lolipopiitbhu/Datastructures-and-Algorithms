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

void reverse(int arr[], int start, int end) {
	int temp;
	while(start < end){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
void leftRotateByReversal(int arr[], int n, int d) {
	if(d==0 || d%n==0){
		return;
	}
	d=d%n;
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);

}

void swap(int arr[],int ai, int bi, int an) {
    int i,temp;
    for(i=0;i<an;i++) {
        temp = arr[ai];
        arr[ai] = arr[bi];
        arr[bi] = temp;
        ai++;
        bi++;
    }
}

void block_rotate_util(int arr[], int ai, int an, int bi, int bn){
    if(an==0 || bn==0) {
        return;
    }
    if(an==bn){
        swap(arr,ai,bi,an);
        return;
    }
    if(an<bn){
        int bli,bln,bri,brn;
        bli=bi;
        bln=bn-an;
        bri=bli+bln;
        brn=an;
        swap(arr,ai,bri,an);
        block_rotate_util(arr,ai,an,bli,bln);
        return;
    }
    if(an>bn){
        int ali,aln,ari,arn;
        ali=ai;
        aln=bn;
        ari=ali+aln;
        arn=an-bn;
        swap(arr, ai,bi,bn);
        block_rotate_util(arr,ari,arn,bi,bn);
    }
}

void block_rotate(int arr[], int n, int d) {
    d=d%n;
	block_rotate_util(arr,0,d,d,n-d);
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