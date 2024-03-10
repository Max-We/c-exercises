#include "list_ops.h"
#include "stdlib.h"
#include "string.h"

// typedef int list_element_t;

// typedef struct {
//    size_t length;
//    list_element_t elements[];
// } list_t;

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *result = malloc(sizeof(list_t) +  length * sizeof(list_element_t));
    result->length = length;
    memcpy(result->elements, elements,  length * sizeof(list_element_t));

    return result;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    // warum geht es auch ohne size of list1 zu addieren?
    list_t *result = realloc(list1, list2->length * sizeof(list_element_t));
    for(size_t i=0; i < list2->length ; i++) {
        result->elements[result->length + i] = list2->elements[i];
    }
    result->length += list2->length;

    return result;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {

}

// returns the length of the list
size_t length_list(list_t *list) {

}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {

}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {

}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {

}   

// reverse the elements of the list
list_t *reverse_list(list_t *list) {

}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {

}

int main() {
    list_element_t e1[3] = {1,2,3};
    list_element_t e2[3] = {1,2,3};
    list_t *l1 = new_list(3, e1);
    list_t *l2 = new_list(3, e2);

    list_t *result = append_list(l1, l2);
    for (size_t i = 0; i < result->length; i++)
    {
        printf("%d\n", result->elements[i]);
    }
}