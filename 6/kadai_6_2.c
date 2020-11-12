#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#define SWAP(a, b) \
  {                \
    temp = (a);    \
    (a) = (b);     \
    (b) = temp;    \
  }
/* 行列の最大次数 */ 
#define NEQ 16 
typedef double ElemType;
/* ガウス・ジョルダン法で演算を行う関数 */ 
int gauss_jordan(
  int n,
  ElemType a[NEQ][NEQ],
  ElemType b[NEQ],
  ElemType inv_a[NEQ][NEQ]
  ){
  /* カウンタ */
  int icol,i, j;
  /* SWAP 作業用変数 */ 
  ElemType temp;
  /* 行列の次数 */
  /* 係数 (n次正方行列) 配列 */
  /* 右辺値 (列ベクトル) 配列 */ /* 逆行列の結果を格納する配列 */
  /* 逆行列演算用の単位行列を作成する */ for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      inv_a[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }
  /* 各列を順番に処理する */
  for (icol = 0; icol < n; icol++)
  {
    int pivot_row;
    /* 列の最大値の成分を探索し、ピボット行候補とする */ {
      ElemType big = 0.0;
      for (i = icol; i < n; i++)
      {
        if (fabs(a[i][icol]) > big)
        {
            big = fabs(a[i][icol]);
            pivot_row = i;
        }
      }
      /* ピボット成分が、演算丸め誤差の分を考慮して、 きわめて 0 に近ければエラー終了とする */
      if (fabs(big) < 1e-10)
      {
        return -1;
      }
    }
    /* ピボット行の入れ替え処理 */ if (icol != pivot_row)
    {
      for (i = 0; i < n; i++)
      {
        SWAP(a[icol][i], a[pivot_row][i]);
        SWAP(inv_a[icol][i], inv_a[pivot_row][i]);
      }
      SWAP(b[icol],b[pivot_row]);
    }
    /* 対角成分を 1 にする */
    {
      ElemType inv_pivot = 1.0 / a[icol][icol];
      for (i = 0; i < n; i++)
      {
        a[icol][i]  *= inv_pivot;
        inv_a[icol][i] *= inv_pivot;
      }
      b[icol] *= inv_pivot;
    }
    /* ピボット列の対角成分以外を 0 にする */ 
    for (i = 0; i < n; i++)
    {
      if (i != icol)
      {
        ElemType refvalue = a[i][icol];
        for (j = 0; j < n; j++)
        {
          a[i][j] -= refvalue * a[icol][j];
          inv_a[i][j] -= refvalue * inv_a[icol][j];
        }
        b[i] -= refvalue * b[icol];
      }
    }
  }

  return 0;
}
/* 使用する行列の型宣言 */ typedef struct
{
  /* 正方行列の要素数 */ int n;
  /* 係数(正方行列) */ ElemType mat[NEQ][NEQ]; /* 右辺(列ベクトル) */
  ElemType vec[NEQ];
  /* 逆行列演算 */
  ElemType rev[NEQ][NEQ];
} Matrix;
/* 行列データの定義 */ Matrix testData[] = {
    {3, {{2, 1, 2}, {3, 2, 0}, {1, 2, 2}}, {6, -1, 3}},
    {3, {{2, 1, 2}, {2, 4, 4}, {1, 2, 2}}, {6, -1, 3}},
    {4, {{2, 2, 3, 4}, {1, 0, 2, 1}, {-1, 2, 1, 2}, {2, 1, 4, 0}}, {6, 3, -1, 0}}};
/* データ数 */

const int dataSize = sizeof(testData) / sizeof(Matrix);
int main()
{
  int idx;
  for (idx = 0; idx < dataSize; idx++)
  { /* カウンタ */
    int i, j;
    /* 行列データ */
    Matrix data = testData[idx];
    /* ガウス・ジョルダン法による連立方程式の解法 */
    int retcode = gauss_jordan(data.n, data.mat, data.vec, data.rev);
    printf("retcode: %d\n", retcode);
    if (retcode == 0)
    {
      /* 行列成分値の表示 */
      for (i = 0; i < data.n; i++)
      {
        for (j = 0; j < data.n; j++)
        {
          printf("%8.3f", data.mat[i][j]);
        }
        printf(" %8.3f ", data.vec[i]);
        for (j = 0; j < data.n; j++)
        {
          printf("%8.3f", data.rev[i][j]);
        }

        printf("\n");
      }
    }
  }
  return 0;
}