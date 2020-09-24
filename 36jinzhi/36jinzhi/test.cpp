/**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
* func getTriggerTime(increase [][]int, requirements [][]int) []int
* @param increase int整型二维数组 属性增加值
* @param increaseRowLen int increase数组行数
* @param increaseColLen int* increase数组列数
* @param requirements int整型二维数组 剧情触发要求
* @param requirementsRowLen int requirements数组行数
* @param requirementsColLen int* requirements数组列数
* @return int整型一维数组
* @return int* returnSize 返回数组行数
*/
int fun(int *req, int *cur) {
	for (int i = 0; i<3; ++i) {
		if (req[i] > cur[i]) return 0;
	}
	return 1;
}

int* getTriggerTime(int** increase, int increaseSize, int* increaseColSize, int** requirements, int requirementsSize, int* requirementsColSize, int* returnSize){
	*returnSize = requirementsSize;
	int *ret = (int*)malloc(requirementsSize * sizeof(int));
	for (int i = 1; i<increaseSize; ++i) {
		for (int j = 0; j<3; ++j) {
			increase[i][j] += increase[i - 1][j];
		}
	}
	for (int i = 0; i<requirementsSize; ++i) {
		int *req = requirements[i];
		if (req[0] == 0 && req[1] == 0 && req[2] == 0) {
			ret[i] = 0;
			continue;
		}
		int row = 0, col = increaseSize;
		while (row < col) {
			int index = (row + col) >> 1;
			if (fun(req, increase[index])) {
				col = index;
			}
			else {
				row = index + 1;
			}
		}
		ret[i] = row < increaseSize ? row + 1 : -1;
	}
	return ret;
}