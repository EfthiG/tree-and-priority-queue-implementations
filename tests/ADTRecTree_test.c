//////////////////////////////////////////////
//                                          //
// Unit tests για τον ADT RecTree.          //
//                                          //
//////////////////////////////////////////////

#include "acutest.h"			

#include <stdlib.h>
#include "ADTRecTree.h"
#include "ADTRecTree_utils.h"

int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		
	*pointer = value;	
	return pointer;
}

void rectree_test(void){
    RecTree rectree;
    RecTree null_rectree;

    null_rectree = rectree_create(NULL, NULL, NULL);
    TEST_ASSERT(rectree_size(null_rectree) == 0);

    rectree = rectree_create(create_int(5), NULL, NULL);
    TEST_ASSERT(rectree != NULL);
    TEST_ASSERT(*(int*)rectree_value(rectree) == 5);
    TEST_ASSERT(rectree_size(rectree) == 1);

   RecTree rectree2 = rectree_create(create_int(7), NULL,  NULL);
   RecTree rectree3 = rectree_create(create_int(10), rectree, rectree2);


    TEST_ASSERT(rectree3 != NULL);

    TEST_ASSERT(rectree_left(rectree3) == rectree);
    TEST_ASSERT(rectree_right(rectree3) == rectree2);

    TEST_ASSERT(*(int*)rectree_value(rectree_right(rectree3)) == 7);
    TEST_ASSERT(*(int*)rectree_value(rectree_left(rectree3)) == 5);

    TEST_ASSERT(rectree_size(rectree3) == 3);

    RecTree rtr = rectree_create(create_int(98), rectree3, rectree);
    TEST_ASSERT(rectree_size(rtr) == 5);


  free(rectree_value(rectree));
  free(rectree_value(rectree2));
  free(rectree_value(rectree3));
  free(rectree_value(rtr));


  rectree_destroy(rectree);
  rectree_destroy(rectree2);
  rectree_destroy(rectree3);
  rectree_destroy(rtr);
  rectree_destroy(null_rectree);

}


TEST_LIST = {
	{ "test_rectree", rectree_test},

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};