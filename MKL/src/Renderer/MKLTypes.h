#ifndef _MKL_TYPES_H_
#define _MKL_TYPES_H_

#include <simd/vector.h>
#include <simd/matrix.h>

typedef struct MKLVertex
{
    vector_float4 position;
} MKLVertex;

typedef struct MKLUniforms
{
    matrix_float4x4 viewMatrix;
    matrix_float4x4 projectionMatrix;
} MKLUniforms;

#endif // _MKL_TYPES_H_