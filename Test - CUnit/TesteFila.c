#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
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
        CU_ASSERT(1);
    }
}

void testCreateQueue() {
    void *c;
    int s[6] = {1,4,3,6,5,2};
    
    int i;
    for(i = 0; i < 6; i++){
        c = &i;
        bt = createQueue(c, s[i], bt, NULL, NULL);
    }
    if(bt != NULL){
        CU_ASSERT(1);
    }
}

void testGet(){
    int s[6] = {1,4,3,6,5,2};
    int i;
    for(i = 0; i < 6; i++){
        if(getFreq(bt) != (i+1)){
            break;
        }
        bt = getNext(bt);
    }
    if(i == 5){
        CU_ASSERT(1);
    }
}

void testRemoveNode() {
    while(bt != NULL){
        bt = removeNode(bt);
    }
    if(bt == NULL){
        CU_ASSERT(1);
    }
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
       (NULL == CU_add_test(pSuite, "Test of get: ", testGet)) ||
       (NULL == CU_add_test(pSuite, "Test of removeNode: ", testRemoveNode))) {
       CU_cleanup_registry();
       return CU_get_error();
   }
//FIM SUITE1

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
