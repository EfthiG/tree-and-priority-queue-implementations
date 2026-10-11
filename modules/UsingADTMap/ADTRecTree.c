///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω Maps
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "../../include/ADTRecTree.h"
#include "../../include/ADTMap.h"
#include <stdio.h>


Map map_value;
Map map_left;
Map map_right;
Map size;
Pointer rectree = (Pointer)1;
int count_create=1;      //Counter για την κλήση της σύναρτησης rectree_create()

int compare_ptrs(Pointer a, Pointer b){ //Συνάρτηση compare που συγκρίνει δύο pointers
   return a - b;
}

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
   if(count_create == 1){     //Αν ο μετρητής ειναι 1 τότε είναι η πρώτη φορά που καλέιται η rectree_create() οπότε πρέπει να δημιουργήσουμε τα maps στα οποία αποθηκέυουμε τα στοιχεία των δεντρων
        map_value = map_create(compare_ptrs, NULL, NULL);
        map_left = map_create(compare_ptrs, NULL, NULL);
        map_right = map_create(compare_ptrs, NULL, NULL);
        size = map_create(compare_ptrs, NULL, NULL);
    }

  //Υπολογίζουμε το μέγεθος του δέντρου
    int treesize;
    if(value!=NULL)	
		  treesize = 1;
    else
      treesize = 0;
    if(left!=NULL)
      treesize += rectree_size(left);
    if(right!=NULL)
      treesize += rectree_size(right);
    
//Προσθέτουμε στα maps τα αντίστοιχα στοιχεία του δέντρου
    map_insert(map_value, rectree, value);
    map_insert(map_left, rectree, left);
    map_insert(map_right, rectree, right);
    map_insert(size, rectree, (Pointer)(long)treesize);

//Αυξάνουμε κατά ένα τον counter για την κλήση της  create και τον pointer που περιέχει την σειριακή τιμή του δέντρου που δημιουργούμε 
    count_create++;
    rectree ++;

//Επιστρέφουμε τον pointer του δέντρου μειωμένο κατά ένα διότι τον αυξήσαμε και τώρα θα περιέχει την σειριακή τιμή του επόμενου δέντρου που θα δημιουργηθεί
    return rectree - 1;
}

int rectree_size(RecTree tree){
  if(tree == REC_TREE_EMPTY){
		return 0;
	}
    return (unsigned long long int)map_find(size, tree);
}

void rectree_destroy(RecTree tree){
  
    map_set_destroy_value(map_value, NULL);
    map_set_destroy_value(map_left, NULL);
    map_set_destroy_value(map_right, NULL);
    map_set_destroy_value(size, NULL);

    map_set_destroy_key(map_value, NULL);
    map_set_destroy_key(map_left, NULL);
    map_set_destroy_key(map_right, NULL);
    map_set_destroy_key(size, NULL);
    
    map_remove(map_value, tree);
    map_remove(map_left, tree);
    map_remove(map_right, tree);
    map_remove(size, tree);

  
  if(map_size(map_value) == 0){  // Αν το μέγεθος του map που περιέχει τα values των δέντρων (άρα και των υπολοιπων maps των στοιχείων) είναι 0 
                                 //τότε τα maps έχουν αδειάσει και πρέπει να καταστραφούν
    map_destroy(map_value);
    map_destroy(map_left);
    map_destroy(map_right);
    map_destroy(size);
    count_create = 1;
  }
  return;
}

Pointer rectree_value(RecTree tree){
    return map_find(map_value, tree);
}

RecTree rectree_left(RecTree tree) {
	return map_find(map_left, tree);
}

RecTree rectree_right(RecTree tree) {
	return map_find(map_right, tree);
}