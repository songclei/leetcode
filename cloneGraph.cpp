/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)  return NULL;
        unordered_map<Node*, Node*> my_map;
        queue<Node*> my_queue;
        Node *new_root = new Node(node->val, vector<Node*>());
        my_map.insert(make_pair(node, new_root));
        my_queue.push(node);
        while (!my_queue.empty()) {
            Node *tmp = my_queue.front();
            my_queue.pop();
            for (auto it = tmp->neighbors.begin(); it != tmp->neighbors.end(); ++it) {
                if (my_map.count(*it) == 0) {
                    Node *new_node = new Node((*it)->val, vector<Node*>());
                    my_map.insert(make_pair(*it, new_node));
                    my_queue.push(*it);
                } 
                my_map[tmp]->neighbors.push_back(my_map[*it]);
            }
        }
        return new_root;
    }
};