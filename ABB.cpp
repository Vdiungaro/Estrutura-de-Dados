#include<iostream>
#include<locale.h>

#define SPACE 10
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode()
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
        TreeNode(int value)
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
};

class BST{
    public:
        TreeNode* root;

        bool isEmpty()
        {
            if (root == NULL)
                return true;
            else
                return false;
        }

        void insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Valor inserido na raiz!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Valor já existe," <<
            "Insira outro valor!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Valor inserido na esquerda!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Valor inserido na direita!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Sucesso na insersão"<<endl;
			return r;
		}
	
		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "Valores repetidos não permitidos!" << endl;
	     	return r; 
		}
		return r;
	}

  void print2D(TreeNode * r, int space) {
    if (r == NULL) // Caso base 1
      return;
    space += SPACE; // Aumenta a distancia entre os niveis   2
    print2D(r -> right, space); // Processa o filho da direita primeiro 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Processa o filho da esquerda 7
  }

  void printPreorder(TreeNode * r) //(nó atual, esquerda, direita) 
  {
    if (r == NULL)
      return;
    /*mostra o valor do nó */
    cout << r -> value << " ";
    /* subarvore da esquerda */
    printPreorder(r -> left);
    /* subarvore da direita */
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) //  (esquerda, nó atual, direita)
  {
    if (r == NULL)
      return;
    /* subarvore da esquerda */
    printInorder(r -> left);
    /* mostra o valor do nó */
    cout << r -> value << " ";
    /* subarvore da direita */
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
    // mostra o valor do nó
    cout << r -> value << " ";
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

  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* calcula o tamanho de cada subarvore */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* utiliza o maior */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  /* mostra os nós no nivel escolhido */
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

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* encontra o filho mais a esquerda */
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
    return r;
  }
};

int main()
{
    setlocale(LC_ALL, "");
    BST obj;
    int option, val;
    
    do
    {
        cout << "Qual opera��o ser� executada?"
        << " Selecione o numero da op��o desejada." << endl;
        cout << "1. Inserir n�" << endl;
        cout << "2. Buscar por n�" << endl;
        cout << "3. Deletar n�" << endl;
        cout << "4. Mostrar os valores da ABB" << endl;
        cout << "5. Limpar a tela" << endl;
        cout << "0. Sair do programa" << endl;

        cin >> option;
        //Nó n1;
        TreeNode * new_node = new TreeNode();

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "INSERIR" << endl;
                cout <<"Insira o valor do nó a ser inserido na ABB: ";
	            cin >> val;
	            new_node->value = val;
	            obj.root= obj.insertRecursive(obj.root,new_node);
	            //obj.insertNode(new_node);
	            cout<<endl;
                break;
            case 2:
                cout << "BUSCAR" << endl;
                cout << "Insira o valor a ser buscado na ABB: ";
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
                cout << "REMOVER" << endl;
                cout << "Insira o valor a ser removido da ABB: ";
                cin >> val;
                new_node = obj.iterativeSearch(val);
                if (new_node != NULL) {
                    obj.deleteNode(obj.root, val);
                    cout << "Valor encontrado" << endl;
                } else {
                    cout << "Valor não encontrado" << endl;
                }
                break;
            case 4:
                cout << "MOSTRAR" << endl;
                obj.print2D(obj.root, 5);
                cout << endl;
                cout << "Ordem da arvore: \n";
                obj.printLevelOrderBFS(obj.root);
                cout << endl;
                break;
            case 5:
                cout << "ALTURA DA ARVORE" << endl;
                cout << "Altura : " << obj.height(obj.root) << endl;
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "Insira um numero valido" << endl;
        }
    } 
    
    while (option!=0);
    


   return 0; 
}
