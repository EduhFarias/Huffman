#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "CUnit/Basic.h"

Fila * fila;
int init_suite1(void)
{
    fila = CreateFila();
    return 0; //sucesso
}

int clean_suite1(void)
{
    clean(fila);
    if (getSize(fila) == 0)
    {
        return 0; //sucesso
    }
    return -1;
}

void teste1()
{

}

void teste2()
{

}

void teste3()
{

}
int main()
{
//INICIO SUITE1
    CU_pSuite pSuite1 = NULL;
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    pSuite1 = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((NULL == CU_add_test(pSuite1, "teste legal 01", teste1)) ||
        (NULL == CU_add_test(pSuite1, "teste legal pra krl 02", teste1)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

//FIM SUITE1

//INICIO SUITE2
    CU_pSuite pSuite2 = NULL;
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    pSuite2 = CU_add_suite("Suite_2", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((NULL == CU_add_test(pSuite2, "teste legal 03", teste3))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }


//FIM SUITE2
    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
