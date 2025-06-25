#include <cstdio>  // C++ version of stdio.h
#include <vector>  // For std::vector


using namespace std;
int main(){
    int n,k;
    vector<int> factors;
    long long res = 1;
    scanf("%d %d",&n,&k);
    int temp_n = n;
    while(temp_n%2 == 0){
        factors.push_back(2);
        temp_n=temp_n/2;
    }
    
    
    for(int i=3;i*i<=temp_n;i=i+2)
    {   while(temp_n%i==0){
            factors.push_back(i);
            temp_n = temp_n/i;
        }
        
    }
    if(temp_n > 1){
        factors.push_back(temp_n);
    }
  
    if(factors.size() >=k){
        for(int i=0;i<k-1;i++){
            printf("%d ",factors[i]);
            res = res * factors[i];
        }
        printf("%lld ", (long)n/res);
    }else{
        printf("-1\n");
    }
    return 0;


}