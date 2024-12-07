//버블 정렬= 원소개수 -1 번만큼 반복
//앞에서부터 두개씩 비교해나가면서 위치 변경
#include <iostream>
#define Swap(x,y) (x!=y) && (x ^= y ^= x ^= y)
void OutPut(int Arr[]) {
    for(int i = 0; i < 6; ++i) 
        std::cout << Arr[i] << " ";
    }
void BubbleSort(int Arr[]){
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5 - i; ++j)
        {
            if (Arr[j] > Arr[j + 1])
            {Swap(Arr[j], Arr[j + 1]);}
        }
    }
    OutPut(Arr);
}
int main()
{
int Arr[6] = {5,7,2,6,9,3};
OutPut(Arr);
std::cout << std::endl;
BubbleSort(Arr);
}