//https://www.acmicpc.net/problem/1967

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

struct Node {
    int id;

    Node* parent = nullptr;
    int parent_weight;

    vector<Node*> children;
    vector<int> weight;

    void print() {
        cout << "Node(" << id << ")" << endl;

        if(parent != nullptr)
            cout << "parent : " << parent->id << "(" << parent_weight << ")" << endl;
        else
            cout << "root" << endl;

        for(int i = 0 ; i < children.size() ; i += 1) {
            cout << "child : " << children[i]-> id << "(" << weight[i] << ")" << endl;
        }

        cout << "----------------------------------" << endl;
    }
};

struct Tree {
    Node* root;
    vector<Node*> nodes;

    Tree() {
        root = new Node;
        root->id = 1;
        nodes.push_back(root);
    }

    void addNode(int id, int parent_id, int weight) {
        Node* parent_node = getNode(parent_id);

        Node* node = new Node;
        node->id = id;
        node->parent_weight = weight;
        node->parent = parent_node;
        this->nodes.push_back(node);

        parent_node->children.push_back(node);
        parent_node->weight.push_back(weight);
    }

    Node* getNode(int id) {
        for(auto np : nodes)
            if(np->id == id)
                return np;
        return nullptr;
    }

    vector<Node*> getLeaves() {
        vector<Node*> ret;
        for(auto np : nodes)
            if(np->children.size() == 0)
                ret.push_back(np);
        return ret;
    }

    void print() {
        for(auto np : nodes)
            np->print();
    }

    ~Tree() {
        for(auto np : nodes)
            delete np;
    }
};

void DFS(Node* leaf, set<int>& result) {
    vector<Node*> stack;
    vector<int> cost_stack;
    stack.push_back(leaf->parent);
    cost_stack.push_back(leaf->parent_weight);
    int find = 0;

    set<int> visited;
    visited.insert(leaf->id);

    while(stack.size() != 0) {
        Node* check = stack.back();
        stack.pop_back();

        int cost = cost_stack.back();
        cost_stack.pop_back();

        // check->print();
        
        //leaf 일 경우
        if(check->children.size() == 0) {
            result.insert(cost);
            find++;
        } else {
            //child
            for(int i = 0 ; i < check->children.size() ; i += 1) {
                Node* child = check->children[i];
                if(visited.count(child->id) == 0) {
                    stack.push_back(child);
                    cost_stack.push_back(cost + check->weight[i]);
                }
            }
            //parent
            if(check->parent != nullptr && visited.count(check->parent->id) == 0) {
                stack.push_back(check->parent);
                cost_stack.push_back(cost + check->parent_weight);
            }
        }

        visited.insert(check->id);
    }
}

Node* findFurthest(Node* root) {
    vector<Node*> stack;
    vector<int> cost_stack;

    stack.push_back(root);
    cost_stack.push_back(0);

    Node* max_node = nullptr;
    int max_cost = -1;

    while(!stack.empty()) {
        Node* check = stack.back();
        stack.pop_back();
        int cost = cost_stack.back();
        cost_stack.pop_back();

        if(check->children.size() == 0 && cost > max_cost) {
            max_node = check;
            max_cost = cost;
            continue;
        }

        for(int i = 0 ; i < check->children.size() ; i += 1) {
            stack.push_back(check->children[i]);
            cost_stack.push_back(cost + check->weight[i]);
        }
    }

    return max_node;
}

int main(void)
{
    int n;
    cin >> n;
    cin.get();

    Tree t;

    for(int i = 0 ; i < n -1 ; i += 1) {
        int s, e, w;
        scanf("%d %d %d\n", &s, &e, &w);
        t.addNode(e, s, w);
    }

    Node* f = findFurthest(t.root);
    set<int> res;
    DFS(f, res);

    cout << *(res.rbegin()) << endl;

    return 0;
}