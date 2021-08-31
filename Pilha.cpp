#include<iostream>
#include<string>
#include<locale.h>

using namespace std;

class Stack
{
    private:
        int top;
        int arr[5];

    public:
        Stack()
        {
            top = -1;
            for(int i = 0; i<5; i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
        }
        
        bool isFull()
        {
            if(top==4)
                return true;
            else
                return false;
        }

        void push(int val)
        {
            if(isFull())
            {
                cout<<"Pilha cheia"<<endl;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Pilha vazia"<<endl;
                return 0;
            }
            else
            {
                int popval = arr[top];
                arr[top] = 0;
                top--;
                return popval;
            }
        }

        int count()
        {
            return(top+1);
        }

        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<<"Pilha vazia"<<endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void change(int pos, int val)
        {
            arr[pos]=val;
            cout<<"Valor alterado na posição"<<pos<<endl;
        }

        void display()
        {
            cout<<"Os valores da pilha são "<<endl;
            for(int i = 4; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }
};

int main()
{
    setlocale(LC_ALL, "");
    Stack s1;
    int option, position, value;

    do
    {
        cout<<"Qual operação deseja executar? Digite 0 para sair"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Verificar se a pilha esta vazia"<<endl;
        cout<<"4. Verificar se a pilha está cheia"<<endl;
        cout<<"5. Verificar um valor especifico"<<endl;
        cout<<"6. Contar elementos da pilha" <<endl;
        cout<<"7. Mudar valor de elemento da pilha"<<endl;
        cout<<"8. Mostrar a pilha"<<endl;
        cout<<"9. Limpar tela"<<endl<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Insira um elemento ao topo da pilha"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"Elemento removida da pilha :"<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<"A pilha está vazia"<<endl;
                else
                    cout<<"A pilha não está vazia"<<endl;
                break;
            case 4:
                if(s1.isFull())
                    cout<<"A pilha está cheia"<<endl;
                else
                    cout<<"A pilha não está cheia"<<endl;
                break;
            case 5:
                cout<<"Insira a posição do item a ser verificado"<<endl;
                cin>>position;
                cout<<"A posição tem o valor: "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<"Numero de elementos na pilha: "<<s1.count()<<endl;
                break;
            case 7:
                cout<<"Insira a posição do elemento que deseja alterar"<<endl;
                cin>>position;
                cout<<endl;
                cout<<"Insira o novo valor"<<endl;
                cin>>value;
                s1.change(position,value);
                break;
            case 8:
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout<<"Insira uma opção valida"<<endl;

        }

    } while (option!=0);
    
    
    return 0;
}