// #include <stdio.h>
// #include <stdlib.h>
// #include "ll.h"



// // display program instructions to user
// void instructions( void )
// {
//    puts( "Enter your choice:");
//       "   1 to insert an element into the list.\n"
//       "   2 to delete an element from the list.\n"
//       "   3 to end." );
// } // end function instructions

// // insert a new value into the list in sorted order
// void insert( LLPtr *sPtr, int value )
// {
//    LLPtr newPtr; // pointer to new node
//    LLPtr previousPtr; // pointer to previous node in list
//    LLPtr currentPtr; // pointer to current node in list

//    newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

//    if ( newPtr != NULL ) { // is space available
//       newPtr->data = value; // place value in node
//       newPtr->nextPtr = NULL; // node does not link to another node
    
       
//       previousPtr = NULL;
//       currentPtr = *sPtr;

//       // loop to find the correct location in the list
//       while ( currentPtr != NULL && value > currentPtr->data ) {
//          previousPtr = currentPtr; // walk to ...
//          currentPtr = currentPtr->nextPtr; // ... next node
//       } // end while

//       // insert new node at beginning of list
//       if ( previousPtr == NULL ) {
//          newPtr->nextPtr = *sPtr;
      
//          *sPtr = newPtr;
        
//       } // end if
//       else { // insert new node between previousPtr and currentPtr
//          previousPtr->nextPtr = newPtr;
   
          
//          newPtr->nextPtr = currentPtr;
 
         
//       } // end else
//    } // end if
//    else {
//       printf( "%d not inserted. No memory available.\n", value );
//    } // end else
// } // end function insert

// // delete a list element
// int deletes( LLPtr *sPtr, int value )
// {
//    LLPtr previousPtr; // pointer to previous node in list
//    LLPtr currentPtr; // pointer to current node in list
//    LLPtr tempPtr; // temporary node pointer

//    // delete first node
//    if ( value == ( *sPtr )->data ) {
//       tempPtr = *sPtr; // hold onto node being removed
//       *sPtr = ( *sPtr )->nextPtr; // de-thread the node
//       free( tempPtr ); // free the de-threaded node
//       return value;
//    } // end if
//    else {
//       previousPtr = *sPtr;
//       currentPtr = ( *sPtr )->nextPtr;

//       // loop to find the correct location in the list
//       while ( currentPtr != NULL && currentPtr->data != value ) {
//          previousPtr = currentPtr; // walk to ...
//          currentPtr = currentPtr->nextPtr; // ... next node
//       } // end while

//       // delete node at currentPtr
//       if ( currentPtr != NULL ) {
//          tempPtr = currentPtr;
//          previousPtr->nextPtr = currentPtr->nextPtr;
//          free( tempPtr );
//          return value;
//       } // end if
//    } // end else

//    return '\0';
// } // end function delete

// // return 1 if the list is empty, 0 otherwise
// int isEmpty( LLPtr sPtr )
// {
//    return sPtr == NULL;
// } // end function isEmpty

// // print the list
// void printList( LLPtr currentPtr )
// {
//    // if list is empty
//    if ( isEmpty( currentPtr ) ) {
//       puts( "List is empty.\n" );
//    } // end if
//    else {
//       puts( "The list is:" );

//       // while not the end of the list
//       while ( currentPtr->nextPtr!= NULL ) {
//          printf( "%d --> ", currentPtr->data );
//          currentPtr = currentPtr->nextPtr;
//       } // end while

//       printf( "%d --> NULL\n",currentPtr->data );
       

     
       
//    } // end else
// } // end function printList


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "ll.h"

// void instructions( void )
// {
//    puts( "Enter your choice:\n"
//          "   1 to insert an element into the list.\n"
//          "   2 to delete an element from the list.\n"
//          "   3 to end." );
// }

// void insert( LLPtr *sPtr, int id, char *name )
// {
//    LLPtr newPtr;
//    LLPtr previousPtr;
//    LLPtr currentPtr;

//    newPtr = (LLPtr) malloc( sizeof( LLnode ) );

//    if ( newPtr != NULL ) {
//       newPtr->id = id;
//       strcpy(newPtr->name, name);
//       newPtr->nextPtr = NULL;
//       newPtr->previousPtr = NULL;

//       previousPtr = NULL;
//       currentPtr = *sPtr;

//       while ( currentPtr != NULL && id > currentPtr->id ) {
//          previousPtr = currentPtr;
//          currentPtr = currentPtr->nextPtr;
//       }

//       if ( previousPtr == NULL ) {
//          newPtr->nextPtr = *sPtr;
//          if( *sPtr != NULL ) {
//             (*sPtr)->previousPtr = newPtr;
//          }
//          *sPtr = newPtr;
//       }
//       else {
//          previousPtr->nextPtr = newPtr;
//          newPtr->previousPtr = previousPtr;

//          newPtr->nextPtr = currentPtr;
//          if( currentPtr != NULL ) {
//             currentPtr->previousPtr = newPtr;
//          }
//       }
//    }
//    else {
//       printf( "%d not inserted. No memory available.\n", id );
//    }
// }

// int deletes( LLPtr *sPtr, int id )
// {
//    LLPtr currentPtr;
//    LLPtr tempPtr;

//    if ( *sPtr != NULL && (*sPtr)->id == id ) {
//       tempPtr = *sPtr;
//       *sPtr = ( *sPtr )->nextPtr;

//       if ( *sPtr != NULL ) {
//           (*sPtr)->previousPtr = NULL;
//       }

//       free( tempPtr );
//       return id;
//    }
//    else {
//       currentPtr = *sPtr;

//       while ( currentPtr != NULL && currentPtr->id != id ) {
//          currentPtr = currentPtr->nextPtr;
//       }

//       if ( currentPtr != NULL ) {
//          tempPtr = currentPtr;

//          if(currentPtr->previousPtr != NULL) {
//              currentPtr->previousPtr->nextPtr = currentPtr->nextPtr;
//          }

//          if(currentPtr->nextPtr != NULL) {
//              currentPtr->nextPtr->previousPtr = currentPtr->previousPtr;
//          }

//          free( tempPtr );
//          return id;
//       }
//    }
//    return '\0';
// }

// int isEmpty( LLPtr sPtr )
// {
//    return sPtr == NULL;
// }

// void printList( LLPtr currentPtr )
// {
//    LLPtr lastPtr = NULL;

//    if ( isEmpty( currentPtr ) ) {
//       puts( "List is empty.\n" );
//    }
//    else {
//       puts( "The list is:" );
//       while ( currentPtr != NULL ) {
//          printf( "%d %s --> ", currentPtr->id, currentPtr->name );
//          lastPtr = currentPtr;
//          currentPtr = currentPtr->nextPtr;
//       }
//       puts( "NULL" );

//       while ( lastPtr != NULL ) {
//           printf( "%d %s --> ", lastPtr->id, lastPtr->name );
//           lastPtr = lastPtr->previousPtr;
//       }
//       puts( "NULL\n" );
//    }
// }

// void clearList( LLPtr *sPtr )
// {
//     LLPtr currentPtr = *sPtr;
//     LLPtr tempPtr;

//     while ( currentPtr != NULL ) {
//         tempPtr = currentPtr;
//         printf("delete %d\n", currentPtr->id);
//         currentPtr = currentPtr->nextPtr;
//         free( tempPtr );
//     }
//     *sPtr = NULL;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void instructions( void )
{
   puts( "Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to end." );
}

void insert( LLPtr *sPtr, int id, char *name )
{
   LLPtr newPtr;
   LLPtr previousPtr;
   LLPtr currentPtr;

   newPtr = (LLPtr) malloc( sizeof( LLnode ) );

   if ( newPtr != NULL ) {
      newPtr->id = id;
      strcpy(newPtr->name, name);
      newPtr->nextPtr = NULL;
      newPtr->previousPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while ( currentPtr != NULL && id > currentPtr->id ) {
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }

      if ( previousPtr == NULL ) {
         newPtr->nextPtr = *sPtr;
         if( *sPtr != NULL ) {
            (*sPtr)->previousPtr = newPtr;
         }
         *sPtr = newPtr;
      }
      else {
         previousPtr->nextPtr = newPtr;
         newPtr->previousPtr = previousPtr;

         newPtr->nextPtr = currentPtr;
         if( currentPtr != NULL ) {
            currentPtr->previousPtr = newPtr;
         }
      }
   }
   else {
      printf( "%d not inserted. No memory available.\n", id );
   }
}

int deletes( LLPtr *sPtr, int id )
{
   LLPtr currentPtr;
   LLPtr tempPtr;

   if ( *sPtr != NULL && (*sPtr)->id == id ) {
      tempPtr = *sPtr;
      *sPtr = ( *sPtr )->nextPtr;

      if ( *sPtr != NULL ) {
          (*sPtr)->previousPtr = NULL;
      }

      free( tempPtr );
      return id;
   }
   else {
      currentPtr = *sPtr;

      while ( currentPtr != NULL && currentPtr->id != id ) {
         currentPtr = currentPtr->nextPtr;
      }

      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;

         if(currentPtr->previousPtr != NULL) {
             currentPtr->previousPtr->nextPtr = currentPtr->nextPtr;
         }

         if(currentPtr->nextPtr != NULL) {
             currentPtr->nextPtr->previousPtr = currentPtr->previousPtr;
         }

         free( tempPtr );
         return id;
      }
   }
   return '\0';
}

int isEmpty( LLPtr sPtr )
{
   return sPtr == NULL;
}

void printList( LLPtr currentPtr )
{
   LLPtr lastPtr = NULL;

   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   }
   else {
      puts( "The list is:" );
      
      while ( currentPtr != NULL ) {
         printf( "%d %s -->", currentPtr->id, currentPtr->name );
         lastPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }
      puts( "NULL" );

      while ( lastPtr != NULL ) {
          printf( "%d %s --> ", lastPtr->id, lastPtr->name );
          lastPtr = lastPtr->previousPtr;
      }
      puts( "NULL\n" );
   }
}

void clearList( LLPtr *sPtr )
{
    LLPtr currentPtr = *sPtr;
    LLPtr tempPtr;

    while ( currentPtr != NULL ) {
        tempPtr = currentPtr;
        printf("delete %d\n", currentPtr->id); 
        currentPtr = currentPtr->nextPtr;
        free( tempPtr );
    }
    *sPtr = NULL;
}