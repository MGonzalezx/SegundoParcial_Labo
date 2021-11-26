#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Menu.h"
#include "Biblioteca.h"
#include "Libro.h"
#include "Editorial.h"
#include "Controller.h"


/** \brief Carga los datos de los libros desde el archivo pasado por parámetro(modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListLibro LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromTextLibro(char* path , LinkedList* pArrayListLibro)
{
	FILE* pArchivo = NULL;

	int retorno = 1;

	if(path != NULL && pArrayListLibro != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_LibroFromText(pArchivo, pArrayListLibro);
			fclose(pArchivo);
			retorno = 0;
		}


	}
	return retorno;
}

/** \brief Carga los datos de las editoriales desde el archivo pasado por parámetro (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEditorial LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial)
{
	FILE* pArchivo = NULL;

	int retorno = 1;

	if(path != NULL && pArrayListEditorial != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_EditorialFromText(pArchivo, pArrayListEditorial);
			fclose(pArchivo);
			retorno = 0;
		}

	}
	return retorno;
}


/** \brief Listar Libros con su información completa
 *
 *\param pArrayListLibro LinkedList* Lista linkeada donde se obtienen los libros.
 *\param pArrayListEditorial LinkedList* Lista linkeada donde se obtienen las editoriales.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial)
{
	int retorno = 1;
	char editorialNombre[128];
	int auxIdEditorialLibro;
	int auxIdEditorial;
	eLibro* pLibro;
	eEditorial* pEditorial;
	if((ll_len(pArrayListLibro))>0)
	{
		printf("%5s | %52s | %25s| %20s | %30s\n", "Id", "Titulo", "Autor", "Precio", "Editorial");
		for(int i=0; i<ll_len(pArrayListLibro); i++)
		{
			pLibro = ll_get(pArrayListLibro, i);
			auxIdEditorialLibro = pLibro->idEditorial;
			for(int j = 0; j < ll_len(pArrayListEditorial); j++)
			{
				pEditorial = ll_get(pArrayListEditorial, j);
				auxIdEditorial = pEditorial->idEditorial;

				if(auxIdEditorial == auxIdEditorialLibro)
				{
					strcpy (editorialNombre, pEditorial->nombre);
				}


			}

			if(pLibro != NULL)
			{
				eLibro_print(pLibro);
				printf("| %30s\n",editorialNombre);
				retorno = 0;
			}



		}
	}
	printf("\n");
	return retorno;



}

/** \brief Ordenar libros por Autor
 *
 * \param pArrayListLibro LinkedList* Lista linkeada donde se obtienen los libros.
 * \param pArrayListEditorial LinkedList* Lista linkeada donde se obtienen las editoriales.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_sortLibroAutores(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial)
{
    int retorno = 1;
    LinkedList* pAuxListLibro = NULL;
    if(pArrayListLibro != NULL)
    {
    	pAuxListLibro = ll_clone(pArrayListLibro);



		printf("Ordenando...\n");
		ll_sort(pAuxListLibro, eLibro_CompararAutor, 1);
		printf("\nLista de empleados ordenada por Autor(Ascendente).\n\n");
		controller_ListLibro(pAuxListLibro, pArrayListEditorial);



        ll_deleteLinkedList(pAuxListLibro);
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda los datos en el archivo que recibimos por parámetros (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param this LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsText(char* path, LinkedList* this)
{
	FILE* pArchivo = NULL;
	LinkedList* listaFiltrada = NULL;
	int retorno = 1;
	if(path != NULL && this != NULL)
	{
		 listaFiltrada = ll_filter(this, FiltraNombreMinotauroEditoriales);
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno = parser_TextFromLibro(pArchivo ,listaFiltrada);
		}
		fclose(pArchivo);

	}
	return retorno;



}


/** \brief Guarda los datos en el archivo que recibimos por parámetros (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param this LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsTextMapeado(char* path, LinkedList* this)
{
	FILE* pArchivo = NULL;
	LinkedList* listaMapeada = NULL;
	int retorno = 1;

	listaMapeada = ll_clone(this);
	if(path != NULL && this != NULL)
	{
		if(ll_map(this, MapearPrecios) == 0)
		{
			pArchivo = fopen(path, "w");
			if(pArchivo != NULL)
			{
				retorno = parser_TextFromLibro(pArchivo ,listaMapeada);
			}
			fclose(pArchivo);
		}


	}
	return retorno;



}
