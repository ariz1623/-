#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int N;  //������ ����
vector<int> parent; //�θ� ���
vector<vector<int>> children; //�ڽ� ��� ����Ʈ
vector<vector<int>> adj; // ���� ����Ʈ

void print() {
	for (int i = 0; i < N; i++) {
		cout << "Node" << i << ":parent(";
		if (parent[i] != -1)cout << parent[i];
		else cout << "-";
		cout << "),children(";
		for (int j = 0; j < children[i].size(); j++) {
			cout << children[i][j];
			if (j < children[i].size() - 1)cout << ", ";
		}
		cout << ")" << endl;
	}
}


void addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void sortList() {
	for (int i = 0; i < N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
}

void makeTree(int root) {
	vector<bool> visited(N, false); //�湮���θ� �����ϴ� �迭
	queue<int> Q;

	visited[root] = true;
	Q.push(root);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (int next : adj[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
				parent[next] = curr;
				children[curr].push_back(next);
			}

		}
	}
	return;
	
}
int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 3);
	addEdge(1, 5);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(2, 6);
	addEdge(2, 8);
	addEdge(6, 7);
	addEdge(6, 8);
	sortList();
	print();

}