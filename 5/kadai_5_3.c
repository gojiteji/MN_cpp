/*
* 無向グラフ 演習プログラム
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>/* 最大ノード数 */
#define MAXORDER 256
/* グラフを表す構造体 */
typedef struct {
	int ord; /* ノード数 */
	int adj[MAXORDER][MAXORDER]; /* 隣接行列 */
} Graph;
/* リストを表す構造体 */
typedef struct {
	int elem[MAXORDER];
} List;
/* 経路情報を表す構造体 */
typedef struct {
	int length;
	List path_list;
} PathData;
/*
*関数プロトタイプ
*/
/* 長さ n、全てのメンバー v のリストを返す */
List initializeList(int val);
/* startNode から goalNode への最短経路を求める */
PathData calcDijkstra(Graph *grp, int start_node, int goal_node);
/* グラフの隣接行列を画面表示する */
void printGraph(Graph *grp);
/* 経路情報リスト(逆順)から、経路を表示する */
void printPath(PathData path, int start_node, int goal_node);
/*
*関数定義
*/
/* 長さ n、全てのメンバー v のリストを返す */
List initializeList(int val)
{
	List t;
	int i;
	for (i = 0; i < MAXORDER; i++)
	t.elem[i] = val;
	return t;
}
/* start_node から goal_node への最短経路を求める */
PathData calcDijkstra(Graph *grp, int start_node, int goal_node)
{
	List temp_list; /* 作業用距離リスト */
	List dist_list; /* 確定距離リスト */
	List link_list; /* 探索ノードに隣接するノードのリスト */
	PathData path;
	/* 最短経路情報を保持するリスト */
	int cur_node = start_node;
	/* カレント探索ノード */
	int next_node;
	temp_list = initializeList(INT_MAX);
	path.path_list = initializeList(-1);
	dist_list = initializeList(-1);
	dist_list.elem[start_node] = 0;do {
	int i;
	int distance;
	int index = 0;
	/*
	* 探索ノードに隣接するノードのリストを作成する
	*/
	for (i = 0; i < grp->ord; i++)
		/* 距離未確定地点に到達可能であれば、次候補としてリストアップする */
		if (dist_list.elem[i] == -1 && grp->adj[cur_node][i] > 0)
			link_list.elem[index++] = i;
	/*
	* 先頭ノードから次候補先までの距離を仮計算する (作業用距離リスト)
	*/
	for (i = 0; i < index; i++) {
		int next = link_list.elem[i];
		/* 距離計算 (確定部分+リンク距離) */
		distance =/*/////////*/dist_list.elem[cur_node]+grp->adj[cur_node][next] ;/*/////////*/
		if (distance < temp_list.elem[next]) {
			/* より短い距離の経路が見つかった場合 */
			temp_list.elem[next]= distance;
			/* 隣接ノードでの最短経路情報を登録する */
			path.path_list.elem[next] = cur_node;
		}
	}
	/*
	* 次探索ノード候補: 現ノードから最短距離のものを探す
	*/
	next_node = -1;
	distance = INT_MAX;
	for (i = 0; i < grp->ord; i++)
		if (dist_list.elem[i] == -1)
			if (temp_list.elem[i] < distance) {
				/* より短い距離の次探索ノード候補 */
				distance =/*/////////*/temp_list.elem[i];/*/////////*/
				next_node = i;
			}
	if (next_node >= 0) {
		/* 現ノードから最短距離のノード確定、next_node を次の探索ノードに */
		dist_list.elem[/*/////////*/next_node/*/////////*/] = temp_list.elem[next_node];
		cur_node = next_node;
	}
	} while (next_node >= 0 && cur_node != goal_node);
	if (cur_node == goal_node) {
		path.length = dist_list.elem[goal_node];
		return /*/////////*/path;/*/////////*/
	}else {
		/* ゴールまでの経路が見つからなかった場合 */
		path.length = -1;
		return /*/////////*/path;/*/////////*/
	}
}
/*********************************************************/
/* 探索するグラフのデータ */
Graph graphdata = {10, {
/*A  B  C  D  E  F  G  H  I  J*/
{ 0, 2, 2, 3, 3, 0, 0, 0, 0, 0 }, /*A*/
{ 2, 0, 2, 0, 0, 0, 0, 0, 4, 0 }, /*B*/
{ 2, 2, 0, 1, 0, 2, 0, 0, 0, 0 }, /*C*/
{ 3, 0, 1, 0, 0, 0, 1, 0, 0, 0 }, /*D*/
{ 3, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, /*E*/
{ 0, 0, 2, 0, 0, 0, 0, 1, 1, 0 }, /*F*/
{ 0, 0, 0, 1, 1, 0, 0, 2, 0, 0 }, /*G*/
{ 0, 0, 0, 0, 0, 1, 2, 0, 0, 2 }, /*H*/
{ 0, 4, 0, 0, 0, 1, 0, 0, 0, 2 }, /*I*/
{ 0, 0, 0, 0, 0, 0, 0, 2, 2, 0 }/*J*/
}};
/* グラフの隣接行列を画面表示する */
void printGraph(Graph *grp)
{
	int i, j;
	for (i = 0; i < grp->ord; i++) {
	for (j = 0; j < grp->ord; j++)
	printf("%2d", grp->adj[i][j]);
	printf("\n");
	}
}
/* 経路情報リスト(逆順)から、経路を表示する */
void printPath(PathData path, int start_node, int goal_node)
{
	int i;
	int idx = 0;
	int pos = goal_node;
	List track_path;
	/* 逆順経路 */
	/* 距離を表示 */
	printf("Length: %d\n", path.length);/* リストに、ゴール地点から逆順で地点データを追加する */
	track_path.elem[idx++] =/*/////////*/pos;/*/////////*/
	do {
		/* ゴール地点から、最短隣接経路を辿っていく */
		pos = path.path_list.elem[/*/////////*/pos/*/////////*/];
		track_path.elem[idx++] =/*/////////*/pos;/*/////////*/
	} while (pos != -1 && pos !=/*/////////*/start_node/*/////////*/);

	printf("Path: ");
	for (i = idx - 1; i >= 0; i--) {
		/* リストを末尾から先頭に向かって表示する */
		printf("%d", track_path.elem[/*/////////*/i/*/////////*/]);
		if (i > 0)
			printf(" -> ");
	}
	printf("\n");
}
/***************************************/
int main()
{
	int start_node = 0; /* 出発点 */
	int goal_node = 9;
	/* 目的地 */
	/* 最短経路を求める */
	PathData path = calcDijkstra(&graphdata, start_node, goal_node);
	printf("\nGraph :\n");
	printGraph(&graphdata);
	if (path.length >= 0) {
		/* 最短経路が正しく計算された */
		printPath(path, start_node, goal_node);
	}
	else {
		printf("Unreachable\n");
	}
	return 0;
}
