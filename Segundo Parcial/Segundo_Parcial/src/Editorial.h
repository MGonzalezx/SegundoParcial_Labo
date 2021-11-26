/*
 * Editorial.h
 *
 *  Created on: 21 nov. 2021
 *      Author: RocioGonzalez
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
	int idEditorial;
	char nombre[128];

}eEditorial;

eEditorial* eEditorial_new();
eEditorial* eEditorial_newParametros(char* idStr,char* nombreStr);
void eEditorial_delete();

int eEditorial_setId(eEditorial* this,int id);
int eEditorial_getId(eEditorial* this,int* id);

int eEditorial_setNombre(eEditorial* this,char* nombre);
int eEditorial_getNombre(eEditorial* this,char* nombre);



#endif /* EDITORIAL_H_ */
