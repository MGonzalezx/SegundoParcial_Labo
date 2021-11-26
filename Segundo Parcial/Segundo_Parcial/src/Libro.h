#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "Editorial.h"
typedef struct
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
}eLibro;

eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialStr);

int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setTitulo(eLibro* this,char* titulo);
int eLibro_getTitulo(eLibro* this,char* titulo);

int eLibro_setAutor(eLibro* this,char* autor);
int eLibro_getAutor(eLibro* this,char* autor);

int eLibro_setIdEditorial(eLibro* this,int editorial);
int eLibro_getIdEditorial(eLibro* this,int* editorial);

int eLibro_setPrecio(eLibro* this,int precio);
int eLibro_getPrecio(eLibro* this,int* precio);

///Mis Funciones

int eLibro_print(eLibro* this);

int eLibro_CompararAutor(void* this, void* thisDos);
int FiltraNombreMinotauroEditoriales(void* pElement);
int MapearPrecios(void* pElement);

#endif // employee_H_INCLUDED
