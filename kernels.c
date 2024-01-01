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

#define BLOCK_SIZE 32
/*
 * batched_mm - Your current working version of batched matrix multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char batched_mm_descr[] = "Batched MM with sum reduction: Current working version";
void batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    int i, j, k, p;
    int dim_dim = dim * dim;
    int pDim = -dim_dim;
    int temp;
    int kk, ii;

    int *tensorPointer = b_mat;

    int *matrix_pointer = mat;

    int *dst_pointer = dst;

    for (p = 0; p < dim; p++)
    {
        pDim += dim_dim;
        for (k = 0; k < dim; k += BLOCK_SIZE)
        {
            for (i = 0; i < dim; i += BLOCK_SIZE)
            {
                for (kk = k; kk < k + BLOCK_SIZE; kk++)
                {
                    int kk_dim = kk * dim;
                    for (ii = i; ii < i + BLOCK_SIZE; ii++)
                    {
                        int ii_dim = ii * dim;

                        int *ptrmat = matrix_pointer + kk_dim;
                        int *ptr = dst_pointer + ii_dim;

                        temp = *(pDim + tensorPointer + ii_dim + kk);
                        for (j = 0; j < dim; j += 32)
                        {
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                            *(ptr++) += temp * *(ptrmat++);
                        }
                    }
                }
            }
        }
    }
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
