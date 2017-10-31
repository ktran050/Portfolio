#ifndef __TREE_H__
#define __TREE_H__
 
#include <iostream>
#include <queue>
 
template<typename T>
class Tree {
    private:
        struct Node {
            T data;
            Node *right;
            Node *left;
            Node():     data(0), right(0), left(0) { }
            Node(T d):  data(d), right(0), left(0) { }
        };
 
        Node *root;
    
        Node *push_(T val, Node *n) {
            if(!n) n = new Node(val);
            else if(val < n->data) n->left = push_(val, n->left);
            else if(val > n->data) n->right = push_(val, n->right);
            else n->data = val; //if val is equal to data
            
            return n;
        }
    
    public:
        Tree():root(0) { }
    
        Node* get_root() { return root; }
    
        void push(T val) { root = push_(val, root); }
    
        void print() {
            typedef std::pair<const Node*,int> node_level;
            std::queue<node_level> q;
            q.push(node_level(root, 1));
            int level = 1;
            
            while (!q.empty()) {
                node_level nl = q.front();
                q.pop();
                const Node *n = nl.first;
                if (!n) { continue; }
                
                if (level != nl.second) {
                    std::cout << std::endl << std::endl;
                    level = nl.second;
                }
                std::cout << n->data << ' ';
                q.push(node_level(n->left,  1 + level));
                q.push(node_level(n->right, 1 + level));
            
            }
            std::cout << std::endl;
        }
        
        T max() const{
            if(root){
                Node* trav = root;
                while( trav->right != 0){
                    trav = trav->right;
                }
                return trav->data;
            }
            return 0;
        }
        // Create node level and follow it all the way right
        T min() const{
            if(root){
                Node* trav = root;
                while( trav->left != 0){
                    trav = trav->left;
                }
                return trav->data;
            }
            return 0;
        }
        // Create node level and follow it all the way right
        Node* find( T val ){
            if(root){
                Node* trav = root;
                while(trav != 0){
                    if(trav->data = val){
                        return trav;
                    }
                    else if(trav->data > val){
                        trav = trav->right;
                    }
                    else{
                        trav = trav->left;
                    }
                }
            }
            return 0;
        }
        // If the values equal return that address
        // If theyre not equal either go left or right
        // If we reach the end then return 0
        
        T total(){
            T tote;
            typedef std::pair<const Node*,int> node_level;
            std::queue<node_level> q;
            q.push(node_level(root, 1));
            int level = 1;
            // total += (node_level.first)->data;
            tote = q.front().first->data;
            while (!q.empty()) {
                node_level nl = q.front();
                q.pop();
                const Node *n = nl.first;
                tote += n->data;
                if (!n) { continue; }
                
                if (level != nl.second) {
                    level = nl.second;
                }
                q.push(node_level(n->left,  1 + level));
                q.push(node_level(n->right, 1 + level));
            }
            return tote;
        }
};
 
 
#endif