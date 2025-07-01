
#include<stdio.h>
#include<string.h>


int main(){

    char a[100];
    scanf("%s",a);
    
    int len = strlen(a);
    for(int i=0;i<len;i++){
        if(a[i]-'0' == 8|| a[i]-'0' == 0){
            printf("YES\n");
            printf("%d\n",a[i] - '0');
            return 0;
        }
    }

    for(int i=0;i<len;i++){
        if(a[i]=='0') continue;
        
        for(int j=i+1;j<len;j++){
            int num = (a[i] - '0') * 10 + (a[j] - '0');
            if(num %8 == 0){
                printf("YES\n");
                printf("%d\n",num);
                return 0;
            }
        }
    }

    for(int i=0;i<len;i++){
        if(a[i]=='0') continue;
        for(int j=i+1;j<len;j++){
            for(int k=j+1;k<len;k++){
                int num = (a[i] - '0') * 100 + (a[j] - '0') * 10 + (a[k]-'0');
                if(num %8 == 0){
                    printf("YES\n");
                     printf("%d\n",num);
                    return 0;
                }
            }
        }
    }

    printf("NO\n");

    return 0;
}