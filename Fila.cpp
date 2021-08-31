#include <iostream>
#include<locale.h>
using namespace std;

class Queue
{
    private:
        int front;
        int back;
        int arr[5];

    public:
        Queue()
        {
            front = -1;
            back = -1;
            for(int i=0;i<5;i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(front == -1 && back == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(back == 4)
                return true;
            else
                return false;
        }

        void enqueue(int val)
        {
            if(isFull())
            {
                cout<<"Fila cheia"<<endl;
                return;
            }
            else if(isEmpty())
            {
                back=0;
                front=0;
                arr[back]=val;
            }
            else
            {
                back++;
                arr[back]=val;
            }
        }

        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                 cout<<"Fila cheia"<<endl;
                return 0;
            }
            else if(front == back)
            {
                x = arr[front];
                arr[front] = 0;
                back = -1;
                front = -1;
                return x;
            }
            else
            {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        int count()
        {
            return (back-front+1);
        }

        void display()
        {
            cout<<"Os valores na fila são: "<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<arr[i]<<" "<<endl;
            }
        }
            
};

int main()
{
    setlocale(LC_ALL, "");
    Queue q1;
    int option,value;
    do
    {
        cout<<"Qual operação deseja executar? Digite 0 para sair"<<endl;
        cout<<"1. Adicionar a fila"<<endl;
        cout<<"2. Remover da fila"<<endl;
        cout<<"3. Verificar se a fila esta vazia"<<endl;
        cout<<"4. Verificar se a fila está cheia"<<endl;
        cout<<"6. Contar elementos da fila" <<endl;
        cout<<"8. Mostrar a fila"<<endl;
        cout<<"9. Limpar tela"<<endl<<endl;

        cin>>option;

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Insira um item para adicionar a fila"<<endl;
                cin>>value;
                q1.enqueue(value);
                break;
            case 2:
                cout<<"Insira um item para remover da fila"<<endl;
                break;
            case 3:
                if(q1.isEmpty())
                    cout<<"A fila está vazia"<<endl;
                else
                    cout<<"A fila não esta vazia"<<endl;
                break;
            case 4:
                if(q1.isFull())
                    cout<<"A fila está cheia"<<endl;
                else
                    cout<<"A fila não esta cheia"<<endl;
                break;
            case 5:
                cout<<"Numero de itens na fila"<<q1.count()<<endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Insira uma opção validar"<<endl;
                break;


        }

    } while (option!=0);
    
}