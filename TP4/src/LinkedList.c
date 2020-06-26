#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/******* STATIC'S FIRMS ***************************************************************/
/**
 * @brief borra la lista, y libera el espacio
 * 
 * \param this LinkedList* Puntero a la lista
 */
static void deleteLinkedList(LinkedList* this);

/**
 * @brief Crea un nodo en memoria dinamica y retorna su puntero
 * 
 * @return Node* puntero a nuevo nodo
 */
static Node* newNode();

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o 
 * (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/**
 * @brief Escribe los valores dentro de un nodo
 * 
 * @param thisNode Puntero a nodo
 * @param pElement Puntero a elemento a guardar en nodo
 * @param nextNode Puntero a siguiente nodo (o NULL)
 */
static void setNode(Node * thisNode, void* pElement, Node * nextNode);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el 
 * indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * @brief Borra un nodo, libera el espacio,y modifica el tamaño de la lista
 * 
 * \param this LinkedList* Puntero a la lista
 * @param thisNode Puntero a nodo
 */
static void deleteNodeandResizell(LinkedList* this,Node * thisNode);

/******* FUNCTIONS **********************************************************************/
LinkedList* ll_newLinkedList(void){
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL){
        this->pFirstNode = NULL;
        this->size = 0;
    }
    return this;
}

static void deleteLinkedList(LinkedList* this){
    this = NULL;
    free(this);
}

int ll_len(LinkedList* this){
    int returnAux = -1;
    if(this!=NULL){
        returnAux = this->size;
    }
    return returnAux;
}

static Node* newNode(){
    Node *new;
    return new = (Node*)malloc(sizeof(Node));
}

static Node* getNode(LinkedList* this, int nodeIndex){
    Node * pNode;
    int len,i;
    pNode = NULL;
    len = ll_len(this);
    if(len > -1){
        if(this->pFirstNode != NULL && nodeIndex > -1 && nodeIndex < len){
            pNode = this->pFirstNode;
            i=0;
            while(i != nodeIndex){
                pNode = pNode->pNextNode;
                i++;
            }
        }
    }
    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this, nodeIndex);
}

static void setNode(Node * thisNode, void* pElement, Node * nextNode){
    thisNode->pElement = pElement;
    thisNode->pNextNode = nextNode;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1, len;
    Node* prev,* nuevoNodo;
    len = ll_len(this);
    if(len > -1 && nodeIndex > -1){
        nuevoNodo = newNode();
        if(nodeIndex == 0 && len == 0){
            //1-> ADD first node
            this->pFirstNode = nuevoNodo;
            setNode(nuevoNodo,pElement,NULL);
            returnAux = 0;
        }
        if(nodeIndex > 0 && nodeIndex == len){
            //2-> ADD node at the end
            prev = getNode(this,nodeIndex-1);
            prev->pNextNode = nuevoNodo;
            setNode(nuevoNodo,pElement,NULL);
            returnAux = 0;
        }
        if(nodeIndex == 0 && len > 0){
            //3-> PUSH node at first
            setNode(nuevoNodo,pElement,this->pFirstNode);
            this->pFirstNode = nuevoNodo;
            returnAux = 0;
        }
        if(nodeIndex < len){
            //4-> PUSH in the middle
            prev = getNode(this,nodeIndex-1);
            setNode(nuevoNodo,pElement,prev->pNextNode);
            prev->pNextNode = nuevoNodo;
            returnAux = 0;
        }
    }
    if(returnAux == 0){
        this->size++;
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
    return addNode(this,nodeIndex,pElement);
}

static void deleteNodeandResizell(LinkedList* this,Node * thisNode){
    thisNode = NULL;
    free(thisNode);
    this->size--;
}

int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1,len;
    len = ll_len(this);
    if(len > -1){
        if(addNode(this,len,pElement) == 0){
            returnAux = 0;
        }
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    Node * current;
    if(this != NULL){
        current = getNode(this,index);
        if(current != NULL){
            returnAux = current->pElement;
        }
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    Node* current;
    if(this != NULL){
        current = getNode(this,index);
        if(current != NULL){
            current->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index){
    int returnAux = -1,len; 
    Node* current,* prev;
    len = ll_len(this);
    if(len > -1){
        current = getNode(this,index);
        if(current != NULL){
            if((index == 0 && len == 1) || (index == len-1 && index > 0)){
                //1-> remove first and only node || 4-> remove last node
                returnAux = 0;                
            }
            if(index == 0 && len > 1){
                //2-> remove first node
                this->pFirstNode = current->pNextNode;
                returnAux = 0;               
            }
            if(index < len-1 && index > 0){
                //3-> remove from the middle
                prev = getNode(this,index-1);
                if(prev != NULL){
                    prev->pNextNode = current->pNextNode;
                    returnAux = 0;
                }
            }
            if(returnAux == 0){
                deleteNodeandResizell(this,current);
            }
        }
    }
    return returnAux;
}

int ll_clear(LinkedList* this){
    int returnAux = -1,len,i;
    Node* nodo;
    len = ll_len (this);
    if(len > -1){
        for(i=0;i<len;i++){
            nodo = getNode(this,i);
            deleteNodeandResizell(this,nodo);
        }
        returnAux = 0;
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1,len,i;
    Node* nodo;
    if(this != NULL){
        len = ll_len(this);
        for(i=0;i<len;i++){
            nodo = getNode(this,i);
            deleteNodeandResizell(this,nodo);
        }
        deleteLinkedList(this);
        returnAux = 0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1,len,i;
    Node* nodo;
    len = ll_len(this);
    if(len > -1){
        for(i=0;i<len;i++){
            nodo = getNode(this,i);
            if(nodo->pElement == pElement){
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
        if(ll_len(this)){
            returnAux = 0;
        }else{
            returnAux = 1;
        }
    }
    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    if(this != NULL){
        if(addNode(this,index,pElement) == 0){
            returnAux = 0;
        }
    }
    return returnAux;
}

void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    int len;
    Node* current,* prev;
    len = ll_len(this);
    if(len > -1){
        current = getNode(this,index);
        if(current != NULL){
            if((index == 0 && len == 1) || (index == len-1 && index > 0)){
                //1-> remove first and only node || 4-> remove last node
                returnAux = current->pElement; 
                deleteNodeandResizell(this,current);     
            }
            if(index == 0 && len > 1){
                //2-> remove first node
                this->pFirstNode = current->pNextNode;
                returnAux = current->pElement;    
                deleteNodeandResizell(this,current);     
            }
            if(index < len-1 && index > 0){
                //3-> remove from the middle
                prev = getNode(this,index-1);
                if(prev != NULL){
                    prev->pNextNode = current->pNextNode;
                    returnAux = current->pElement;  
                    deleteNodeandResizell(this,current);
                }
            }
        }
    }
    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;
    if(this != NULL){
        if(ll_indexOf(this,pElement) > -1){
            returnAux = 1;
        }else{
            returnAux = 0;

        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1,i,len;
    Node* nodo;
    if(this != NULL && this2 != NULL){
        len = ll_len(this2);
        for(i=0;i<len;i++){
            nodo = getNode(this2,i);
            if(nodo != NULL){
                if(ll_contains(this,nodo->pElement) == 0){
                    break;
                }
            }
        }
        if(i == len){
            returnAux = 1;
        }else{
            returnAux = 0;
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* cloneArray = NULL;
    Node * aux;
    int len, index = 0,i;
    len = ll_len(this);
    if(len > -1){
        if(from > -1 && from < to && to <= len){
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL){
                for(i=from;i<to;i++){                  
                    aux = getNode(this,i); 
                    if(aux != NULL){
                        addNode(cloneArray,index,aux->pElement);  
                        index++;
                    } 
                }
            }
        }
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    if(this != NULL){
        cloneArray = this;
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order){
    int returnAux =-1,len,i,j;
    Node *auxI, * auxJ;
    void* pAux;
    len = ll_len(this);
    if(len > -1 && pFunc != NULL && (order == 0 || order == 1)){
        for(i=0;i<len-1;i++){
            for(j=i+1;j<len;j++){
                auxI = getNode(this,i);
                auxJ = getNode(this,j);
                if(auxI != NULL && auxJ != NULL){
                    if(order == 1 && pFunc(auxI->pElement,auxJ->pElement) == 1){
                        pAux = auxI->pElement;
                        ll_set(this,i,auxJ->pElement);
                        ll_set(this,j,pAux);
                    }
                    if(order == 0  && pFunc(auxI->pElement,auxJ->pElement) == -1){
                        pAux = auxI->pElement;
                        ll_set(this,i,auxJ->pElement);
                        ll_set(this,j,pAux);
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}