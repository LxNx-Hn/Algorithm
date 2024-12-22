//nxn의 행렬이 주어질때, 왼쪽위에서 시작해 x,y에 이르는 모든 경로들의 합이 가장 큰경우, 경로는 오른쪽, 아래쪽방향으로만 이동이 가능함
#include <stdio.h>
#define SIZE 5

int arr[SIZE][SIZE] = {
    { 1, 4, 2, 5, 7 },
    { 13, 8, 11, 6, 10 },
    { 2, 6, 12, 1, 9 },
    { 3, 8, 16, 12, 18 },
    { 17, 4, 7, 15, 14 }
};
/*  해당 경로까지의 최고합을 제시함
1   5   7   12  19
14  22  33  39  49
16  28  45  46  58
19  36  61  73  91
36  40  68  88  105
*/

void out(int arr[SIZE][SIZE]){
     for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void Max(int x, int y) {
    int dp[SIZE][SIZE] = {0};
    dp[0][0] = arr[0][0];
    for (int j = 1; j <= y; j++) {
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    }
    for (int i = 1; i <= x; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            dp[i][j] = arr[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
                            //위쪽경로와 아래쪽경로를 비교해서 더큰경로합에 현재값을 더해줌
        }
    }
    printf("(%d, %d)로의 최대 경로 합: %d\n", x, y, dp[x][y]);
    out(dp);
    printf("변환행렬");
}

void Matrix() {
    int x, y;
    printf("목표 위치 x와 y를 입력하세요 최대 값: %d: ", SIZE - 1);
    scanf("%d %d", &x, &y);
    if (x >= SIZE || y >= SIZE || x < 0 || y < 0) {
        printf("잘못된 목표 위치입니다. 프로그램을 종료합니다.\n");
        return;
    }


    printf("원래 행렬:\n");
    out(arr);
    Max(x, y);
}

int main() {
    Matrix();
    return 0;
}
