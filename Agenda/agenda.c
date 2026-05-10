// Nome: Victor Matheus Marques Morales
// Turma M1
// Matrícula: 25100782

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
ShowMenu
====================
*/
void ShowMenu( void ) {
	puts( "\n1- Adicionar Pessoa (Nome, Idade, email)" );
	puts( "2- Remover Pessoa" );
	puts( "3- Buscar Pessoa" );
	puts( "4- Listar todos" );
	puts( "5- Sair" );
}

/*
====================
AddPerson
====================
*/
void AddPerson( void **pBuffer ) {
	int *totalSize = ( int * ) *pBuffer + 3;

	// realloc for personSize variable and set pointer again
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + sizeof( int ) );
	totalSize = ( int * ) *pBuffer + 3;

	// initialize other variables
	void *pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
	char *currChar = NULL;
	int *currAge = NULL;
	int *personCounter = ( int * ) *pBuffer + 1;
	int *buffer = ( int * ) *pBuffer + 4;
	int *personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );

	// variable to keep track of this person's size
	*personSize = sizeof( int );

	// increase people count
	*personCounter += 1;

	// Ask for name
	printf( "Nome: " );

	// put chars from stdin to buffer variable until enter is pressed
	while ( ( *buffer = getchar() ) != '\n' ) {
		*personSize += 1;

		// realloc for new char
		*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *personSize );

		// reinitialize pointers
		pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
		personCounter = ( int * ) *pBuffer + 1;
		totalSize = ( int * ) *pBuffer + 3;
		buffer = ( int * ) *pBuffer + 4;
		personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );
		currChar = ( char * ) ( ( char * ) ( personSize ) + *personSize - 1 );

		// put buffer char to pBuffer
		*currChar = ( char ) *buffer;
	}

	*personSize += 1;

	// realloc for '\0'
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *personSize );

	// reinitialize pointers
	pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
	personCounter = ( int * ) *pBuffer + 1;
	totalSize = ( int * ) *pBuffer + 3;
	buffer = ( int * ) *pBuffer + 4;
	personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );
	currChar = ( char * ) ( ( char * ) ( personSize ) + *personSize - 1 );

	// put '\0' to end name string
	*currChar = '\0';

	// ask for age
	printf( "Idade: " );

	*personSize += sizeof( int );

	// realloc for int age
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *personSize );

	// reinitialize pointers
	pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
	personCounter = ( int * ) *pBuffer + 1;
	totalSize = ( int * ) *pBuffer + 3;
	buffer = ( int * ) *pBuffer + 4;
	personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );
	currAge = ( int * ) ( ( char * ) personSize + ( *personSize - sizeof( int ) ) );

	scanf( "%d", currAge );
	getchar();

	// ask for email
	printf( "E-mail: " );

	// put chars from stdin to buffer variable until enter is pressed
	while ( ( *buffer = getchar() ) != '\n' ) {
		*personSize += 1;

		// realloc for new char
		*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *personSize );

		// reinitialize pointers
		pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
		personCounter = ( int * ) *pBuffer + 1;
		totalSize = ( int * ) *pBuffer + 3;
		buffer = ( int * ) *pBuffer + 4;
		personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );
		currChar = ( char * ) ( ( char * ) ( personSize ) + *personSize - 1 );

		// put buffer char to pBuffer
		*currChar = ( char ) *buffer;
	}

	*personSize += 1;

	// realloc for '\0'
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *personSize );

	// reinitialize pointers
	pBufferBase = ( char * ) *pBuffer + ( sizeof( int ) * 5 );
	personCounter = ( int * ) *pBuffer + 1;
	totalSize = ( int * ) *pBuffer + 3;
	buffer = ( int * ) *pBuffer + 4;
	personSize = ( int * ) ( ( char * ) pBufferBase + *totalSize );
	currChar = ( char * ) ( ( char * ) ( personSize ) + *personSize - 1 );

	// put '\0' to end email string
	*currChar = '\0';

	*totalSize += *personSize;
}

/*
====================
RemovePerson
====================
*/
void RemovePerson( void **pBuffer ) {
	int *personCounter = ( int * ) *pBuffer + 1;

	if ( *personCounter == 0 ) {
		puts( "Lista vazia." );
		return;
	}

	int *totalSize = ( int * ) *pBuffer + 3;

	// realloc for new string search
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + 1 );
	totalSize = ( int * ) *pBuffer + 3;

	// initialize variables
	int *counter = ( int * ) *pBuffer + 2;
	char *search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
	int *buffer = ( int * ) *pBuffer + 4;
	char *currChar = search;

	// use counter as search's length
	*counter = 0;

	// ask for search
	printf( "Busque por nome para excluir: " );

	// put chars from stdin to buffer variable until enter is pressed
	while ( ( *buffer = getchar() ) != '\n' ) {

		// realloc for new char
		*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *counter + 1 );

		// reinitialize pointers
		search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
		counter = ( int * ) *pBuffer + 2;
		totalSize = ( int * ) *pBuffer + 3;
		buffer = ( int * ) *pBuffer + 4;
		currChar = search + *counter;

		// put buffer char to pBuffer
		*currChar = ( char ) *buffer;
		*counter += 1;
	}

	// realloc for '\0'
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *counter + 1 );

	// reinitialize pointers
	search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
	personCounter = ( int * ) *pBuffer + 1;
	counter = ( int * ) *pBuffer + 2;
	totalSize = ( int * ) *pBuffer + 3;
	buffer = ( int * ) *pBuffer + 4;
	currChar = search + *counter;

	// put '\0' to end name string
	*currChar = '\0';

	int *currSize = ( int * ) *pBuffer + 5;
	int *intP = NULL;
	char *currName = ( char * ) *pBuffer + sizeof( int ) * 5 + sizeof( int );

	*counter = 0;

	// compare names to searched name
	while ( strcmp( currName, search ) != 0 ) {
		*counter += 1;

		if ( *counter >= *personCounter ) {
			puts( "Pessoa não encontrada." );
			return;
		}

		currName += *currSize;
		currSize = ( int * ) ( ( char * ) currSize + *currSize );
	}

	// points to the found person
	char *currPerson = currName - sizeof( int );

	// save persons size to buffer
	*buffer = *( int * ) currPerson;

	// go to next person
	currPerson += *buffer;

	// update variables
	*totalSize -= *buffer;
	*personCounter -= 1;

	// calculate remaining size
	char *end = ( char * ) *pBuffer + sizeof( int ) * 5 + *totalSize + *buffer;

	// put remaining size in *counter
	*counter = end - currPerson;

	// overwrite removed person's bytes
	memmove( currPerson - *buffer, currPerson, *counter );

	// realloc to correct size, also remove search
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize );

	puts( "Pessoa removida" );
}

/*
====================
SearchPerson
====================
*/
void SearchPerson( void **pBuffer ) {
	int *personCounter = ( int * ) *pBuffer + 1;

	if ( *personCounter == 0 ) {
		puts( "Lista vazia." );
		return;
	}

	int *totalSize = ( int * ) *pBuffer + 3;

	// realloc for new string search
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + 1 );
	totalSize = ( int * ) *pBuffer + 3;

	// initialize variables
	int *buffer = ( int * ) *pBuffer + 4;
	char *search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
	char *currChar = search;
	int *counter = ( int * ) *pBuffer + 2;

	// use counter as search's length
	*counter = 0;

	// ask for search
	printf( "Busque por nome: " );

	// put chars from stdin to buffer variable until enter is pressed
	while ( ( *buffer = getchar() ) != '\n' ) {

		// realloc for new char
		*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *counter + 1 );

		// reinitialize pointers
		search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
		totalSize = ( int * ) *pBuffer + 3;
		buffer = ( int * ) *pBuffer + 4;
		currChar = search + *counter;
		counter = ( int * ) *pBuffer + 2;

		// put buffer char to pBuffer
		*currChar = ( char ) *buffer;
		*counter += 1;
	}

	// realloc for '\0'
	*pBuffer = realloc( *pBuffer, ( sizeof( int ) * 5 ) + *totalSize + *counter + 1 );

	// reinitialize pointers
	search = ( char * ) *pBuffer + ( sizeof( int ) * 5 ) + *totalSize;
	personCounter = ( int * ) *pBuffer + 1;
	totalSize = ( int * ) *pBuffer + 3;
	buffer = ( int * ) *pBuffer + 4;
	currChar = search + *counter;
	counter = ( int * ) *pBuffer + 2;

	// put '\0' to end name string
	*currChar = '\0';

	int *currSize = ( int * ) *pBuffer + 5;
	int *intP = NULL;
	char *currName = ( char * ) *pBuffer + sizeof( int ) * 5 + sizeof( int );

	*counter = 0;

	// compare names to searched name
	while ( strcmp( currName, search ) != 0 ) {
		*counter += 1;

		if ( *counter >= *personCounter ) {
			puts( "Pessoa não encontrada." );
			return;
		}

		currName += *currSize;
		currSize = ( int * ) ( ( char * ) currSize + *currSize );
	}

	// print found person info
	currChar = currName;

	printf( "Nome: " );

	while ( *currChar != '\0' ) {
		printf( "%c", *currChar );
		currChar += 1;
	}

	intP = ( int * ) ( currChar + 1 );

	printf( "\nIdade: %d", *intP );

	printf( "\nE-mail: " );

	currChar += 1 + sizeof( int );

	while ( *currChar != '\0' ) {
		printf( "%c", *currChar );
		currChar += 1;
	}

	*pBuffer = realloc( *pBuffer, sizeof( int ) * 5 + *totalSize );
}

/*
====================
ListAll
====================
*/
void ListAll( void **pBuffer ) {

	// pBuffer:
	// [int choice][int personCounter][int counter]
	// [int totalSize][int buffer][person][next person...]
	//
	// Person:
	// [int size][string name][int age][string email]

	int *personCounter = ( int * ) *pBuffer + 1;

	if ( *personCounter == 0 ) {
		puts( "Lista vazia." );
		return;
	}

	int *counter = ( int * ) *pBuffer + 2;
	int *pBufferBase = ( int * ) *pBuffer + 5;
	int *intP = pBufferBase;
	char *charP = ( char * ) pBufferBase + sizeof( int );

	*counter = 0;

	while ( *counter < *personCounter ) {
		printf( "\n\n--- Pessoa %d ---\n", *counter + 1 );
		printf( "Nome: " );

		while ( *charP != '\0' ) {
			printf( "%c", *charP );
			charP += 1;
		}

		intP = ( int * ) ( charP + 1 );

		printf( "\nIdade: %d", *intP );

		printf( "\nE-mail: " );

		charP += 1 + sizeof( int );

		while ( *charP != '\0' ) {
			printf( "%c", *charP );
			charP += 1;
		}

		*counter += 1;

		charP += 1 + sizeof( int );
	}
}

/*
====================
main
====================
*/
int main( void ) {

	// pBuffer:
	// [int choice][int personCounter][int counter][int totalSize][int buffer][people]
	
    // Person:
	// [int size][char * name][int age][char * email]

	void *pBuffer = malloc( sizeof( int ) * 5 );

	int *personCounter = ( int * ) pBuffer + 1;
	int *totalSize = ( int * ) pBuffer + 3;
	int *choice = ( int * ) pBuffer;

	*personCounter = 0;
	*totalSize = 0;
	*choice = 0;

	while ( *choice != 5 ) {
		*choice = 0;

		ShowMenu();

		printf( "Input: " );
		scanf( "%d", choice );
		getchar();

		switch ( *choice ) {

		case 1:
			AddPerson( &pBuffer );
			break;

		case 2:
			RemovePerson( &pBuffer );
			break;

		case 3:
			SearchPerson( &pBuffer );
			break;

		case 4:
			ListAll( &pBuffer );
			break;

		case 5:
			continue;
			break;

		default:
			break;
		}
	}

	free( pBuffer );
}