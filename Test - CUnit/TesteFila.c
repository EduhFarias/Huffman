#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"

BinaryTree *bt;

int init_suite1(void) {
    return 0;
}

int clean_suite1(void) {
    return 0;
}

void testCreateNode(){
    bt = createEmpty();
    if(bt == NULL){
        CU_ASSERT(0);
    }
}

void testCreateQueue() {
    void *c;
    char s[6] = {A,B,C,D,E};
    int i;
    for(i = 0; i < 6; i++){
        c = &s[i];
        bt = createQueue(c, i, bt, NULL, NULL);
    }
    if(bt != NULL){
        CU_ASSERT(0);
    }
}

void testGet(){
    long long int freq;
    char *c = (char) malloc(sizeof(char));
    
}

void testRemoveNode() {
    bt = removeNode(bt);
}

int main(){
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
       CU_cleanup_registry();
       return CU_get_error();
   }
   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "Test of createNode: ", testCreateNode)) ||
       (NULL == CU_add_test(pSuite, "Test of createQueue: ", testCreateQueue)) ||
       (NULL = CU_add_test(pSuite, "Test of get: ", testGet)) ||
       (NULL = CU_add_test(pSuite, "Test of removeNode: ", testRemoveNode)) {
       CU_cleanup_registry();
       return CU_get_error();
   }
//FIM SUITE1

/*
//INICIO SUITE2
   CU_pSuite pSuite2 = NULL;
   if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();
   pSuite2 = CU_add_suite("Suite_2", init_suite1, clean_suite1);
   if (NULL == pSuite) {
       CU_cleanup_registry();
       return CU_get_error();
   }
   if ((NULL == CU_add_test(pSuite2, "teste legal 03", teste3))) {
       CU_cleanup_registry();
       return CU_get_error();
   }
//FIM SUITE2
*/

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
