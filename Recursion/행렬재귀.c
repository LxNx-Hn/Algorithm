#include <stdio.h>
#define SIZE 5
int arr[SIZE][SIZE] = {
    { 1, 4, 2, 5, 7 },
    { 13, 8, 11, 6, 10 },
    { 2, 6, 12, 1, 9 },
    { 3, 8, 16, 12, 18 },
    { 17, 4, 7, 15, 14 }
};
void out(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int Max(int x,int y){return(x>y)?x:y;}

int Matrix(int x, int y) {
    //둘다 0인경우
    if (x==0 && y==0) return arr[0][0];
    //하나만 0인경우
    else if (y==0) return arr[x][y]+Matrix(x-1,y);
    else if (x==0) return arr[x][y]+Matrix(x,y-1);
    //둘다 1이상일경우
    else return arr[x][y]+ Max(Matrix(x,y-1),Matrix(x-1,y));
}

int main() {
    int x, y;
    //out(arr);
    printf("목표 위치 x와 y를 입력하세요 (최댓값: %d): ", SIZE - 1);
    scanf("%d %d", &x, &y);
    printf("최대합: %d\n", Matrix(x, y));
    return 0; 
}
