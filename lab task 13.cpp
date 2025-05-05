#include <iostream>
using namespace std;
//DFS in trees (insert and trasverse)
struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

void dfs(treeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    dfs(root->left);           
    dfs(root->right);          
}

int main() {
    
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->left = new treeNode(4);
    root->left->right = new treeNode(5);

    cout << "DFS (Preorder) traversal of Tree: ";
    dfs(root);
    return 0;
}
//DFS in graphs 

#include<vector>
void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(neighbor, visited, graph);
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    vector<bool> visited(V, false);
    cout << "DFS traversal of Graph from node 0: ";
    dfs(0, visited, graph);

    return 0;
}
//BFS in graph
#include <queue>
void bfs(int start, vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    cout << "BFS traversal of Graph from node 0: ";
    bfs(0, graph, V);

    return 0;
}
//BFS in trees
struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

void bfs(treeNode* root) {
    if (root == nullptr) return;

    queue<treeNode*> q;
    q.push(root);

    while (!q.empty()) {
        treeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main(){
    treeNode* root = new treeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "BFS (Level Order) traversal of Tree: ";
    bfs(root);
    return 0;
}
