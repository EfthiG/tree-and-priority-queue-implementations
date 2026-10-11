///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT CompTree μέσω ADT RecTree
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "ADTRecTree.h"
#include "ADTCompTree.h"
#include "ADTRecTree_utils.h"


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

CompTree comptree_create(Pointer value, CompTree left, CompTree right) {
	return (CompTree)rectree_create(value, (RecTree)left, (RecTree)right);
}


// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int comptree_size(CompTree tree) {
	return rectree_size((RecTree)tree);
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void comptree_destroy(CompTree tree) {
	rectree_destroy((RecTree)tree);
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer comptree_value(CompTree tree) {
	return rectree_value((RecTree)tree);
}

CompTree comptree_left(CompTree tree) {
	return (CompTree)rectree_left((RecTree)tree);
}

CompTree comptree_right(CompTree tree) {
	return (CompTree)rectree_right((RecTree)tree);
}

CompTree comptree_get_subtree(CompTree tree, int pos){
	return (CompTree)rectree_get_subtree((RecTree)tree, pos);
}

CompTree comptree_replace_subtree(CompTree tree, int pos, CompTree subtree){
	return (CompTree)rectree_replace_subtree((RecTree)tree, pos, (RecTree)subtree);
}

CompTree comptree_insert_last(CompTree tree, Pointer value){
	//Αντικαθιστούμε το δέντρο στην θέση του δέντρου που είναι η τελευτάια θέση συν 1 στην οποία πρέπει να υπάρχει NULL με το υποδένρο που έχει τιμή το value που θέλουμε να προσθέσουμε και NULL υποδένδρα
	return comptree_replace_subtree(tree, comptree_size(tree), comptree_create(value, NULL, NULL));
}


CompTree comptree_remove_last(CompTree tree){	
	//Αντικαθιστούμε το τελευταίο υποδένδρο του tree με κενό δέντρο.
	return comptree_replace_subtree(tree, comptree_size(tree)-1, COMP_TREE_EMPTY);
}