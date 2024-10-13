#include <iostream>
#include <string>

using namespace std;

//去chatgpt看建樹邏輯謬誤QAQ

class node {

private:

    node* left;
    node* right;
    char name;

public:

    //設值
    void set_name(char name) {
        this->name = name;
    }
    void set_right(node* node) {
        right = node;
    }
    void set_left(node* node) {
        left = node;
    }

    //取用
    node* get_right() {
        return right;
    }
    node* get_left() {
        return left;
    }
    char get_name() {
        return name;
    }

    node() {
        right = NULL;
        left = NULL;
    }

};

node* build_tree(string inorder, string preorder) {

    if (preorder == "" || inorder == "")
        return NULL;

    node* next = new node;
    next->set_name(preorder[0]);

    //偷當前節點在中序字串位置
    int in_Index = inorder.find(preorder[0]);

    //in_Index同時也代表當前左子樹有多少節點
    string left_inorder = inorder.substr(0, in_Index);
    string left_preorder= preorder.substr(1, in_Index);

    string right_inorder = inorder.substr(in_Index + 1);
    string right_preorder = preorder.substr(in_Index + 1);

    next->set_left(build_tree(left_inorder, left_preorder));
    next->set_right(build_tree(right_inorder, right_preorder));

    return next;
}

void postorder(node* now) {

    if (now == NULL)
        return;
    
    postorder(now->get_left());
    postorder(now->get_right());
    cout << now->get_name();
}

int main()
{
    string inorder,preorder;

    while (cin >> preorder >> inorder) {
        node* root = build_tree(inorder, preorder);
        postorder(root);
        cout << '\n';
    }

    return 0;
}
