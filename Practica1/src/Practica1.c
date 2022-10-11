/*
 ============================================================================
 Name        : Practica1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"

typedef struct {
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[10];
	char ataqueCargado[100];
	int valorAtaque;
	int esVariocolor;
} Pokemon;
//-----------------------------------------------------GETTERS
int pokemon_getNumero(Pokemon* p,int* numero);
int pokemon_getNombre(Pokemon* p,char* nombre);
int pokemon_getTipo(Pokemon* p,char* tipo);
int pokemon_getTamanio(Pokemon* p,char* tamanio);
int pokemon_getAtaqueCargado(Pokemon* p,char* ataqueC);
int pokemon_getValorAtaque(Pokemon* p,int* vAtaque);
int pokemon_getEsVariocolor(Pokemon* p,int* variocolor);

int controller_saveAsText(LinkedList* lista, char*path);
int controller_Batalla(LinkedList* lista);
int countGanarBatalla(void* p);
int controller_mapeado(LinkedList* lista);
void* mapearAtaque(void* p);
int filtrarWater(void* p);
LinkedList* controller_filter(LinkedList* lista);
int controller_remove(LinkedList* lista);
int buscarPokemon(LinkedList* lista,int numero);
void mostrarPokemon(Pokemon *p) ;
int controller_show(LinkedList *lista);
int menu(void);
int controller_loadFromText(char *path, LinkedList *lista);
int parserFromText(FILE *f, LinkedList *lista);

int controller_sort(LinkedList* lista);
int compararTipoValorAtaque(void* a, void* b);

int main(void) {
	setbuf(stdout, NULL);

	srand(time(NULL));
	float numero;
	int max = 10;
	int min = 5;

	numero = (float) (rand() % (max - min + 1) + min) * 1.1;
	printf("Numero %f\n", numero);

	numero = (float) (rand() % (max - min + 1) + min) / 1.1;
	printf("Numero %f\n", numero);
	numero = (float) (rand() % (max - min + 1) + min) * 1.1;
	printf("Numero %f\n", numero);

	puts("!!!Pokemon!!!"); /* prints !!!Hello World!!! */
	LinkedList* filtrada;
	char confirma[3];
	char seguir = 's';
	char path[100];
	LinkedList *lista = ll_newLinkedList();
	if (lista == NULL) {
		puts("Error en creacion de lista");
		exit(-1);
	}

	do {
		system("cls");
		switch (menu()) {
		case 1:
			if(ll_isEmpty(lista)==0)
			{
				fflush(stdin);
				puts("Lista ya cargada, desea sobrescribirla s/n");
				gets(confirma);
			}
			if((ll_isEmpty(lista)==1) || (stricmp(confirma,"si")==0))
			{
				ll_clear(lista);
				fflush(stdin);
					puts("Ingrese path (Data_Pokemones.csv)");
					gets(path);
					if(controller_loadFromText(path, lista))
					{
						puts("Lectura exitosa");
					}
					else
					{
						puts("Error en lectura de archivo");
					}


			}


			break;
		case 2:
			if(ll_isEmpty(lista))
			{
				puts("Lista vacia");
			}
			else
			{
				if(controller_remove(lista))
				{
					puts("eliminacion exitosa");
				}
				else
				{
					puts("Error en eliminancion");
				}
			}
			break;
		case 3:
	printf("resulatdo de mosktarr:%d\n",controller_show(lista));
			break;
		case 4:
			if(ll_isEmpty(lista))
			{
				puts("Lista vacia");
			}else
			{

						filtrada= controller_filter(lista);
						if(filtrada!=NULL)
						{
								if(ll_isEmpty(filtrada)==0)
								{
									puts(" Guardar lista no vacia");
									ll_deleteLinkedList(filtrada);
								}
						}else
						{
							puts("Error en filtrado");
						}
			}
			break;
		case 5:
			if(ll_isEmpty(lista)==1)
			{
				puts("lista vacia");
			}
			else
			{
				if(controller_mapeado(lista))
				{
					puts("Mapeado exitoso");
				}
				else
				{
					puts("Error en mapeado");
				}
			}
			break;
		case 6:
			if(ll_isEmpty(lista)==1)
			{
				puts("lista vacia");
			}
			else
			{
				if(controller_Batalla(lista))
				{
					puts("Batalla producida con exito");
				}
				else
				{
					puts("Error al realizar batalla");
				}
			}


			break;
		case 7:
			if(ll_isEmpty(lista))
			{
			puts("Lista vacia");

			}
			else
			{
				fflush(stdin);
				puts("Ingrese path");
				gets(path);
				if(controller_saveAsText(lista,path))
				{

					printf("Archivo guardado en: %s\n",path);
				}
				else
				{
					puts("Error en guardadod e archivo");
				}

			}
			// gurdar
			break;
		case 8:
			if(ll_isEmpty(lista))
			{

				puts("lista vacia");
			}
			else{

				if(controller_sort(lista))
				{
					puts("Ordenamiento exitoso");
				}
				else
				{
					puts("error en ordenamiento");
				}
			}
			//ordenar
			break;
		case 9:
			break;

		case 10:
			seguir = 'n';
			break;
		default:
			break;

		}
		system("pause");
	} while (seguir == 's');





ll_deleteLinkedList(lista);


	return EXIT_SUCCESS;
}

int filtrarWater(void* p)
{
	int todoOk=0;
	if(p!=NULL)
	{
		if(stricmp(((Pokemon*)p)->tipo,"Water")==0)
		{
			todoOk=1;
		}
	}
		return todoOk;
}
LinkedList* controller_filter(LinkedList* lista)
{
	LinkedList* filtrada=NULL;
	if(lista!=NULL)
	{
		filtrada=ll_filter(lista,filtrarWater);
		if(filtrada!=NULL)
		{
			controller_show(filtrada);
		}
	}
	return filtrada;
}
int controller_remove(LinkedList* lista)
{
	int todoOk=0;
	int num;
	Pokemon* aux=NULL;
	char confirma[3];
	int indice;
	if(lista!=NULL)
	{
	controller_show(lista);
	fflush(stdin);
	puts("Ingrese numero de pokemon a eliminar");
	while(!scanf("%d",&num))
	{
		fflush(stdin);
		puts("Error, reingrese num");

	}
	indice=buscarPokemon(lista,num);
	if(indice!=-1)
	{
		aux=(Pokemon*)ll_get(lista,indice);
		if(aux!=NULL)
		{

			mostrarPokemon(aux);
			fflush(stdin);
			puts("Confirma eliminacion si/no?");
			gets(confirma);
			if(stricmp(confirma,"si")==0)
			{
				ll_remove(lista,indice);
				if(ll_contains(lista,aux)==0)
				{
					todoOk=1;
				}

			}else
			{
				puts("Eliminacion cancelada por el ususario");
			}

		}
	}
	else
	{

		puts("Numero no encontrado");
	}


	}
	return todoOk;

}

Pokemon* newPokemon(void)
{
	Pokemon* aux=NULL;
	aux=(Pokemon*)calloc(1,sizeof(Pokemon));
	return aux;
}
Pokemon* newPokemonParam(char* numero,char* nombre, char* tipo,char* tamanio,char* ataque,char* valorAtaque,char* variocolor)
{
Pokemon* aux=NULL;
if(numero!=NULL && nombre!=NULL && tamanio!=NULL && ataque!=NULL && valorAtaque!=NULL && variocolor!=NULL)
{
	aux=newPokemon();
	if(aux!=NULL)
	{
		aux->numero=atoi(numero);
		strcpy(aux->nombre,nombre);
		strcpy(aux->tamanio,tamanio);
		strcpy(aux->tipo,tipo);
		strcpy(aux->ataqueCargado,ataque);
		aux->esVariocolor=atoi(variocolor);
	aux->valorAtaque=atoi(valorAtaque);

	}
}
return aux;
}


int menu(void) {
	int opcion;
	puts("Menu Pokemon");
	puts("1-Cargar archivos pokemones");
	puts("2-Eliminar Pokemon");
	puts("3-Imprimir pokemones");
	puts("4-Filtrar de tipo Agua variocolor");
	puts("5- Mapear ataque cargado");

	puts("6_ batalla pokemon");
	puts("7_Guardar texto");
	puts("10 - salir");
	fflush(stdin);
	while (!scanf("%d", &opcion)) {
		fflush(stdin);
		puts("ERROR REingrese opcion");
	}
	return opcion;
}
int controller_loadFromText(char *path, LinkedList *lista) {
	int todoOk = 0;
	FILE *f = NULL;
	if (path != NULL && lista != NULL) {

		f = fopen(path, "r"); //lectura
		if (f != NULL) {

			if (parserFromText(f, lista)) {
				todoOk = 1;
			}

			fclose(f);
		}

	}
	return todoOk;
}
int parserFromText(FILE *f, LinkedList *lista) {
	int cant;
	Pokemon* aux=NULL;
	int todoOk = 0;
	char buffer[7][100];
	if (f != NULL && lista != NULL) {
		todoOk = 1;
		/*
		 * NO HAY ENCABEZADO
		 *
		 * fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
				buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],
				buffer[6]);
		puts("leyendo:");
		printf("%s-%s-%s-%s-%s-%s-%s\n", buffer[0], buffer[1], buffer[2],
				buffer[3], buffer[4], buffer[5], buffer[6]);
*/
		while (!feof(f)) {

			cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
					buffer[5], buffer[6]);
			if (cant < 7) {
				break;
			}
			//puts("TENGO q escribir esto en memoria");
			//printf("%s-%s-%s-%s-%s-%s-%s\n", buffer[0], buffer[1], buffer[2],
				//	buffer[3], buffer[4], buffer[5], buffer[6]);
			aux=newPokemonParam(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			if( aux!=NULL)
			{
				puts("Pokemon creado:");
				mostrarPokemon(aux);
				ll_add(lista,aux);
			}
		}

	}

	return todoOk;
}
void mostrarPokemon(Pokemon *p) {
	if (p != NULL) {
		printf("%6d %-10s %-10s %-10s %-10s %6d %6d\n", p->numero, p->nombre,
				p->tipo, p->tamanio, p->ataqueCargado, p->valorAtaque,
				p->esVariocolor);
	}

}
int controller_show(LinkedList *lista) {

	int todoOk = 0;
	int tam;
	Pokemon *aux = NULL;
	if (lista != NULL) {
		todoOk = 1;
		tam = ll_len(lista);
		for (int i = 0; i < tam; i++) {
			aux = (Pokemon*) ll_get(lista, i);
			if (aux != NULL) {
				mostrarPokemon(aux);
			}

		}
	}
	return todoOk;
}

/// @param lista
/// @param numero
/// @return -1 error ok indice del elemento
int buscarPokemon(LinkedList* lista,int numero)
{

	Pokemon* aux=NULL;
	int indice=-1;
	int tam;
	if (lista != NULL) {
	tam = ll_len(lista);
	for (int i = 0; i < tam; i++)
	{
		aux=(Pokemon*)ll_get(lista,i);
		if(aux!=NULL)
		{
			if(aux->numero== numero)
			{
				indice=i;
				break;
			}
		}

	}

	}
		return indice;
}
///la modificación del valor del ataque cargado según el siguiente criterio:
///Como el dia esta despejado, los pokemones de tipo Fire, Ground y Grass
///aumentarán su poder un 10%;
void* mapearAtaque(void* p)
{
	int random;
	int max=50;
	int min=20;
	int valor;
	if(p!=NULL)
	{
		if((stricmp(((Pokemon*)p)->tipo,"Fire")==0)||
		(stricmp(((Pokemon*)p)->tipo,"Ground")==0) ||
		(stricmp(((Pokemon*)p)->tipo,"Grass")==0))
		{
			valor=((Pokemon*)p)->valorAtaque;
			//((Pokemon*)p)->valorAtaque= valor+( valor*0.1);
			random=rand()% (max-min+1)+min;
			((Pokemon*)p)->valorAtaque=valor+random;

		}

	}
	return p;
}
int controller_mapeado(LinkedList* lista)
{
	int todoOk=0;
	if(lista!=NULL)
	{

		lista=ll_map(lista,mapearAtaque);
		if( lista!=NULL)
		{
			controller_show(lista);
			todoOk=1;
		}
	}


	return todoOk;
}
int countGanarBatalla(void* p)
{
	int count=0;
	Pokemon* aux=NULL;
	if(p!=NULL )
	{

		aux=(Pokemon*)p;
		if( aux!=NULL)
		{
			if(((stricmp(aux->tipo,"Fire")==0) && (stricmp(aux->tamanio,"XL")==0) && (stricmp(aux->ataqueCargado,"Lanzallamas")==0) && (aux->valorAtaque>80)) ||
				((stricmp(aux->tipo,"Water")==0) && (stricmp(aux->tamanio,"L")==0) && (stricmp(aux->ataqueCargado," Hidrobomba")==0) && (aux->valorAtaque>80)))
			{
				count++;
			}
		}
	}

return count;
}
int controller_Batalla(LinkedList* lista)
{
int todoOk=0;
	int cantidad;
	if (lista != NULL) {
		cantidad = ll_count(lista, countGanarBatalla);
		if (cantidad != -1) {

			printf("La cantidad de pokemones que pueden ganar la batalla son %d\n",cantidad);
			if(cantidad>2)
			{
				printf(" Ganamos la batalla por que hay minimo 3 pokemones");
			}
			else
			{
				puts("No se pudo vencer al pokemon legendario con la cantidad de pokemones");
			}
			todoOk=1;
		}
	}


return todoOk;
}
int controller_saveAsText(LinkedList* lista, char*path)
{
	int todoOk=0;
	int tam;
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[10];
	char ataqueC[100];
	int valorAtaque;
	int esVariocolor;


	Pokemon* p=NULL;
	FILE* aux=NULL;
	FILE* f=NULL;
	char confirma[3];
	if( lista!=NULL && path!=NULL)
	{
		aux=fopen(path,"r");
		if(aux!=NULL)
		{
			fflush(stdin);
			puts("Archivo existente desea sobreescribirlo?si/no");
			gets(confirma);
			fclose(aux);
		}
		if( aux==NULL || stricmp(confirma,"si")==0)
		{
			f=fopen(path,"w");
			if(f!=NULL)
			{
				todoOk=1;

				tam=ll_len(lista);
				for(int i=0;i<tam;i++)
				{

					p=(Pokemon*)ll_get(lista,i);
					if( p!=NULL)
					{
						if(pokemon_getNombre(p,nombre) && pokemon_getNumero(p,&numero)&& pokemon_getTipo(p,tipo) && pokemon_getTamanio(p,tamanio) && pokemon_getAtaqueCargado(p,ataqueC) && pokemon_getValorAtaque(p,&valorAtaque) && pokemon_getEsVariocolor(p,&esVariocolor))
						{
								fprintf(f,"%d,%s,%s,%s,%s,%d,%d\n",numero,nombre,tipo,tamanio,ataqueC,valorAtaque,esVariocolor);
								printf("Escribiendo %d,%s,%s,%s,%s,%d,%d\n",numero,nombre,tipo,tamanio,ataqueC,valorAtaque,esVariocolor);
						}

					}

				}

				fclose(f);
			}



			}

		}
	return todoOk;
	}

//-----------------------------------------------------GETTERS
int pokemon_getNumero(Pokemon* p,int* numero)
{
	int todoOk=0;
	if(p!=NULL && numero!=NULL)
	{
		*numero=p->numero;
		todoOk=1;
	}
	return todoOk;
}
int pokemon_getNombre(Pokemon* p,char* nombre)
{
	int todoOk=0;
	if(p!=NULL && nombre!=NULL)
	{
		todoOk=1;
		strcpy(nombre,p->nombre);
	}
	return todoOk;
}
int pokemon_getTipo(Pokemon* p,char* tipo)
{
	int todoOk=0;
	if(p!=NULL && tipo!=NULL)
	{
		todoOk=1;
		strcpy(tipo,p->tipo);
	}
	return todoOk;
}
int pokemon_getTamanio(Pokemon* p,char* tamanio)
{
	int todoOk=0;
	if(p!=NULL && tamanio!=NULL)
	{
		todoOk=1;
		strcpy(tamanio,p->tamanio);
	}
	return todoOk;
}
int pokemon_getAtaqueCargado(Pokemon* p,char* ataqueC)
{
	int todoOk=0;
	if(p!=NULL && ataqueC!=NULL)
	{
		todoOk=1;
		strcpy(ataqueC,p->ataqueCargado);
	}
	return todoOk;
}
int pokemon_getValorAtaque(Pokemon* p,int* vAtaque)
{
	int todoOk=0;
	if(p!=NULL && vAtaque!=NULL)
	{
		todoOk=1;
		*vAtaque=p->valorAtaque;
	}
	return todoOk;
}
int pokemon_getEsVariocolor(Pokemon* p,int* variocolor)
{
	int todoOk=0;
	if(p!=NULL && variocolor!=NULL)
	{
		todoOk=1;
		*variocolor=p->esVariocolor;
	}
	return todoOk;
}
int controller_sort(LinkedList* lista)
{

int todoOk=0;
LinkedList* copia;

	if( lista!=NULL)
	{
		copia=ll_clone(lista);
		if(copia!=NULL)
		{
			if(ll_sort(copia,compararTipoValorAtaque,1)==0)
			{
				controller_show(copia);
				todoOk=1;
				ll_deleteLinkedList(copia);
			}

		}
	}

return todoOk;


}
int compararTipoValorAtaque(void* a, void* b)
{
	int todoOk=0;
	Pokemon* aux1=NULL;

	Pokemon* aux2=NULL;
	if(a!=NULL && b!=NULL)
	{

		aux1=(Pokemon*)a;
		aux2=(Pokemon*)b;
		if(aux1!=NULL && aux2!=NULL)
		{

			if(((stricmp(aux1->tipo,aux2->tipo)==0) && (aux1->valorAtaque >aux2->valorAtaque)) ||
					((stricmp(aux1->tipo,aux2->tipo)>0)))
			{
				todoOk=1;
			}
			if(((stricmp(aux1->tipo,aux2->tipo)==0) && (aux1->valorAtaque <aux2->valorAtaque)) ||
								((stricmp(aux1->tipo,aux2->tipo)<0)))
						{
							todoOk=-1;
						}

		}


	}

return todoOk;
}
