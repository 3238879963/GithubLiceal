#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, k, t1, t2;
	map<int, vector<int>> m;//��,��ֵ�ԣ�<��Ʒid������>
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {//���ֵ�
		scanf("%d%d", &t1, &t2);
		m[t1].push_back(t2);
		m[t2].push_back(t1);
	}
	while (k--) {
		int cnt, flag = 0, a[100000] = { 0 };//�±��ʾ����Ʒ���ڲ���
		scanf("%d", &cnt);
		vector<int> v(cnt);//��Ʒi����v[i],���
		for (int i = 0; i < cnt; i++) {
			scanf("%d", &v[i]);//����Ʒid
			a[v[i]] = 1;//���ڵ�
		}
		for (int i = 0; i < v.size(); i++)//���ڵ�ǰ������Ʒ����v[i]
		for (int j = 0; j < m[v[i]].size(); j++)//��Ʒv[i]��Ӧ�ĳ�ͻ����m[v[i]]
		if (a[m[v[i]][j]] == 1) flag = 1;//����Ʒv[i]�ĳ�ͻ��Ʒm[v[i]][j]ȥ�˶�
		//����������v[i]�ĳ�ͻ��ȥ�˶�v[i]
		printf("%s\n", flag ? "No" : "Yes");
	}
	return 0;
}
