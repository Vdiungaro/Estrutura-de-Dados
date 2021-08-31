#include<iostream>
#include <locale.h>
using namespace std;

class Node{

    public:
        int key;
        int data;
        Node* next;
        Node* prev;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class DoubleLinkList
{
    public:
        Node* head;

        DoubleLinkList()
        {
            head = NULL;
        }
        
        DoubleLinkList(Node *n)
        {
            head = n;
        }

        //1. Verificar se o nó existe utilizando a chave
        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr != NULL)
            {
                if(ptr->key == k)
                {
                    temp=ptr;
                }
                ptr= ptr->next;
            }

            return temp;
        }

        //2. Insere um nó na lista

        void appendNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<< "O nó ja existe com a chave: "<<n->key<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout<<"Nó adicionado"<<endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next!= NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next=n;
                    n->prev = ptr;
                    cout<<"Nó adicionado ao fim da lista"<<endl;
                }
            }
        }

        //3. Insere um nó no começo da lista
        void prependNode(Node* n)
        {
            if(nodeExists(n->key)!= NULL)
            {
                cout<< "O nó ja existe com a chave: "<<n->key<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout<<"Nó adicionado"<<endl;
                }
                else
                {
                    head->prev=n;
                    n->next=head;

                    head=n;
                    cout<<"Nó adicionado no começo da lista"<<endl;
                }
                
            }
        }

        //4. Inserir apos nó utilizando a chave
        void insertNodeAfter(int k, Node *n)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"Não existe um nó com esse valor de chave"<<endl;
            }
            else
            {
                if(nodeExists(n->key)!= NULL)
                {
                    cout<<"O nó ja existe com o valor de chave: "<<n->key<<endl;
                }
                else
                {
                    cout<<"Inserindo"<<endl;

                    Node *nextNode = ptr->next;
                    //Inserindo no fim
                    if(nextNode==NULL)
                    {
                        ptr->next = n;
                        n->prev = ptr;
                        cout<<"Nó inserido no fim"<<endl;
                    }

                    //Inserindo no meio
                    else
                    {
                        n->next = nextNode;
                        nextNode->prev = n;
                        n->prev = ptr;
                        ptr->next = n;

                        cout<<"Nó inserido no meio"<<endl;
                    }

                }
            }
        }

        // 5. Deletar Nó
        void deleteNode(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"Não existe um nó com essa chave"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    cout<<"A lista se encontra vazia, impossivel remover"<<endl;
                }
                else if(head!=NULL)
                {
                    if(head->key==k)
                    {
                        head = head->next;
                        cout<<"Nó removido"<<endl;
                    }
                    else
                    {
                        Node *nextNode = ptr->next;
                        Node *prevNode = ptr->prev;

                        //Removendo do fim
                        if(nextNode==NULL)
                        {
                            prevNode->next =NULL;
                            cout<<"Nó removido do fim da lista"<<endl;
                        }

                        //Removendo do meio
                        else
                        {
                            prevNode->next =nextNode;
                            nextNode->prev =prevNode;
                            cout<<"Nó removido do meio da lista"<<endl;
                        }
                    }
                }
            }
        }


        //6. Atualizar nó
        void updateNode(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                ptr->data=d;
                cout<<"Nó atualizado com sucesso"<<endl;
            }
            else
            {
                cout<<"Não existe nó com esse valor de chave"<<endl;
            }
        }

        void printList()
        {
            if(head==NULL)
            {
                cout<<"Não existe nós na lista"<<endl;
            }
            else
            {
                cout<<endl<<"Valores da lista: ";
                Node* temp = head;

                while(temp != NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") <--->";
                    temp = temp->next;
                }
            }
        }

};

int main()
{
    setlocale(LC_ALL, "");
    DoubleLinkList dlist;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"Qual operação deseja executar? Digite 0 para sair"<<endl;
        cout<<"1. Adicionar nó no fim da lista"<<endl;
        cout<<"2. Adicionar nó no começo da lista"<<endl;
        cout<<"3. Inserir um nó apos um nó especifico da lista."<<endl;
        cout<<"4. Deletar nó por chave unica"<<endl;
        cout<<"5. Atualizar nó"<<endl;
        cout<<"6. Mostrar Lista" <<endl;
        cout<<"7. Limpar tela"<<endl<<endl;

        cin>>option;
        Node* n1 = new Node();

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Digite a chave e o valor do nó a ser adicionado ao fim da lista"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                dlist.appendNode(n1);
                break;
            case 2:
                cout<<"Digite a chave e o valor a ser adiciondo ao começo da lista"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                dlist.prependNode(n1);
                break;
            case 3:
                cout<< "Digite a chave do nó no qual você deseja inserir após"<<endl;
                cin>>k1;
                cout<<"Digite a chave e o valor do novo nó"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                dlist.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Digite a chave do nó a ser removido"<<endl;
                cin>>k1;
                dlist.deleteNode(k1);
                break;
            case 5:
                cout<<"Digite a chave e o novo valor do nó"<<endl;
                cin>>key1;
                cin>>data1;
                dlist.updateNode(key1,data1);
                break;
            case 6:
                dlist.printList();
                break;
            case 7:
                system("cls");
                break;

            default:
                cout<<"Digite uma opção valida"<<endl;
        }
    } while (option!=0);
    
    return 0;
}