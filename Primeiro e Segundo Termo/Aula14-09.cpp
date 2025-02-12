#include <stdio.h>
#include <stdlib.h>
#include "meuconio.h"
#include <ctype.h>
#include <string.h>

#define TF 50

struct TpFone{
	int DDD,Numero;
};

struct TpData{
	int dia,mes,ano;
};

struct TpEnd{
	char rua[30],Compl[20],Bairro[20],Cidade[40],Estado[3],Pais[30],Cep[10];
	int Num;
};

struct TpAgenda{
	char Nome[40],obs[100],Email[50];
	TpEnd Endereco;
	TpFone Fone;
	TpData Data;
};

void Cadastro(TpAgenda Ag[TF],int &TL){
	char AuxEmail[50];
	system("cls");
	printf("\n### Cadastro de Pessoas###\n");
	printf("Email:"); fflush(stdin);
	scanf("%s",&AuxEmail);
	while(TL<TF && strcmp(AuxEmail,"/0")!=0){
		strcpy(Ag[TL].Email,AuxEmail);
		printf("nome:");fflush(stdin);
		gets(Ag[TL].Nome);
		printf("Telefone (DDD Numero)");
		scanf("%d%d",&Ag[TL].Fone.DDD,&Ag[TL].Fone.Numero);
		printf("Data de Nascimento[dd mm aaaa]:");
		scanf("%d%d%d",&Ag[TL].Data.dia,&Ag[TL].Data.mes,&Ag[TL].Data.ano);
		printf("Endereço (Rua Numero complemento bairro):");
		scanf("%s%d%s%s",&Ag[TL].Endereco.rua,&Ag[TL].Endereco.Num,&Ag[TL].Endereco.Compl,&Ag[TL].Endereco.Bairro);
		printf("Localidade [Cidade Estado Pais e Cep]:");
		scanf("%s%s%s%s",&Ag[TL].Endereco.Cidade,&Ag[TL].Endereco.Estado,&Ag[TL].Endereco.Pais,&Ag[TL].Endereco.Cep);
		TL++;
	}
}

int main(){
	TpAgenda Agenda[TF];
	int TL=0;
	Cadastro(Agenda, TL);
}
