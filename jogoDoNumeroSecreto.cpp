#include <iostream>
using namespace std;


void escreve(int limete, string caracter);
int testarChuteDoUsuario(int numeroSecreto);

int main()
{
    setlocale(LC_ALL,"");  // Ativa o uso de acentos
    // -------------------------------
    int limete = 40;
    
    srand(time(NULL));
    int numeroSecreto = rand()%10;
   
    escreve(limete, "*");
    escreve(1, "Bem vindo ao nosso jogo de adivinha��o!");
    escreve(limete, "*");
    testarChuteDoUsuario(numeroSecreto);
    
    // -------------------------------
    system("pause");
    return 0;
}

void escreve(int limite, string caracter) {
    int i;
    for (i = 0; i < limite; i++) 
    {
        cout << caracter;
    }
    cout << "\n";
}

int testarChuteDoUsuario(int numeroSecreto)
{
    int chute, tentativas, nivel, numeroDeTentativas;
    float  meusPontos, pontosPerdidos;
    bool acertou = false;
    pontosPerdidos = 0.00;
    tentativas = 0;
    meusPontos = 1000.00;
    
    cout << " (1) F�CIL \n (2) M�DIO \n (3) DIF�CIL \n Escolha um n�vel:  ";
    cin >> nivel;
    
    switch(nivel){
        case 1:
            numeroDeTentativas = 20;
            break;
        case 2: 
            numeroDeTentativas = 15;
            break;
        default:
            numeroDeTentativas = 5;
            break;
    }
   
    while(tentativas < numeroDeTentativas && !acertou){
        escreve(1, "Chute um n�mero: ");
        cin >> chute;
       
        if(chute > 0){
            if(chute == numeroSecreto){
                cout << "Parab�ns, voc� acertou o n�mero secreto em: " << tentativas + 1 << " tentativa(s)!\n";
                cout << "Total de pontos: " << meusPontos << " pontos!\n";
                acertou = true;
            }else {
                pontosPerdidos = (numeroSecreto - chute);
                pontosPerdidos /= 2;
               
                if(chute > numeroSecreto){
                    escreve(1, "O chute � maior que o n�mero secreto!");
                    meusPontos += pontosPerdidos;
                }else{
                    escreve(1, "O chute � menor que o n�mero secreto!");
                     meusPontos -= pontosPerdidos;
                }
                tentativas++;
            }
        }else{
            escreve(1, "informe um n�mero maior que 0");
        }
   }
   return 0;
}
 
