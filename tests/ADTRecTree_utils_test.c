//////////////////////////////////////////////
//                                          //
// Unit tests για τον ADT_RecTree_utils.    //
//                                          //
//////////////////////////////////////////////

#include "acutest.h"			

#include "ADTRecTree.h"
#include "ADTRecTree_utils.h"

int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		
	*pointer = value;	
	return pointer;
}

void rectree_get_subtree_test(void){
    RecTree tree1 = rectree_create(create_int(1), NULL, NULL);
    RecTree tree2 = rectree_create(create_int(2), NULL, NULL);
    RecTree tree3 = rectree_create(create_int(3), NULL, tree2);
    RecTree tree4 = rectree_create(create_int(4), tree1, tree3);

    TEST_ASSERT(rectree_get_subtree(tree4, 0) == tree4);
    TEST_ASSERT(rectree_get_subtree(tree4, 2) == tree3);
    TEST_ASSERT(rectree_get_subtree(tree4, 6) == tree2);
    TEST_ASSERT(rectree_get_subtree(tree4, 20) == REC_TREE_EMPTY);
    TEST_ASSERT(rectree_get_subtree(tree4, 4) == REC_TREE_EMPTY);
    TEST_ASSERT(rectree_get_subtree(REC_TREE_EMPTY, 5) == REC_TREE_EMPTY);

    free(rectree_value(tree1));
    free(rectree_value(tree2));
    free(rectree_value(tree3));
    free(rectree_value(tree4));

    rectree_destroy(tree1);
    rectree_destroy(tree2);
    rectree_destroy(tree3);
    rectree_destroy(tree4);
}

void rectree_replace_subtree_test(void){    
    RecTree tree1 = rectree_create(create_int(1), NULL, NULL);
    RecTree tree2 = rectree_create(create_int(2), NULL, NULL);
    RecTree tree3 = rectree_create(create_int(3), NULL, tree2);
    RecTree tree4 = rectree_create(create_int(4), tree1, tree3);

    RecTree tree_changed = rectree_create(create_int(3), tree1, tree2);
    RecTree replaced = rectree_replace_subtree(tree3, 1, tree1);

    TEST_ASSERT(*(int*)rectree_value(replaced) == *(int*)rectree_value(tree_changed));
    TEST_ASSERT(rectree_left(replaced) == rectree_left(tree_changed));
    TEST_ASSERT(rectree_size(replaced) == rectree_size(tree_changed));

    rectree_destroy(tree_changed);
    free(rectree_value(tree_changed));

    tree_changed = rectree_create(create_int(4), tree1, tree2);
    replaced = rectree_replace_subtree(tree4, 2, tree2);

    TEST_ASSERT(*(int*)rectree_value(replaced) == *(int*)rectree_value(tree_changed));
    TEST_ASSERT(rectree_right(replaced) == rectree_right(tree_changed));
    TEST_ASSERT(rectree_size(replaced) == rectree_size(tree_changed));

    rectree_destroy(replaced);

    replaced = rectree_replace_subtree(tree3, 0, tree1);
    TEST_ASSERT(replaced == tree1);
    TEST_ASSERT(rectree_replace_subtree(REC_TREE_EMPTY, 6, tree4) == REC_TREE_EMPTY);

    free(rectree_value(tree1));
    free(rectree_value(tree2));
    free(rectree_value(tree3));
    free(rectree_value(tree4));
    free(rectree_value(tree_changed));

    rectree_destroy(tree1);
    rectree_destroy(tree2);
    rectree_destroy(tree4);
    rectree_destroy(tree_changed);


}


TEST_LIST = {
   { "test_rectree_get_subtree", rectree_get_subtree_test},
   { "test_rectree_replace_subtree", rectree_replace_subtree_test},

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};


