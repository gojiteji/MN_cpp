#include <stdio.h> 
#include <math.h>
#define M_PI 3.14159265358979323846264338327
const int N_MAX = 64;
void fft(int n, float arr_r[], float arr_i[]) {
float ev_r[N_MAX], ev_i[N_MAX]; /* 偶数成分 FFT 部分系列 */ 
float od_r[N_MAX], od_i[N_MAX]; /* 奇数成分 FFT 部分系列 */
/* 回転因子の角度 */
float theta = 2 * M_PI / n; /* カウンタ */
int nh, j;
    if (n <= 1)
        return;
/* N/2 */
  nh = n / 2;
for (j=0;j<nh-1;j++) {
float xr, xi, wr, wi;
/* 偶数成分を計算し、格納する */ 
ev_r[j] = arr_r[j] + arr_r[nh + j];
ev_i[j] = arr_i[j] + arr_i[nh + j];
 /* 奇数成分を計算する */
xr =  arr_r[j] - arr_r[nh + j];
xi =  arr_i[j] - arr_i[nh + j];
/* 係数を求める */
wr =   (ev_r[j]+xr)*cos(theta);
wi =   (ev_i[j]+xi)*cos(theta);
/* 奇数成分に係数を乗じて、格納する */ od_r[j] = xr * wr - xi * wi;
od_i[j] = xi * wr + xr * wi;
}
/* 偶数成分の FFT を帰納的に求める */ fft(n, ev_r,ev_i);
/* 奇数成分の FFT を帰納的に求める */ fft(n, od_r,od_i);
/* 得られた FFT 部分系列を書き戻す */ for (j = 0; j < nh; j++) {
arr_r[2 * j] = ev_r[j]; /* 偶数成分 実数部分 */ 
arr_i[2 * j] = ev_i[j]; /* 偶数成分 虚数部分 */

arr_r[2 * j+1] = od_r[j]; /* 奇数成分 実数部分 */
arr_i[2 * j+1] = od_i[j]; /* 奇数成分 虚数部分 */
 } 
}
int main() {
float x[N_MAX], y[N_MAX]; 
const int n = 64;
    int i;
    for (i = 0; i < n; i++) {
x[i] = sin(4 * 2 * M_PI * i / n);
y[i] = 0; }
/* FFT */ fft(n, x, y);
for (i = 0; i < n; i++) {
printf("%d %8f %8f\n", i, x[i], y[i]);
}
return 0; }