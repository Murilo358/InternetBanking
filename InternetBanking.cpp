#include<stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    char login1[15];
    char senha1[15];
    float saldo_Atual;

} pessoa; // Define o nome do novo tipo criado

pessoa usuario[99];

//Variaiveis do login em conjunto com deposito.
    char login[15];
    char senha[15];
    int check_Login;
    int tam=0;
    int i;
    int times_login=0;

////Função que limpa o terminal
void clear()
{
    system("clear || cls");
}

//Funcao que faz a validação se a SENHA esta correto ou nao
int validacao_Senha(char l[])
{
    int i;

        for(i=0;i<(strlen(l));i++) //Verifica se não possui 2 caracteres iguais seguidos
        {
            if (l[i]==l[i+1])
            {
                return -2;
            }
        }

    if ((strlen(l))<=5) //Verifica se a senha possui mais que 6 caracteres
    {
        return -1;
    }

    else
    {
        return 1;
    }
}

//Funcao que faz a validação se o CPF esta correto ou nao
int validacao_Cpf(char s[])
{

    for(i=0;i<tam;i++)
    {
        if (strcmp(usuario[tam].login1, usuario[i].login1) == 0)
        {
           return -1;
        }
    }

    if (s[3]!='.' && s[7]!='.' && s[11]!='.') //Verifica se tem todos os pontos
    {
        return -2;
    }
    else if (strlen(s)!=14)  //Verifica se tem 14 digitos
    {
        return -3;
    }
    else if(isdigit(s[0])==0 || isdigit(s[1])==0 ||
    isdigit(s[2])==0 || isdigit(s[4])==0 ||
    isdigit(s[5])==0 || isdigit(s[6])==0 ||
    isdigit(s[8])==0 || isdigit(s[9])==0 ||
    isdigit(s[10])==0 || isdigit(s[12])==0 ||
    isdigit(s[13])==0 && isdigit(s[14])==0)
    {
    return -4; //Verifica se é digito
    }
    else
    {
        return 1;
    }
}

void arquivo_Txt()
{
    FILE *file;

    file = fopen("string.txt", "w");

    if (file == NULL)
    {
        printf("ERRO! O arquivo não foi aberto!\n");
    }
    else
    {
        for(i=0;i<tam;i++)
        {
            if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
            {
                clear();
                fprintf(file, "CPF do titular da conta: %s\n", usuario[i].login1);
                fprintf(file, "Seu extrato e de: %0.2f\n", usuario[i].saldo_Atual);

                fclose(file);

                printf("Imprimindo seu extrato por favor Aguarde \n");
            }
        }
    }
}

void extrato_Console()
{
    for(i=0;i<tam;i++)
    {
        if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
        {
            printf("CPF do titular da conta: %s\n", usuario[i].login1);
            printf("Seu extrato e de: %0.2f\n", usuario[i].saldo_Atual);
        }
    }
}

//Função que faz a criação de uma conta no sistema do banco.
void criacao_Conta()
{
    printf("Insira seu CPF para cadastro EX: XXX.XXX.YYY.YY\n");
    printf("Ou digite 1 para voltar\n");
    setbuf(stdin,NULL);
    scanf("%s", usuario[tam].login1);

    if(validacao_Cpf(usuario[tam].login1) == -1)
    {
        clear();
        printf("CPF ja cadastrado!\n");
        return;
    }

    if (strcmp(usuario[tam].login1, "1") == 0)
    {
        clear();
        return;
    }
    //Validacao login e senha atraves da função com retorno.
    else if (validacao_Cpf(usuario[tam].login1) == -2)
    {
        clear();
        printf("Digite os pontos nos lugares requisitados \n");
        criacao_Conta();
    }
    else if (validacao_Cpf(usuario[tam].login1) == -3)
    {
        clear();
        printf("Digite o total de 14 caracteres(incluindo os pontos) \n");
        criacao_Conta();
    }
    else if(validacao_Cpf(usuario[tam].login1) == -4)
    {
        clear();
        printf("Digite apenas números \n");
        criacao_Conta();
    }
    else
    {

        printf("Insira sua senha para cadastro \n");
        setbuf(stdin,NULL);
        scanf("%s", usuario[tam].senha1);

        if(validacao_Senha(usuario[tam].senha1) == -1)
        {
            clear();
            printf("A senha precisa conter no minimo 6 caracteres! \n");
            criacao_Conta();
        }
        else if(validacao_Senha(usuario[tam].senha1) == -2)
        {
            clear();
            printf("Não repita 2 caracteres iguais seguidos \n");
            criacao_Conta();
        }
        else
        {
        clear();
        printf("Usuario cadastrado! \n");
        tam++;
        }
    }
}

//Função que faz a verificação, se as credenciais estão certas ou não.
void sistema_Login()
{
    printf("Insira seu LOGIN: \n");
    printf("Ou digite 1 para voltar \n");
    setbuf(stdin,NULL);
    scanf("%s",login);

    if (strcmp(login, "1") == 0)
    {
        clear();
        return;
    }
    else if(validacao_Cpf(login) == -2)
    {
        clear();
        printf("Digite os pontos nos lugares requisitados \n");
        sistema_Login();
    }
    else if(validacao_Cpf(login) == -3)
    {
        clear();
        printf("Digite o total de 14 caracteres (incluindo os pontos) \n");
        sistema_Login();
    }
    else if(validacao_Cpf(login) == -4)
    {
        clear();
        printf("Digite apenas números \n");
        sistema_Login();
    }
    else
    {
        printf("SENHA:\n");
        scanf("%s",senha);

        if(tam==0)
        {
            printf("Por favor crie uma conta antes de iniciar.\n");
        }

        //Logica validacao se foi logado ou nao.
        for(i=0;i<tam;i++)
        {
            if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
            {
            	    clear();
            	    printf("Logado com sucesso\n");
                    check_Login++;
            }

            if(check_Login==0)
            {
                clear();
                printf("Senha ou CPF incorretos\n");

                times_login++;
                if(times_login>4)
                {
                    clear();
                    printf("Voce tentou logar muitas vezes \n Se esqueceu a senha entre em contato com o email SisBanco@hotmail.com \n");
                    return;
                }
            }
        }
    }
}

//Função que faz o deposito para a conta solicitada, somando com o saldo total.
void depositar_Dinheiro()
{
    clear();
    float deposito;

    for(i=0;i<tam;i++)
    {
        if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
        {
            //Coleta de dados do deposito.
            printf("Saldo atual: %0.2f\n", usuario[i].saldo_Atual);
            printf("Quanto deseja depositar?\n");
            scanf("%f", &deposito);

            if(deposito == 0)
            {
                clear();
                printf("Digite um valor maior que 0\n");
            }
            else
            {
                clear();
                //Logica soma saldo mais deposito.
                usuario[i].saldo_Atual = usuario[i].saldo_Atual + deposito;
                printf("Deposito efetuado com sucesso!\n");

            }
        }
    }
}

//Função que faz o saque do dinheiro subtraindo o valor do saldo total.
void sacar_Dinheiro()
{
    clear();
    float saque;

    for(i=0;i<tam;i++)
    {
       if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
        {
            printf("Saldo atual: %0.2f\n", usuario[i].saldo_Atual);
            printf("Quanto deseja Sacar?");
            scanf("%f", &saque);

            if(saque<=usuario[i].saldo_Atual)
            {
                clear();
                //Logica subtracao saldo menos saque.
                usuario[i].saldo_Atual = usuario[i].saldo_Atual - saque;
                printf("Saque efetuado com sucesso!\n");
            }
            else
            {
                clear();
                printf("Saldo indisponivel\n");
            }
        }
    }
}

//Função que retorna os dados da conta em conjunto com o saldo na conta.
void extrato()
{
    clear();

    for(i=0;i<tam;i++)
    {
        if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
        {
            clear();
            arquivo_Txt();
            extrato_Console();
        }
    }
}

void transferir_Dinheiro()
{
    clear();
    float transferencia;
    char comparacao[15];

    //Logica transferencia de dinheiro de uma conta para outra
    for(i=0;i<tam;i++)
    {
        if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
        {
            //Coleta de dados do deposito.
            printf("Saldo atual: %0.2f\n", usuario[i].saldo_Atual);
            printf("Quanto deseja transferir?\n");
            scanf("%f", &transferencia);

            if(transferencia<=usuario[i].saldo_Atual)
            {
                printf("Insira o CPF da conta a receber:\n");
                scanf("%s",comparacao);

                for(i=0;i<tam;i++)
                {
                    if (strcmp(comparacao, usuario[i].login1) == 0)
                    {
                        clear();
                        //Logica soma saldo mais deposito.
                        usuario[i].saldo_Atual = usuario[i].saldo_Atual + transferencia;
                        printf("Deposito efetuado com sucesso!\n");

                        for(i=0;i<tam;i++)
                        {
                           if (strcmp(login, usuario[i].login1) == 0 & strcmp(senha, usuario[i].senha1) == 0 )
                            {
                                if(transferencia<=usuario[i].saldo_Atual)
                                {
                                    //Logica subtracao saldo menos saque.
                                    usuario[i].saldo_Atual = usuario[i].saldo_Atual - transferencia;
                                }
                            }
                        }
                    }
                    else
                    {
                        clear();
                        printf("Conta inexistente por favor verifique o CPF!\n");
                    }
                }
            }
            else
            {
                clear();
                printf("Saldo indisponivel\n");
            }
        }
    }
}

//Função que encerra o banco.
void sair()
{
    clear();
    printf("Encerrando sessao...\n");
    check_Login=0;
}

void encerrar()
{
    clear();
    printf("Finalizando aplicativo...\n");
    check_Login = 2;
}


int menu_Inicial()
{

    int home_Continuar=0;

    //Saida de dados menu Inicial.
    do
    {

        printf("**********************************\n");
        printf("\tSISTEMA DE BANCO\n");
        printf("**********************************\n");

        printf("1.CRIAR UMA CONTA\n");
        printf("2.FAZER LOGIN\n");
        setbuf(stdin,NULL);
        scanf("%i", &home_Continuar);

        if (home_Continuar == 1)
        {
            clear();
            home_Continuar = 1;
        }
        else if (home_Continuar == 2)
        {
            clear();
            home_Continuar = 2;
        }
        else
        {
            clear();
            printf("Digite uma opcao valida\n");
        }


      //Logica de escolha no menu Inicial.
        switch(home_Continuar)
        {
            case 1:
                criacao_Conta();
                break;

            case 2:
                sistema_Login();
                break;
        }

        home_Continuar = 0;

    }while(check_Login==0);

}

int main()
{
    menu_Inicial();

    //Sistema de escolha no menu principal
    int continuar=0;

    //Saida de dados menu principal.
    do
    {
        printf("**********************************\n");
        printf("\tSISTEMA DE BANCO\n");
        printf("**********************************\n");

        printf("1.DEPOSITAR DINHEIRO\n");
        printf("2.SACAR DINHEIRO\n");
        printf("3.EXTRATO\n");
        printf("4.TRANSFERIR PARA OUTRA CONTA\n");
        printf("5.ENCERRAR SESSAO\n");
        printf("6.FECHAR APLICATIVO\n");
        setbuf(stdin,NULL);
        scanf("%d", &continuar);

       if(continuar > 0 && continuar < 7)
        {
            continuar=continuar;
        }
        else
        {
            clear();
            printf("Digite uma opcao valida\n");
        }

        //Logica de escolha no menu principal.
        switch(continuar)
        {
            case 1:
            depositar_Dinheiro();
            break;

            case 2:
                sacar_Dinheiro();
                break;

            case 3:
                extrato();
                break;

            case 4:
                transferir_Dinheiro();
                break;

            case 5:
                sair();
                menu_Inicial();
                break;

            case 6:
                encerrar();
                break;
        }

        continuar = 0;

    }while(check_Login==1);
}
