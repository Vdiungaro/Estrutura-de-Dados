#include<iostream>
#include<locale.h>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class SingleLinkList{
    public:
        Node* head;

        SingleLinkList()
        {
            head=NULL;
        }

        SingleLinkList(Node *n)
        {
            head=n;
        }

        // 1. Verifica se o nó existe utilizando o valor da chave.
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

        // 2. Adiciona um nó no fim da lista

        void appendNode(Node *n)
        {
            if(nodeExists(n-> key)!=NULL)
            {
                cout<<"O nó ja existe com a chave : "<<n->key<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout<< "Nó adicionado"<<endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout<<"Nó adicionado"<<endl;
                }
            }
        }

        // 3. Adicona um nó no começo da lista
        void prependNode(Node *n)
        {
            if(nodeExists(n-> key)!=NULL)
            {
                cout<<"O nó ja existe com a chave : "<<n->key<<endl;
            }
            else
            {
                n->next = head;
                head = n;
                cout<<"Nó adicionado"<<endl;
            }
        }

        // 4. Inserir um nó apos um nó especifico da lista.
        void insertNode(int k, Node *n)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"Não existe um nó com esse valor de chave: "<<k<<endl;
            }
            else
            {
                if(nodeExists(n-> key)!=NULL)
                {
                cout<<"O nó ja existe com a chave : "<<n-> key<<endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next =n;
                    cout<< "Nó inserido"<<endl;
                }
            }
        }

        // 5. Deletar nó por chave unica.

        void deleteNodeByKey(int k)
        {
            if(head == NULL)
            {
                cout<<"A lista está vazia."<<endl;
            }
            else if(head!=NULL)
            {
                if(head->key == k)
                {
                    head = head->next;
                    cout<<"Nó removido da lista com a chave: " <<k<<endl;
                }
                else
                {
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head-> next;
                    while(currentptr!= NULL)
                    {
                        if (currentptr->key==k)
                        {
                            temp = currentptr;
                            currentptr=NULL;
                        }
                        else
                        {
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    if(temp!=NULL)
                    {
                        prevptr->next = temp->next;
                        cout<<"Nó removido da lista com a chave: " <<k<<endl;
                    }
                    else
                    {
                        cout<<"Não existe nó com este valor de chave: " <<k<<endl;
                    }
                }
            }
        }

        // 6. Atualizar nó.

        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout<<"Nó atualizado"<<endl;
            }
            else
            {
                cout<<"Não existe nó com este valor de chave: " <<k<<endl;
            }
        }

        // 7. Mostrar lista.
        void printList()
        {
            if(head == NULL)
            {
                cout<<"A lista está vazia"<<endl;
            }
            else
            {
                cout<<endl<<"Os valores da lista são: ";
                Node* temp = head;

                while(temp!= NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") --> ";
                    temp = temp->next;
                }
            }
        }
};

int main()
{
    setlocale(LC_ALL, "");
    SingleLinkList s;
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
                s.appendNode(n1);
                break;

            case 2:
                cout<<"Digite a chave e o valor a ser adiciondo ao começo da lista"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.prependNode(n1);
                break;

            case 3:
                cout<< "Digite a chave do nó no qual você deseja inserir após"<<endl;
                cin>>k1;
                cout<<"Digite a chave e o valor do novo nó"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.insertNode(k1,n1);
                break;

            case 4:
                cout<<"Digite a chave do nó a ser removido"<<endl;
                cin>>k1;
                s.deleteNodeByKey(k1);
                break;
            
            case 5:
                cout<<"Digite a chave e o novo valor do nó"<<endl;
                cin>>key1;
                cin>>data1;
                s.updateNodeByKey(key1,data1);
                break;

            case 6:
                s.printList();
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