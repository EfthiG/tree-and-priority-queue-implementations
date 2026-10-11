///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "ADTRecTree.h"


// Προς υλοποίηση...


//  Ένα δέντρο είναι pointer σε αυτό το struct
struct rec_tree {
	RecTree tree_left;        //Το δεξί υποδένδρο
	RecTree tree_right;       //Το αριστερό υποδένδρο
	Pointer value;            //Η τιμή του υποδένδρου
	int size;                 //Το μέγεθος του υποδένδρου
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	RecTree rectree = malloc(sizeof(struct rec_tree));       

	rectree->value = value;
	rectree->tree_left = left;
	rectree->tree_right = right;
	if(value!=NULL){	
		rectree->size = 1; //Αν υπάρχει τιμή τότε τότε το μέγεθος του υποδένδρου είναι 1
	}else{
		rectree->size = 0;	//Αν δεν υπάρχει τότε το δεντρο είναι άδειο και έχει μέγεθος 0	
	}	
	if(left!=NULL)
		rectree->size += rectree_size(left);  //Αν υπάρχει αριστερό υποδένδρο και δεν είναι NULL τότε στο μέγεθος του συνολικού δένδρου προσθέτουμε το μέγεθος του αριστερόυ υποδένδρου
	if(right!=NULL)
		rectree->size += rectree_size(right); //Αν υπάρχει δεξί υποδένδρο τότε στο μέγεθος του συνολικού υποδένδρου προσθέτουμε το μέγεθος του δεξιού υποδένδρου
	

	return rectree;
}


// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {
	return tree->size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.
void rectree_destroy(RecTree tree) {
	free(tree);
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {
	return tree->value;
}

RecTree rectree_left(RecTree tree) {
	return tree->tree_left;
}

RecTree rectree_right(RecTree tree) {
	return tree->tree_right;
}

