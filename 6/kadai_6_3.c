#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
/* 行列の最大次数 */ 
#define NEQ 16 
typedef double ElemType;
int Jacobi(int n,
           /* 行列の次数 */
           /* 入力値 (正方対称行列)配列 */ /* 固有ベクトル格納配列 */
           /* 繰り返し処理上限回数 */      /* 収束判定の閾値 */
                                           /* 回転作業用行列 */
                                           /* 固有ベクトル作業配列 */
           ElemType A[NEQ][NEQ],
           ElemType X[NEQ][NEQ])
{
  const int maxloop = 1000;
  const double eps = 1.0e-6;
  ElemType A2[NEQ][NEQ];
  ElemType X2[NEQ][NEQ];
  int i, j, cnt = 0;
  /* カウンタ */
  /* 固有ベクトル計算用単位行列のセット */ 
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      X[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }
  /* 繰り返し処理 */
  for (cnt = 0; cnt < maxloop; cnt++)
  {
    /* p, q 変数 */
    int p = 0, q = 0; /* sin, cos 変数 */
    ElemType sn, cs;
    /* 非対角要素の最大要素の探索 */ 
    ElemType max = 0.0;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (i != j)
        {
          if (fabs(A[i][j]) > max)
          {
            /* 最大値、位置インデックスの保持 (p < q) */ 
            max = fabs(A[i][j]);
            q = i;
            p = j;
          }
        }
      }
    }
    /* 収束判定閾値より小さくなれば処理終了 */ 
    if (max < eps)
     return 0;

    {
      ElemType alpha = 0.5 * (A[p][p] - A[q][q]);
      ElemType beta = -A[p][q];
      ElemType gamma = fabs(alpha)/sqrt(alpha*alpha+beta*beta);
      cs = sqrt(0.5 * (1.0 + gamma));
      sn = sqrt(0.5 * (1.0 - gamma));
      if (alpha * beta < 0)
        sn = -sn;
    }
    /* 行列に回転演算を施して、要素を 0 にする処理 */ 
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if ((i == p || i == q) && (j == p || j == q))
        {
          if (i == p && j == p)
            /* App の計算 */
            A2[i][j] = cs*(cs*A[p][p]-sn*A[p][q])-sn*(cs*A[p][q]-sn*A[q][q]);
          else if (i == q && j == q)
            /* Aqq の計算 */
            A2[i][j] = sn*(sn*A[p][p]+cs*A[p][q])+cs*(sn*A[p][q]+cs*A[q][q]);
          else
            /* Apq, Aqp の計算 */
            A2[i][j] = sn*(cs*A[p][p]-sn*A[p][q])+cs*(cs*A[p][q]-sn*A[q][q]);
        }
        else if (i == p || j == p)
        {
          /* Api, Aip の要素の計算 */
          int k = (j == p) ? i : j;
          A2[i][j] = cs*A[k][p]-sn*A[k][q];
        }
        else if (i == q || j == q)
        {
          /* Aqi, Aiq の要素の計算 */
          int k = (j == q) ? i : j;
          A2[i][j] = sn*A[k][p]+cs*A[k][q];
        }
        else
        A2[i][j] = A[i][j];
      }
    }
    
    /* 固有ベクトル値の計算 */ for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (j == p)
          X2[i][p] = X[i][p] * cs - X[i][q] * sn;
        else if (j == q)
          X2[i][q] = X[i][q] * cs + X[i][p] * sn;
        else
          X2[i][j] = X[i][j];
      }
    }
    /* 作業領域からの書き戻し */
    for (i = 0; i < n; i++)
    {

      for (j = 0; j < n; j++)
      {
        A[i][j] = A2[i][j];
        X[i][j] = X2[i][j];
      }
    }
  }
  return -1;
}
/* 使用する行列の型宣言 */ typedef struct
{
  /* 正方行列の要素数 */
  int n;
  /* 正方行列 (対称行列) */ ElemType mat[NEQ][NEQ];
  /* 固有ベクトル (列ベクトル) */ ElemType vec[NEQ][NEQ];
} Matrix;
/* 行列データの定義 */ Matrix testData[] = {
    {3, {{1, 3, 0}, {3, 2, 1}, {0, 1, 3}}},
    {4, {{0, 2, 1, 2}, {2, 3, 0, 0}, {1, 0, 0, 1}, {2, 0, 1, 0}}},

    {4, {{0, 1, 0, 1}, {1, 2, 0, 1}, {0, 0, 0, 0}, {1, 1, 0, 0}}}};
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
    printf("--------------\n"); /* 入力行列の表示 */
    printf("Matrix\n");
    for (i = 0; i < data.n; i++)
    {
      for (j = 0; j < data.n; j++)
      {
        printf("%8f ", data.mat[i][j]);
      }
      printf("\n");
    }
    /* Jacobi 法による、固有値・固有ベクトルの導出 */ 
    int retcode = Jacobi(data.n, data.mat, data.vec);
    printf("retcode: %d\n", retcode);
    if (retcode < 0)
      printf("Matrix Does Not Converge.\n");
    else if (retcode == 0)
    {
      /* 対角要素の表示 */ printf("Eigenvalue\n");
      for (i = 0; i < data.n; i++)
        printf(" %8f ", data.mat[i][i]);
      /* 列ベクトルの表示 */ printf("\nEigenvector\n");
      for (i = 0; i < data.n; i++)
      {
        for (j = 0; j < data.n; j++)
        {
          printf("%8f ", data.vec[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}