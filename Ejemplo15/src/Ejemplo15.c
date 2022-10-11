/*
 ============================================================================
 Name        : Ejemplo15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Nodo{
	void* carga;
	struct Nodo* nextNodo;

}typedef Nodo;

struct LinkedList{
	int tam;
	 Nodo* primerNodo;

}typedef LinkedList;


int ll_invertir(LinkedList* lista);
LinkedList* ll_map(LinkedList* lista,void*(*pFunc)(void*));
LinkedList* ll_filter(LinkedList* lista,int (*pFunc)(void*));
int ll_sort(LinkedList* lista, int (*pFunc)(void*,void*),int criterio);
LinkedList* ll_clone(LinkedList* lista);
LinkedList* ll_subList(LinkedList* lista, int desde,int hasta);
int ll_constainsAll(LinkedList* uno,LinkedList* dos);
int ll_contains(LinkedList* lista, void* carga);
void* ll_pop(LinkedList* lista, int indice);
int ll_push(LinkedList* lista, int indice, void* carga);
int ll_isEmpty(LinkedList* lista);
int ll_indexOf(LinkedList* lista,void* carga);
int ll_deleteLinkedList(LinkedList* lista);
LinkedList* ll_newLinkedList(void);
int ll_remove(LinkedList* lista,int indice);
int ll_clear(LinkedList* lista);
int ll_add(LinkedList* lista,void* carga);
int ll_len(LinkedList* lista);
Nodo* getNode(LinkedList* lista, int indice);
int addNode(LinkedList* lista, int indice,void* carga);
void* ll_get(LinkedList* lista, int indice);
int ll_set(LinkedList* lista, int indice,void* carga);



void showLista(LinkedList* lista,void (*pFuncMostrar)(void*));
void mostrar(void* a);
int main(void) {
	setbuf(stdout,NULL);
	puts("!!!CLASE 23 y 24 (miTp3 y linkedList)\n !!!"); /* prints !!!Hello World!!! */


/*
 *
 *
 * clase 23  clase 22 hacer controler
 * 23 linked list
	linked s una estructura q tiene dos canmposnew crea el linked list
	lllen gettter del campio size del tam
	sttati no publicas , estan el el punto c las usa ahi
	getNode retorna la direccion dek nodo, si es el primero la direccion kla tiene el linkedlist esino el nodo de adelanbte tiene la direcciond de memoria
	tiene q ser el indice tam -1 por q no exite el nodo tam
	addNOde crrea vagon lo carga y lo inserta en el indice indicado, lo q implica es q copiar la direccion del ex nodo en ese indice para q sea el siguiente y el anterior nodo hacer q apunte al nuevo nodo en ese orden por q si no pierdo la direccion del antreior nodo
	puede ser tam== por q puedo agregar al final, pero en elcaso q sea indice cero NO puedo husar getNodo -indice por q seria -1 y no da hay q sacar la dirreccion del linked list

	ll add agrega un elemento al final de la lista addNode(this,tam)  0 correcto -1 erro
	ll_get devuel void* la carga el campo *peLEMENTE  del nodo NULL error
	NUNCA HACER FREE del un elementto de la lista por q ottra lista lo puede tener
	ll_set pisa , inserta una carga en ese indice
	ll remove el el caso
	 del indice cero y en el cso q sea otro indice es diferente copia la dierccion del cmapo nextNode en el anterior nodo Y LIBERO EL NODO REMOVIDO NO La CARGA

	24 video

	llclear remove de todas los nodo la lista size cero, las cargas NADA si los NODOS , hacerlo desde el ultimo hasta el primero
	//las cargas no eliminarlas ni FREE
	 // tengo q rmover de atras ahcia delante para q coincida la variabñle de contrtol con el indice a eliminar usu remove
	ll_delete (clear y elininar el linked list
	indeoxOf(buscca la 1° ocurrencia de la carga
	isEmpty fija si la lista esta vacia usar llLen, usar para q el codigo sea mas semnantico
	ll_get( puede guardar un NULL
	ll_push agrega entre EN la posicion indicada, crea un Nodo y y coloca la carga

	ll_ pop elimina el nodo pero antes nos devuelve la garga

	ll_contains( verifica q la carga este en la lista
	ll_contains (Todos los elementos de la lista DOS en el uno reccoro lista dos y saco llGet de los lementos
	llSubList crea un nuevo linkedlist parate o toda DESDE HASTA(NO Incluido) si fuera la lista 4 elemento y quiero guardar del 2 hasta el cuatro tengo q aceptar ==tam 0 1 (2 3)  de este modo llega hasta el uktimo
	ll:cloe sublist de toda la lista
	llSort ordena la lista  de acuerdo del burbuijeo y el puntero de funcion



	   25
	   COde block
	   tP4 biblioteca de t4 q tiene el tes
	   copio linked.c y .h pego en nuevo proyecto carpeta y luego addFile y selecciono los archivos y elimino

	   LinkedList* ll_filter(lista , fucnion q sabe filtar9 ) crea un nuevo lined kist si la fubcuon etorna Uno agrego el nuevo linkedList
	   llMap

ALEATORIOS
Incuir time.h
solo una vez lo llamo en elmain
srand(time(NULL)); semilla inicializa desde el valor pasado como parametro
numero=rand();//si no pongo srand
	// si quiero q este entre un rango
	 * int max=200;
	 * int min=50;
	 * numeros=rand()%(max-min+1)+min;
	 *


*/
srand(time(NULL));
	int numeros;
	int max=10;
	int min=1;

	numeros=rand()%(max-min+1)+min;
	printf("numero :%d\n",numeros);
	numeros=rand()%(max-min+1)+min;
	printf("numero :%d\n",numeros);
	numeros=rand()%(max-min+1)+min;
	printf("numero :%d\n",numeros);



	float n;
	n=(float)(rand() % (max-min+1)+min)/100;
	printf("numero :%f\n",n);
	n=(float)(rand() % (max-min+1)+min)/1.10;
	printf("numero :%f\n",n);
	n=(float)(rand() % (max-min+1)+min)*1.0f;
	printf("numero :%f\n",n);


	float c=(float)(rand()%(max-min+1)+min)/1.10;
	printf("numero %f\n",c);
	LinkedList* lista=ll_newLinkedList();
	if(lista!=NULL)
	{
		puts("Lista creada agrego elementos");
		ll_add(lista,"Lucas");
		ll_add(lista,"Anya");
		ll_add(lista,"Mack");
		showLista(lista,mostrar);
		puts("invierto");
		ll_invertir(lista);

		showLista(lista,mostrar);
	}

ll_deleteLinkedList(lista);
	return EXIT_SUCCESS;
}
void mostrar(void* a)
{
	printf("%s\n",(char*)a);
}

LinkedList* ll_filter(LinkedList* lista,int (*pFunc)(void*))
{
	int tam;
	void* aux=NULL;
	LinkedList* filtrada=NULL;// declaro lo q voy a retornar
	if(lista!=NULL && pFunc!=NULL)
	{
		tam=ll_len(lista);
		filtrada=ll_newLinkedList();
		if(filtrada!=NULL)
		{
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(lista,i);
				if(aux!=NULL)
				{
					if(pFunc(aux)==1)
					{
						if(ll_add(filtrada,aux))//0 ok -1 error
						{
							ll_deleteLinkedList(filtrada);
							filtrada=NULL;// por q lña fucnion solo elimina la direccion pero la variabel sigue teniendo esa direccion
						}
					}
				}
			}

		}

	}

	return filtrada;
}
int ll_sort(LinkedList* lista, int (*pFunc)(void*,void*),int criterio)
{
int todoOk=-1;
int tam;
void* swap=NULL;
void* auxI=NULL;
void* auxJ=NULL;
if(lista!=NULL && pFunc!=NULL && (criterio==1 || criterio==0))
{
	tam=ll_len(lista);
	todoOk=0;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			auxI=ll_get(lista,i);
			auxJ=ll_get(lista,j);
			if(auxI!=NULL && auxJ!=NULL)
			{
				if((pFunc(auxI,auxJ) >0 && criterio) ||(pFunc(auxI,auxJ) <0 && !criterio))
				{
					//swap=auxI; quizas no hace falta
					ll_set(lista,i,auxJ);//piso el i

					ll_set(lista,j,swap);// piso el j
				}
			}

		}

	}

}

return todoOk;
}

LinkedList* ll_clone(LinkedList* lista)
{
	LinkedList* copia=NULL;
	int tam;
	if(lista!=NULL)
	{
		tam=ll_len(lista);
		copia=ll_subList(lista,0,tam);
	}
	return copia;
}
LinkedList* ll_subList(LinkedList* lista, int desde,int hasta)
{
	LinkedList* aux=NULL;
	void* auxCarga=NULL;
	if(lista!=NULL && desde >=0 && hasta>desde && desde<ll_len(lista) && hasta<=ll_len(lista))
	{
		aux=ll_newLinkedList();//CREO LISTA
		if(aux!=NULL)
		{
			for(int i=desde;i<hasta;i++)// recorro la lista a copiar
			{
				auxCarga=ll_get(lista,i);//estraigo la carga
				ll_add(aux,auxCarga);//AGREGO en SUBLIST
			}
		}

	}
	return  aux;
}
int ll_constainsAll(LinkedList* uno,LinkedList* dos)
{
	int todoOk=-1;
	int tam;
	void* aux=NULL;
	if(uno!=NULL && dos!=NULL)
	{
		todoOk=1;//estan todos
		tam=ll_len(dos);
		for(int i=0;i<tam;i++)// recorro la lista dos
		{
			aux=ll_get(dos,i);// estraigo un elemento de dos
			if(aux!=NULL)
			{
				if(ll_contains(uno,aux)==0) // si no esta elemento
				{
					todoOk=0;//no esta un elemento
					break;
				}
			}

		}

	}
return todoOk;
}

int ll_contains(LinkedList* lista, void* carga)
{
int todoOk=-1;//Error
	if (lista != NULL && carga != NULL) {
		todoOk = 1; // esta
		if (ll_indexOf(lista, carga) == -1) {
			todoOk = 0; // NO esta
		}
	}
return todoOk;
}

void* ll_pop(LinkedList* lista, int indice)
{
	void* aux=NULL;
	if(lista!=NULL && indice >=0 && indice <ll_len(lista)) // NO exite el elemento igual al tam
	{
		aux=ll_get(lista,indice); // obtengo la carga de ese inidce
		ll_remove(lista,indice);

	}
	return aux;
}
int ll_push(LinkedList* lista, int indice, void* carga)
{
	int todoOk=-1;//Error

	if(lista!=NULL && indice >=0 && indice <=ll_len(lista))
	{

		if(addNode(lista,indice,carga)==0)
		{
			todoOk=0;
		}
	}
	return todoOk;
}
int ll_isEmpty(LinkedList* lista)
{
	int vacio=-1;//error

	if (lista != NULL) {
		vacio=1;//vacio
		if (lista->tam != 0) {
			vacio = 0;//ocupado
		}
	}
	return vacio;
}
int ll_indexOf(LinkedList* lista,void* carga)
{
	int indice = -1;
	int tam;
	void* aux=NULL;
	if (lista != NULL && carga != NULL) {

		tam=ll_len(lista);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(lista,i);
			if(aux==carga)
			{
				indice=i;
				break;
			}
		}


	}
	return indice;
}
int ll_deleteLinkedList(LinkedList* lista)
{
	int todoOk = -1;
	if (lista != NULL) {

		if (ll_clear(lista) == 0) {
			free(lista);
			lista = NULL;
			todoOk = 0;
		}
	}
	return todoOk;
}

LinkedList* ll_newLinkedList(void)
{
	LinkedList* l=NULL;
	l=(LinkedList*)malloc(sizeof(LinkedList));
	if(l!=NULL)
	{
		l->primerNodo=NULL;
		l->tam=0;
	}
	return l;
}


int ll_remove(LinkedList* lista,int indice)
{
	int todoOk=-1;
	Nodo* aux=NULL;
	if(lista!=NULL && indice >=0 && indice<ll_len(lista))
	{
		aux=getNode(lista,indice);
		if(aux!=NULL)
		{todoOk=0;
			if(indice==0)
			{

				lista->primerNodo=aux->nextNodo;
			}
			else
			{
				(getNode(lista,indice-1))->nextNodo=aux->nextNodo;

			}
			free(aux);
			lista->tam--;

		}
	}
	return todoOk;
}
int ll_clear(LinkedList* lista)
{
	int todoOk=-1;//fallo
	int tam;
	int flag=0;
	if(lista!=NULL)
	{
		tam=ll_len(lista);
		todoOk=0;// se limpio correctamente
		for(int i=tam-1;i>=0;i--)//elimino del primero al ultimo
		{
			if(ll_remove(lista,i)==-1)
			{
				flag=1;
				break;
			}

		}
		if(flag)
		{
			todoOk=-1;
		}
	}
return todoOk;
}
int ll_add(LinkedList* lista,void* carga)
{
	int todoOk=-1;
	int tam;
	if(lista!=NULL && carga!=NULL)
	{
		tam=ll_len(lista);
	if(addNode(lista,tam,carga)==0)
	{
		todoOk=0;
	}

	}
	return todoOk;
}
int ll_len(LinkedList* lista)
{
	int tam=-1;
	if(lista!=NULL)
	{
	tam=lista->tam;

	}
return tam;
}
Nodo* getNode(LinkedList* lista, int indice)
{
	Nodo* aux=NULL;
	if(lista!=NULL && indice>=0 && indice<ll_len(lista))
	{
			aux=lista->primerNodo;
			while(indice>0)
			{
				aux=aux->nextNodo;
				indice--;
			}
	}
	return aux;
}

int addNode(LinkedList* lista, int indice,void* carga)
{
	int todoOk=-1;
	Nodo* nodo=NULL;
	if(lista!=NULL && indice >=0 && indice<=ll_len(lista) )
	{

		nodo=(Nodo*)malloc(sizeof(Nodo));
		if(nodo!=NULL)
		{
			todoOk=0;
			nodo->carga=carga;
			nodo->nextNodo=NULL;
				if(indice==0)
				{
					nodo->nextNodo=lista->primerNodo;
					lista->primerNodo=nodo;

				}
				else
				{
					nodo->nextNodo=getNode(lista,indice);
					(getNode(lista,indice-1))->nextNodo=nodo;
				}
				lista->tam++;


		}
	}
	return todoOk;
}
void* ll_get(LinkedList* lista, int indice)
{
	void* carga=NULL;
	Nodo* aux=NULL;
	if(lista!=NULL && indice >=0 && indice<ll_len(lista) )
	{
		aux=getNode(lista,indice);
		if(aux!=NULL)
		{
			carga=aux->carga;
		}
	}
	return carga;
}

int ll_set(LinkedList* lista, int indice,void* carga)
{
	int todoOk=-1;
	Nodo* aux=NULL;
	if(lista!=NULL && indice >=0 && indice<ll_len(lista) )
	{
		aux=getNode(lista,indice);
		if(aux!=NULL)
		{
			aux->carga=carga;//NO FREE a la carga anterior
			todoOk=0;
		}
	}
	return todoOk;
}





LinkedList* ll_map(LinkedList* lista,void*(*pFunc)(void*))
{
	LinkedList* map=NULL;
	int tam;
	void* aux=NULL;
	if(lista!=NULL && pFunc!=NULL)
	{
		tam=ll_len(lista);
		map=ll_newLinkedList();
		if( map!=NULL)
		{


			for(int i=0;i<tam;i++)
			{
				aux=ll_get(lista,i);
				if(aux!=NULL)
				{
					if(ll_add(map,pFunc(aux))!=0)
					{
						free(map);
						map=NULL;
					}
				}

			}

		}

	}
	return map;
}


int ll_invertir(LinkedList* lista)
{
	int todoOk=-1;
	int tam;
	void* auxI=NULL;
	void* auxJ=NULL;
	if(lista!=NULL)
	{
		tam=ll_len(lista);
			todoOk=0;
			for(int i=0;i<tam-1;i++)
			{
				for(int j=i+1;j<tam;j++)
				{
					auxI=ll_get(lista,i);

					auxJ=ll_get(lista,j);
					if(auxI!=NULL && auxJ!=NULL)
					{
						ll_set(lista,i,auxJ);
						ll_set(lista,j,auxI);
					}

				}
			}
	}
	return todoOk;
}

void showLista(LinkedList* lista,void (*pFuncMostrar)(void*))
{
	void* aux=NULL;
	if(lista!=NULL)
	{

		for(int i=0;i<ll_len(lista);i++)
		{
			aux=ll_get(lista,i);
			if(aux!=NULL)
			{
			pFuncMostrar(aux);
			}
		}
	}
}
