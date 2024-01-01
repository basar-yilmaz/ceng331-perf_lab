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
    int i, j, k, l;

    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            for (k = 0; k < dim; k++)
            {
                if (i == 0)
                {
                    dst[RIDX(j, k, dim)] = 0;
                }
                for (l = 0; l < dim; l++)
                {
                    dst[RIDX(j, k, dim)] += b_mat[RIDX(i * dim + j, l, dim)] * mat[RIDX(l, k, dim)];
                }
            }
        }
    }
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
    int i, dim_by_dim = dim * dim;
    int block_size = dim_by_dim - 64;
    int *tmp_dst = &dst[dim_by_dim - 1];
    for (i = 0; i <= block_size; i += 64)
    {
        // printf("dst_index: %d src_index: %d", dst_index, src_index);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
        *(tmp_dst--) = *(src++);
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
