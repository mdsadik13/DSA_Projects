#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void add(char* a,char* b,char* c){
    int n2=strlen(b);
    int carry=0;
    int i=0;
    while(a[i]!='\0')
    {
        int num=(a[i]-'0')+(b[i]-'0')+carry;
        carry=num/10;
        num=num%10;
        char ch=num+'0';
        c[i]=ch;
        i++;
    }
    while(i<n2)
    {
        int num=(b[i]-'0')+carry;
        carry=num/10;
        num=num%10;
        char ch=num+'0';
        c[i]=ch;
        i++;
    }
    if (carry>0)
    {
        char ch=carry+'0';
        c[i]=ch;
        i++;
    }
    c[i]='\0';
}

void fibonnaci(int N){
    if(N==0||N==1){
       printf("%d",N);
    }
    else{
        char a[1000]="0";
        char b[1000]="1";
        char c[1000];
        for (int i = 2; i<=N; i++)
        {
          add(a,b,c);
          int j=0;
          while(b[j]!='\0')
          {
              a[j]=b[j];
              b[j]=c[j];
              j++;
          }
          a[j]='\0';
          while (c[j]!='\0')
          {
              b[j]=c[j];
              j++;
          }
          b[j]='\0';
          
        }
        int n=strlen(c);
        char* res=malloc(sizeof(char)*n);
        int i=0;
        while(c[i]!='\0')
        {
            res[i]=c[n-(i+1)];
            i++;
        }
        res[i]='\0';
       
        puts(res);
        printf("%d",i);
       
    }
}
int main(){
    int N;
    scanf("%d",&N);
    fibonnaci(N);
   
    return 0;
}