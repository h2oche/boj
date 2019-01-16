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

    Node* child_max_node = nullptr;
    int child_max = -1;
    int child_sum_max = -1;

    void update_child_max(int child_weight, Node* child_node) {
        int child_old_max = child_max;
        Node* child_old_max_node = child_max_node;
        bool flag = false;

        //update child max
        if(child_weight > child_max) {
            flag = true;
            child_max = child_weight;
            child_max_node = child_node;

            if(parent != nullptr)
                parent->update_child_max(child_weight + parent_weight, this);
        }

        //update child sum max
        if(children.size() > 1) {
            if(child_sum_max == -1)
                child_sum_max = child_old_max + child_weight;
            else if(flag){
                if(child_max_node == child_old_max_node)
                    child_sum_max = child_sum_max - child_old_max + child_max;
                else
                    child_sum_max = child_old_max + child_max;
            } else if(child_max_node != child_node && child_sum_max < child_max + child_weight) {
                child_sum_max = child_max + child_weight;
            }
        }
    }

    void print() {
        cout << "Node(" << id << ")" << endl;

        if(parent != nullptr)
            cout << "parent : " << parent->id << "(" << parent_weight << ")" << endl;
        else
            cout << "root" << endl;

        for(int i = 0 ; i < children.size() ; i += 1) {
            cout << "child : " << children[i]-> id << "(" << weight[i] << ", "<< children[i]->child_max <<")" << endl;
        }

        cout << "child max : " << child_max << endl;
        cout << "child sum max : " << child_sum_max << endl; 

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

        //update child_max, child_sum_max
        parent_node->update_child_max(weight, node);
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

    // for(auto np : t.nodes)
    //     np->print();

    int ans = -1;
    for(auto np : t.nodes)
        if(np->child_sum_max > ans)
            ans = np->child_sum_max;

    ans = max(t.root->child_max, ans);

    cout << ans << endl;

    return 0;
}