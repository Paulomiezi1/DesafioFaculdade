#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <windows.h>
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
          reiniciar:printf("\n\t\t\t\t\t\tUNIVERSIDADE KIMPA VITA\n");
					printf("\t\t\t\t\tESCOLA SUPERIOR POLIT�CNICA DO U�GE\n");
					printf("\t\t\t\t\t\tENGENHARIA INFORM�TICA\n\n\n");
					
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo=localtime (&rawtime);
	 
	int op, numIbam, ibam=1996, 
	    senha,novaSenha,senhaConfirm, posi=3, senha1=100,
		cancelarTentar, conf, valorLevantar,i=0;

	float saldo, valor, numTentativas, 
          valorDepositar, saldoTrans, valorTrans,
		  saldoTransferido,limiteLevantamento;
		//
		printf("\n\n");
		refazer:printf("\t\tIntroduza a senha: ");
	scanf("%d",&senha);
		system("cls");
		if(senha==senha1){
			refaz: printf("\n\n");
			printf("\n\n");
			printf("\t\t\t\t|********************************************************************|\n");
			printf("\t\t\t\t|                                                                    |\n");
			printf("\t\t\t\t|-----------------SEJA BEM VINDO AO SISTEMA MULTICAIXA---------------|\n");
			printf("\t\t\t\t|                                                                    |\n");
			printf("\t\t\t\t**********************************************************************\n\n");;
	      
			printf("\t\t\t\t\t\t ____________MENU PRINCIPAL____________\n");
			printf("\t\t\t\t\t\t|                                      |\n");
			printf("\t\t\t\t\t\t|           <1> Levantamento           |\n");
			printf("\t\t\t\t\t\t|           <2> Transfer�ncia          |\n");
			printf("\t\t\t\t\t\t|           <3> Consultar Saldo        |\n");
			printf("\t\t\t\t\t\t|           <4> Dep�sito               |\n");
			printf("\t\t\t\t\t\t|           <5> Alterar o C�digo       |\n");
			printf("\t\t\t\t\t\t|           <6> Sair do Sistema        |\n");
			printf("\t\t\t\t\t\t|______________________________________|\n\n");
	
		
			printf(" \t\tEscolha uma das op��es: ");	
			scanf("%d",&op);
		
	switch(op)
	{
        case 1:
        	printf("\t\tIntroduza o valor a Levantar: ");
        	scanf("%d",&valorLevantar); 
        
        if(valorLevantar>50000)
        {                  
        	printf("\t\tN�o � poss�vel levantar um valor superior a 50.000 kz\n");
        }
         //
        else if (saldo<=0)
        {
        	printf("\t\tSaldo insuficiente, faz um dep�sito antes!\n");
        }
        //
        else if(saldo>=valorLevantar)
		{
			if((valorLevantar%500==0))
			{
			 limiteLevantamento=limiteLevantamento+valorLevantar;
		  if(limiteLevantamento<=50000)
		  {
		  	saldo=saldo-valorLevantar;
			printf("\n\n");
			printf("\t\t Hora e Data de: %s\n\n",asctime(timeinfo));
			printf("Opera��o efectuada no valor de %d,00 o saldo actual � de: %2.2f\n ", valorLevantar,saldo);
			printf("\t\tDigite qualquer tecla para tirar o Cart�o");
			scanf("%d", &conf);
			system("CLS");
			goto refazer;
		  }	
		  else
		  {
		  	printf("\t\t S� � permitido levantar 50.000,00 por dia\n");
		  }
			} 
			else
			{
				//Caso o valor n�o seja m�ltiplo de 500kz, imprima:
				printf("\t\t\t Verifique o seu valor para Levantamento \n");
			}
		} 
		else
		{
		 printf("\t\t\t Opera��o n�o autorizada!\n"); //Caso o valor for maior que o Saldo.
		}
		system("PAUSE");
		system("CLS");
		goto refaz;
		printf("\n"); break; //Para a instru��o e repita o programa.
         
      	case 2:
       	printf("Introduza o n�mero de IBAN para transfer�ncia:");
       	scanf("%d",&numIbam);
       	if(numIbam==ibam)
       	{
       	  printf("Introduza o Valor da Transfer�ncia. \n");
			 scanf("%f",&valorTrans);
			 if((saldo>0)&&(saldo>=valorTrans))
		{
			saldo=saldo-valorTrans;
			saldoTransferido=saldoTransferido+valorTrans;
			
			printf("\t\t\t Hora e Data de: %s\n\n",asctime(timeinfo));
			printf("\t\t\t O Saldo transferido � de %2.3f para o IBAM %d\n", valorTrans,ibam);
		}
		else
	   	{
	   	printf("\t\t\tO Saldo da sua conta � insuficiente\n");
	    }
       	}
       	else
       	{
       		printf("\t\t\t O n�mero do IBAM n�o existe, verifique Novamente!");
       	}
       		system("PAUSE");
       		system("cls");
       		goto refaz;
       		printf("\n"); break;
       	
       	case 3:
       		
       		printf("\t\t Hora e Data de: %s\n\n",asctime(timeinfo));
       		printf("\t \t\t\t O Saldo da sua conta e %2.2f Kz \n\n",saldo);
			system("PAUSE");
       		system("cls");
       		goto refaz;
       		printf("\n");break; 
       		
       	case 4:
       			
			printf("\t\tIntroduza o Valor a Depositar: ");
			scanf("%f",&valorDepositar);
			saldo=saldo+valorDepositar;
			printf(" \n");
			printf("\t\t\t Hora e Data de: %s\n\n",asctime(timeinfo));
			printf("\t\t\t Valor depositado O seu Saldo Actual e de %2.2f \n\n",saldo);
			system("PAUSE");
			system("CLS");
			goto refaz;
			printf("\n");break;
		
		case 5:
			printf("\n");
			printf("\t\tInsere a nova Senha: ");
			scanf("%d",&novaSenha);
			printf("\t\tConfirma a nova senha: ");
			scanf("%d", &senhaConfirm);
			
			if(senhaConfirm==novaSenha)
			{
			 senha1=novaSenha;
			 printf("\t\tO seu c�digo foi alterado com Sucesso.\n");
			 printf("\t\tPresione 0 para concluir! \n");
			 scanf("%d",&conf);
			 system("cls");
			 goto refaz;
			  }  
			 else
			 {
			 	printf("\n\n");
			 	printf("\t\tWarning! A senha n�o � a mesma! \n");
			 	printf("\t\tPresione 0 para concluir. ");
			 	scanf("%d",&conf);
			 	
				system("cls");
				goto refazer;	
			 }
			printf("\n"); break;
	} 
		}	
		else
		{	
			for(;;){
				posi=posi-1;
			printf("\n\n");
			printf("\t\t\t\tC�digo errado, restam apenas %d tentativas \n\n",posi);
				if(posi==0){
					printf("\t\t\t\tCart�o bloqueado \n\n");
					system("PAUSE");
					}
				goto refazer;
				} while(op!=6);
			}
    system("PAUSE");
	return 0;
}
