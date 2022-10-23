#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

class Tree {
    private: Node *root; //declara root
    
    public: Tree() {
        root = NULL; // inicializa a árvore
    }
    
    public: void insert(int value) {
        Node *novo = new Node(); //cria um novo nó
        novo->data = value;
        novo->right = NULL;
        novo->left = NULL;
        
        if(root == NULL) {
            root = novo;
        } else {
            Node *atual = root;
            Node *aux;
            while(true) {
                aux = atual;
                if (value < atual->data) {
                    atual = atual->left;
                    if (atual == NULL) {
                        aux->left = novo;
                        return;
                    }
                } else {
                    atual = atual->right;
                    if (atual ==  NULL) {
                        aux->right = novo;
                        return;
                    }
                }
            }
        }
    }
    
    private: void folhas(Node *no){
        if (no == NULL) {
            cout << "Tree is empty.";
        } if (no->left == NULL && no->right == NULL) {
            cout << no->data << " ";
        }else {
            if (no->left != NULL) {
                folhas(no->left);
            }
            if (no->right != NULL) {
                folhas(no->right);
            }
        }
    }
    
    private: void inOrder(Node *no) {
        if (no != NULL) {
            inOrder(no->left);
            cout << no->data << " ";
            inOrder(no->right);
        }
    }
    
    private: void preOrder(Node *no) {
        if (no != NULL) {
            cout << no->data << " ";
            preOrder(no->left);
            preOrder(no->right);
        }
    }
    
    private: void posOrder(Node *no) {
        if (no != NULL) {
            posOrder(no->left);
            posOrder(no->right);
            cout << no->data << " ";
        }
    }

    private: void nodeGrades(Node *no) {
      if (no->right == NULL && no->left == NULL) {
        cout << no->data << "-> 0" << endl;
      } else if (no->right != NULL && no->left != NULL) {
        cout << no->data << "-> 2" << endl;
        if (no->left != NULL) {
          nodeGrades(no->left);
        }
        if (no->right != NULL) {
          nodeGrades(no->right);
        }
      } else {
        cout << no->data << "-> 1" << endl;
        if (no->left != NULL) {
          nodeGrades(no->left);
        }
        if (no->right != NULL) {
          nodeGrades(no->right);
        }
      }
    }

    //functions para altura por no e depois puxando da root

    private: int nodeHeight(Node *no) {
     if(no == NULL || (no->left == NULL && no->right == NULL))
       return 0;
     else {
   	if (nodeHeight(no->left) > nodeHeight(no->right))
   	   return ( 1 + nodeHeight(no->left) );
   	else
	   return ( 1 + nodeHeight(no->right) );
     }
  }

    private: void allNodeHeights(Node *no) {
      cout << no->data << "-> " << nodeHeight(no) << endl;
       if (no->left != NULL) {
         allNodeHeights(no->left);
       }
       if (no->right != NULL) {
         allNodeHeights(no->right);
       }
    }

    private: void nodeAncestors(Node *no, int quantity) {
      cout << no->data << "-> " << quantity << endl;
      if (no->left != NULL) {
        nodeAncestors(no->left, quantity + 1);
      }
      if (no->right != NULL) {
        nodeAncestors(no->right, quantity + 1);
      }
    }

    private: void nodeSubtrees(Node *no) {
      if (no != root) {
        cout << no->data << "-> ";
        preOrder(no);
        cout << "\n";
      }
      if (no->left != NULL) {
        nodeSubtrees(no->left);
      }
      if (no->right != NULL) {
        nodeSubtrees(no->right);
      }
    }

    public: void showResults() {
        cout << "a)" << endl;
        cout << "\nIn Order: ";
        inOrder(root);
        cout << "\nPre Order: ";
        preOrder(root);
        cout << "\nPos Order: ";
        posOrder(root);
        cout << "\n\nb)" << endl;
        cout << "\nFolhas: ";
        folhas(root);
        cout << "\n\nc)" << "\n\nGrau de cada nó: " << endl;
        nodeGrades(root);
        cout << "\n\nd)" << endl;
        cout << "\nAltura de cada nó: " << endl;
        allNodeHeights(root);
        cout << "\n\ne, f)" << endl;
        cout << "\nProfundidade e Nível de cada nó: " << endl;
        nodeAncestors(root, 0);
        cout << "\n\ng)" << endl;
        cout << "\nSubárvores: " << endl;
        nodeSubtrees(root);
      
    }
};

int main() {
    Tree tree = Tree();
    tree.insert(10);
    tree.insert(7);
    tree.insert(9);
    tree.insert(12);
    tree.insert(3);
    tree.insert(11);
    tree.insert(14);
    tree.insert(1);
    
    tree.showResults();
}
Footer
