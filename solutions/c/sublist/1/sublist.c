#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {

    //check for empty lists
    if (!list_to_compare_element_count && !base_list_element_count) {
        return EQUAL;
    } else if ( base_list && !list_to_compare_element_count) {
        return SUBLIST;
    } else if (  !base_list_element_count && list_to_compare_element_count) {
        return SUPERLIST;
    }

    comparison_result_t my_result = UNEQUAL;

    //check for equal lists
    if (list_to_compare_element_count == base_list_element_count) {
        for (size_t i = 0; i < list_to_compare_element_count; i++) {
            if (list_to_compare[i] != base_list[i]) {
                my_result = UNEQUAL;
                return my_result;
            }
        }
        my_result = EQUAL;
        return my_result;
    }

    //check if list_to_compare is a sublist
    if (list_to_compare_element_count < base_list_element_count) {
        size_t i, j, k = base_list_element_count - list_to_compare_element_count, l;
        for (i = 0; i <= k; i++) {
            if (base_list[i] == list_to_compare [0]) {
                l = i;
                my_result = SUBLIST;
                for (j = 0; j < list_to_compare_element_count; j++, l++) {
                    if (base_list[l] != list_to_compare [j]) {
                        my_result = UNEQUAL;
                        break;
                    }
                }

                if (my_result == SUBLIST) { return my_result; }
            }

        }
    }

    //check if list_to_compare is a superlist
    if (list_to_compare_element_count > base_list_element_count) {
        size_t i, j, k = list_to_compare_element_count - base_list_element_count, l;
        for (i = 0; i <= k; i++) {
            if (list_to_compare [i] == base_list [0]) {
                my_result = SUPERLIST;
                l = i;
                for (j = 0; j < base_list_element_count; j++, l++) {
                    if (base_list[j] != list_to_compare [l]) {
                        my_result = UNEQUAL;
                        break;
                    }
                }
            }

        }
    }

    return my_result;



}