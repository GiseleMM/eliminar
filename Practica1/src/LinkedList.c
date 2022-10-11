#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex); // estas funciones staticas por  q son privadas para q las funciones del linked list, por eso el prototipo no esta en .h si no aca en el .c tamto el cuerpo como el prototipo
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	// this es una palabra en c++ , significa q modica a la estructura donde estoy
	LinkedList *this = NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) // limpiar los datos
	{
		this->pFirstNode = NULL; //no hay vagon
		this->size = 0; // no tiene  nodos
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) //retorna la direccion de un nodo
{
	//retrona la direccion de memoria del nodo q esta en la posicion q pasa como parametro
	Node *nodo = NULL;
	// NO exite un nodo de igual al len_len(linkedList) por que si es size es 4 , empieza 0 1 2 3 3 es el ¿ultuimo indice
	// el Nodo CERO solo conoce se ubiucacion la linkedlist el resto ben nodo anterior

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))	// IMPORTANTE IGUAL A CERO POR Q PUEDE SER CERO Y """NO"""" IGUAL A LL_LEN
			{
		/*  VESRION  UNO
		 if (nodeIndex == 0)	// en el caso de q se quiera saber elñ primer Nodo
		 {

		 nodo = this->pFirstNode;	// estoy en la direccion de 1 nodo

		 }
		 else	//otro NODO  tiene q ir hasta llegar un nodoAntes antes
		 {

		 nodo = this->pFirstNode;
		 while (nodeIndex > 0) {


		 nodo = nodo->pNextNode;
		 nodeIndex--;


		 //ejemplo nodeIndex= 2
		 //  estoy en el cero , entro al while
		 // voy al UNO nodeIndex decrementa un valor y pasa a ser 1
		 // vuelvop a iterar por q nodeindex es mayor a Cero
		 // paso al NODO 2 resto nodoIndex queda igual acero y no itera el nodo index queda en la posicion 2 por q se tiene la direccion del dos
		 //
		 }*/
		nodo = this->pFirstNode;
		while (nodeIndex > 0) {
			nodo = nodo->pNextNode;
			nodeIndex--;

		}
	}
	return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement)	// agrega un nodo , crea vagon insertar carga y poner el vagon en la posicion indicada
{
	int returnAux = -1;
	Node* nodo= NULL;
	Node* aux=NULL; //------- nodo auxiliar para obtener la direccion del proximo nodo

	//SI ME DICE en el indice 2 me dice q en nodo anterior (uno) copiar la direccion del prximo NOdo (el anterior 2) en el campo NextNode de mi nuevo dos
	// luego cambair el campo del anterior y hacer que apunte a el nuevo nodo 2
	// primero copio en el campo nextNodo la direccion del anterior nodo ubicado en esa posicion y luego al nodo Anterior al nodo hago q apunte a ese nodo

	// uso getNode para retornar la direccion del nodo



	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))// ES MENOR O  IGUAUL A LL_LEN ´POR q quizas quiera agregarlos en la ultima posicion
	{
		/*
		nodo=(Node*)malloc(sizeof(Node));//----------creo nodo
		if(nodo!=NULL)
		{							//------cargo el campo del elemento del nodo creado
				nodo->pElement=pElement;// porq se permite ingresar el NULL como pElemnet
				nodo->pNextNode=getNode(this,nodeIndex); //---------------obetengo la direccion an anterior nodo , ahora apunta a ese nodo dos Nodos
				getNode(this,nodeIndex-1)->pNextNode=nodo;  // ------------ hago q el anterior nodo me apunte al nuevo nodo y deje de apuntar al  ex nodo
				returnAux=0;
		}
		*/

		nodo=(Node*)malloc(sizeof(Node));//---creo nuevo nodo
		if(nodo!=NULL)
		{
			//-------------pongo la cargat
			nodo->pElement=pElement;
			nodo->pNextNode=NULL;//---aseguro q NO apunte nada con NULL

			//el q viene adelante a a apunar al nuevop nodo
			// EL QUE VIENE ADELANTe Puede ser un Nodo o la locamotora
			if(nodeIndex==0)
			{
				// ahago q el neuvo apunte an anterior cero
				nodo->pNextNode=this->pFirstNode;//  saco la direccion del primer nodo de la locomotora
				//nodo->pNextNode=getNode(this,0);//TAMBIEN FFUNCIONA
				this->pFirstNode=nodo;

			}
			else
			{
				nodo->pNextNode=getNode(this,nodeIndex);
				aux=getNode(this,nodeIndex-1); // traigo la direccion del nodo q viene antes (EL NODO ANTERIOR)
				aux->pNextNode=nodo;// hago q el nodo anterior apunte al nuevo Nodo


				/*version 2 sin auxiliar
				 * nodo->pNextNode=getNode(this,nodeIndex);// asigno al campo nextNode el anterior nodo en ese indice
				getNode(this,nodeIndex-1)->pNextNode=nodo;// al nodo anterior hago q apunte al nuevo nodo
				*/

			}
			this->size++;
			returnAux= 0;
		}

	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement)//agrega al final
{
	/* por q todo esto lohace addNode
	int returnAux = -1;
	if(this!=NULL)
	{
		if(addNode(this,ll_len(this),pElement)==0)
		{
			returnAux=0;
		}
	}

	return returnAux;
	*/

	return addNode(this,ll_len(this),pElement);

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index)// retorna la carga del nodo en el indice indicado
{   // GETTER DE CAMPO PELEMENT
	void *returnAux = NULL;
	 if(this!=NULL && index >= 0 && index <ll_len(this))// NO PUEDE SER IGUIAL A LL_LEN por que no exite un indiuce igual tam por q empieza por cero , si el size son 2 =0,1 son los indices coprrectors
	{
		Node* aux=NULL;
		aux=getNode(this,index);// obtengo el nodo del indice indicado
		if(aux!=NULL)
		{
			returnAux=aux->pElement;// retorno la carga
		}


	}

	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement)// pisa la carga , el campo del elemnte se pisa
{ //SETTER DEL CAMPO PELEMENT
	int returnAux = -1;
	Node* aux=NULL;
	if(this!=NULL &&  index >= 0 && index <ll_len(this))
	{   // VESION sin AUX
		// si quisiera insertar un elemento en la lista  pero si fuera igual tendraimos q crear un nodo y obtener
		//getNode(this,index)->pElement=pElement;
		//returnAux=0;

		aux=getNode(this,index);
		if(aux!=NULL)
		{
			aux->pElement=pElement;//la carga anterior yo ya no la apunto PERO NUNCA hacer FREE a la direccion de memoria del elemnto por q puede ser q ese elemento puede estar apuntado por la mascota , solo libero la meoria que creo yo con malloc en el linked list
			// q deje de existir en una lista no significa q deje de existir el emento solo q no esta mas en la lista
			returnAux=0;
		}


	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index)//lo cotarrio del addNode
{
	int returnAux = -1;
	Node* aux=NULL;
	Node* anterior=NULL;
	if(this!=NULL &&  index >= 0 && index <ll_len(this))//----el index debe ser de un valor valido
	{
		aux=getNode(this,index);//obtengo el nodo a eliminar
		if(aux!=NULL)
		{

			if(index==0)// si el de adelante es el linked list  ahogo q apunte al el campo nextNode del nodo a eliminar
			{
				// uso la rcursividad
				//this->pFirstNode esto es la direccion de memoria del primer eleemnto this->pfirtNode->NextNode
				this->pFirstNode=aux->pNextNode;
			}
			else// si es un nodo el q esta adelante tiene q apuntar al del atras del nodo a eliminar
			{

				//getNode(this,index-1)->pNextNode=aux->pNextNode;
				anterior=getNode(this,index-1);
				if(anterior!=NULL)
				{
					anterior->pNextNode=aux->pNextNode;// o  podria poner= anterior->pNextNode->pNextNode , con el primero fecha estoy en el nodo sigueinte(q es el a eliminar ) y con la otra flecha estoy en el siguiente q es el campo q quiero guardar en el campo next node anterior

				}
			}

			free(aux);// libero el nodo q cree con el linked list no libero la carga por q no la creamos nosotros
			this->size--;
			returnAux=0;
		}
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this)
{
	//liberrar todos los nodos s
	int returnAux = -1;
	if(this!=NULL)
	{

		while(ll_len(this))// mientras tenga elementos remuevo CUANDO ES CERO ES FALSE
		{
			ll_remove(this,0);//va eliminando del primero y el segundo

		}
		returnAux=0;
		/*for(int i=ll_len(this)-1;i>=0;i--) borra de atras para adelante
		{
			ll_remove(this,i);
		}
		returnAux=0;*/

	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this)// libero todos los nodos(clear) q nosostros lo creamos y libero la linkedList con free por q nopsotros la creamos
{
	int returnAux = -1;
	if( this!=NULL)
	{
		if(ll_clear(this)==0)
		{
			free(this);
			this=NULL;
			returnAux=0;
		}
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement)
{
	// busca un elento en el linkdlist
	int returnAux = -1;
	int tam;
	if(this!=NULL)
	{
		tam=ll_len(this);
		//Busco un elemento dentro del linkedList con ll_get q retorna la carga con
		for(int i=0;i<tam;i++)
		{
			if(pElement==ll_get(this,i))// busco la carga con ll_get inidce a indice
			{
				returnAux=i;
				break; // para q retorne la 1° ocurrencia
			}
		}

	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this)
{
	int returnAux = -1;
	if(this!=NULL)
	{
		returnAux=1;//ESTA VACIA
		if(ll_len(this))//solo entra si es distindto de cerop
		{
			returnAux=0;// NO ESTA VACIA
		}
		/*
		int x=23;
		!x da cero
		x=0;
		!x=1(true)


		returnAux=!ll_len(this) si da un numero da 0 y significa q hay elementos ; y si da Cero se niega es uno q significa q esta vacia
		*/

	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) // agrega un nodo en la posicion indicada usa addNodeq crea un nodo , lo cargo en el indice indicado SE Diferencia del ll_addPor q este lo agrega alFinal y push en el indice indicado
{
	int returnAux = -1;
	/*if(this!=NULL && index >= 0 && index <= ll_len(this))
	{
		if(addNode(this,index,pElement)==0)
		{
			returnAux=0;
		}
	}*/
returnAux=addNode(this,index,pElement);
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index)
{// retorna el la carga del elemnto a eliminar
	void *returnAux = NULL;
	if(this!=NULL && index >= 0 && index <ll_len(this))
	{
		returnAux=ll_get(this,index);
		ll_remove(this,index);

	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement)
{
	int returnAux = -1;
		if( this!=NULL)
		{
			returnAux=0;// NO contiene
			if(ll_indexOf(this,pElement)>= 0) // me retorna un indice por lo q el elemento exite
			{
				returnAux=1;// CONTIENE
			}
		}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;

	int tam2;
	void* aux=NULL;
	if(this!=NULL && this2!=NULL)
	{
		tam2=ll_len(this2);//VOY A RECORRER LA LISTA 2 la lista 1 puede tener mas elementos solo tengo q fijarme si TODOS los elelentos de la lista 2 estan en la lista 1 por
		// eso recorro la lista dos saco la carga y se la paso a ll_cvontaisn para saber si esta en la LISTA UNO
		// si un elemento NO esta retrono 0 y salgo del bucle

		returnAux=1;// estan todos Los elemento
		for(int i=0;i<tam2;i++)// recorro la lista 2 para ver si esta en la lista UNo
		{
			aux=ll_get(this2,i);// saco la carga( pElemnt) de la lista2 de cada iteracion
			if( aux!=NULL)
			{
					if(!ll_contains(this,aux))// me fijo si esta en la lista1
					{
						returnAux=0;//NO ESTA UN ELEMENTO
						break;
					}

					/*
					 if(!ll_contains(this,ll_get(this2,i))// me fijo si esta en la lista1 el elemento de ll_get de la lista dos en el indice ¿de la iteraciom
					{
						returnAux=0;
						break;
					}
					 * */
			}
		}
	}

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	//from desde
	//to hasta NoIncluido
	if(this!=NULL && from >= 0 && from <ll_len(this) && to > from && to <=ll_len(this))//tengo poder llegar al tam por que en el for NO se incluye el to , si quisiera el ultimo elemento en eun array de tam 3y quiero llegar al ultimo tengo q poner to=3 y va a llegar a tam-1
	{
		cloneArray=ll_newLinkedList();
		if(cloneArray!=NULL)
		{
			for(int i=from; i <to;i++)// recorre el linkedlkist pasado como parametro desde los indices indicados
			{
			ll_add(cloneArray,ll_get(this,i));// agrego el melemento
			}
		}
	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {

	LinkedList *cloneArray = NULL;
	if(this!=NULL)
	{
		cloneArray=ll_subList(this,0,ll_len(this));
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;

	int tam;
	void* auxSwap=NULL;
	if(this!=NULL && pFunc!=NULL && order >= 0 && order <=1 )
	{
		tam=ll_len(this);
		for(int i=0;i<tam-1;i++)
		{
			for(int j=i+1;j<tam;j++)
			{
// si la funcion rectorna mayor a cero es q  el param 1 es mas grande q el dos y el orden es ascente hay q swapear 12,3= 3,12 ASC orden ascentende
				// lo mismo si el resultado de la fun cion da menor es que el parametro 2 es mas grande q el 1 por lo q si el orden  es desc hay q swaper 2,4 ==4,2DEsc order 0 desc
				if((pFunc(ll_get(this,i),ll_get(this,j))>0 && order )||
						(pFunc(ll_get(this,i),ll_get(this,j))<0 && !order))// paso la fucion q indica por q ordenar
				{

					//aux=i;
					//i=J
					//j=aux;

					auxSwap=ll_get(this,i);
					//como paso un elemento con ll_set
					ll_set(this,i,ll_get(this,j));// del elemento q guarde en el auxSwap lo piso con el elemento j

					ll_set(this,j,auxSwap);
				}
			}
		}
		returnAux=0;
	}

	return returnAux;

}
//retorna un nuevo linkedLis*
//recorre el linked list y se la pasa a la funcion y si la fuincion retorna 1 lo agrega ala nueva linea
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))// recibe un puntero a void y retor
{
	void* elemento=NULL;
	LinkedList* lista=NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		lista=ll_newLinkedList();
		if(lista!=NULL)
		{
			for(int i=0;i<ll_len(this);i++)
			{
				elemento=ll_get(this,i);
				if(pFunc(elemento))
				{
					ll_add(lista,elemento);
				}
			}
		}
	}
	return lista;
}
LinkedList* ll_map(LinkedList* lista,void* (*pFunc)(void*))
{
	LinkedList* aux=NULL;
	void* carga=NULL;
	int tam;
	if(lista!=NULL && pFunc!=NULL)
	{
		tam=ll_len(lista);
		aux=ll_newLinkedList();
		if( aux!=NULL)
		{

			for(int i=0;i<tam;i++)
			{

				carga=ll_get(lista,i);
				if( carga!=NULL)
				{
					if(ll_add(aux,pFunc(carga))!=0)
					{
						free(aux);
						aux=NULL;
					}
				}

			}
		}

	}
return aux;
}
/// La funcion “ll_count” recibirá la lista y una función criterio “fn”. La función “fn” deberá devolver 1 en
///caso de que el elemento recibido cumpla con el/los criterios especificados. Al finalizar la iteración, la
///función count retornará la cantidad de elementos que pasaron el criterio.
/// @param pFunc
/// @return
int ll_count(LinkedList* lista,int(*pFunc)(void*))
{
	int count=-1;//ERROR
	int tam;
	void* aux=NULL;
	if(lista!=NULL && pFunc!=NULL)
	{
		count=0;
		tam=ll_len(lista);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(lista,i);
			if(aux!=NULL)
			{
				if(pFunc(aux)==1)
				{
					count++;
				}


			}
		}
	}
	return count;
}
