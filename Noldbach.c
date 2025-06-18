/**
 * 
 * A. Noldbach problem
time limit per test2 seconds
memory limit per test64 megabytes
Nick is interested in prime numbers. Once he read about Goldbach problem. It states that every even integer greater than 2 can be expressed as the sum of two primes. That got Nick's attention and he decided to invent a problem of his own and call it Noldbach problem. Since Nick is interested only in prime numbers, Noldbach problem states that at least k prime numbers from 2 to n inclusively can be expressed as the sum of three integer numbers: two neighboring prime numbers and 1. For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1.

Two prime numbers are called neighboring if there are no other prime numbers between them.

You are to help Nick, and find out if he is right or wrong.

Input
The first line of the input contains two integers n (2 ≤ n ≤ 1000) and k (0 ≤ k ≤ 1000).

Output
Output YES if at least k prime numbers from 2 to n inclusively can be expressed as it was described above. Otherwise output NO.

Examples
InputCopy
27 2
OutputCopy
YES
InputCopy
45 7
OutputCopy
NO
Note
In the first sample the answer is YES since at least two numbers can be expressed as it was described (for example, 13 and 19). In the second sample the answer is NO since it is impossible to express 7 prime numbers from 2 to 45 in the desired form.
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int binary_search(int *new_array,int target,int index){

    int start = 0, end = index-1;
    while(start<=end){
        int mid = (start + end)/2;
        if(new_array[mid] == target){
            return 1;
        }
        else if(new_array[mid] > target){
            end = mid -1;
        }else{
            start = mid + 1;
        }
    }
    return 0;
}

void sieve_of_eratosthenes(int *arr,  int n,int k,int *count){
    
    for(int i=2;i<=n;i++){
        if(arr[i] == 1){
            (*count)++;
           
            for(long j= i*i;j<=n;j=j+i){
                arr[j] = 0;
            }
        }
        
    }
   
    
}



int main(){

    int n,k;
    int count = 0;
    scanf("%d %d",&n,&k);
    int *arr = malloc((n+1) * sizeof(int));
    /** initialize the array */
    
    for(int i=0;i<=n;i++){
        if(i==0 || i==1){
            arr[i] = 0;
        }else{
            arr[i]= 1;
        }
        
    } 

    sieve_of_eratosthenes(arr,n,k,&count);
    
    int *new_array = malloc(count * sizeof(int));
    int index =0;
    int _k = 0;
    for(int i=0;i<=n;i++){
        if(arr[i]==1){
            new_array[index++] = i;
            
        }
    }

   

    for(int i=1;i<index;i++){
        
        // if(binary_search(new_array,new_array[i-1]+new_array[i] + 1,index)){
        //     // printf("%d ",new_array[i-1]+new_array[i]+1);
        //     _k++;
        // }
        int sum = new_array[i-1] + new_array[i] + 1;
        if(sum <=n && arr[sum] == 1){
            _k++;
        }

    }

    if(_k>=k){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;

}