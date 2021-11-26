/*
 * parser.h
 *
 *  Created on: 3 nov. 2021
 *      Author: RocioGonzalez
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
int parser_TextFromLibro(FILE* pFile , LinkedList* pArrayListLibro);


#endif /* PARSER_H_ */
