#include<iostream>
#include<locale.h>

#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class AVLTree {
  public:
    TreeNode * root;
  AVLTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  // Obter altura  
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* calcula a altura de cada sub-arvore */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* usa a maior */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  // Obtem o fator de balanço do nó N
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }

  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;

    // Realiza a rotação  
    x -> right = y;
    y -> left = T2;

    return x;
  }

  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;

    // Realiza a rotação 
    y -> left = x;
    x -> right = T2;

    return y;
  }

  TreeNode * insert(TreeNode * r, TreeNode * new_node) {
    if (r == NULL) {
      r = new_node;
      cout << "Valor inserido com sucesso!" << endl;
      return r;
    }

    if (new_node -> value < r -> value) {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);
    } else {
      cout << "Valores duplicados não são permitidos" << endl;
      return r;
    }

    int bf = getBalanceFactor(r);
    // Caso esquerda esquerda  
    if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);

    // Caso direita direita 
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);

    // Caso esquerda direita  
    if (bf > 1 && new_node -> value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }

    // Caso direita esquerda 
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    /* retorna o ponteiro do nó não modificado */
    return r;

  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* encontra o filho mais profundo do lado esquerdo */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * deleteNode(TreeNode * r, int v) {
    // caso base
    if (r == NULL) {
      return NULL;
    }
    // Se a chave a ser deletada for menor que a da raiz, 
    // então pertence a subarvore da esquerda
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // Se a chave a ser deletada for maior que a da raiz,
    // então pertence a subarvore da direita 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // Se a chave a ser deletada for igual que a da raiz, esse é o nó que deve ser removido 
    else {
      // nó sem filhos ou com apenas um filho 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // Nó com dois filhos: Achar o sucessor (menor 
        // valor na subarvore) 
        TreeNode * temp = minValueNode(r -> right);
        // Copia o conteudo do sucessor para este nó
        r -> value = temp -> value;
        // Remove o sucessor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }

    int bf = getBalanceFactor(r);
    // Desequilibrio/caso esquerda esquerda ou rotação para direita 
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
      return rightRotate(r);
    // Desequilibrio/caso esquerda direita ou rotação ED 
    else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    // Desequilibrio/caso direita direita ou rotação para esquerda	
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
      return leftRotate(r);
    // Desequilibrio/caso direita esquerda ou rotação DE
    else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
  }

  void print2D(TreeNode * r, int space) {
    if (r == NULL) // Caso base  1
      return;
    space += SPACE; // Aumenta a distancia entre os niveis   2
    print2D(r -> right, space); // Processa o filho da direita primeiro 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Processa o filho da esquerda  7
  }
  void printPreorder(TreeNode * r) //(nó atual, Esquerda, Direita) 
  {
    if (r == NULL)
      return;
    /* primeiro valor do nó */
    cout << r -> value << " ";
    /* subarovre da esquerda */
    printPreorder(r -> left);
    /* subarvore da direita */
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) //  (esquerda, nó atual, direita)
  {
    if (r == NULL)
      return;
    /* primeiro o filho da direita */
    printInorder(r -> left);
    /* valor do nó */
    cout << r -> value << " ";
    /* filho da direita */
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) //(esquerda, direita, raiz)
  {
    if (r == NULL)
      return;
    // subarvore da esquerda 
    printPostorder(r -> left);
    // subarvore da direita
    printPostorder(r -> right);
    // nó atual 
    cout << r -> value << " ";
  }

  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> value << " ";
    else // nivel > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

  TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }

  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }

};

int main() 
{
  setlocale(LC_ALL, "Portuguese");
  AVLTree obj;
  int option, val;

  do {
    cout << "Que operação deseja executar? " <<
      " Selecione o numero da operação." << endl;
    cout << "1. Inserir nó" << endl;
    cout << "2. Encontrar nó" << endl;
    cout << "3. Remover nó" << endl;
    cout << "4. Mostrar valores da arvore" << endl;
    cout << "5. Altura da arvore" << endl;
    cout << "6. Limpar tela" << endl;
    cout << "0. Sair" << endl;

    cin >> option;
    //Nó n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Inserir nó" << endl;
      cout << "Insira o valor do nó da arvore a ser inserido: ";
      cin >> val;
      new_node -> value = val;
      obj.root = obj.insert(obj.root, new_node);
      cout << endl;
      break;
    case 2:
      cout << "Busca" << endl;
      cout << "Insira o valor do nó da arvore a ser buscado: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Valor encontrado" << endl;
      } else {
        cout << "Valor não encontrado" << endl;
      }
      break;
    case 3:
      cout << "Remover" << endl;
      cout << "Insira o valor do nó da arvore a ser removido: ";
      cin >> val;
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        obj.root = obj.deleteNode(obj.root, val);
        cout << "Valor Removido" << endl;
      } else {
        cout << "Valor não encontrado" << endl;
      }
      break;
    case 4:
      cout << "Mostrar: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      //cout <<"Print Level Order BFS: \n";
      //obj.printLevelOrderBFS(obj.root);
      //cout <<endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "Altura da arvore" << endl;
      cout << "Altura : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Insira uma opção valida" << endl;
    }

  } while (option != 0);

  return 0;
}