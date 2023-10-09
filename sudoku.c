#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode()
{
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n)
{
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name)
{
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n) //validar si un estado/nodo es válido
{
  
  
  //int arregloSubm[10] = {};
  //recorro matriz
  for(int i = 0 ; i < 9 ; i++){
    int arregloFilas[10] = {};
    int arregloCols[10] = {};
    //No se repitan números en las filas
    for(int j = 0; j < 9 ; j++){ 
      if(n->sudo[i][j] != 0){ //si la casilla no es cero
        if(arregloFilas[n->sudo[i][j]] == 1) return 0; //si se repite retorna 0
        arregloFilas[n->sudo[i][j]] = 1; //guardar numero
      }
    }
    
    //No se repitan números en las columnas
    for(int j = 0; j < 9 ; j++){ 
      if(n->sudo[j][i] != 0){
        if(arregloCols[n->sudo[j][i]] == 1) return 0; //si se repite retorna 0
        arregloCols[n->sudo[j][i]] = 1; //guardar numero
      }
    }
  }
  
  //No se repitan números en las submatrices de 3x3
  
  
  return 1;
}

// Función que devuelve una lista de nodos adyacentes
List* get_adj_nodes(Node* n)
{
  List* list=createList();
  
  for(int i=0; i < 9; i++){
    for(int j=0; j < 9; j++){
      // Si la celda está vacía
      if(n->sudo[i][j] == 0) //retornar una lista con **9 nodos**
      {
        for(int k = 1; k < 10 ; k++){
          n->sudo[i][j] = k; //asigno valor a la casilla
          Node* newNode = copy(n);
          // Agregar el nuevo estado a la lista de nodos adyacentes
          pushBack(list, newNode);  
        }
      }
    }
  }
  return list;
}


int is_final(Node* n)
{
  for(int i = 0; i<9;i++){
    for(int j=0; j<9;j++){
      if(n->sudo[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/