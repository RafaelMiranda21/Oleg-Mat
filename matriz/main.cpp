#include <QCoreApplication>
#include <bits/stdc++.h>
#include "matriz.h"

int main()
{
    int tamacol,tamalinha;
    int escolha,qualmat;
    puts("Digite a quantidade de linhas da primeira matriz : ");
    std::cin>>tamalinha;
    puts("Digite a quantidade de colunas da primeira matriz : ");
    std::cin>>tamacol;
    TP2::Matriz *teste1 = new TP2::Matriz(tamalinha,tamacol);
    TP2::Matriz *auxtest= new TP2::Matriz(tamalinha,tamacol);
    TP2::Matriz *teste2= new TP2::Matriz(tamalinha,tamacol);


    do
    {
        puts("1- Para setar um valor na matriz");
        puts("2- Para setar um valor para a segunda matriz " );
        puts("3- Para somar a matriz criada");
        puts("4- Para subtrair a matriz");
        puts("5- Para mostrar todas as matrizes");
        puts("6- Para determinar se a matriz é triangular inferior");
        puts("7- Para determinar se a matriz é triangular superior");
        puts("8- Para determinar se a matriz é identidade");
        puts("9- Para determinar a matriz transposta");
        puts("10- Para determinar se a matriz é simetrica");
        puts("11- Para determinar se as duas matrizes são iguais ou diferentes");
        puts("12- Para determinar se a matriz é ortogonal");        //falta terminar
        puts("13- Para determinar se a matriz é de permutação");        //falta terminar
        puts("14- Para calcular a multiplicação de duas matrizes");     //falta terminar
        puts("15- Para calcular a potenciação de uma matriz");      //falta terminar
        puts("0- Para sair do pograna ");
        std::cin>>escolha;

        switch (escolha) {
        case 1:

            int colocael,line,col;
            puts("Digite o valor que você quer inserir");
            std::cin>>colocael;
            puts("Digite a linha em que quer colocar o elemento");
            std::cin>>line;
            puts("Digite a coluna em que deseja colocar o elemento");
            std::cin>>col;
            teste1->setElemento(colocael,line,col);
            auxtest->setElemento(colocael,line,col);
            break;


        case 2:

            int colocaelaux,lineaux,colaux;
            puts("Digite o valor que você quer inserir\n");
            std::cin>>colocaelaux;
            puts("Digite a linha em que quer colocar o elemento\n");
            std::cin>>lineaux;
            puts("Digite a coluna em que deseja colocar o elemento\n");
            std::cin>>colaux;
            teste2->setElemento(colocaelaux,lineaux,colaux);

            break;

        case 3:

            auxtest=*teste1+(teste2);
            auxtest->getMatriz();
            break;

        case 4:

            auxtest=*teste1-(teste2);
            auxtest->getMatriz();
            break;

        case 5:

            std::cout<<"\nPrimeira matriz \n";
            teste1->getMatriz();
            std::cout<<"\n\nSegunda matriz \n";
            teste2->getMatriz();
            /*std::cout<<"\n\nAuxiliar matriz \n";
            auxtest->getMatriz();
            puts("");*/
            break;

        case 6:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->trianginf())
                        std::cout<<"\nA matriz é triangular inferior\n";
                    else
                        std::cout<<"\nA matriz não é triangular inferior\n";
                }
                if(qualmat==2)
                {
                    if(teste2->trianginf())
                        std::cout<<"\nA matriz é triangular inferior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular inferior\n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;

        case 7:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->triangsup())
                        std::cout<<"\nA matriz é triangular superior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular superior\n\n";
                }
                if(qualmat==2)
                {
                    if(teste2->triangsup())
                        std::cout<<"\nA matriz é triangular superior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular superior\n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;
        case 8:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->identidade())
                        std::cout<<"\nA matriz é identidade \n\n";
                    else
                        std::cout<<"\nA matriz não é identidade \n\n";
                }
                if(qualmat==2)
                {
                    if(teste2->identidade())
                        std::cout<<"\nA matriz é identidade \n\n";
                    else
                        std::cout<<"\nA matriz não é identidade \n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;

        case 9:
           std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
           do
           {
               std::cin>>qualmat;
               if(qualmat==1)
               {
                    auxtest->transposta(teste1);
                    auxtest->getMatriz();
               }
               if(qualmat==2)
               {
                   auxtest->transposta(teste2);
                   auxtest->getMatriz();
               }
               if(qualmat!=1&&qualmat!=2)
                   std::cout<<"\nDigite um numero valido!\n";

           }while(qualmat!=1&&qualmat!=2);
            break;

        case 10:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                     auxtest->transposta(teste1);
                     if(teste1->simetrica(auxtest))
                     {
                         std::cout<<"\n A matriz é simétrica ! \n\n";
                     }
                     else
                         std::cout<<"\n A matriz não é simétrica ! \n\n";
                }
                if(qualmat==2)
                {
                    auxtest->transposta(teste2);
                    if(teste2->simetrica(auxtest))
                    {
                        std::cout<<"\n A matriz é simétrica ! \n\n";
                    }
                    else
                        std::cout<<"\n A matriz não é simétrica ! \n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);
            break;

        case 11:

            if(teste1->iguais(teste2))
            {
                std::cout<<"\n A matrizes são iguais \n\n";
            }
            else
            {
                std::cout<<"\n A matrizes são diferentes \n\n";
            }
            break;

        case 12:


            break;

        case 13:

            break;

        case 14:

            auxtest=*teste1*(teste2);
            auxtest->getMatriz();
            break;

        case 15:

            break;

        default:
            break;
        }
    }while(escolha!=0);
    return 0;

}
