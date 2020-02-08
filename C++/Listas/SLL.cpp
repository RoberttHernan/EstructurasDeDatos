#include <iostream>
using namespace std;

class Nodo
{
public:
    int data;
    Nodo *next;
};

// prototipos de funciones
void printList(Nodo *);
void InsertarInicio(Nodo **, int);
void InsertarDespues(Nodo *, int); // INSERTA UN NODO LUEGO DE UN NODO DADO
void InsertarFinal(Nodo **, int);  // INSERTA UN NODO AL FINAL DE LA LISTA
void imprimirListaCompleta(Nodo *);

int main()
{
    Nodo *head = NULL;

    InsertarInicio(&head, 6);
    InsertarDespues(head, 8);
    
    InsertarInicio(&head, 7);
    InsertarFinal(&head, 10);

    imprimirListaCompleta(head);

    return 0;
}

// imprime la lista dado un nodo especifico
//IMPRIMIR A PARTIR DE NODO
void printList(Nodo *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void InsertarInicio(Nodo **head_reference, int new_data)
{

    Nodo *new_node = new Nodo;          // reservar espacio en el heap para el nuevo nodo
    new_node->data = new_data;          // insertar la data en el nuevo nodo
    new_node->next = (*head_reference); // colocamos el nuevo nodo como head
    (*head_reference) = new_node;
}

void InsertarDespues(Nodo *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "Error, Nodo previo no puedo ser nulo" << endl;
    }
    else
    {
        Nodo *new_nodo = new Nodo(); // reservamos memoria para el nuevo nodo
        new_nodo->data = new_data;
        new_nodo->next = prev_node->next;
        prev_node->next = new_nodo;
    }
}
void InsertarFinal(Nodo **head_ref, int new_data)
{
    Nodo *new_nodo = new Nodo(); //RESERVAMOS MEMORIA PARA EL NUEVO NODO

    Nodo *last = *head_ref; //NODO QUE SE MOVERA A LA ULTIMA POSICION

    new_nodo->data = new_data; //ASIGNAMOS LA DATA A NUEVO NODO;

    /*El NUEVO NODO SERA EL ULTIMO, ASI QUE HACEMOS QUE APUNTE A NULL*/
    new_nodo->next = NULL;

    //VERIFICAMOS QUE LA LISTA NO ESTE VACIA, DE SER ASI EL NUEVO NODO SERA LA CABEZA DE LA LISTA
    if (*head_ref == NULL)
    {
        *head_ref = new_nodo;
        
    }
    
        while (last->next != NULL) // DE LO CONTRARIO RECOREMOS HASTA EL ULTIMO NODO
        {
            last = last->next;
            //CAMBIAMOS LA POSICION DE LOS NODOS
            
        
        }last->next = new_nodo;
}

void imprimirListaCompleta(Nodo *nodo)
{
    while (nodo->next != NULL)
    {
        cout << " " << nodo->data << endl;
        nodo = nodo->next;
    }
    cout << nodo->data << endl;
}
