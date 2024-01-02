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
    int j, k, l;
    int dimSquare = dim * dim;
    int dim_intsize = dimSquare * sizeof(int);
    int *transpose1 = malloc(dim_intsize);
    int *transpose1_cursor = transpose1;
    int *initialdst = dst;
    int temp_acc1 = 0;
    int temp_acc2 = 0;
    int temp_acc3 = 0;
    int temp_acc4 = 0;
    int temp_acc5 = 0;
    int temp_acc6 = 0;
    int temp_acc7 = 0;
    int temp_acc8 = 0;
    int temp_acc9 = 0;
    int temp_acc10 = 0;
    int temp_acc11 = 0;
    int temp_acc12 = 0;
    int temp_acc13 = 0;
    int temp_acc14 = 0;
    int temp_acc15 = 0;
    int temp_acc16 = 0;
    int temp_acc17 = 0;
    int temp_acc18 = 0;
    int temp_acc19 = 0;
    int temp_acc20 = 0;
    int temp_acc21 = 0;
    int temp_acc22 = 0;
    int temp_acc23 = 0;
    int temp_acc24 = 0;
    int temp_acc25 = 0;
    int temp_acc26 = 0;
    int temp_acc27 = 0;
    int temp_acc28 = 0;
    int temp_acc29 = 0;
    int temp_acc30 = 0;
    int temp_acc31 = 0;
    int temp_acc32 = 0;

    int *ptrtoplam;
    int *newMatrix = malloc(dim_intsize);
    int *newMatrix_cursor = newMatrix;
    for (int i = 0; i < dim; i++)
    {
        transpose1 = transpose1_cursor + i;
        int i_dim = i * dim;
        for (int j = 0; j < dim; j += 32)
        {
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;

            int *cursor1 = &b_mat[i_dim + j];
            for (int k = 0; k < dim; k++)
            {
                ptrtoplam = cursor1;
                temp_acc1 += *ptrtoplam++;
                temp_acc2 += *ptrtoplam++;
                temp_acc3 += *ptrtoplam++;
                temp_acc4 += *ptrtoplam++;
                temp_acc5 += *ptrtoplam++;
                temp_acc6 += *ptrtoplam++;
                temp_acc7 += *ptrtoplam++;
                temp_acc8 += *ptrtoplam++;
                temp_acc9 += *ptrtoplam++;
                temp_acc10 += *ptrtoplam++;
                temp_acc11 += *ptrtoplam++;
                temp_acc12 += *ptrtoplam++;
                temp_acc13 += *ptrtoplam++;
                temp_acc14 += *ptrtoplam++;
                temp_acc15 += *ptrtoplam++;
                temp_acc16 += *ptrtoplam++;
                temp_acc17 += *ptrtoplam++;
                temp_acc18 += *ptrtoplam++;
                temp_acc19 += *ptrtoplam++;
                temp_acc20 += *ptrtoplam++;
                temp_acc21 += *ptrtoplam++;
                temp_acc22 += *ptrtoplam++;
                temp_acc23 += *ptrtoplam++;
                temp_acc24 += *ptrtoplam++;
                temp_acc25 += *ptrtoplam++;
                temp_acc26 += *ptrtoplam++;
                temp_acc27 += *ptrtoplam++;
                temp_acc28 += *ptrtoplam++;
                temp_acc29 += *ptrtoplam++;
                temp_acc30 += *ptrtoplam++;
                temp_acc31 += *ptrtoplam++;
                temp_acc32 += *ptrtoplam++;
                cursor1 += dimSquare;
            }
            *newMatrix++ = temp_acc1;
            *newMatrix++ = temp_acc2;
            *newMatrix++ = temp_acc3;
            *newMatrix++ = temp_acc4;
            *newMatrix++ = temp_acc5;
            *newMatrix++ = temp_acc6;
            *newMatrix++ = temp_acc7;
            *newMatrix++ = temp_acc8;
            *newMatrix++ = temp_acc9;
            *newMatrix++ = temp_acc10;
            *newMatrix++ = temp_acc11;
            *newMatrix++ = temp_acc12;
            *newMatrix++ = temp_acc13;
            *newMatrix++ = temp_acc14;
            *newMatrix++ = temp_acc15;
            *newMatrix++ = temp_acc16;
            *newMatrix++ = temp_acc17;
            *newMatrix++ = temp_acc18;
            *newMatrix++ = temp_acc19;
            *newMatrix++ = temp_acc20;
            *newMatrix++ = temp_acc21;
            *newMatrix++ = temp_acc22;
            *newMatrix++ = temp_acc23;
            *newMatrix++ = temp_acc24;
            *newMatrix++ = temp_acc25;
            *newMatrix++ = temp_acc26;
            *newMatrix++ = temp_acc27;
            *newMatrix++ = temp_acc28;
            *newMatrix++ = temp_acc29;
            *newMatrix++ = temp_acc30;
            *newMatrix++ = temp_acc31;
            *newMatrix++ = temp_acc32;
            temp_acc1 = 0;
            temp_acc2 = 0;
            temp_acc3 = 0;
            temp_acc4 = 0;
            temp_acc5 = 0;
            temp_acc6 = 0;
            temp_acc7 = 0;
            temp_acc8 = 0;
            temp_acc9 = 0;
            temp_acc10 = 0;
            temp_acc11 = 0;
            temp_acc12 = 0;
            temp_acc13 = 0;
            temp_acc14 = 0;
            temp_acc15 = 0;
            temp_acc16 = 0;
            temp_acc17 = 0;
            temp_acc18 = 0;
            temp_acc19 = 0;
            temp_acc20 = 0;
            temp_acc21 = 0;
            temp_acc22 = 0;
            temp_acc23 = 0;
            temp_acc24 = 0;
            temp_acc25 = 0;
            temp_acc26 = 0;
            temp_acc27 = 0;
            temp_acc28 = 0;
            temp_acc29 = 0;
            temp_acc30 = 0;
            temp_acc31 = 0;
            temp_acc32 = 0;
        }
    }
    newMatrix = newMatrix_cursor;
    transpose1 = transpose1_cursor;
    dst = initialdst;
    int *ptr1;
    int *ptr2;
    int *ptr3;
    int result = 0;

    for (j = 0; j < dim; j++)
    {
        int j_dim = j * dim;
        int *temp_ptr3 = &transpose1[-dim];
        int *temp_ptr2 = &newMatrix[j_dim];

        for (k = 0; k < dim; k++)
        {
            ptr1 = &dst[j_dim + k];
            ptr2 = temp_ptr2;

            temp_ptr3 += dim;
            ptr3 = temp_ptr3;

            for (l = 0; l < dim; l += 32)
            {
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
            }
            *ptr1 += result;
            result = 0;
        }
    }

    free(transpose1_cursor);
    free(newMatrix_cursor);
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
    int *tmp_src = src;
    int block_size = dim_by_dim - 64;
    int *tmp_dst = &dst[dim_by_dim - 1];
    for (i = 0; i <= block_size; i += 64)
    {
        // printf("dst_index: %d src_index: %d", dst_index, src_index);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
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
