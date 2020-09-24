/**
* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
* func getTriggerTime(increase [][]int, requirements [][]int) []int
* @param increase int���Ͷ�ά���� ��������ֵ
* @param increaseRowLen int increase��������
* @param increaseColLen int* increase��������
* @param requirements int���Ͷ�ά���� ���鴥��Ҫ��
* @param requirementsRowLen int requirements��������
* @param requirementsColLen int* requirements��������
* @return int����һά����
* @return int* returnSize ������������
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