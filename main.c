#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
 
typedef struct{
  char titulo[30];
  char autor[30];
  char genero[30];
  int ISBN;
  char ubicacion[10];
  char estadoLibro[30];
  List* nombresReservas;
  int cant_reservas;
} Libro;

// funcion para obtener frases hasta ingresar un enter.
void obtenerEntrada(char *cadena, int tallaMax) {
  fgets(cadena, tallaMax, stdin);
  size_t largo = strlen(cadena);
  if (largo > 0 && cadena[largo - 1] == '\n') {
    cadena[largo - 1] = '\0';
  }
}
/* El carácter '\n' que se introduce cuando el usuario presiona Enter después de introducir una opción numérica queda en el búfer de entrada y es consumido por la primera llamada a fgets(), lo que hace que fgets() se salte la primera entrada de texto. Es por esto que se agrega el getchar(); al comienzo de cada funcion y cada vez que se ingresan datos numericos.*/

void registrarLibro(List *lst_libros) {
  getchar();
  char titulo[30],autor[30],genero[30],ubicacion[30];
  int isbn;
  printf("----------------------------------------\n");
  printf("\n        Ingrese los datos del libro        ");
  printf("\nTitulo: ");
  obtenerEntrada(titulo, sizeof(titulo));
  
  printf("Autor: ");
  obtenerEntrada(autor, sizeof(autor));
  
  printf("Genero: ");
  obtenerEntrada(genero, sizeof(genero));
  
  printf("ISBN: ");
  scanf("%d",&isbn);
  getchar();
  
  printf("Ubicacion: ");
  obtenerEntrada(ubicacion, sizeof(ubicacion));
  printf("\n----------------------------------------\n");
  
  Libro* libro = (Libro*)malloc(sizeof(Libro));
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor, autor);
  strcpy(libro->genero, genero);
  libro->ISBN = isbn;
  strcpy(libro->ubicacion, ubicacion);
  strcpy(libro->estadoLibro, "Disponible");
  libro->nombresReservas = createList();
  
  pushBack(lst_libros, libro);
}

void mostrar_unLibro(List* lst_libros) {
  getchar();
  char titulo_candidato[30], autor[30];
  printf("----------------------------------------\n");
  printf("\nTitulo del libro a mostrar: ");
  obtenerEntrada(titulo_candidato, sizeof(titulo_candidato));
  printf("Autor del libro a mostrar: ");
  obtenerEntrada(autor, sizeof(autor));

  Libro* aux = firstList(lst_libros);
  while (aux != NULL) {
    if (strcmp(aux->titulo, titulo_candidato) == 0 && strcmp(aux->autor, autor) == 0) {
      printf("\n            Datos del libro            ");
      printf("\nTitulo: %s\nAutor: %s\nGenero: %s\nISBN: %d\nUbicacion: %s\nEstado: %s\n", aux->titulo, aux->autor, aux->genero, aux->ISBN, aux->ubicacion, aux->estadoLibro);
      printf("\n----------------------------------------\n");
      return;
    }
    aux = nextList(lst_libros);
  }
  printf("El libro que busca no coincide con los registros.\n");
  printf("\n----------------------------------------\n");
}

void mostrar_todosLosLibros(List* lista) {
  Libro* aux = firstList(lista);
  while (aux != NULL) {
    printf("\nTitulo: %s\nAutor: %s\nGenero: %s\nISBN: %d\nUbicacion: %s\nEstado: %s\n", aux->titulo, aux->autor, aux->genero, aux->ISBN, aux->ubicacion, aux->estadoLibro);
    aux = nextList(lista);
  }
  printf("\n----------------------------------------\n");
}

void reservarLibro(List *lst_libros) {
  getchar();
  char titulo[30], autor[30], nombre[30];
  
  printf("----------------------------------------\n");
  printf("\n        Datos del libro a reservar      ");
  printf("\nTitulo: ");
  obtenerEntrada(titulo, sizeof(titulo));
  
  printf("Autor: ");
  obtenerEntrada(autor, sizeof(autor));
  
  printf("Nombre de la persona que realiza la reserva: ");
  obtenerEntrada(nombre, sizeof(nombre));

  Node *current = lst_libros->head;
  while (current != NULL) {
    Libro *libro = (Libro *)current->data;
    if (strcmp(libro->titulo, titulo) == 0 && strcmp(libro->autor, autor) == 0) {
      if (strcmp(libro->estadoLibro, "Disponible") == 0) {
        pushBack(libro->nombresReservas, nombre);
        strcpy(libro->estadoLibro, "Reservado");
        printf("\nEl libro ha sido reservado con éxito.\n");
        printf("\n----------------------------------------\n");
        // libro->cant_reservas++;
        return;
      }
      else {
        printf("\nEl libro ha sido reservado con éxito.");
        printf("\n----------------------------------------\n");
        
      }
    }
    current = current->next;
  }
  printf("\nEl libro que busca no coincide con los registros.\n");
  printf("\n----------------------------------------\n");
}

void cancelarReserva(List* lst_libros){
  getchar();
  char titulo[30],autor[30],nombresReservas[30];
  printf("----------------------------------------\n");
  printf("\n        Datos del libro a cancelar reserva      ");
  printf("\nTitulo: ");
  obtenerEntrada(titulo, sizeof(titulo));
  printf("Autor: ");
  obtenerEntrada(autor, sizeof(autor));
  printf("Nombre de la persona que realiza el prestamo: ");
  obtenerEntrada(nombresReservas, sizeof(nombresReservas));
  
  Libro* aux = firstList(lst_libros);
  while (aux != NULL) {
    if (strcmp(aux->titulo,titulo) == 0 && strcmp(aux->autor,autor) == 0){
      if (strcmp(aux->estadoLibro, "Reservado") == 0) {
        // Actualizamos el estado del libro.
        strcpy(aux->estadoLibro, "Disponble");
        // Eliminamos el primer nombre de la lista de personas utilizando popcurrent.
        if (aux->nombresReservas != NULL) {
          popFront(aux->nombresReservas);
          printf("\n Su reserva ha sido cancelada correctamente.\n");
          printf("\n----------------------------------------\n");
          return;
        }
      }
      else{
        printf("\nEl libro al que intenta acceder aun no ha sido reservado.\n");
        printf("\n----------------------------------------\n");
      }
    }
  }
  printf("\nEl libro que busca no coincide con los registros.\n");
  printf("\n----------------------------------------\n");
}

void retirarLibro(List * lst_libros, List * lst_prestados) {
  getchar();
  char titulo[30], autor[30], nombre[30];
  
  printf("----------------------------------------\n");
  printf("\n        Datos del libro a retirar      ");
  printf("\nTitulo: ");
  obtenerEntrada(titulo, sizeof(titulo));
  
  printf("Autor: ");
  obtenerEntrada(autor, sizeof(autor));
  
  printf("Nombre de la persona que desea retirar un libro: ");
  obtenerEntrada(nombre, sizeof(nombre));

  Node *current = lst_libros->head;
  while (current != NULL) {
    Libro *libro = (Libro *)current->data;
    if (strcmp(libro->titulo, titulo) == 0 && strcmp(libro->autor, autor) == 0) {
      if (strcmp(libro->estadoLibro, "Disponible") == 0) {
        pushBack(lst_prestados, libro);
        strcpy(libro->estadoLibro, "Prestado");
        printf("\nEl libro ha sido reservado con éxito.\n");
        printf("\n----------------------------------------\n");
        return;
      }
      else {
        printf("\nEl libro no se encuentra disponible para retiro.\n");
        printf("\n----------------------------------------\n");
        return;
      }
    }
    current = current->next;
  }
  printf("\nEl libro que busca no coincide con los registros.\n");
  printf("\n----------------------------------------\n");
}

void devolverLibro(List * lst_libros, List * lst_prestados){
  char titulo[30], autor[30], nombre[30];
  
  printf("----------------------------------------\n");
  printf("\n        Datos del libro a devolver      ");
  printf("\nTitulo: ");
  obtenerEntrada(titulo, sizeof(titulo));
  printf("Autor: ");
  obtenerEntrada(autor, sizeof(autor));  
  printf("Nombre de la persona que desea retirar un libro: ");
  obtenerEntrada(nombre, sizeof(nombre));
  
  Libro* aux= firstList(lst_libros);
  while (aux != NULL) {
    if (strcmp(aux->titulo, titulo) == 0 && strcmp(aux->autor, autor) == 0) {
      if(strcmp(aux->estadoLibro, "Prestado") == 0){
        if(lst_prestados!=NULL){
          popBack(lst_prestados);
          strcpy(aux->estadoLibro, "Disponble");
          printf("\nEl libro ha sido devuelto con éxito.\n");
          printf("\n----------------------------------------\n");
          return;     
        }else{
          printf("\nError, este libro no ha sido prestado\n");
          return;
        }
      }
    }
    aux = nextList(lst_prestados);
  }
}

//Funcion para leer el k-esimo elemento de un string (separado por comas)
const char *get_csv_field(char *tmp, int k) {
    int open_mark = 0;
    char *ret = (char *)malloc(100 * sizeof(char));
    int ini_i = 0, i = 0;
    int j = 0;
    while (tmp[i] != '\0') {
        if (tmp[i] == '\"') {
            open_mark = 1 - open_mark;
            if (open_mark)
                ini_i = i + 1;
        } else if (open_mark || tmp[i] != ',') {
            if (k == j)
                ret[i - ini_i] = tmp[i];
        } else {
            if (k == j) {
                ret[i - ini_i] = 0;
                return ret;
            }
            j++;
            ini_i = i + 1;
        }
        i++;
    }
    if (k == j) {
        ret[i - ini_i] = 0;
        return ret;
    }
    free(ret);
    return NULL;
}

void *importarDatos(List * lst_libros) {
    getchar();

    char archivo[50];
    printf("----------------------------------------\n");
    printf("¿Qué archivo desea importar?\n");
    scanf("%49[^\n]", archivo);
    getchar();
    FILE *fp = fopen(archivo, "r");
    if (fp == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo.\n");
        return NULL;
    }
    char linea[1024];
    int i;
    fgets(linea, 1023, fp);
  
    char *aux;
    while (fgets(linea, 1023, fp) != NULL ) {
        Libro *datos = malloc(sizeof(Libro));
        for (i = 0; i < 5; i++) {
            aux = get_csv_field(linea,i);
            if (aux != NULL) {
                if (i == 0) {
                    strcpy(datos->titulo, aux);
                } else if (i == 1) {
                    strcpy(datos->autor, aux);
                } else if (i == 2) {
                    strcpy(datos->genero, aux);
                } else if (i == 3) {
                    datos->ISBN = atoi(aux);
                } else if (i == 4) {
                    strcpy(datos->ubicacion, aux);
                    pushBack(lst_libros, datos);
                    
                }
            }
        }
        strcpy(datos->estadoLibro, "Disponible");
        datos->nombresReservas = createList();
       
        
    }
    printf("----------------------------------------\n");
    fclose(fp);
    
}

void Exportar_datos_libros(List* lista) {
  char nombre_archivo[40];
  printf("----------------------------------------\n");
  printf("Ingrese el nombre del archivo que desea crear\n");
  scanf("%39s", nombre_archivo);

  FILE* archivo = fopen(nombre_archivo, "a");
  if (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return;
  }
  fprintf(archivo, "Titulo,Autor,Genero,ISBN,Ubicacion,Estado del Libro,Cantidad de Reservas\n");
  
  Libro* libro = firstList(lista);
  for (Libro *c=firstList(lista); c!=NULL ; c=nextList(lista)){
    
    fprintf(archivo, "%s,%s,%s,%d,%s,%s,%d\n", libro->titulo, libro->autor, libro->genero, libro->ISBN, libro->ubicacion, libro->estadoLibro, libro->cant_reservas);
    
  }
  
  fclose(archivo);
  printf("Se ha creado el archivo correctamente: %s\n", nombre_archivo);
  printf("----------------------------------------\n");
}

int main(int argc, char* argv[]){
    List* lst_libros = createList();
    List* lst_prestados = createList();
 
    int opcion;
    while(true){
      printf("\n      ¿Qué operacion desea realizar?      \n");
      printf("1. Registrar libro.\n");
      printf("2. Mostrar datos de libro.\n");
      printf("3. Mostrar todos los libros.\n");
      printf("4. Reservar libro.\n");
      printf("5. Cancelar reserva de libro.\n");
      printf("6. Retirar libro.\n");
      printf("7. Devolver libro.\n");
      printf("8. Mostrar libros prestados.\n");
      printf("9. Importar libros desde un archivo CSV.\n");
      printf("10. Exportar libros a un archivo CSV.\n");
      printf("11. SALIR DEL PROGRAMA. \n");
      scanf("%d",&opcion);

      if(opcion ==11) {
        return 0;
      }
      else if (opcion==1){
        registrarLibro(lst_libros);
      }
      else if (opcion==2){
        mostrar_unLibro(lst_libros);
      }
      else if (opcion==3){
        printf("----------------------------------------\n");
        printf("\n        Todos los libros registrados      ");
        mostrar_todosLosLibros(lst_libros);
      }
      else if(opcion==4){
        reservarLibro(lst_libros);
      }
      else if(opcion==5){
        cancelarReserva(lst_libros);
      }
      else if(opcion==6){
        retirarLibro(lst_libros, lst_prestados);
      }
      
      else if(opcion==7){
        devolverLibro(lst_libros, lst_prestados);
      }
      else if(opcion==8){
        printf("----------------------------------------\n");
        printf("\n        Todos los libros prestados      ");
        mostrar_todosLosLibros(lst_prestados);
      }
      else if(opcion==9){
        importarDatos(lst_libros);
      }
      else if(opcion==10){
        Exportar_datos_libros(lst_libros);
      }
  }
    return 0;
}