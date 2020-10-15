/*
* B-Tree 演習プログラム
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ノード内の要素の型 */
typedef struct {
	char *key; /* key string*/
	char *value; /* data string */
} ElemType;
/* B-Tree ノードの型 */
typedef struct treenode {
	/* ノード内の要素 */ElemType left; /* 最初に格納されるデータ */
	ElemType right; /* 追加されたデータ (left < right) */
	/* 子孫ノードへのリンク */
	struct treenode *child_left;
	/* データ < left */
	struct treenode *child_center; /* left < データ < right */
	struct treenode *child_right;
	/* right < データ */
} TreeNode;
/*
*
関数プロトタイプ
*/
/* B-Tree のノードをメモリに割り当てる */
TreeNode *createNode();
/* B-Tree に ノードを追加する。
子孫から繰り上がりのノードがあれば、ノードポインタが返される */
TreeNode *insertNode(TreeNode *tree, char *key, char *value);
/* B-Tree に データを追加する。
Tree が NULL のとき、新規 Tree を作成する。 */
TreeNode *addTree(TreeNode *tree, char *key, char *value);/* B-Tree 表示関数 */
void printTree(TreeNode *p);
void listTree(TreeNode *p, int lv);
/*
*
マクロ定義
*/
#define SWAP(x,y) \
{\
void *temp; \
temp = (x); \
(x) = (y); \
(y) = temp; \
}
/*
*
関数定義
*/
/* B-Tree のノードをメモリに割り当てる */
TreeNode *createNode()
{
	TreeNode *tree = malloc(sizeof (TreeNode));
	if (tree != NULL) {
		/* メンバーの初期化 */
		tree->left.key = NULL;
		tree->left.value = NULL;
		tree->right.key = NULL;
		tree->right.value = NULL;
		tree->child_left = NULL;
		tree->child_center = NULL;
		tree->child_right = NULL;
	}
	return tree;
}
/* B-Tree に データを追加する。
Tree が NULL のとき、新規 Tree を作成する。 */
TreeNode *addTree(TreeNode *tree, char *key, char *value)
{
	if (tree == NULL) {
		/* Tree がない場合、新規作成する */
		tree = createNode();
	}
	if (tree != NULL) {/* ノードへのデータ追加処理本体 */
		TreeNode *new_root = insertNode(tree, key, value);
	if (new_root != NULL)/* B-Tree がバランスされ、新しいルートノードが設定された */
		tree = new_root;
	}
	return tree;
}
/* B-Tree に ノードを追加する。
子孫から繰り上がりのノードがあれば、ノードポインタが返される */
TreeNode *insertNode(TreeNode *tree, char *key, char *value)
{
	TreeNode *carry_node = NULL;
	/*
	* まず、ノード内の要素を探索する
	*/
	if ((tree->left.key != NULL) && strcmp(key, tree->left.key) == 0) {
		tree->left.value = value;
		return NULL;
	}
	if ((tree->right.key != NULL) && strcmp(key, tree->right.key) == 0) {
		/*
		///////////////////
		write code here
		///////////////////
		*/
		return NULL;
	}
	/*
	* ノード内の要素と一致しなかったので、子孫リンクがあれば進む
	*/
		/* child_left の処理 */
		if ((tree->left.key != NULL) && strcmp(key, tree->left.key) < 0) {
			/* left より小さい場合、chid_left があれば進む */
		if (tree->child_left != NULL) {
			carry_node = insertNode(tree->child_left, key, value);
		if (carry_node == NULL)
			/* 子孫から繰り上がりのノードが無ければ終了 */
			return NULL;
		}
	}
	/* child_right の処理 */
	else if ((tree->right.key != NULL) && strcmp(key, tree->right.key) > 0) {
		/* right より大きい場合、chid_right があれば進む */
		/*
		///////////////////
		write code here
		///////////////////
	*/
	}/* child_center の処理 */
	else {
		/* left より大きく right より小さいので、child_center があれば進む */
		if (tree->child_center != NULL) {
			/*
			///////////////////
			write code here
			///////////////////
			*/
		}
		}
	/*
	* 要素を格納する処理
	* 1) 子孫へのリンクがない場合、left / right にデータを格納する
	* 2) 子孫からの繰り上がりがあった場合、繰り上がりノードのリンクを含めてマージ
	* 3) データが満杯だった場合は、繰り上がりノードを作成して return
	*/
	/* left / right に格納できるかどうか */
	if ((tree->left.key == NULL) || (tree->right.key == NULL)) {/* left / right に格納できる */
		if (carry_node == NULL) {
			/* 繰り上がりではない → 単純にデータをセット */
			if (tree->left.key == NULL) {
				tree->left.key = key;
				tree->left.value = value;
			}
			else {
				if (strcmp(key, tree->left.key) < 0){
					/* データ < left の場合、元の left 位置にデータを挿入 */
					tree->right.key = tree->left.key;
					tree->right.value = tree->left.value;
					tree->left.key = key;
					tree->left.value = value;
			}
				else {
					/* right < データ の場合、right 位置にデータを設定 */
					/*
					///////////////////
					write code here
					///////////////////
					*/
				}
			}
		}else {
			/* 子孫からの繰り上がり → ノードをマージ */
			if (strcmp(carry_node->left.key, tree->left.key) < 0){
			/* データ < left の場合 */
				tree->right.key = tree->left.key;
				tree->right.value = tree->left.value;
				tree->child_right = tree->child_center;
				tree->left.key = carry_node->left.key;
				tree->left.value = carry_node->left.value;
				tree->child_left = carry_node->child_left;
				tree->child_center = carry_node->child_center;
			}
			else {
				/* left < データ の場合 */
				tree->right.key = carry_node->left.key;
				tree->right.value = carry_node->left.value;
				tree->child_right = carry_node->child_center;
			}
		}
	}
	else {
		/* left / right に格納できない場合、分割・繰り上がりが発生する *//* 分割・繰り上がり用のノードを作成する */
		TreeNode *new_node = createNode();
		TreeNode *sortlist[3];
		/* 挿入対象のデータは、引数データか繰り上がりデータのどちらか */
	if (carry_node == NULL) {
		/* 引数データをノード化する */
		carry_node = createNode();
		carry_node->left.key = key;
		carry_node->left.value = value;
		/* left ノードが最小のデータとなるように調整 */
		if (strcmp(key, tree->left.key) < 0) {
			SWAP(carry_node->left.key, tree->left.key);
			SWAP(carry_node->left.value, tree->left.value);
		}
	}
	/* ノードを分割して、right データを分割ノードにコピー */
	new_node->left.key = tree->right.key;
	new_node->left.value = tree->right.value;
	new_node->child_left = tree->child_center;
	new_node->child_center = tree->child_right;
	tree->right.key = NULL;tree->right.value = NULL;
	tree->child_right = NULL;
	/*
	* ノード内の要素をソートして、中間データを選出する
	*/
	/* tree (left) ノードが最小のデータとなるように調整
	*/
	if (strcmp(carry_node->left.key, tree->left.key) < 0) {
	SWAP(tree->left.key, carry_node->left.key);
	SWAP(tree->left.value, carry_node->left.value);
	SWAP(tree->child_left, carry_node->child_left);
	SWAP(tree->child_center, carry_node->child_center);
	}
	sortlist[0] = tree;
	sortlist[1] = carry_node;
	sortlist[2] = new_node;
	/* tree (left) < new_node (right) なので、
	carry_node の位置に着目してソートする */
	if (strcmp(sortlist[0]->left.key, sortlist[1]->left.key) > 0) {
		/* Swap sortlist[0] <--> sortlist[1] */
		SWAP(sortlist[0], sortlist[1]);
	}
	if (
		/*
	///////////////////
	write code here
	///////////////////
	*/
	) {
		/* Swap sortlist[1] <--> sortlist[2] */
		SWAP(sortlist[1], sortlist[2]);}
		/* right ノードの子孫リンクの調整 */
		sortlist[2]->child_left = sortlist[1]->child_center;
		/* 繰り上げノードに子孫リンク left / right を設定 */
		sortlist[1]->child_left = sortlist[0];
		sortlist[1]->child_center = sortlist[2];
		/* 中間ノードが繰り上がる */
		return
			/*
			///////////////////
			write code here
			///////////////////
			*/
	return NULL;
}

/*********************************************************/
typedef struct {
	char *eng;
	char *jpn;
} WordList;
#define WORDLISTSIZE(x) (sizeof (x) / sizeof (WordList))
WordList wordlist[] = {
	{ "07", "seven" },
	{ "15", "fifteen" },
	{ "21", "twenty-one" },
	{ "04", "four" },
	{ "14", "fourteen" },
	{ "23", "twenty-three" },
	{ "05", "five" },
	{ "18", "eighteen" },
	{ "22", "twenty-two" },
	{ "17", "seventeen" },
	{ "01", "one" },
	{ "13", "thirteen" },
	{ "09", "nine" },
	{ "20", "twenty" },
	{ "19", "nineteen" },
	{ "06", "six" },
	{ "08", "eight" },
	{ "03", "three" },
	{ "10", "ten" },
	{ "02", "two" },
	{ "12", "twelve" },
	{ "11", "eleven" },{ "24", "twenty-four" },
	{ "16", "sixteen" }
};
void disp_Tree(TreeNode *p)
{
	if (p == NULL) {
		printf(" . ");
		return;
	}
	printf(" (");
	disp_Tree(p->child_left);
	printf("\"%s\"", p->left.key);
	disp_Tree(p->child_center);
	printf("\"%s\"", p->right.key);
	disp_Tree(p->child_right);
	printf(") ");
}
void printTree(TreeNode *p)
{
	if (p) {
		disp_Tree(p);printf("\n");
	}
}
void listTree(TreeNode *p, int lv)
{
	int i;
	char spc[64];
	for (i = 0; i < sizeof (spc); i++)
		spc[i] = ' ';
		spc[lv * 2] = '\0';
	if (p) {
	if (p->child_left)
		listTree(p->child_left, lv + 1);
	if (p->left.key)
		printf("%s|L> %s: %s\n", spc, p->left.key, p->left.value);
	if (p->child_center)
		listTree(p->child_center, lv + 1);
	if (p->right.key)
		printf("%s|R> %s: %s\n", spc, p->right.key, p->right.value);
	if (p->child_right)
		listTree(p->child_right, lv + 1);
	}
}

int main()
{
	int i;
	TreeNode *root = NULL;
	for (i = 0; i < WORDLISTSIZE(wordlist); i++) {
	printf("%d%s: %s\n", i, wordlist[i].eng, wordlist[i].jpn);
	root = addTree(root, wordlist[i].eng, wordlist[i].jpn);
	if (root == NULL) {
		perror("malloc error\n");
		return 1;
	}
	if (i == -1) {
		printf("quit %d...\n", i);
		break;
	}
	/* printTree(root); */
	}
	printf("\nlisting:\n");
	listTree(root, 0);return 0;
}




