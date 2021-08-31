#include<iostream>
#include<locale.h>
using namespace std;

class List{
    public:
        List()
        {
            length = 0;
        }
        void MakeEmpty()
        {
            length = 0;
        }

        bool isFull() const
        {
            return (length == 10);
        }

        int GetLength() const
        {
            return length;
        }

        void InsertItem(int item)
        {
            if (isFull())
            {
                return;
            }
            info[length] = item;
            length++;
        }
        void RemoveItem(int item)
        {
            for(int i = 0; i<10; i++) 
            {
                if(info[i] == item)
                {
                    info[i] = info[length - 1];
                    length--;
                }
            }
        }

        void Show()
        {
            for(int i = 0; i<10; i++)
            {
                cout << info[i] <<endl;
            }
        };
    private:
        int length;
        int info[10];

};


int main()
{
    setlocale(LC_ALL, "");
    List obj;
    int option;
    int item1;

    do
    {
        cout<<"Qual operação deseja executar? Digite 0 para sair"<<endl;
        cout<<"1. Adicionar item"<<endl;
        cout<<"2. Remover item"<<endl;
        cout<<"3. Verificar tamanho"<<endl;
        cout<<"4. Checar se esta cheia"<<endl;
        cout<<"5. Tornar vazia"<<endl;
        cout<<"6. Mostrar Lista" <<endl;
        cout<<"7. Limpar tela"<<endl<<endl;

        cin>>option;

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Digite o item a ser adicionado a lista"<<endl;
                cin>>item1;
                obj.InsertItem(item1);
                break;
            case 2:
                cout<<"Digite o item a ser removido da lista"<<endl;
                cin>>item1;
                obj.RemoveItem(item1);
                break;
            case 3:
                cout << "O tamanho da lista é :" << obj.GetLength() <<endl;
                break;
            case 4:
                if(obj.isFull())
                {
                    cout<< "A lista está cheia"<< endl;
                    break;
                }
                else
                {
                    cout<< "A lista não esta cheia"<< endl;
                    break;
                }
            case 5:
                obj.MakeEmpty();
                cout<< "A lista foi esvaziada"<< endl;
                break;
            case 6:
                obj.Show();
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