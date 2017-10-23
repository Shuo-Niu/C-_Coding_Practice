#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef int tree_node_elem_t;

struct binary_tree_node_t {
    binary_tree_node_t* left;
    binary_tree_node_t* right;
    tree_node_elem_t elem;
};

/*
 * @param[in] root root of the binary tree
 * @return void
 */
void dfs_recursion(const binary_tree_node_t* root) {
    if(root == nullptr) return;

    // pre-order traversal visit
    dfs_recursion(root->left);
    // in-order traversal visit
    dfs_recursion(root->right);
    // post-order traversal visit
}

void dfs_iteration_pre_order(const binary_tree_node_t* root) {
    stack<const binary_tree_node_t*> s;
    if(root != nullptr) s.push(p);
    while(!s.empty()) {
        const binary_tree_node_t* node;
        node = s.top();
        s.pop();

        //visit node

        if(node->right != nullptr) s.push(node->right);
        if(node->left != nullptr) s.push(node->left);
    }
}

void dfs_iteration_in_order(const binary_tree_node_t* root) {
    stack<const binary_tree_node_t*> s;
    const binary_tree_node_t* p;
    p = root;
    while(!s.empty() || p != nullptr) {
        if(p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();

            // visit

            p = p->right;
        }
    }
}

void dfs_iteration_post_order(const binary_tree_node_t* root) {
    stack<const binary_tree_node_t*> s;
    /* p, currently visiting node; q, previously visited node */
    const binary_tree_node_t *p, *q;
    p = root;
    do{
        while(p != nullptr) {
            s.push(p);
            p = p->left;
        }
        q = nullptr;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            if(p->right == q) { // right child is nullptr or visited
                // visit p
                q = p;
            } else { // cannot visit p now, push it one more time
                s.push(p);
                p = p->right;
                break;
            }
        }
    } while(!s.empty());
}

void bfs_iteration(const binary_tree_node_t* root) {
    queue<const binary_tree_node_t*> q;
    if(root != nullptr) q.push(root);
    while(!q.empty()) {
        const binary_tree_node_t* node;
        node = q.front();
        q.pop();

        // visit

        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }
}
