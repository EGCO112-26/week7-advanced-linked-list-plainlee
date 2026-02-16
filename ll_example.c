// // Fig. 12.3: fig12_03.c
// // Inserting and deleting nodes in a list
// #include <stdio.h>
// #include <stdlib.h>
// #include "ll.h"

// int main(void)
// { 
//    LLPtr startPtr = NULL; // initially there are no nodes
//    unsigned int choice; // user's choice
//    int item; // char entered by user

//    instructions(); // display the menu
//    printf( "%s", "? " );
//    scanf( "%u", &choice );

//    // loop while user does not choose 3
//    while ( choice != 3 ) { 

//       switch ( choice ) { 
//          case 1:
//             printf( "%s", "Enter a number: " );
//             scanf( "%d", &item );
//             insert( &startPtr, item ); // insert item in list
//             printList( startPtr );
//             break;
//          case 2: // delete an element
//             // if list is not empty
//             if ( !isEmpty( startPtr ) ) { 
//                printf( "%s", "Enter number to be deleted: " );
//                scanf( "%d", &item );

//                // if character is found, remove it
//                if ( deletes( &startPtr, item ) ) { // remove item
//                   printf( "%d deleted.\n", item );
//                   printList( startPtr );
//                } // end if
//                else {
//                   printf( "%d not found.\n\n", item );
//                } // end else
//             } // end if
//             else {
//                puts( "List is empty.\n" );
//             } // end else

//             break;
//          default:
//             puts( "Invalid choice.\n" );
//             instructions();
//             break;
//       } // end switch

//       printf( "%s", "? " );
//       scanf( "%u", &choice );
//    } // end while
//   /* Clear all nodes at the end of nodes*/
//    puts( "End of run." );
// } // end main


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "ll.h"

// int main( void )
// {
//    LLPtr startPtr = NULL;
//    unsigned int choice;
//    int id;
//    char name[50];
//    char buffer[100];

//    instructions();

//    while ( 1 ) {
//       printf( "%s", "? " );

     
//       if ( fgets(buffer, sizeof(buffer), stdin) == NULL ) break;

      
//       if ( sscanf(buffer, "%u", &choice) != 1 ) {
//          puts( "Invalid choice." );
//          instructions();
//          continue; 
//       }

//       if ( choice == 3 ) break;

//       switch ( choice ) {
//          case 1:
//             printf( "%s", "Enter id and name: " );
//             while ( 1 ) {
//                 if ( fgets(buffer, sizeof(buffer), stdin) != NULL ) {
//                     if ( sscanf(buffer, "%d %49s", &id, name) == 2 ) {
//                         break;
//                     }
//                 }
//                 printf( "Invalid input. Try again: " );
//             }

//             insert( &startPtr, id, name );
//             printList( startPtr );
//             break;

//          case 2:
//             if ( !isEmpty( startPtr ) ) {
//                printf( "%s", "Enter number to be deleted: " );
//                while ( 1 ) {
//                     if ( fgets(buffer, sizeof(buffer), stdin) != NULL ) {
//                         if ( sscanf(buffer, "%d", &id) == 1 ) break;
//                     }
//                     printf( "Invalid input. Enter number to be deleted again: " );
//                }

//                if ( deletes( &startPtr, id ) ) {
//                   printf( "id %d deleted.\n", id );
//                   printList( startPtr );
//                }
//                else {
//                   printf( "id %d not found.\n\n", id );
//                }
//             }
//             else {
//                puts( "List is empty.\n" );
//             }
//             break;

//          default:
//             puts( "Invalid choice.\n" );
//             instructions();
//             break;
//       }
//    }

//    puts( "Clear all nodes" );
//    clearList( &startPtr );
//    puts( "End of run." );
   
//    return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main( void )
{
   LLPtr startPtr = NULL;
   unsigned int choice;
   int id;
   char name[50];

   instructions();

   while ( 1 ) {
      printf( "%s", "? " );
      
      // รับ Choice: ถ้าอ่านไม่สำเร็จ หรือจบไฟล์ (EOF) ให้จบโปรแกรมทันที
      if ( scanf( "%u", &choice ) != 1 ) break;

      if ( choice == 3 ) break;

      switch ( choice ) {
         case 1:
            printf( "%s", "Enter id and name: " );
            // รับ id และ name พร้อมกัน (เช่น 123 Somchai)
            // ถ้าอ่านไม่ได้ครบ 2 ตัว ให้จบโปรแกรมทันที (ป้องกัน Loop)
            if ( scanf( "%d %49s", &id, name ) != 2 ) goto end_of_run;

            insert( &startPtr, id, name );
            printList( startPtr );
            break;

         case 2:
            if ( !isEmpty( startPtr ) ) {
               printf( "%s", "Enter id to be deleted: " );
               // รับ id ที่จะลบ ถ้าอ่านไม่ได้ ให้จบโปรแกรม
               if ( scanf( "%d", &id ) != 1 ) goto end_of_run;

               if ( deletes( &startPtr, id ) ) {
                  printf( "id %d deleted.\n", id );
                  printList( startPtr );
               }
               else {
                  printf( "id %d not found.\n\n", id );
               }
            }
            else {
               puts( "List is empty.\n" );
            }
            break;

         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      }
   }

end_of_run:
   puts( "Clear all nodes" );
   clearList( &startPtr );
   puts( "End of run." );
   
   return 0;
}