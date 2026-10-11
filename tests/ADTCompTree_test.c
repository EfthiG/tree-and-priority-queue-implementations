//////////////////////////////////////////////
//                                          //
// Unit tests για τον ADT CompTree.          //
//                                          //
//////////////////////////////////////////////

#include "acutest.h"			

#include "../modules/UsingADTRecTree/ADTCompTree.h"
#include "../include/ADTRecTree_utils.h"

int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		
	*pointer = value;	
	return pointer;
}





void comptree_test(void){
   
    CompTree null_comptree = comptree_create(NULL, NULL, NULL);
    TEST_ASSERT(comptree_size(null_comptree) == 0);

    CompTree comptree = comptree_create(create_int(5), NULL, NULL);
    TEST_ASSERT(comptree != NULL);
    TEST_ASSERT(*(int*)comptree_value(comptree) == 5);
    TEST_ASSERT(comptree_size(comptree) == 1);

   CompTree comptree2 = comptree_create(create_int(7), NULL,  NULL);
   CompTree comptree3 = comptree_create(create_int(10), comptree, comptree2);


    TEST_ASSERT(comptree3 != NULL);

    TEST_ASSERT(comptree_left(comptree3) == comptree);
    TEST_ASSERT(comptree_right(comptree3) == comptree2);

    TEST_ASSERT(*(int*)comptree_value(comptree_right(comptree3)) == 7);
    TEST_ASSERT(*(int*)comptree_value(comptree_left(comptree3)) == 5);

    TEST_ASSERT(comptree_size(comptree3) == 3);

    free(comptree_value(comptree));
    free(comptree_value(comptree2));
    free(comptree_value(comptree3));


   comptree_destroy(comptree);
   comptree_destroy(comptree2);
   comptree_destroy(comptree3);
   comptree_destroy(null_comptree);

}

void comptree_insert_last_test(void){
    CompTree comptree = comptree_create(create_int(5), NULL, NULL);
    CompTree comptree2 = comptree_create(create_int(7), NULL,  NULL);
    CompTree comptree3 = comptree_create(create_int(10), comptree, comptree2);

    free(comptree_value(comptree3));

    int old_size_comptree3 = comptree_size(comptree3);
    Pointer value = create_int(37);
    comptree3 = comptree_insert_last(comptree3, value);
    TEST_ASSERT(comptree_size(comptree3) == old_size_comptree3 + 1);
    CompTree last_subtree = (CompTree)rectree_get_subtree((RecTree)comptree3, 3);
    TEST_ASSERT(*(int*)comptree_value(last_subtree) == 37);

    CompTree null_comptree = comptree_create(NULL, NULL, NULL);
    value = create_int(18);
    CompTree non_empty_tree = comptree_insert_last(null_comptree, value);
    TEST_ASSERT(comptree_size(non_empty_tree) == 1);
    TEST_ASSERT(*(int*)comptree_value(non_empty_tree) == 18);

    free(value);
    free(comptree_value(comptree));
    free(comptree_value(comptree2));
    free(comptree_value(comptree3));

    comptree_destroy(comptree2);
    comptree_destroy(comptree3);
    comptree_destroy(non_empty_tree);
    comptree_destroy(last_subtree);
    comptree_destroy(null_comptree);



}

void comptree_remove_last_test(void){
    CompTree comptree = comptree_create(create_int(5), NULL, NULL);
    CompTree comptree2 = comptree_create(create_int(7), NULL,  NULL);
    CompTree comptree3 = comptree_create(create_int(10), comptree, comptree2);   
    CompTree comptree4 = comptree_create(create_int(40), comptree3, comptree3);

    int old_size = comptree_size(comptree4);
    comptree4 = comptree_remove_last(comptree4);
    TEST_ASSERT(comptree_size(comptree4) == old_size -1);
    TEST_ASSERT(rectree_get_subtree((RecTree)comptree4, old_size-1) == NULL);




}




TEST_LIST = {
	{ "test_comptree", comptree_test},
    { "test_comptree_insert_last", comptree_insert_last_test},
    { "test_comptree_remove_last", comptree_remove_last_test},

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};