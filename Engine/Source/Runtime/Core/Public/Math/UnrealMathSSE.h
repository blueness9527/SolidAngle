#pragma once

#include <emmintrin.h>

// float4 vector register type, where the first float(X) is stored in the lowest 32 bits, and so on

typedef __m128					VectorRegister;
typedef __m128i					VectorRegisterInt;
typedef __m128d					VectorRegisterDouble;

// for an __m128, we need a single set of braces (for clang)
#define DECLARE_VECTOR_REGISTER(X, Y, Z, W) { X, Y, Z, W }

// A0	Selects which element(0 - 3) from 'A' into 1st slot in the result
// A1	Selects which element(0 - 3) from 'A' into 2nd slot in the result
// B2	Selects which element(0 - 3) from 'B' into 3rd slot in the result
// B3	Selects which element(0 - 3) from 'B' into 4th slot in the result
#define SHUFFLEMASK(A0,A1,B2,B3) ( (A0) | ((A1)<<2) | ((B2)<<4) | ((B3)<<6) )

// Returns a bitwise equivalent vector based on 4 DWORDs.
// X		1st uint32 component
// Y		2nd uint32 component
// Z		3rd uint32 component
// W		4th uint32 component
// return	Bitwise equivalent vector with 4 floats
FORCEINLINE VectorRegister		MakeVectorRegister(uint32 X, uint32 Y, uint32 Z, uint32 W)
{
	union { VectorRegister v; VectorRegisterInt i; } Tmp;
	Tmp.i = _mm_setr_epi32(X, Y, Z, W);
	return Tmp.v;
}

// Returns a vector based on 4 FLOATs.
// X		1st float component
// Y		2nd float component
// Z		3rd float component
// W		4th float component
// return	Vector of the 4 FLOATs
FORCEINLINE VectorRegister		MakeVectorRegister(float X, float Y, float Z, float W)
{
	// !!Note by zyx, �����Ǵ�r�İ汾�����Ŵӵ�λ���λ�����r��__mm_set_ps�ǴӸ�λ���λ��
	return _mm_setr_ps(X, Y, Z, W);
}

// Returns a vector based on 4 int32.
// X		1st int32 component
// Y		2nd int32 component
// Z		3rd int32 component
// W		4th int32 component
// return	Vector of the 4 int32
FORCEINLINE VectorRegisterInt		MakeVectorRegisterInt(int32 X, int32 Y, int32 Z, int32 W)
{
	return _mm_setr_epi32(X, Y, Z, W);
}

// Constants:
#include "UnrealVectorConstant.h"

//Instinsics

// Return a vector with all zeros
#define VectorZero()			_mm_setzero_ps()

// Return a vector with all ones
#define VectorOne()				(GlobalVectorConstants::FloatOne)

// Return an component from a vector
// Vec:							VectorRegister
// ComponentIndex:				Which component to get, X=0, Y=1, Z=2, W=3
// Return:						The component as a float
FORCEINLINE float				VectorGetComponent(VectorRegister Vec, uint32 ComponentIndex)
{
	return ((float*)&(Vec))[ComponentIndex];
}

// Load 4 FLOATs from unaligned memory
// Ptr:							Unaligned memory pointer to the 4 FLOATs
// Return:						VectorRegister(Ptr[0],Ptr[1],Ptr[2],Ptr[3])
#define VectorLoad( Ptr )		_mm_loadu_ps( (float*)(Ptr))

// Load 3 FLOATs from unaligned memory and leaves W undefined.
// Ptr:							Unaligned memory pointer to the 3 FLOATs
// Return:						VectorRegister(Ptr[0],Ptr[1],Ptr[2],undefined)
#define VectorLoadFloat3( Ptr ) MakeVectorRegister( ((const float*)(Ptr))[0], ((const float*)(Ptr))[1], ((const float*)(Ptr))[2], 0.0f )

// Load 3 FLOATs from unaligned memory and sets W = 0.0f
// Ptr:							Unaligned memory pointer to the 3 FLOATs
// Return:						VectorRegister(Ptr[0],Ptr[1],Ptr[2], 0.0f)
#define VectorLoadFloat3_W0( Ptr ) MakeVectorRegister( ((const float*)(Ptr))[0], ((const float*)(Ptr))[1], ((const float*)(Ptr))[2], 0.0f )

// Load 3 FLOATs from unaligned memory and sets W = 1.0f
// Ptr:							Unaligned memory pointer to the 3 FLOATs
// Return:						VectorRegister(Ptr[0],Ptr[1],Ptr[2], 1.0f)
#define VectorLoadFloat3_W1( Ptr ) MakeVectorRegister( ((const float*)(Ptr))[0], ((const float*)(Ptr))[1], ((const float*)(Ptr))[2], 1.0f )

// Load 4 FLOATs from aligned memory
// Ptr:							Aligned memory pointer to the 4 FLOATs
// Return:						VectorRegister(Ptr[0],Ptr[1],Ptr[2], Ptr[3])
#define VectorLoadAligned( Ptr )  _mm_load_ps((float*)Ptr)

// Loads 1 float from unaligned memory and replicates it to all 4 elements.
//Ptr:							Unaligned memory pointer to the float
//Return:						VectorRegister(Ptr[0], Ptr[0], Ptr[0], Ptr[0])
#define VectorLoadFloat1( Ptr ) _mm_load_ps1((float*)(Ptr))

// Creates a vector out of three FLOATs and leaves W undefined.
// X:							1st float component
// Y:							2nd float component
// Z:							3rd float component
// Return:						VectorRegister(X, Y, Z, undefined)
#define VectorSetFloat3( X, Y, Z )		MakeVectorRegister( X, Y, Z, 0.0f)

// Propagates passed in float to all registers
// F:							Float to Set
// Result:						VectorRegister(F,F,F,F)
#define VectorSetFloat1( F )	_mm_set_ps1( F )

// Creates a vector out of four FLOATs.
// X:							1st float component
// Y:							2nd float component
// Z:							3rd float component
// W:							4th float component
// return:						VectorRegister(X, Y, Z, W)
#define VectorSet( X, Y, Z, W )			MakeVectorRegister( X, Y, Z, W )

// Stores a vector to aligned memory.
// Vec:							Vector to store
// Ptr:							Aligned memory pointer
#define VectorStoreAligned( Vec, Ptr )	_mm_store_ps( (float*)(Ptr), Vec) 

//Performs non-temporal store of a vector to aligned memory without polluting the caches
// !!Note by zyx,û������Poluuting the caches��ʲô��˼
// Vec:							Vector to store
// Ptr:							Aligned memory pointer
#define VectorStoreAlignedStreamed( Vec, Ptr )	_mm_stream_ps( (float*)(Ptr), Vec )

// Stores a vector to memory(aligned or unaligned).
// Vec:							Vector to store
// Ptr:							Memory pointer
#define VectorStore( Vec, Ptr )			_mm_storeu_ps( (float*)(Ptr), Vec )

// Stores the XYZ components of a vector to unaligned memory.
// Vec:							Vector to store XYZ
// Ptr:							Unaligned memory pointer
FORCEINLINE void				VectorStoreFloat3(const VectorRegister& Vec, void* Ptr)
{
#if 0   // !!Note by zyx, Implement by UE
	union { VectorRegister v; float f[4]; } Tmp;
	Tmp.v = Vec;
	float* FloatPtr = (float*)(Ptr);
	FloatPtr[0] = Tmp.f[0];
	FloatPtr[1] = Tmp.f[1];
	FloatPtr[2] = Tmp.f[2];
#else
	float* FloatPtr = (float*)(Ptr);
	FloatPtr[0] = ((const float*)&(Vec))[0];
	FloatPtr[1] = ((const float*)&(Vec))[1];
	FloatPtr[2] = ((const float*)&(Vec))[2];
#endif
}

// Stores the X component of a vector to unaligned memory.
// Vec:							Vector to store X
// Ptr:							Unaligned memory pointer
#define VectorStoreFloat1( Vec, Ptr )	_mm_store_ss((float*)(Ptr), Vec)

// Replicates one element into all four elements and returns the new vector.
// Vec:							Source Vector
// ElementIndex:				Index(0-3�� of the element to replicate
// Return:						VectorRegister( Vec[ElementIndex], Vec[ElementIndex], Vec[ElementIndex], Vec[ElementIndex] )
// !!Note by zyx, ʵ��ԭ������
//__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8)
//{
//	SELECT4(src, control) { //�������ã����Ǹ���control��2bit,4��ֵ����Ӧ__m128��ÿ��float)
//		CASE(control[1:0])
//			0:	tmp[31:0] : = src[31:0]
//			1 : tmp[31:0] : = src[63:32]
//			2 : tmp[31:0] : = src[95:64]
//			3 : tmp[31:0] : = src[127:96]
//			ESAC
//			RETURN tmp[31:0]
//	}
//
//		dst[31:0] : = SELECT4(a[127:0], imm8[1:0])
//		dst[63:32] : = SELECT4(a[127:0], imm8[3:2])
//		dst[95:64] : = SELECT4(b[127:0], imm8[5:4])
//		dst[127:96] : = SELECT4(b[127:0], imm8[7:6])
//}
#define VectorReplicate( Vec, ElementIndex )	_mm_shuffle_ps( Vec, Vec, SHUFFLEMASK(ElementIndex,ElementIndex,ElementIndex,ElementIndex) )

// Returns the absolute value (component-wise).
// Vec:							Source vector
// return:						VectorRegister( abs(Vec.x), abs(Vec.y), abs(Vec.z), abs(Vec.w) )
// // !!Note by zyx, ʵ��ԭ��:�������λΪ����λ����0x7FFFFFFF�������
#define VectorAbs( Vec )		_mm_and_ps(Vec, GlobalVectorConstants::SignMask)

// Returns the negated value (component-wise).
// Vec:							Source Vector
// Return:						VectorRegister( -Vec.x, -Vec.y, -Vec.z, -Vec.w )
#define VectorNegate( Vec )		_mm_sub_ps(_mm_setzero_ps(),Vec)

// Adds two vectors(component - wise) and returns the result.
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x + Vec2.x, Vec1.y + Vec2.y, Vec1.z + Vec2.z, Vec1.w + Vec2.w)
#define VectorAdd( Vec1, Vec2 )			_mm_add_ps( Vec1, Vec2 )

// Subtracts a vector from another (component-wise) and returns the result.
// Vec1:						1st vector
// Vec2:						2nd vector
// Return						VectorRegister( Vec1.x-Vec2.x, Vec1.y-Vec2.y, Vec1.z-Vec2.z, Vec1.w-Vec2.w )
#define VectorSubtract( Vec1, Vec2 )	_mm_sub_ps( Vec1, Vec2 )

// Multiplies two vectors (component-wise) and returns the result.
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister( Vec1.x*Vec2.x, Vec1.y*Vec2.y, Vec1.z*Vec2.z, Vec1.w*Vec2.w )
#define VectorMultiply( Vec1, Vec2 )	_mm_mul_ps( Vec1, Vec2 )

// Multiplies two vectors(component - wise), adds in the third vector and returns the result.
// Vec1:						1st vector
// Vec2:						2nd vector
// Vec3:						3rd vector
// Return:						VectorRegister(Vec1.x*Vec2.x + Vec3.x, Vec1.y*Vec2.y + Vec3.y, Vec1.z*Vec2.z + Vec3.z, Vec1.w*Vec2.w + Vec3.w)
#define VectorMultiplyAdd( Vec1, Vec2, Vec3 )	_mm_add_ps(_mm_mul_ps( Vec1, Vec2), Vec3)

// Calculates the dot3 product of two vectors and returns a vector with the result in all 4 components.
//  Only really efficient on Xbox 360
// Vec1:						1st vector
// Vec2:						2nd vector
// return:						d = dot3(Vec1.xyz, Vec2.xyz), VectorRegister(d, d, d, d)
FORCEINLINE VectorRegister		VectorDot3(const VectorRegister& Vec1, const VectorRegister& Vec2)
{
	VectorRegister Temp = VectorMultiply(Vec1, Vec2);
	return VectorAdd(VectorReplicate(Temp, 0), VectorAdd(VectorReplicate(Temp, 1), VectorReplicate(Temp, 2)));
}

// Calculates the dot4 product of two vectors and returns a vector with the result in all 4 components.
//  Only really efficient on Xbox 360
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						d = dot4(Vec1.xyzw, Vec2.xyzw), VectorRegister(d, d, d, d)
FORCEINLINE VectorRegister VectorDot4(const VectorRegister& Vec1, const VectorRegister& Vec2)
{
	VectorRegister Temp1, Temp2;
	Temp1 = VectorMultiply(Vec1, Vec2);
	Temp2 = _mm_shuffle_ps(Temp1, Temp1, SHUFFLEMASK(2, 3, 0, 1));	// (Z,W,X,Y).
	Temp1 = VectorAdd(Temp1, Temp2);								// (X*X + Z*Z, Y*Y + W*W, Z*Z + X*X, W*W + Y*Y)
	Temp2 = _mm_shuffle_ps(Temp1, Temp1, SHUFFLEMASK(1, 2, 3, 0));	// Rotate left 4 bytes (Y,Z,W,X).
	return VectorAdd(Temp1, Temp2);								// (X*X + Z*Z + Y*Y + W*W, Y*Y + W*W + Z*Z + X*X, Z*Z + X*X + W*W + Y*Y, W*W + Y*Y + X*X + Z*Z)
}

// Creates a four - part mask based on component - wise == compares of the input vectors
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x == Vec2.x ? 0xFFFFFFFF : 0, same for yzw)
#define VectorCompareEQ( Vec1, Vec2 )			_mm_cmpeq_ps( Vec1, Vec2 )

// Creates a four - part mask based on component - wise != compares of the input vectors
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x != Vec2.x ? 0xFFFFFFFF : 0, same for yzw)
#define VectorCompareNE( Vec1, Vec2 )			_mm_cmpneq_ps( Vec1, Vec2 )

// Creates a four - part mask based on component - wise > compares of the input vectors
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x > Vec2.x ? 0xFFFFFFFF : 0, same for yzw)
#define VectorCompareGT( Vec1, Vec2 )			_mm_cmpgt_ps( Vec1, Vec2 )

// Creates a four - part mask based on component - wise >= compares of the input vectors
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x >= Vec2.x ? 0xFFFFFFFF : 0, same for yzw)
#define VectorCompareGE( Vec1, Vec2 )			_mm_cmpge_ps( Vec1, Vec2 )

// Does a bitwise vector selection based on a mask(e.g., created from VectorCompareXX)
// Mask:						Mask(when 1: use the corresponding bit from Vec1 otherwise from Vec2)
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(for each bit i : Mask[i] ? Vec1[i] : Vec2[i])
FORCEINLINE VectorRegister VectorSelect(const VectorRegister& Mask, const VectorRegister& Vec1, const VectorRegister& Vec2)
{
	return _mm_xor_ps(Vec2, _mm_and_ps(Mask, _mm_xor_ps(Vec1, Vec2)));
}

// Combines two vectors using bitwise OR(treating each vector as a 128 bit field)
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(for each bit i : Vec1[i] | Vec2[i])
#define VectorBitwiseOr(Vec1, Vec2)  _mm_or_ps(Vec1, Vec2)

// Combines two vectors using bitwise AND (treating each vector as a 128 bit field)
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(for each bit i : Vec1[i] & Vec2[i])
#define VectorBitwiseAnd(Vec1, Vec2)  _mm_and_ps(Vec1, Vec2)

// Combines two vectors using bitwise XOR (treating each vector as a 128 bit field)
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(for each bit i : Vec1[i] ^ Vec2[i])
#define VectorBitwiseXor(Vec1, Vec2)  _mm_xor_ps(Vec1, Vec2)

// Calculates the cross product of two vectors(XYZ components).W is set to 0.
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						cross(Vec1.xyz, Vec2.xyz).W is set to 0.
FORCEINLINE VectorRegister VectorCross(const VectorRegister& Vec1, const VectorRegister& Vec2)
{
	VectorRegister A_YZXW = _mm_shuffle_ps(Vec1, Vec1, SHUFFLEMASK(1, 2, 0, 3));
	VectorRegister B_ZXYW = _mm_shuffle_ps(Vec2, Vec2, SHUFFLEMASK(2, 0, 1, 3));
	VectorRegister A_ZXYW = _mm_shuffle_ps(Vec1, Vec1, SHUFFLEMASK(2, 0, 1, 3));
	VectorRegister B_YZXW = _mm_shuffle_ps(Vec2, Vec2, SHUFFLEMASK(1, 2, 0, 3));
	return VectorSubtract(VectorMultiply(A_YZXW, B_ZXYW), VectorMultiply(A_ZXYW, B_YZXW));
}

// Calculates x raised to the power of y(component - wise).
// Base:						Base vector
// Exponent:					Exponent vector
// Return:						VectorRegister(Base.x^Exponent.x, Base.y^Exponent.y, Base.z^Exponent.z, Base.w^Exponent.w)
FORCEINLINE VectorRegister VectorPow(const VectorRegister& Base, const VectorRegister& Exponent)
{
	//@TODO: Optimize
	union { VectorRegister v; float f[4]; } B, E;
	B.v = Base;
	E.v = Exponent;
	return _mm_setr_ps(powf(B.f[0], E.f[0]), powf(B.f[1], E.f[1]), powf(B.f[2], E.f[2]), powf(B.f[3], E.f[3]));
}

// Returns an estimate of 1/sqrt(c) for each component of the vector
// Vector:						Vector
// Return:						VectorRegister(1/sqrt(t), 1/sqrt(t), 1/sqrt(t), 1/sqrt(t))
#define VectorReciprocalSqrt(Vec)		_mm_rsqrt_ps( Vec )

/**
* Computes an estimate of the reciprocal of a vector (component-wise) and returns the result.
*
* @param Vec	1st vector
* @return		VectorRegister( (Estimate) 1.0f / Vec.x, (Estimate) 1.0f / Vec.y, (Estimate) 1.0f / Vec.z, (Estimate) 1.0f / Vec.w )
*/
#define VectorReciprocal(Vec)			_mm_rcp_ps(Vec)

// Return Reciprocal Length of the vector (estimate)
// Vector:						Vector
// Return:						VectorRegister(rlen, rlen, rlen, rlen) when rlen = 1/sqrt(dot4(V))
FORCEINLINE VectorRegister VectorReciprocalLen(const VectorRegister& Vector)
{
	VectorRegister RecipLen = VectorDot4(Vector, Vector);
	return VectorReciprocalSqrt(RecipLen);
}

// Return the reciprocal of the square root of each component
// Vector:						Vector
// Return:						VectorRegister(1 / sqrt(Vec.X), 1 / sqrt(Vec.Y), 1 / sqrt(Vec.Z), 1 / sqrt(Vec.W))
FORCEINLINE VectorRegister VectorReciprocalSqrtAccurate(const VectorRegister& Vec)
{
	// Perform two passes of Newton-Raphson iteration on the hardware estimate
	//    v^-0.5 = x
	// => x^2 = v^-1
	// => 1/(x^2) = v
	// => F(x) = x^-2 - v
	//    F'(x) = -2x^-3

	//    x1 = x0 - F(x0)/F'(x0)
	// => x1 = x0 + 0.5 * (x0^-2 - Vec) * x0^3
	// => x1 = x0 + 0.5 * (x0 - Vec * x0^3)
	// => x1 = x0 + x0 * (0.5 - 0.5 * Vec * x0^2)

	const VectorRegister OneHalf = GlobalVectorConstants::FloatOneHalf;
	const VectorRegister VecDivBy2 = VectorMultiply(Vec, OneHalf);

	// Initial estimate
	const VectorRegister x0 = VectorReciprocalSqrt(Vec);

	// First iteration
	VectorRegister x1 = VectorMultiply(x0, x0);
	x1 = VectorSubtract(OneHalf, VectorMultiply(VecDivBy2, x1));
	x1 = VectorMultiplyAdd(x0, x1, x0);

	// Second iteration
	VectorRegister x2 = VectorMultiply(x1, x1);
	x2 = VectorSubtract(OneHalf, VectorMultiply(VecDivBy2, x2));
	x2 = VectorMultiplyAdd(x1, x2, x1);

	return x2;
}

// Computes the reciprocal of a vector(component - wise) and returns the result.
// Vec:							1st vector
// Return:						VectorRegister(1.0f / Vec.x, 1.0f / Vec.y, 1.0f / Vec.z, 1.0f / Vec.w)
FORCEINLINE VectorRegister VectorReciprocalAccurate(const VectorRegister& Vec)
{
	// Perform two passes of Newton-Raphson iteration on the hardware estimate
	//   x1 = x0 - f(x0) / f'(x0)
	//
	//    1 / Vec = x
	// => x * Vec = 1 
	// => F(x) = x * Vec - 1
	//    F'(x) = Vec
	// => x1 = x0 - (x0 * Vec - 1) / Vec
	//
	// Since 1/Vec is what we're trying to solve, use an estimate for it, x0
	// => x1 = x0 - (x0 * Vec - 1) * x0 = 2 * x0 - Vec * x0^2 

	// Initial estimate
	const VectorRegister x0 = VectorReciprocal(Vec);

	// First iteration
	const VectorRegister x0Squared = VectorMultiply(x0, x0);
	const VectorRegister x0Times2 = VectorAdd(x0, x0);
	const VectorRegister x1 = VectorSubtract(x0Times2, VectorMultiply(Vec, x0Squared));

	// Second iteration
	const VectorRegister x1Squared = VectorMultiply(x1, x1);
	const VectorRegister x1Times2 = VectorAdd(x1, x1);
	const VectorRegister x2 = VectorSubtract(x1Times2, VectorMultiply(Vec, x1Squared));

	return x2;
}

// Normalize vector
// Vector:						Vector to normalize
// Return:						Normalized VectorRegister
FORCEINLINE VectorRegister VectorNormalize(const VectorRegister& Vector)
{
	return VectorMultiply(Vector, VectorReciprocalLen(Vector));
}

// Loads XYZ and sets W = 0
// Vector:						VectorRegister
// Return:						VectorRegister(X, Y, Z, 0.0f)
#define VectorSet_W0( Vec )		_mm_and_ps( Vec, GlobalVectorConstants::XYZMask )

// Loads XYZ and sets W = 1
// Vector:						VectorRegister
// Return:						VectorRegister(X, Y, Z, 1.0f)
FORCEINLINE VectorRegister VectorSet_W1(const VectorRegister& Vector)
{
	// Temp = (Vector[2]. Vector[3], 1.0f, 1.0f)
	VectorRegister Temp = _mm_movehl_ps(VectorOne(), Vector);

	// Return (Vector[0], Vector[1], Vector[2], 1.0f)
	return _mm_shuffle_ps(Vector, Temp, SHUFFLEMASK(0, 1, 0, 3));
}

// Multiplies two 4x4 matrices.
// Result:						Pointer to where the result should be stored
// Matrix1:						Pointer to the first matrix
// Matrix2:						Pointer to the second matrix
FORCEINLINE void VectorMatrixMultiply(void *Result, const void* Matrix1, const void* Matrix2)
{
	const VectorRegister *A = (const VectorRegister *)Matrix1;
	const VectorRegister *B = (const VectorRegister *)Matrix2;
	VectorRegister *R = (VectorRegister *)Result;
	VectorRegister Temp, R0, R1, R2, R3;

	// First row of result (Matrix1[0] * Matrix2).
	Temp = VectorMultiply(VectorReplicate(A[0], 0), B[0]);
	Temp = VectorMultiplyAdd(VectorReplicate(A[0], 1), B[1], Temp);
	Temp = VectorMultiplyAdd(VectorReplicate(A[0], 2), B[2], Temp);
	R0 = VectorMultiplyAdd(VectorReplicate(A[0], 3), B[3], Temp);

	// Second row of result (Matrix1[1] * Matrix2).
	Temp = VectorMultiply(VectorReplicate(A[1], 0), B[0]);
	Temp = VectorMultiplyAdd(VectorReplicate(A[1], 1), B[1], Temp);
	Temp = VectorMultiplyAdd(VectorReplicate(A[1], 2), B[2], Temp);
	R1 = VectorMultiplyAdd(VectorReplicate(A[1], 3), B[3], Temp);

	// Third row of result (Matrix1[2] * Matrix2).
	Temp = VectorMultiply(VectorReplicate(A[2], 0), B[0]);
	Temp = VectorMultiplyAdd(VectorReplicate(A[2], 1), B[1], Temp);
	Temp = VectorMultiplyAdd(VectorReplicate(A[2], 2), B[2], Temp);
	R2 = VectorMultiplyAdd(VectorReplicate(A[2], 3), B[3], Temp);

	// Fourth row of result (Matrix1[3] * Matrix2).
	Temp = VectorMultiply(VectorReplicate(A[3], 0), B[0]);
	Temp = VectorMultiplyAdd(VectorReplicate(A[3], 1), B[1], Temp);
	Temp = VectorMultiplyAdd(VectorReplicate(A[3], 2), B[2], Temp);
	R3 = VectorMultiplyAdd(VectorReplicate(A[3], 3), B[3], Temp);

	// Store result
	R[0] = R0;
	R[1] = R1;
	R[2] = R2;
	R[3] = R3;
}

// Calculate the inverse of an YMatrix.
// DstMatrix:					YMatrix pointer to where the result should be stored
// SrcMatrix:					YMatrix pointer to the Matrix to be inversed
// TODO : Vector version of this function that doesn't use D3DX
FORCEINLINE void VectorMatrixInverse(void* DstMatrix, const void* SrcMatrix)
{
	typedef float Float4x4[4][4];
	const Float4x4& M = *((const Float4x4*)SrcMatrix);
	Float4x4 Result;
	float Det[4];
	Float4x4 Tmp;

	Tmp[0][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
	Tmp[0][1] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
	Tmp[0][2] = M[1][2] * M[2][3] - M[1][3] * M[2][2];

	Tmp[1][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
	Tmp[1][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
	Tmp[1][2] = M[0][2] * M[2][3] - M[0][3] * M[2][2];

	Tmp[2][0] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
	Tmp[2][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
	Tmp[2][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

	Tmp[3][0] = M[1][2] * M[2][3] - M[1][3] * M[2][2];
	Tmp[3][1] = M[0][2] * M[2][3] - M[0][3] * M[2][2];
	Tmp[3][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

	Det[0] = M[1][1] * Tmp[0][0] - M[2][1] * Tmp[0][1] + M[3][1] * Tmp[0][2];
	Det[1] = M[0][1] * Tmp[1][0] - M[2][1] * Tmp[1][1] + M[3][1] * Tmp[1][2];
	Det[2] = M[0][1] * Tmp[2][0] - M[1][1] * Tmp[2][1] + M[3][1] * Tmp[2][2];
	Det[3] = M[0][1] * Tmp[3][0] - M[1][1] * Tmp[3][1] + M[2][1] * Tmp[3][2];

	float Determinant = M[0][0] * Det[0] - M[1][0] * Det[1] + M[2][0] * Det[2] - M[3][0] * Det[3];
	const float	RDet = 1.0f / Determinant;

	Result[0][0] = RDet * Det[0];
	Result[0][1] = -RDet * Det[1];
	Result[0][2] = RDet * Det[2];
	Result[0][3] = -RDet * Det[3];
	Result[1][0] = -RDet * (M[1][0] * Tmp[0][0] - M[2][0] * Tmp[0][1] + M[3][0] * Tmp[0][2]);
	Result[1][1] = RDet * (M[0][0] * Tmp[1][0] - M[2][0] * Tmp[1][1] + M[3][0] * Tmp[1][2]);
	Result[1][2] = -RDet * (M[0][0] * Tmp[2][0] - M[1][0] * Tmp[2][1] + M[3][0] * Tmp[2][2]);
	Result[1][3] = RDet * (M[0][0] * Tmp[3][0] - M[1][0] * Tmp[3][1] + M[2][0] * Tmp[3][2]);
	Result[2][0] = RDet * (
		M[1][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
		M[2][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) +
		M[3][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1])
		);
	Result[2][1] = -RDet * (
		M[0][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
		M[2][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
		M[3][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1])
		);
	Result[2][2] = RDet * (
		M[0][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) -
		M[1][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
		M[3][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
		);
	Result[2][3] = -RDet * (
		M[0][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1]) -
		M[1][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1]) +
		M[2][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
		);
	Result[3][0] = -RDet * (
		M[1][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
		M[2][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) +
		M[3][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
		);
	Result[3][1] = RDet * (
		M[0][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
		M[2][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
		M[3][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1])
		);
	Result[3][2] = -RDet * (
		M[0][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) -
		M[1][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
		M[3][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
		);
	Result[3][3] = RDet * (
		M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
		M[1][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1]) +
		M[2][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
		);

	memcpy(DstMatrix, &Result, 16 * sizeof(float));
}

//Calculate Homogeneous transform.
// VecP:						VectorRegister
// MatrixM:						YMatrix pointer to the Matrix to apply transform
// Return:						VectorRegister = VecP*MatrixM

FORCEINLINE VectorRegister VectorTransformVector(const VectorRegister&  VecP, const void* MatrixM)
{
	const VectorRegister *M = (const VectorRegister *)MatrixM;
	VectorRegister VTempX, VTempY, VTempZ, VTempW;

	// Splat x,y,z and w
	VTempX = VectorReplicate(VecP, 0);
	VTempY = VectorReplicate(VecP, 1);
	VTempZ = VectorReplicate(VecP, 2);
	VTempW = VectorReplicate(VecP, 3);
	// Mul by the matrix
	VTempX = VectorMultiply(VTempX, M[0]);
	VTempY = VectorMultiply(VTempY, M[1]);
	VTempZ = VectorMultiply(VTempZ, M[2]);
	VTempW = VectorMultiply(VTempW, M[3]);
	// Add them all together
	VTempX = VectorAdd(VTempX, VTempY);
	VTempZ = VectorAdd(VTempZ, VTempW);
	VTempX = VectorAdd(VTempX, VTempZ);

	return VTempX;
}

// Returns the minimum values of two vectors(component - wise).
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(min(Vec1.x, Vec2.x), min(Vec1.y, Vec2.y), min(Vec1.z, Vec2.z), min(Vec1.w, Vec2.w))
#define VectorMin( Vec1, Vec2 )			_mm_min_ps( Vec1, Vec2 )

// Returns the maximum values of two vectors(component - wise).
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister( max(Vec1.x,Vec2.x), max(Vec1.y,Vec2.y), max(Vec1.z,Vec2.z), max(Vec1.w,Vec2.w) )
#define VectorMax( Vec1, Vec2 )			_mm_max_ps( Vec1, Vec2 )

// Swizzle the 4 components of a vector and returns the result.
// Vec:							Source vector
// X:							Index for which component to use for X(literal 0 - 3)
// Y:							Index for which component to use for Y(literal 0 - 3)
// Z:							Index for which component to use for Z(literal 0 - 3)
// W:							Index for which component to use for W(literal 0 - 3)
// !!Note by zyx, ��û�����أ�ֻ�ܽ��������ӣ��ο��������Shuffle����
#define VectorSwizzle( Vec, X, Y, Z, W )	_mm_shuffle_ps( Vec, Vec, SHUFFLEMASK(X,Y,Z,W) )

//Creates a vector through selecting two components from each vector via a shuffle mask.
// Vec1:						Source vector1
// Vec2:						Source vector2
// X:							Index for which component of Vector1 to use for X(literal 0 - 3)
// Y:							Index for which component to Vector1 to use for Y(literal 0 - 3)
// Z:							Index for which component to Vector2 to use for Z(literal 0 - 3)
// W:							Index for which component to Vector2 to use for W(literal 0 - 3)
#define VectorShuffle( Vec1, Vec2, X, Y, Z, W )	_mm_shuffle_ps( Vec1, Vec2, SHUFFLEMASK(X,Y,Z,W) )

//These functions return a vector mask to indicate which components pass the comparison.
//Each component is 0xffffffff if it passes, 0x00000000 if it fails.
// Vec1:						1st source vector
// Vec2:						2nd source vector
// Return:						Vector with a mask for each component.
#define VectorMask_LT( Vec1, Vec2 )			_mm_cmplt_ps(Vec1, Vec2)
#define VectorMask_LE( Vec1, Vec2 )			_mm_cmple_ps(Vec1, Vec2)
#define VectorMask_GT( Vec1, Vec2 )			_mm_cmpgt_ps(Vec1, Vec2)
#define VectorMask_GE( Vec1, Vec2 )			_mm_cmpge_ps(Vec1, Vec2)
#define VectorMask_EQ( Vec1, Vec2 )			_mm_cmpeq_ps(Vec1, Vec2)
#define VectorMask_NE( Vec1, Vec2 )			_mm_cmpneq_ps(Vec1, Vec2

// Returns an integer bit - mask(0x00 - 0x0f) based on the sign - bit for each component in a vector.
// VecMask:						Vector
// Return:						Bit 0 = sign(VecMask.x), Bit 1 = sign(VecMask.y), Bit 2 = sign(VecMask.z), Bit 3 = sign(VecMask.w)

#define VectorMaskBits( VecMask )			_mm_movemask_ps( VecMask )

// Divides two vectors(component - wise) and returns the result.
// Vec1:						1st vector
// Vec2:						2nd vector
// Return:						VectorRegister(Vec1.x / Vec2.x, Vec1.y / Vec2.y, Vec1.z / Vec2.z, Vec1.w / Vec2.w)
#define VectorDivide( Vec1, Vec2 )		_mm_div_ps( Vec1, Vec2 ) 

//Counts the number of trailing zeros in the bit representation of the value,
//counting from least - significant bit to most.
// Value:						the value to determine the number of leading zeros for 
// Return:						the number of zeros before the first "on" bit
#if PLATFORM_WINDOWS
#pragma intrinsic( _BitScanForward )
FORCEINLINE uint32 appCountTrailingZeros(uint32 Value)
{
	if (Value == 0)
	{
		return 32;
	}
	uint32 BitIndex;	// 0-based, where the LSB is 0 and MSB is 31
	_BitScanForward((::DWORD *)&BitIndex, Value);	// Scans from LSB to MSB
	return BitIndex;
}
#else // PLATFORM_WINDOWS
FORCEINLINE uint32 appCountTrailingZeros(uint32 Value)
{
	if (Value == 0)
	{
		return 32;
	}
	return __builtin_ffs(Value) - 1;
}
#endif // PLATFORM_WINDOWS

// Merges the XYZ components of one vector with the W component of another vector and returns the result.
// VecXYZ:						Source vector for XYZ_
// VecW:						Source register for ___W(note: the fourth component is used, not the first)
// Return:						VectorRegister(VecXYZ.x, VecXYZ.y, VecXYZ.z, VecW.w)
#define VectorMergeVecXYZ_VecW( VecXYZ, VecW )	VectorSelect( GlobalVectorConstants::XYZMask, VecXYZ, VecW )

// Loads 4 BYTEs from unaligned memory and converts them into 4 FLOATs.
// IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Ptr:							Unaligned memory pointer to the 4 BYTEs.
// Return:						VectorRegister(float(Ptr[0]), float(Ptr[1]), float(Ptr[2]), float(Ptr[3]))
// Looks complex but is really quite straightforward:
// Load as 32-bit value, unpack 4x unsigned bytes to 4x 16-bit ints, then unpack again into 4x 32-bit ints, then convert to 4x floats
#define VectorLoadByte4( Ptr )			_mm_cvtepi32_ps(_mm_unpacklo_epi16(_mm_unpacklo_epi8(_mm_cvtsi32_si128(*(int32*)Ptr), _mm_setzero_si128()), _mm_setzero_si128()))

// Loads 4 BYTEs from unaligned memory and converts them into 4 FLOATs in reversed order.
// IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Ptr:							Unaligned memory pointer to the 4 BYTEs.
// Return:						VectorRegister(float(Ptr[3]), float(Ptr[2]), float(Ptr[1]), float(Ptr[0]))
FORCEINLINE VectorRegister VectorLoadByte4Reverse(void* Ptr)
{
	VectorRegister Temp = VectorLoadByte4(Ptr);
	return _mm_shuffle_ps(Temp, Temp, SHUFFLEMASK(3, 2, 1, 0));
}

// Converts the 4 FLOATs in the vector to 4 BYTEs, clamped to[0, 255], and stores to unaligned memory.
// IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Vec:							Vector containing 4 FLOATs
// Ptr:							Unaligned memory pointer to store the 4 BYTEs.
FORCEINLINE void VectorStoreByte4(const VectorRegister& Vec, void* Ptr)
{
	// Looks complex but is really quite straightforward:
	// Convert 4x floats to 4x 32-bit ints, then pack into 4x 16-bit ints, then into 4x 8-bit unsigned ints, then store as a 32-bit value
	*(int32*)Ptr = _mm_cvtsi128_si32(_mm_packus_epi16(_mm_packs_epi32(_mm_cvttps_epi32(Vec), _mm_setzero_si128()), _mm_setzero_si128()));
}

//Loads packed RGB10A2(4 bytes) from unaligned memory and converts them into 4 FLOATs.
//IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Ptr:							Unaligned memory pointer to the RGB10A2(4 bytes).
// Return:						VectorRegister with 4 FLOATs loaded from Ptr.
FORCEINLINE VectorRegister		VectorLoadURGB10A2N(void* Ptr)
{
	VectorRegister Tmp;

	Tmp = _mm_and_ps(_mm_load_ps1((const float *)Ptr), MakeVectorRegister(0x3FFu, 0x3FFu << 10, 0x3FFu << 20, 0x3u << 30));
	Tmp = _mm_xor_ps(Tmp, VectorSet(0, 0, 0, 0x80000000));
	Tmp = _mm_cvtepi32_ps(*(const VectorRegisterInt*)&Tmp);
	Tmp = _mm_add_ps(Tmp, VectorSet(0, 0, 0, 32768.0f*65536.0f));
	Tmp = _mm_mul_ps(Tmp, VectorSet(1.0f / 1023.0f, 1.0f / (1023.0f*1024.0f), 1.0f / (1023.0f*1024.0f*1024.0f), 1.0f / (3.0f*1024.0f*1024.0f*1024.0f)));

	return Tmp;
}

//Converts the 4 FLOATs in the vector RGB10A2, clamped to[0, 1023] and [0, 3], and stores to unaligned memory.
//IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Vec:							Vector containing 4 FLOATs
// Ptr:							Unaligned memory pointer to store the packed RGBA16(8 bytes).
FORCEINLINE void				VectorStoreURGB10A2N(const VectorRegister& Vec, void* Ptr)
{
	VectorRegister Tmp;
	Tmp = _mm_max_ps(Vec, MakeVectorRegister(0.0f, 0.0f, 0.0f, 0.0f));
	Tmp = _mm_min_ps(Tmp, MakeVectorRegister(1.0f, 1.0f, 1.0f, 1.0f));
	Tmp = _mm_mul_ps(Tmp, MakeVectorRegister(1023.0f, 1023.0f*1024.0f*0.5f, 1023.0f*1024.0f*1024.0f, 3.0f*1024.0f*1024.0f*1024.0f*0.5f));

	VectorRegisterInt TmpI;
	TmpI = _mm_cvttps_epi32(Tmp);
	TmpI = _mm_and_si128(TmpI, MakeVectorRegisterInt(0x3FFu, 0x3FFu << (10 - 1), 0x3FFu << 20, 0x3u << (30 - 1)));

	VectorRegisterInt TmpI2;
	TmpI2 = _mm_shuffle_epi32(TmpI, _MM_SHUFFLE(3, 2, 3, 2));
	TmpI = _mm_or_si128(TmpI, TmpI2);

	TmpI2 = _mm_shuffle_epi32(TmpI, _MM_SHUFFLE(1, 1, 1, 1));
	TmpI2 = _mm_add_epi32(TmpI2, TmpI2);
	TmpI = _mm_or_si128(TmpI, TmpI2);

	_mm_store_ss((float *)Ptr, *(const VectorRegister*)&TmpI);
}

//Loads packed RGBA16(4 bytes) from unaligned memory and converts them into 4 FLOATs.
//IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Ptr:							Unaligned memory pointer to the RGBA16(8 bytes).
// Return:						VectorRegister with 4 FLOATs loaded from Ptr.
FORCEINLINE VectorRegister VectorLoadURGBA16N(void* Ptr)
{
	VectorRegisterDouble TmpD = _mm_load1_pd(reinterpret_cast<const double *>(Ptr));

	VectorRegisterInt Mask = MakeVectorRegisterInt(0x0000FFFF, 0x0000FFFF, 0xFFFF0000, 0xFFFF0000);
	VectorRegisterInt FlipSign = MakeVectorRegisterInt(0, 0, 0x80000000, 0x80000000);

	VectorRegister Tmp = _mm_and_ps(
		reinterpret_cast<const VectorRegister*>(&TmpD)[0],
		reinterpret_cast<const VectorRegister*>(&Mask)[0]
	);

	Tmp = _mm_xor_ps(Tmp, reinterpret_cast<const VectorRegister*>(&FlipSign)[0]);
	Tmp = _mm_cvtepi32_ps(reinterpret_cast<const VectorRegisterInt*>(&Tmp)[0]);
	Tmp = _mm_add_ps(Tmp, MakeVectorRegister(0, 0, 32768.0f*65536.0f, 32768.0f*65536.0f));
	Tmp = _mm_mul_ps(Tmp, MakeVectorRegister(1.0f / 65535.0f, 1.0f / 65535.0f, 1.0f / (65535.0f*65536.0f), 1.0f / (65535.0f*65536.0f)));
	return _mm_shuffle_ps(Tmp, Tmp, _MM_SHUFFLE(3, 1, 2, 0));
}

//Converts the 4 FLOATs in the vector RGBA16, clamped to [0, 65535], and stores to unaligned memory.
//IMPORTANT: You need to call VectorResetFloatRegisters() before using scalar FLOATs after you've used this intrinsic!
// Vec:							Vector containing 4 FLOATs
// Ptr:							Unaligned memory pointer to store the packed RGB10A2(4 bytes).
FORCEINLINE void VectorStoreURGBA16N(const VectorRegister& Vec, void* Ptr)
{

	VectorRegister Tmp;
	Tmp = _mm_max_ps(Vec, MakeVectorRegister(0.0f, 0.0f, 0.0f, 0.0f));
	Tmp = _mm_min_ps(Tmp, MakeVectorRegister(1.0f, 1.0f, 1.0f, 1.0f));
	Tmp = _mm_mul_ps(Tmp, MakeVectorRegister(65535.0f, 65535.0f, 65535.0f, 65535.0f));

	VectorRegisterInt TmpI = _mm_cvtps_epi32(Tmp);

	uint16* Out = (uint16*)Ptr;
	Out[0] = static_cast<int16>(_mm_extract_epi16(TmpI, 0));
	Out[1] = static_cast<int16>(_mm_extract_epi16(TmpI, 2));
	Out[2] = static_cast<int16>(_mm_extract_epi16(TmpI, 4));
	Out[3] = static_cast<int16>(_mm_extract_epi16(TmpI, 6));
}

// Returns non - zero if any element in Vec1 is greater than the corresponding element in Vec2, otherwise 0.
// Vec1:						1st source vector
// Vec2							2nd source vector
// Return:						Non - zero integer if (Vec1.x > Vec2.x) || (Vec1.y > Vec2.y) || (Vec1.z > Vec2.z) || (Vec1.w > Vec2.w)
#define VectorAnyGreaterThan( Vec1, Vec2 )		_mm_movemask_ps( _mm_cmpgt_ps(Vec1, Vec2) )

//Resets the floating point registers so that they can be used again.
// Some intrinsics use these for MMX purposes(e.g.VectorLoadByte4 and VectorStoreByte4).
// This is no longer necessary now that we don't use MMX instructions
#define VectorResetFloatRegisters()

// Returns the control register.
// Return:						The uint32 control register
#define VectorGetControlRegister()		_mm_getcsr()

// Sets the control register.
// ControlStatus:				The uint32 control status value to set
#define	VectorSetControlRegister(ControlStatus) _mm_setcsr( ControlStatus )

// Control status bit to round all floating point math results towards zero.
#define VECTOR_ROUND_TOWARD_ZERO		_MM_ROUND_TOWARD_ZERO

//Multiplies two quaternions; the order matters.
//Order matters when composing quaternions : C = VectorQuaternionMultiply2(A, B) will yield a quaternion C = A * B
//that logically first applies B then A to any subsequent transformation(right first, then left).
// Quat1:						Pointer to the first quaternion
// Quat2:						Pointer to the second quaternion
// Return:						Quat1 * Quat2
FORCEINLINE VectorRegister VectorQuaternionMultiply2(const VectorRegister& Quat1, const VectorRegister& Quat2)
{
	VectorRegister Result = VectorMultiply(VectorReplicate(Quat1, 3), Quat2);
	Result = VectorMultiplyAdd(VectorMultiply(VectorReplicate(Quat1, 0), VectorSwizzle(Quat2, 3, 2, 1, 0)), GlobalVectorConstants::QMULTI_SIGN_MASK0, Result);
	Result = VectorMultiplyAdd(VectorMultiply(VectorReplicate(Quat1, 1), VectorSwizzle(Quat2, 2, 3, 0, 1)), GlobalVectorConstants::QMULTI_SIGN_MASK1, Result);
	Result = VectorMultiplyAdd(VectorMultiply(VectorReplicate(Quat1, 2), VectorSwizzle(Quat2, 1, 0, 3, 2)), GlobalVectorConstants::QMULTI_SIGN_MASK2, Result);

	return Result;
}

// Multiplies two quaternions; the order matters.
// When composing quaternions : VectorQuaternionMultiply(C, A, B) will yield a quaternion C = A * B
// that logically first applies B then A to any subsequent transformation(right first, then left).
// Result:						Pointer to where the result Quat1 * Quat2 should be stored
// Quat1:						Pointer to the first quaternion(must not be the destination)
// Quat2:						Pointer to the second quaternion(must not be the destination)

FORCEINLINE void VectorQuaternionMultiply(void* RESTRICT Result, const void* RESTRICT Quat1, const void* RESTRICT Quat2)
{
	*((VectorRegister *)Result) = VectorQuaternionMultiply2(*((const VectorRegister *)Quat1), *((const VectorRegister *)Quat2));
}

// Returns true if the vector contains a component that is either NAN or +/-infinite.
inline bool VectorContainsNaNOrInfinite(const VectorRegister& Vec)
{
	// https://en.wikipedia.org/wiki/IEEE_754-1985
	// Infinity is represented with all exponent bits set, with the correct sign bit.
	// NaN is represented with all exponent bits set, plus at least one fraction/significand bit set.
	// This means finite values will not have all exponent bits set, so check against those bits.

	// Mask off Exponent
	VectorRegister ExpTest = VectorBitwiseAnd(Vec, GlobalVectorConstants::FloatInfinity);
	// Compare to full exponent. If any are full exponent (not finite), the signs copied to the mask are non-zero, otherwise it's zero and finite.
	bool IsFinite = VectorMaskBits(VectorCompareEQ(ExpTest, GlobalVectorConstants::FloatInfinity)) == 0;
	return !IsFinite;
}

FORCEINLINE VectorRegister VectorTruncate(const VectorRegister& X)
{
	// cvt abbreviate from convert
	return _mm_cvtepi32_ps(_mm_cvttps_epi32(X));
}

FORCEINLINE VectorRegister VectorFractional(const VectorRegister& X)
{
	return VectorSubtract(X, VectorTruncate(X));
}

FORCEINLINE VectorRegister VectorCeil(const VectorRegister& X)
{
	VectorRegister Trunc = VectorTruncate(X);
	VectorRegister PosMask = VectorCompareGE(X, GlobalVectorConstants::FloatZero);
	VectorRegister Add = VectorSelect(PosMask, GlobalVectorConstants::FloatOne, (GlobalVectorConstants::FloatZero));
	return VectorAdd(Trunc, Add);
}

FORCEINLINE VectorRegister VectorFloor(const VectorRegister& X)
{
	VectorRegister Trunc = VectorTruncate(X);
	VectorRegister PosMask = VectorCompareGE(X, (GlobalVectorConstants::FloatZero));
	VectorRegister Sub = VectorSelect(PosMask, (GlobalVectorConstants::FloatZero), (GlobalVectorConstants::FloatOne));
	return VectorSubtract(Trunc, Sub);
}

FORCEINLINE VectorRegister VectorMod(const VectorRegister& X, const VectorRegister& Y)
{
	VectorRegister Temp = VectorTruncate(VectorDivide(X, Y));
	return VectorSubtract(X, VectorMultiply(Y, Temp));
}

FORCEINLINE VectorRegister VectorSign(const VectorRegister& X)
{
	VectorRegister Mask = VectorCompareGE(X, (GlobalVectorConstants::FloatZero));
	return VectorSelect(Mask, (GlobalVectorConstants::FloatOne), (GlobalVectorConstants::FloatMinusOne));
}

FORCEINLINE VectorRegister VectorStep(const VectorRegister& X)
{
	VectorRegister Mask = VectorCompareGE(X, (GlobalVectorConstants::FloatZero));
	return VectorSelect(Mask, (GlobalVectorConstants::FloatOne), (GlobalVectorConstants::FloatZero));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorExp(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Exp(VectorGetComponent(X, 0)), YMath::Exp(VectorGetComponent(X, 1)), YMath::Exp(VectorGetComponent(X, 2)), YMath::Exp(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorExp2(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Exp2(VectorGetComponent(X, 0)), YMath::Exp2(VectorGetComponent(X, 1)), YMath::Exp2(VectorGetComponent(X, 2)), YMath::Exp2(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorLog(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Loge(VectorGetComponent(X, 0)), YMath::Loge(VectorGetComponent(X, 1)), YMath::Loge(VectorGetComponent(X, 2)), YMath::Loge(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorLog2(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Log2(VectorGetComponent(X, 0)), YMath::Log2(VectorGetComponent(X, 1)), YMath::Log2(VectorGetComponent(X, 2)), YMath::Log2(VectorGetComponent(X, 3)));
}

/**
* Using "static const float ..." or "static const VectorRegister ..." in functions creates the branch and code to construct those constants.
* Doing this in FORCEINLINE not only means you introduce a branch per static, but you bloat the inlined code immensely.
* Defining these constants at the global scope causes them to be created at startup, and avoids the cost at the function level.
* Doing it at the function level is okay for anything that is a simple "const float", but usage of "sqrt()" here forces actual function calls.
* ����˵���ʹ��static const�Ļ������ڲ�����
*  if( bCreated)
*  {
*      = initialized value
*  }
*  ��������������inline�ģ�����չ���˸��������У�
*  �ή�ͺ���ִ��Ч�ʣ���������е�static const vector�ŵ�global�ռ䣬�Ͳ�������������
*/
namespace VectorSinConstantsSSE
{
	static const float p = 0.225f;
	static const float a = (16 * sqrt(p));
	static const float b = ((1 - p) / sqrt(p));
	static const VectorRegister A = MakeVectorRegister(a, a, a, a);
	static const VectorRegister B = MakeVectorRegister(b, b, b, b);
}

FORCEINLINE VectorRegister VectorSin(const VectorRegister& X)
{
	//Sine approximation using a squared parabola restrained to f(0) = 0, f(PI) = 0, f(PI/2) = 1.
	//based on a good discussion here http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
	//After approx 2.5 million tests comparing to sin(): 
	//Average error of 0.000128
	//Max error of 0.001091

	VectorRegister y = VectorMultiply(X, GlobalVectorConstants::OneOverTwoPi);
	y = VectorSubtract(y, VectorFloor(VectorAdd(y, GlobalVectorConstants::FloatOneHalf)));
	y = VectorMultiply(VectorSinConstantsSSE::A, VectorMultiply(y, VectorSubtract(GlobalVectorConstants::FloatOneHalf, VectorAbs(y))));
	return VectorMultiply(y, VectorAdd(VectorSinConstantsSSE::B, VectorAbs(y)));
}

FORCEINLINE VectorRegister VectorCos(const VectorRegister& X)
{
	return VectorSin(VectorAdd(X, GlobalVectorConstants::PiByTwo));
}


// Computes the sine and cosine of each component of a Vector.
// VSinAngles:					VectorRegister Pointer to where the Sin result should be stored
// VCosAngles:					VectorRegister Pointer to where the Cos result should be stored
// VAngles:						 VectorRegister Pointer to the input angles
FORCEINLINE void VectorSinCos(VectorRegister* RESTRICT VSinAngles, VectorRegister* RESTRICT VCosAngles, const VectorRegister* RESTRICT VAngles)
{
	// Map to [-pi, pi]
	// X = A - 2pi * round(A/2pi)
	// Note the round(), not truncate(). In this case round() can round halfway cases using round-to-nearest-even OR round-to-nearest.

	// Quotient = round(A/2pi)
	VectorRegister Quotient = VectorMultiply(*VAngles, GlobalVectorConstants::OneOverTwoPi);
	Quotient = _mm_cvtepi32_ps(_mm_cvtps_epi32(Quotient)); // round to nearest even is the default rounding mode but that's fine here.
														   // X = A - 2pi * Quotient
	VectorRegister X = VectorSubtract(*VAngles, VectorMultiply(GlobalVectorConstants::TwoPi, Quotient));

	// Map in [-pi/2,pi/2]
	VectorRegister sign = VectorBitwiseAnd(X, GlobalVectorConstants::SignBit);
	VectorRegister c = VectorBitwiseOr(GlobalVectorConstants::Pi, sign);  // pi when x >= 0, -pi when x < 0
	VectorRegister absx = VectorAbs(X);
	VectorRegister rflx = VectorSubtract(c, X);
	VectorRegister comp = VectorCompareGT(absx, GlobalVectorConstants::PiByTwo);
	X = VectorSelect(comp, rflx, X);
	sign = VectorSelect(comp, GlobalVectorConstants::FloatMinusOne, GlobalVectorConstants::FloatOne);

	const VectorRegister XSquared = VectorMultiply(X, X);

	// 11-degree minimax approximation
	//*ScalarSin = (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
	const VectorRegister SinCoeff0 = MakeVectorRegister(1.0f, -0.16666667f, 0.0083333310f, -0.00019840874f);
	const VectorRegister SinCoeff1 = MakeVectorRegister(2.7525562e-06f, -2.3889859e-08f, /*unused*/ 0.f, /*unused*/ 0.f);

	VectorRegister S;
	S = VectorReplicate(SinCoeff1, 1);
	S = VectorMultiplyAdd(XSquared, S, VectorReplicate(SinCoeff1, 0));
	S = VectorMultiplyAdd(XSquared, S, VectorReplicate(SinCoeff0, 3));
	S = VectorMultiplyAdd(XSquared, S, VectorReplicate(SinCoeff0, 2));
	S = VectorMultiplyAdd(XSquared, S, VectorReplicate(SinCoeff0, 1));
	S = VectorMultiplyAdd(XSquared, S, VectorReplicate(SinCoeff0, 0));
	*VSinAngles = VectorMultiply(S, X);

	// 10-degree minimax approximation
	//*ScalarCos = sign * (((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f);
	const VectorRegister CosCoeff0 = MakeVectorRegister(1.0f, -0.5f, 0.041666638f, -0.0013888378f);
	const VectorRegister CosCoeff1 = MakeVectorRegister(2.4760495e-05f, -2.6051615e-07f, /*unused*/ 0.f, /*unused*/ 0.f);

	VectorRegister C;
	C = VectorReplicate(CosCoeff1, 1);
	C = VectorMultiplyAdd(XSquared, C, VectorReplicate(CosCoeff1, 0));
	C = VectorMultiplyAdd(XSquared, C, VectorReplicate(CosCoeff0, 3));
	C = VectorMultiplyAdd(XSquared, C, VectorReplicate(CosCoeff0, 2));
	C = VectorMultiplyAdd(XSquared, C, VectorReplicate(CosCoeff0, 1));
	C = VectorMultiplyAdd(XSquared, C, VectorReplicate(CosCoeff0, 0));
	*VCosAngles = VectorMultiply(C, sign);
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorTan(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Tan(VectorGetComponent(X, 0)), YMath::Tan(VectorGetComponent(X, 1)), YMath::Tan(VectorGetComponent(X, 2)), YMath::Tan(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorASin(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Asin(VectorGetComponent(X, 0)), YMath::Asin(VectorGetComponent(X, 1)), YMath::Asin(VectorGetComponent(X, 2)), YMath::Asin(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorACos(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Acos(VectorGetComponent(X, 0)), YMath::Acos(VectorGetComponent(X, 1)), YMath::Acos(VectorGetComponent(X, 2)), YMath::Acos(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorATan(const VectorRegister& X)
{
	return MakeVectorRegister(YMath::Atan(VectorGetComponent(X, 0)), YMath::Atan(VectorGetComponent(X, 1)), YMath::Atan(VectorGetComponent(X, 2)), YMath::Atan(VectorGetComponent(X, 3)));
}

//TODO: Vectorize
FORCEINLINE VectorRegister VectorATan2(const VectorRegister& X, const VectorRegister& Y)
{
	return MakeVectorRegister(YMath::Atan2(VectorGetComponent(X, 0), VectorGetComponent(Y, 0)),
		YMath::Atan2(VectorGetComponent(X, 1), VectorGetComponent(Y, 1)),
		YMath::Atan2(VectorGetComponent(X, 2), VectorGetComponent(Y, 2)),
		YMath::Atan2(VectorGetComponent(X, 3), VectorGetComponent(Y, 3)));
}
