/*
 * Editorial.c
 *
 *  Created on: 21 nov. 2021
 *      Author: RocioGonzalez
 */

#include "Editorial.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**\brief Constructor de eDitorial.
 *
 * \param void
 * \return eEditorial* Retorna un puntero de la editorial o NULL.
 *
 */
eEditorial* eEditorial_new(void)
{
	eEditorial* pEditorial = NULL;
	pEditorial = (eEditorial *) malloc(sizeof(eEditorial));
    return pEditorial;
}

/** \brief Constructor parametrizado de editorial.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \return eEditorial* Retorna un puntero de editorial con los datos cargados o NULL.
 *
 */
eEditorial* eEditorial_newParametros(char* idStr,char* nombreStr)
{
	eEditorial* pEditorial = NULL;
    int id;
    if(idStr != NULL && nombreStr != NULL )
    {
    	pEditorial = eEditorial_new();
        if(pEditorial != NULL)
        {
            id = atoi(idStr);
            eEditorial_setId(pEditorial, id);
            eEditorial_setNombre(pEditorial, nombreStr);
        }

    }
    return pEditorial;
}
/** \brief  Establece el id de una editorial.
 *
 * \param this eEditorial* editorial con la que vamos a trabajar
 * \param id int id a setear
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEditorial_setId(eEditorial* this,int id)
{
	int retorno = 1;
    if(this != NULL)
    {
        this->idEditorial = id;
        retorno =0;
    }
    return retorno;
}

/** \brief Devuelve el id de una editorial.
 *
 * \param this eEditorial* editorial con la que vamos a trabajar
 * \param id int* puntero en donde vamos a poner el id a obtener
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEditorial_getId(eEditorial* this,int* id)
{
	int retorno = 1;
    if(this != NULL && id != NULL)
    {
        *id = this->idEditorial;
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el nombre de una editorial.
 *
 * \param this eEditorial* editorial con la que vamos a trabajar
 * \param nombre char* nombre a setear
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEditorial_setNombre(eEditorial* this,char* nombre)
{
	int retorno = 1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Devuelve el nombre de una editorial.
 *
 * \param this eEditorial* editorial con la que vamos a trabajar
 * \param nombre char* puntero en donde vamos a poner el nombre a obtener
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEditorial_getNombre(eEditorial* this,char* nombre)
{
	int retorno = 1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
