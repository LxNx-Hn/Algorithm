#include <iostream>
void Swap(int x,int y) {
    int temp;
    if (x != y){
        temp=x;
        x=y;
        y=temp;
    }
}
    
void OutPut(int Arr[],int len) {
    for(int i = 0; i < len; i++) 
        std::cout << Arr[i] << " ";
    }
void BubbleSort(int Arr[],int n){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (Arr[j] > Arr[j + 1])
            {Swap(Arr[j], Arr[j + 1]);}
        }
    }
}
int main()
{
int Arr[] = {3,24,44,58,5,14};
int len= sizeof(Arr)/sizeof(int);
OutPut(Arr,len);
BubbleSort(Arr,len-1);
std::cout << std::endl;
OutPut(Arr,len);
}



