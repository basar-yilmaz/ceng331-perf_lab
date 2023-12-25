/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
    "TEAM", /* Team Name */

    "e264440",      /* First student ID */
    "BAŞAR YILMAz", /* First student name */

    "31", /* Second student ID */
    "31"  /* Second student name */

};

/*******************************************************
 * BATCHED MATRIX MULTIPLICATION \W SUM REDUCTION KERNEL
 *******************************************************/

/*********************************************************************************
 * Your different versions of the batched matrix multiplication functions go here
 *********************************************************************************/

/*
 * naive_batched_mm - The naive baseline version of batched matrix multiplication
 */
char naive_batched_mm_descr[] = "naive_batched_mm: Naive baseline implementation";
void naive_batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    // int i, j, k, l;

    // for (i = 0; i < dim; i++)
    // {
    //     for (j = 0; j < dim; j++)
    //     {
    //         for (k = 0; k < dim; k++)
    //         {
    //             if (i == 0)
    //             {
    //                 dst[RIDX(j, k, dim)] = 0;
    //             }
    //             for (l = 0; l < dim; l++)
    //             {
    //                 dst[RIDX(j, k, dim)] += b_mat[RIDX(i * dim + j, l, dim)] * mat[RIDX(l, k, dim)];
    //             }
    //         }
    //     }
    // }
}

/*
 * batched_mm - Your current working version of batched matrix multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char batched_mm_descr[] = "Batched MM with sum reduction: Current working version";
void batched_mm(int dim, int *b_mat, int *mat, int *dst)
{

    naive_batched_mm(dim, b_mat, mat, dst);
}

/*********************************************************************
 * register_batched_mm_functions - Register all of your different versions
 *     of the batched matrix multiplication functions  with the driver by calling the
 *     add_batched_mm_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_batched_mm_functions()
{
    add_batched_mm_function(&naive_batched_mm, naive_batched_mm_descr);
    add_batched_mm_function(&batched_mm, batched_mm_descr);
    /* ... Register additional test functions here */
}

/************************
 * POINT REFLECTION KERNEL
 ************************/

/*********************************************************
 * Your different versions of the point reflection go here
 *********************************************************/

/*
 * naive_reflect - The naive baseline version of point reflection
 */
char naive_reflect_descr[] = "Naive Point Reflection: Naive baseline implementation";
void naive_reflect(int dim, int *src, int *dst)
{
    int i, j;

    // RIDX(i,j,n) ((i)*(n)+(j))

    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            dst[RIDX(dim - 1 - i, dim - 1 - j, dim)] = src[RIDX(i, j, dim)];
        }
    }
}

/*
 * reflect - Your current working version of reflect
 * IMPORTANT: This is the version you will be graded on
 */
char reflect_descr[] = "Point Reflection: Current working version";
void reflect(int dim, int *src, int *dst)
{
    int i, j;

    int dimMinus1 = dim - 1;
    int dimMinus1TimesDim = dimMinus1 * dim;
    int dimTimes2 = (dim << 1);
    int dimTimes3 = dimTimes2 + dim;
    int dimTimes4 = (dim << 2);
    int dimTimes5 = dimTimes4 + dim;
    int dimTimes6 = dimTimes5 + dim;
    int dimTimes7 = dimTimes6 + dim;
    int dimTimes8 = (dim << 3);
    int dimTimes9 = dimTimes8 + dim;
    int dimTimes10 = dimTimes9 + dim;
    int dimTimes11 = dimTimes10 + dim;
    int dimTimes12 = dimTimes11 + dim;
    int dimTimes13 = dimTimes12 + dim;
    int dimTimes14 = dimTimes13 + dim;
    int dimTimes15 = dimTimes14 + dim;

    // Unroll the outer loop by a factor of 16 (try with 8, 4, 2, 1)
    for (i = 0; i < dim; i += 16)
    {
        int dimTimesi1 = dim * i;
        int dimTimesi2 = dimTimesi1 + dim;
        int dimTimesi3 = dimTimesi1 + dimTimes2;
        int dimTimesi4 = dimTimesi1 + dimTimes3;
        int dimTimesi5 = dimTimesi1 + dimTimes4;
        int dimTimesi6 = dimTimesi1 + dimTimes5;
        int dimTimesi7 = dimTimesi1 + dimTimes6;
        int dimTimesi8 = dimTimesi1 + dimTimes7;
        int dimTimesi9 = dimTimesi1 + dimTimes8;
        int dimTimesi10 = dimTimesi1 + dimTimes9;
        int dimTimesi11 = dimTimesi1 + dimTimes10;
        int dimTimesi12 = dimTimesi1 + dimTimes11;
        int dimTimesi13 = dimTimesi1 + dimTimes12;
        int dimTimesi14 = dimTimesi1 + dimTimes13;
        int dimTimesi15 = dimTimesi1 + dimTimes14;
        int dimTimesi16 = dimTimesi1 + dimTimes15;

        int dim_i1 = dimMinus1TimesDim - dimTimesi1;
        int dim_i2 = dimMinus1TimesDim - dimTimesi2;
        int dim_i3 = dimMinus1TimesDim - dimTimesi3;
        int dim_i4 = dimMinus1TimesDim - dimTimesi4;
        int dim_i5 = dimMinus1TimesDim - dimTimesi5;
        int dim_i6 = dimMinus1TimesDim - dimTimesi6;
        int dim_i7 = dimMinus1TimesDim - dimTimesi7;
        int dim_i8 = dimMinus1TimesDim - dimTimesi8;
        int dim_i9 = dimMinus1TimesDim - dimTimesi9;
        int dim_i10 = dimMinus1TimesDim - dimTimesi10;
        int dim_i11 = dimMinus1TimesDim - dimTimesi11;
        int dim_i12 = dimMinus1TimesDim - dimTimesi12;
        int dim_i13 = dimMinus1TimesDim - dimTimesi13;
        int dim_i14 = dimMinus1TimesDim - dimTimesi14;
        int dim_i15 = dimMinus1TimesDim - dimTimesi15;
        int dim_i16 = dimMinus1TimesDim - dimTimesi16;

        int dim_i1PLUSdimMinus1 = dim_i1 + dimMinus1;
        int dim_i2PLUSdimMinus1 = dim_i2 + dimMinus1;
        int dim_i3PLUSdimMinus1 = dim_i3 + dimMinus1;
        int dim_i4PLUSdimMinus1 = dim_i4 + dimMinus1;
        int dim_i5PLUSdimMinus1 = dim_i5 + dimMinus1;
        int dim_i6PLUSdimMinus1 = dim_i6 + dimMinus1;
        int dim_i7PLUSdimMinus1 = dim_i7 + dimMinus1;
        int dim_i8PLUSdimMinus1 = dim_i8 + dimMinus1;
        int dim_i9PLUSdimMinus1 = dim_i9 + dimMinus1;
        int dim_i10PLUSdimMinus1 = dim_i10 + dimMinus1;
        int dim_i11PLUSdimMinus1 = dim_i11 + dimMinus1;
        int dim_i12PLUSdimMinus1 = dim_i12 + dimMinus1;
        int dim_i13PLUSdimMinus1 = dim_i13 + dimMinus1;
        int dim_i14PLUSdimMinus1 = dim_i14 + dimMinus1;
        int dim_i15PLUSdimMinus1 = dim_i15 + dimMinus1;
        int dim_i16PLUSdimMinus1 = dim_i16 + dimMinus1;

        // Unroll the inner loop by a factor of 16 (try with 8, 4)
        for (j = 0; j < dim; j += 16)
        {
            int constant_dst1 = dim_i1PLUSdimMinus1 - j;
            int constant_src1 = dimTimesi1 + j;
            dst[constant_dst1] = src[constant_src1];
            dst[constant_dst1 - 1] = src[constant_src1 + 1];
            dst[constant_dst1 - 2] = src[constant_src1 + 2];
            dst[constant_dst1 - 3] = src[constant_src1 + 3];
            dst[constant_dst1 - 4] = src[constant_src1 + 4];
            dst[constant_dst1 - 5] = src[constant_src1 + 5];
            dst[constant_dst1 - 6] = src[constant_src1 + 6];
            dst[constant_dst1 - 7] = src[constant_src1 + 7];
            dst[constant_dst1 - 8] = src[constant_src1 + 8];
            dst[constant_dst1 - 9] = src[constant_src1 + 9];
            dst[constant_dst1 - 10] = src[constant_src1 + 10];
            dst[constant_dst1 - 11] = src[constant_src1 + 11];
            dst[constant_dst1 - 12] = src[constant_src1 + 12];
            dst[constant_dst1 - 13] = src[constant_src1 + 13];
            dst[constant_dst1 - 14] = src[constant_src1 + 14];
            dst[constant_dst1 - 15] = src[constant_src1 + 15];

            int constant_dst2 = dim_i2PLUSdimMinus1 - j;
            int constant_src2 = dimTimesi2 + j;
            dst[constant_dst2] = src[constant_src2];
            dst[constant_dst2 - 1] = src[constant_src2 + 1];
            dst[constant_dst2 - 2] = src[constant_src2 + 2];
            dst[constant_dst2 - 3] = src[constant_src2 + 3];
            dst[constant_dst2 - 4] = src[constant_src2 + 4];
            dst[constant_dst2 - 5] = src[constant_src2 + 5];
            dst[constant_dst2 - 6] = src[constant_src2 + 6];
            dst[constant_dst2 - 7] = src[constant_src2 + 7];
            dst[constant_dst2 - 8] = src[constant_src2 + 8];
            dst[constant_dst2 - 9] = src[constant_src2 + 9];
            dst[constant_dst2 - 10] = src[constant_src2 + 10];
            dst[constant_dst2 - 11] = src[constant_src2 + 11];
            dst[constant_dst2 - 12] = src[constant_src2 + 12];
            dst[constant_dst2 - 13] = src[constant_src2 + 13];
            dst[constant_dst2 - 14] = src[constant_src2 + 14];
            dst[constant_dst2 - 15] = src[constant_src2 + 15];

            int constant_dst3 = dim_i3PLUSdimMinus1 - j;
            int constant_src3 = dimTimesi3 + j;
            dst[constant_dst3] = src[constant_src3];
            dst[constant_dst3 - 1] = src[constant_src3 + 1];
            dst[constant_dst3 - 2] = src[constant_src3 + 2];
            dst[constant_dst3 - 3] = src[constant_src3 + 3];
            dst[constant_dst3 - 4] = src[constant_src3 + 4];
            dst[constant_dst3 - 5] = src[constant_src3 + 5];
            dst[constant_dst3 - 6] = src[constant_src3 + 6];
            dst[constant_dst3 - 7] = src[constant_src3 + 7];
            dst[constant_dst3 - 8] = src[constant_src3 + 8];
            dst[constant_dst3 - 9] = src[constant_src3 + 9];
            dst[constant_dst3 - 10] = src[constant_src3 + 10];
            dst[constant_dst3 - 11] = src[constant_src3 + 11];
            dst[constant_dst3 - 12] = src[constant_src3 + 12];
            dst[constant_dst3 - 13] = src[constant_src3 + 13];
            dst[constant_dst3 - 14] = src[constant_src3 + 14];
            dst[constant_dst3 - 15] = src[constant_src3 + 15];

            int constant_dst4 = dim_i4PLUSdimMinus1 - j;
            int constant_src4 = dimTimesi4 + j;
            dst[constant_dst4] = src[constant_src4];
            dst[constant_dst4 - 1] = src[constant_src4 + 1];
            dst[constant_dst4 - 2] = src[constant_src4 + 2];
            dst[constant_dst4 - 3] = src[constant_src4 + 3];
            dst[constant_dst4 - 4] = src[constant_src4 + 4];
            dst[constant_dst4 - 5] = src[constant_src4 + 5];
            dst[constant_dst4 - 6] = src[constant_src4 + 6];
            dst[constant_dst4 - 7] = src[constant_src4 + 7];
            dst[constant_dst4 - 8] = src[constant_src4 + 8];
            dst[constant_dst4 - 9] = src[constant_src4 + 9];
            dst[constant_dst4 - 10] = src[constant_src4 + 10];
            dst[constant_dst4 - 11] = src[constant_src4 + 11];
            dst[constant_dst4 - 12] = src[constant_src4 + 12];
            dst[constant_dst4 - 13] = src[constant_src4 + 13];
            dst[constant_dst4 - 14] = src[constant_src4 + 14];
            dst[constant_dst4 - 15] = src[constant_src4 + 15];

            int constant_dst5 = dim_i5PLUSdimMinus1 - j;
            int constant_src5 = dimTimesi5 + j;
            dst[constant_dst5] = src[constant_src5];
            dst[constant_dst5 - 1] = src[constant_src5 + 1];
            dst[constant_dst5 - 2] = src[constant_src5 + 2];
            dst[constant_dst5 - 3] = src[constant_src5 + 3];
            dst[constant_dst5 - 4] = src[constant_src5 + 4];
            dst[constant_dst5 - 5] = src[constant_src5 + 5];
            dst[constant_dst5 - 6] = src[constant_src5 + 6];
            dst[constant_dst5 - 7] = src[constant_src5 + 7];
            dst[constant_dst5 - 8] = src[constant_src5 + 8];
            dst[constant_dst5 - 9] = src[constant_src5 + 9];
            dst[constant_dst5 - 10] = src[constant_src5 + 10];
            dst[constant_dst5 - 11] = src[constant_src5 + 11];
            dst[constant_dst5 - 12] = src[constant_src5 + 12];
            dst[constant_dst5 - 13] = src[constant_src5 + 13];
            dst[constant_dst5 - 14] = src[constant_src5 + 14];
            dst[constant_dst5 - 15] = src[constant_src5 + 15];

            int constant_dst6 = dim_i6PLUSdimMinus1 - j;
            int constant_src6 = dimTimesi6 + j;
            dst[constant_dst6] = src[constant_src6];
            dst[constant_dst6 - 1] = src[constant_src6 + 1];
            dst[constant_dst6 - 2] = src[constant_src6 + 2];
            dst[constant_dst6 - 3] = src[constant_src6 + 3];
            dst[constant_dst6 - 4] = src[constant_src6 + 4];
            dst[constant_dst6 - 5] = src[constant_src6 + 5];
            dst[constant_dst6 - 6] = src[constant_src6 + 6];
            dst[constant_dst6 - 7] = src[constant_src6 + 7];
            dst[constant_dst6 - 8] = src[constant_src6 + 8];
            dst[constant_dst6 - 9] = src[constant_src6 + 9];
            dst[constant_dst6 - 10] = src[constant_src6 + 10];
            dst[constant_dst6 - 11] = src[constant_src6 + 11];
            dst[constant_dst6 - 12] = src[constant_src6 + 12];
            dst[constant_dst6 - 13] = src[constant_src6 + 13];
            dst[constant_dst6 - 14] = src[constant_src6 + 14];
            dst[constant_dst6 - 15] = src[constant_src6 + 15];

            int constant_dst7 = dim_i7PLUSdimMinus1 - j;
            int constant_src7 = dimTimesi7 + j;
            dst[constant_dst7] = src[constant_src7];
            dst[constant_dst7 - 1] = src[constant_src7 + 1];
            dst[constant_dst7 - 2] = src[constant_src7 + 2];
            dst[constant_dst7 - 3] = src[constant_src7 + 3];
            dst[constant_dst7 - 4] = src[constant_src7 + 4];
            dst[constant_dst7 - 5] = src[constant_src7 + 5];
            dst[constant_dst7 - 6] = src[constant_src7 + 6];
            dst[constant_dst7 - 7] = src[constant_src7 + 7];
            dst[constant_dst7 - 8] = src[constant_src7 + 8];
            dst[constant_dst7 - 9] = src[constant_src7 + 9];
            dst[constant_dst7 - 10] = src[constant_src7 + 10];
            dst[constant_dst7 - 11] = src[constant_src7 + 11];
            dst[constant_dst7 - 12] = src[constant_src7 + 12];
            dst[constant_dst7 - 13] = src[constant_src7 + 13];
            dst[constant_dst7 - 14] = src[constant_src7 + 14];
            dst[constant_dst7 - 15] = src[constant_src7 + 15];

            int constant_dst8 = dim_i8PLUSdimMinus1 - j;
            int constant_src8 = dimTimesi8 + j;
            dst[constant_dst8] = src[constant_src8];
            dst[constant_dst8 - 1] = src[constant_src8 + 1];
            dst[constant_dst8 - 2] = src[constant_src8 + 2];
            dst[constant_dst8 - 3] = src[constant_src8 + 3];
            dst[constant_dst8 - 4] = src[constant_src8 + 4];
            dst[constant_dst8 - 5] = src[constant_src8 + 5];
            dst[constant_dst8 - 6] = src[constant_src8 + 6];
            dst[constant_dst8 - 7] = src[constant_src8 + 7];
            dst[constant_dst8 - 8] = src[constant_src8 + 8];
            dst[constant_dst8 - 9] = src[constant_src8 + 9];
            dst[constant_dst8 - 10] = src[constant_src8 + 10];
            dst[constant_dst8 - 11] = src[constant_src8 + 11];
            dst[constant_dst8 - 12] = src[constant_src8 + 12];
            dst[constant_dst8 - 13] = src[constant_src8 + 13];
            dst[constant_dst8 - 14] = src[constant_src8 + 14];
            dst[constant_dst8 - 15] = src[constant_src8 + 15];

            int constant_dst9 = dim_i9PLUSdimMinus1 - j;
            int constant_src9 = dimTimesi9 + j;
            dst[constant_dst9] = src[constant_src9];
            dst[constant_dst9 - 1] = src[constant_src9 + 1];
            dst[constant_dst9 - 2] = src[constant_src9 + 2];
            dst[constant_dst9 - 3] = src[constant_src9 + 3];
            dst[constant_dst9 - 4] = src[constant_src9 + 4];
            dst[constant_dst9 - 5] = src[constant_src9 + 5];
            dst[constant_dst9 - 6] = src[constant_src9 + 6];
            dst[constant_dst9 - 7] = src[constant_src9 + 7];
            dst[constant_dst9 - 8] = src[constant_src9 + 8];
            dst[constant_dst9 - 9] = src[constant_src9 + 9];
            dst[constant_dst9 - 10] = src[constant_src9 + 10];
            dst[constant_dst9 - 11] = src[constant_src9 + 11];
            dst[constant_dst9 - 12] = src[constant_src9 + 12];
            dst[constant_dst9 - 13] = src[constant_src9 + 13];
            dst[constant_dst9 - 14] = src[constant_src9 + 14];
            dst[constant_dst9 - 15] = src[constant_src9 + 15];

            int constant_dst10 = dim_i10PLUSdimMinus1 - j;
            int constant_src10 = dimTimesi10 + j;
            dst[constant_dst10] = src[constant_src10];
            dst[constant_dst10 - 1] = src[constant_src10 + 1];
            dst[constant_dst10 - 2] = src[constant_src10 + 2];
            dst[constant_dst10 - 3] = src[constant_src10 + 3];
            dst[constant_dst10 - 4] = src[constant_src10 + 4];
            dst[constant_dst10 - 5] = src[constant_src10 + 5];
            dst[constant_dst10 - 6] = src[constant_src10 + 6];
            dst[constant_dst10 - 7] = src[constant_src10 + 7];
            dst[constant_dst10 - 8] = src[constant_src10 + 8];
            dst[constant_dst10 - 9] = src[constant_src10 + 9];
            dst[constant_dst10 - 10] = src[constant_src10 + 10];
            dst[constant_dst10 - 11] = src[constant_src10 + 11];
            dst[constant_dst10 - 12] = src[constant_src10 + 12];
            dst[constant_dst10 - 13] = src[constant_src10 + 13];
            dst[constant_dst10 - 14] = src[constant_src10 + 14];
            dst[constant_dst10 - 15] = src[constant_src10 + 15];

            int constant_dst11 = dim_i11PLUSdimMinus1 - j;
            int constant_src11 = dimTimesi11 + j;
            dst[constant_dst11] = src[constant_src11];
            dst[constant_dst11 - 1] = src[constant_src11 + 1];
            dst[constant_dst11 - 2] = src[constant_src11 + 2];
            dst[constant_dst11 - 3] = src[constant_src11 + 3];
            dst[constant_dst11 - 4] = src[constant_src11 + 4];
            dst[constant_dst11 - 5] = src[constant_src11 + 5];
            dst[constant_dst11 - 6] = src[constant_src11 + 6];
            dst[constant_dst11 - 7] = src[constant_src11 + 7];
            dst[constant_dst11 - 8] = src[constant_src11 + 8];
            dst[constant_dst11 - 9] = src[constant_src11 + 9];
            dst[constant_dst11 - 10] = src[constant_src11 + 10];
            dst[constant_dst11 - 11] = src[constant_src11 + 11];
            dst[constant_dst11 - 12] = src[constant_src11 + 12];
            dst[constant_dst11 - 13] = src[constant_src11 + 13];
            dst[constant_dst11 - 14] = src[constant_src11 + 14];
            dst[constant_dst11 - 15] = src[constant_src11 + 15];

            int constant_dst12 = dim_i12PLUSdimMinus1 - j;
            int constant_src12 = dimTimesi12 + j;
            dst[constant_dst12] = src[constant_src12];
            dst[constant_dst12 - 1] = src[constant_src12 + 1];
            dst[constant_dst12 - 2] = src[constant_src12 + 2];
            dst[constant_dst12 - 3] = src[constant_src12 + 3];
            dst[constant_dst12 - 4] = src[constant_src12 + 4];
            dst[constant_dst12 - 5] = src[constant_src12 + 5];
            dst[constant_dst12 - 6] = src[constant_src12 + 6];
            dst[constant_dst12 - 7] = src[constant_src12 + 7];
            dst[constant_dst12 - 8] = src[constant_src12 + 8];
            dst[constant_dst12 - 9] = src[constant_src12 + 9];
            dst[constant_dst12 - 10] = src[constant_src12 + 10];
            dst[constant_dst12 - 11] = src[constant_src12 + 11];
            dst[constant_dst12 - 12] = src[constant_src12 + 12];
            dst[constant_dst12 - 13] = src[constant_src12 + 13];
            dst[constant_dst12 - 14] = src[constant_src12 + 14];
            dst[constant_dst12 - 15] = src[constant_src12 + 15];

            int constant_dst13 = dim_i13PLUSdimMinus1 - j;
            int constant_src13 = dimTimesi13 + j;
            dst[constant_dst13] = src[constant_src13];
            dst[constant_dst13 - 1] = src[constant_src13 + 1];
            dst[constant_dst13 - 2] = src[constant_src13 + 2];
            dst[constant_dst13 - 3] = src[constant_src13 + 3];
            dst[constant_dst13 - 4] = src[constant_src13 + 4];
            dst[constant_dst13 - 5] = src[constant_src13 + 5];
            dst[constant_dst13 - 6] = src[constant_src13 + 6];
            dst[constant_dst13 - 7] = src[constant_src13 + 7];
            dst[constant_dst13 - 8] = src[constant_src13 + 8];
            dst[constant_dst13 - 9] = src[constant_src13 + 9];
            dst[constant_dst13 - 10] = src[constant_src13 + 10];
            dst[constant_dst13 - 11] = src[constant_src13 + 11];
            dst[constant_dst13 - 12] = src[constant_src13 + 12];
            dst[constant_dst13 - 13] = src[constant_src13 + 13];
            dst[constant_dst13 - 14] = src[constant_src13 + 14];
            dst[constant_dst13 - 15] = src[constant_src13 + 15];

            int constant_dst14 = dim_i14PLUSdimMinus1 - j;
            int constant_src14 = dimTimesi14 + j;
            dst[constant_dst14] = src[constant_src14];
            dst[constant_dst14 - 1] = src[constant_src14 + 1];
            dst[constant_dst14 - 2] = src[constant_src14 + 2];
            dst[constant_dst14 - 3] = src[constant_src14 + 3];
            dst[constant_dst14 - 4] = src[constant_src14 + 4];
            dst[constant_dst14 - 5] = src[constant_src14 + 5];
            dst[constant_dst14 - 6] = src[constant_src14 + 6];
            dst[constant_dst14 - 7] = src[constant_src14 + 7];
            dst[constant_dst14 - 8] = src[constant_src14 + 8];
            dst[constant_dst14 - 9] = src[constant_src14 + 9];
            dst[constant_dst14 - 10] = src[constant_src14 + 10];
            dst[constant_dst14 - 11] = src[constant_src14 + 11];
            dst[constant_dst14 - 12] = src[constant_src14 + 12];
            dst[constant_dst14 - 13] = src[constant_src14 + 13];
            dst[constant_dst14 - 14] = src[constant_src14 + 14];
            dst[constant_dst14 - 15] = src[constant_src14 + 15];

            int constant_dst15 = dim_i15PLUSdimMinus1 - j;
            int constant_src15 = dimTimesi15 + j;
            dst[constant_dst15] = src[constant_src15];
            dst[constant_dst15 - 1] = src[constant_src15 + 1];
            dst[constant_dst15 - 2] = src[constant_src15 + 2];
            dst[constant_dst15 - 3] = src[constant_src15 + 3];
            dst[constant_dst15 - 4] = src[constant_src15 + 4];
            dst[constant_dst15 - 5] = src[constant_src15 + 5];
            dst[constant_dst15 - 6] = src[constant_src15 + 6];
            dst[constant_dst15 - 7] = src[constant_src15 + 7];
            dst[constant_dst15 - 8] = src[constant_src15 + 8];
            dst[constant_dst15 - 9] = src[constant_src15 + 9];
            dst[constant_dst15 - 10] = src[constant_src15 + 10];
            dst[constant_dst15 - 11] = src[constant_src15 + 11];
            dst[constant_dst15 - 12] = src[constant_src15 + 12];
            dst[constant_dst15 - 13] = src[constant_src15 + 13];
            dst[constant_dst15 - 14] = src[constant_src15 + 14];
            dst[constant_dst15 - 15] = src[constant_src15 + 15];

            int constant_dst16 = dim_i16PLUSdimMinus1 - j;
            int constant_src16 = dimTimesi16 + j;
            dst[constant_dst16] = src[constant_src16];
            dst[constant_dst16 - 1] = src[constant_src16 + 1];
            dst[constant_dst16 - 2] = src[constant_src16 + 2];
            dst[constant_dst16 - 3] = src[constant_src16 + 3];
            dst[constant_dst16 - 4] = src[constant_src16 + 4];
            dst[constant_dst16 - 5] = src[constant_src16 + 5];
            dst[constant_dst16 - 6] = src[constant_src16 + 6];
            dst[constant_dst16 - 7] = src[constant_src16 + 7];
            dst[constant_dst16 - 8] = src[constant_src16 + 8];
            dst[constant_dst16 - 9] = src[constant_src16 + 9];
            dst[constant_dst16 - 10] = src[constant_src16 + 10];
            dst[constant_dst16 - 11] = src[constant_src16 + 11];
            dst[constant_dst16 - 12] = src[constant_src16 + 12];
            dst[constant_dst16 - 13] = src[constant_src16 + 13];
            dst[constant_dst16 - 14] = src[constant_src16 + 14];
            dst[constant_dst16 - 15] = src[constant_src16 + 15];
        }
    }
}

/* Bu da geliştilebilir
void reflect(int dim, int *src, int *dst)
{
    int i, j;

    int dimMinus1 = dim - 1;
    int dimMinus1TimesDim = dimMinus1 * dim;

    // Unroll the outer loop by a factor of 4
    for (i = 0; i < dim; i += 4)
    {
        int dimTimesi1 = dim * i;
        int dimTimesi2 = dim * (i + 1);
        int dimTimesi3 = dim * (i + 2);
        int dimTimesi4 = dim * (i + 3);

        int dim_i1 = dimMinus1TimesDim - dimTimesi1;
        int dim_i2 = dimMinus1TimesDim - dimTimesi2;
        int dim_i3 = dimMinus1TimesDim - dimTimesi3;
        int dim_i4 = dimMinus1TimesDim - dimTimesi4;

        int dim_i1PLUSdimMinus1 = dim_i1 + dimMinus1;
        int dim_i2PLUSdimMinus1 = dim_i2 + dimMinus1;
        int dim_i3PLUSdimMinus1 = dim_i3 + dimMinus1;
        int dim_i4PLUSdimMinus1 = dim_i4 + dimMinus1;

        // Unroll the inner loop by a factor of 16
        for (j = 0; j < dim; j += 16)
        {
            int constant_dst1 = dim_i1PLUSdimMinus1 - j;
            int constant_src1 = dimTimesi1 + j;
            dst[constant_dst1] = src[constant_src1];
            dst[constant_dst1 - 1] = src[constant_src1 + 1];
            dst[constant_dst1 - 2] = src[constant_src1 + 2];
            dst[constant_dst1 - 3] = src[constant_src1 + 3];
            dst[constant_dst1 - 4] = src[constant_src1 + 4];
            dst[constant_dst1 - 5] = src[constant_src1 + 5];
            dst[constant_dst1 - 6] = src[constant_src1 + 6];
            dst[constant_dst1 - 7] = src[constant_src1 + 7];
            dst[constant_dst1 - 8] = src[constant_src1 + 8];
            dst[constant_dst1 - 9] = src[constant_src1 + 9];
            dst[constant_dst1 - 10] = src[constant_src1 + 10];
            dst[constant_dst1 - 11] = src[constant_src1 + 11];
            dst[constant_dst1 - 12] = src[constant_src1 + 12];
            dst[constant_dst1 - 13] = src[constant_src1 + 13];
            dst[constant_dst1 - 14] = src[constant_src1 + 14];
            dst[constant_dst1 - 15] = src[constant_src1 + 15];

            int constant_dst2 = dim_i2PLUSdimMinus1 - j;
            int constant_src2 = dimTimesi2 + j;
            dst[constant_dst2] = src[constant_src2];
            dst[constant_dst2 - 1] = src[constant_src2 + 1];
            dst[constant_dst2 - 2] = src[constant_src2 + 2];
            dst[constant_dst2 - 3] = src[constant_src2 + 3];
            dst[constant_dst2 - 4] = src[constant_src2 + 4];
            dst[constant_dst2 - 5] = src[constant_src2 + 5];
            dst[constant_dst2 - 6] = src[constant_src2 + 6];
            dst[constant_dst2 - 7] = src[constant_src2 + 7];
            dst[constant_dst2 - 8] = src[constant_src2 + 8];
            dst[constant_dst2 - 9] = src[constant_src2 + 9];
            dst[constant_dst2 - 10] = src[constant_src2 + 10];
            dst[constant_dst2 - 11] = src[constant_src2 + 11];
            dst[constant_dst2 - 12] = src[constant_src2 + 12];
            dst[constant_dst2 - 13] = src[constant_src2 + 13];
            dst[constant_dst2 - 14] = src[constant_src2 + 14];
            dst[constant_dst2 - 15] = src[constant_src2 + 15];

            int constant_dst3 = dim_i3PLUSdimMinus1 - j;
            int constant_src3 = dimTimesi3 + j;
            dst[constant_dst3] = src[constant_src3];
            dst[constant_dst3 - 1] = src[constant_src3 + 1];
            dst[constant_dst3 - 2] = src[constant_src3 + 2];
            dst[constant_dst3 - 3] = src[constant_src3 + 3];
            dst[constant_dst3 - 4] = src[constant_src3 + 4];
            dst[constant_dst3 - 5] = src[constant_src3 + 5];
            dst[constant_dst3 - 6] = src[constant_src3 + 6];
            dst[constant_dst3 - 7] = src[constant_src3 + 7];
            dst[constant_dst3 - 8] = src[constant_src3 + 8];
            dst[constant_dst3 - 9] = src[constant_src3 + 9];
            dst[constant_dst3 - 10] = src[constant_src3 + 10];
            dst[constant_dst3 - 11] = src[constant_src3 + 11];
            dst[constant_dst3 - 12] = src[constant_src3 + 12];
            dst[constant_dst3 - 13] = src[constant_src3 + 13];
            dst[constant_dst3 - 14] = src[constant_src3 + 14];
            dst[constant_dst3 - 15] = src[constant_src3 + 15];

            int constant_dst4 = dim_i4PLUSdimMinus1 - j;
            int constant_src4 = dimTimesi4 + j;
            dst[constant_dst4] = src[constant_src4];
            dst[constant_dst4 - 1] = src[constant_src4 + 1];
            dst[constant_dst4 - 2] = src[constant_src4 + 2];
            dst[constant_dst4 - 3] = src[constant_src4 + 3];
            dst[constant_dst4 - 4] = src[constant_src4 + 4];
            dst[constant_dst4 - 5] = src[constant_src4 + 5];
            dst[constant_dst4 - 6] = src[constant_src4 + 6];
            dst[constant_dst4 - 7] = src[constant_src4 + 7];
            dst[constant_dst4 - 8] = src[constant_src4 + 8];
            dst[constant_dst4 - 9] = src[constant_src4 + 9];
            dst[constant_dst4 - 10] = src[constant_src4 + 10];
            dst[constant_dst4 - 11] = src[constant_src4 + 11];
            dst[constant_dst4 - 12] = src[constant_src4 + 12];
            dst[constant_dst4 - 13] = src[constant_src4 + 13];
            dst[constant_dst4 - 14] = src[constant_src4 + 14];
            dst[constant_dst4 - 15] = src[constant_src4 + 15];
        }
    }
}

*/

/******************************************************************************
 * register_reflect_functions - Register all of your different versions
 *     of the reflect with the driver by calling the
 *     add_reflect_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 ******************************************************************************/

void register_reflect_functions()
{
    add_reflect_function(&naive_reflect, naive_reflect_descr);
    add_reflect_function(&reflect, reflect_descr);
    /* ... Register additional test functions here */
}
