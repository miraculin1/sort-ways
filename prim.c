#include <stdlib.h>
struct Graph {
  int vetN;    // 节点总数
  int **matix; // 邻接矩阵
};

// 返回一个数组，其中按照顺序储存最小生成树的节点
int *prim(struct Graph *g, int start) {

  // 结果数组
  int *res = malloc(sizeof(int) * g->vetN);
  int resN = 0;

  // outward[i] 代表目前从已经选过的节点到 i 这个节点的最短长度
  int *outward = malloc(sizeof(int) * g->vetN);

  // 初始化 outward
  for (int i = 0; i < g->vetN; i++) {
    outward[i] = g->matix[start][i];
  }
  res[resN++] = start;

  for (int i = 1; i < g->vetN; i++) {

    // find min
    int min = outward[0];
    int minPos = 0;
    for (int j = 0; j < g->vetN; j++) {
      if (outward[j] != 0 && outward[j] < min) { // outward[j] != 0 代表未选择过
        min = outward[j];
        minPos = j;
      }
    }

    // 将 新的点 加入 res
    res[resN++] = minPos;

    // 将 新的点 加入已经选过的节点
    outward[minPos] = 0;

    // 更新 outward 保持意义不变
    for (int k = 0; k < g->vetN; k++) {
      if (outward[k] != 0 && g->matix[minPos][k] < outward[k]) {
        outward[k] = g->matix[minPos][k];
      }
    }
  }
  return res;
}
