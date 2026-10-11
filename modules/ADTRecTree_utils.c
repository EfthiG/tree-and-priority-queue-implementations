#include "ADTRecTree_utils.h"
#include <stddef.h>

// Επιστρέφει το υποδέντρο του tree στη θέση pos. Η αρίθμηση των θέσεων ξεκινάει
// από το 0 (ρίζα) και κινείται κατά επίπεδα, τα παιδιά της ρίζας έχουν θέση 1
// και 2, τα δικά τους παιδιά έχουν θέσεις 3,4,5,6, κλπ. Αν το υποδέντρο δεν
// υπάρχει θα επιστρέφεται REC_TREE_EMPTY. 

RecTree rectree_get_subtree(RecTree tree, int pos){
    if(tree == REC_TREE_EMPTY){
        return REC_TREE_EMPTY;
    }

    if(pos == 0){  // Base case της αναδρομής: Αν δωθεί θέση 0 τότε επιστρέφουμε το ίδιο το δέντρο από τη ρίζα του
        return tree;
    }

    int parent_pos = (pos - 1)/2;  //Βρίσκουμε τη θέση του πατέρα του υποδένδρου που βρίσκεται στη θέση pos

    RecTree tree_parent = rectree_get_subtree(tree, parent_pos); //Καλούμε αναδρομικά την συνάρτηση κάθε φορα για τη θέση του πατέρα του κάθε υποδένδρου μέχρι η θέση να γίνει 0
    if (tree_parent == NULL) {                                   //οπότε θα έχουμε βρει τη θέση του πατέρα του υποδένδρου που ψάχνουμε
        return REC_TREE_EMPTY;
    }

    RecTree tree_in_pos;

    //Για κάθε υποδένδρο σε θέσυ pos ισχύει: θεση δεξιού υποδένδρου = pos*2 + 1 και θέση αριστερού υποδένδρου = pos*2 + 2 
    if(pos - 2*parent_pos - 1 == 0){            
        tree_in_pos = rectree_left(tree_parent);
    }else{
        tree_in_pos = rectree_right(tree_parent);
    } 

    return tree_in_pos;
}

// Δημιουργεί και επιστρέφει ένα νέο δέντρο, το οποίο προκύπτει αντικαθιστώντας
// το υποδέντρο του tree στη θέση pos με το subtree που δίνεται.  Η θέση pos
// πρέπει να αντιστοιχεί είτε σε υπάρχον κόμβο (που αντικαθίσταται), είτε στο
// κενό παιδί ενός υπάρχοντος κόμβου (οπότε προστίθεται εκεί το subtree).  Αν το
// subtree τοποθετείται στη ρίζα (pos == 0) τότε επιστρέφεται το ίδιο το subtree.

// Η συνάρτηση καταστρέφει αυτόματα τόσο το παλιό υποδέντρο που αντικαθίσταται
// (αν υπάρχει), καθώς και όλους τους προγόνους του που μεταβάλλονται (οπότε
// ξαναδημιουργούνται).
RecTree rectree_replace_subtree(RecTree tree, int pos, RecTree subtree){
    if(tree == NULL){
        return REC_TREE_EMPTY;
    }

    if(pos == 0){        //Bse case της αναδρομής: Αν δωθεί θέση 0 τότε επιστρέφουμε το ίδιο το subtree αφού αντικαθιστούμε ουσιαστικά όλο το δέντρο από τη ρίζα με το υποδένρο
        return subtree;
    }

    int parent_pos = (pos - 1)/2; //Βρίσκουμε τη θέση του πατέρα του υποδένδρου που θέλουμε να αντικαταστήσουμε 
    RecTree tree_parent = rectree_get_subtree(tree, parent_pos); //Βρίσκουμε το υποδένδρο του πατέρα
    
    if(tree_parent == REC_TREE_EMPTY){     // Αν το υποδένδρο του πατέρα είναι κενό δέντρο τότε επιστρέφουμε το ίδιο το δένδρο χωρίς αλλαγές
        return tree;
    }
    RecTree parent_changed;
    if((pos - 2*parent_pos) - 1 == 0){
        parent_changed = rectree_create(rectree_value(tree_parent), subtree, rectree_right(tree_parent));
        rectree_destroy(rectree_left(tree_parent));
    }else{
        parent_changed = rectree_create(rectree_value(tree_parent), rectree_left(tree_parent), subtree);  
        rectree_destroy(rectree_right(tree_parent)); 
    } 
    return rectree_replace_subtree(tree, parent_pos, parent_changed); 
      
}
