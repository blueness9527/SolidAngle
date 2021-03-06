// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "Math/SolidAngleMathUtility.h"
#include "Containers/SolidAngleString.h"
#include "Math/IntPoint.h"
#include "Math/Vector2D.h"

struct Rect;

/**
* Structure for integer rectangles in 2-d space.
*
* @todo Docs: The operators need better documentation, i.e. what does it mean to divide a rectangle?
*/
struct YIntRect
{
	/** Holds the first pixel line/row (like in Win32 RECT). */
	YIntPoint Min;

	/** Holds the last pixel line/row (like in Win32 RECT). */
	YIntPoint Max;

public:

	/** Constructor */
	YIntRect();

	/**
	* Constructor
	*
	* @param X0 Minimum X coordinate.
	* @param Y0 Minimum Y coordinate.
	* @param X1 Maximum X coordinate.
	* @param Y1 Maximum Y coordinate.
	*/
	YIntRect(int32 X0, int32 Y0, int32 X1, int32 Y1);

	/**
	* Constructor
	*
	* @param InMin Minimum Point
	* @param InMax Maximum Point
	*/
	YIntRect(YIntPoint InMin, YIntPoint InMax);

public:

	/**
	* Gets a specific point in this rectangle.
	*
	* @param PointIndex Index of Point in rectangle.
	* @return Const reference to point in rectangle.
	*/
	const YIntPoint& operator()(int32 PointIndex) const;

	/**
	* Gets a specific point in this rectangle.
	*
	* @param PointIndex Index of Point in rectangle.
	* @return Reference to point in rectangle.
	*/
	YIntPoint& operator()(int32 PointIndex);

	/**
	* Compares Rectangles for equality.
	*
	* @param Other The Other Rectangle for comparison.
	* @return true if the rectangles are equal, false otherwise..
	*/
	bool operator==(const YIntRect& Other) const;

	/**
	* Compares Rectangles for inequality.
	*
	* @param Other The Other Rectangle for comparison.
	* @return true if the rectangles are not equal, false otherwise..
	*/
	bool operator!=(const YIntRect& Other) const;

	/**
	* Applies scaling to this rectangle.
	*
	* @param Scale What to multiply the rectangle by.
	* @return Reference to this rectangle after scaling.
	*/
	YIntRect& operator*=(int32 Scale);

	/**
	* Adds a point to this rectangle.
	*
	* @param Point The point to add onto both points in the rectangle.
	* @return Reference to this rectangle after addition.
	*/
	YIntRect& operator+=(const YIntPoint& Point);

	/**
	* Subtracts a point from this rectangle.
	*
	* @param Point The point to subtract from both points in the rectangle.
	* @return Reference to this rectangle after subtraction.
	*/
	YIntRect& operator-=(const YIntPoint& Point);

	/**
	* Gets the result of scaling on this rectangle.
	*
	* @param Scale What to multiply this rectangle by.
	* @return New scaled rectangle.
	*/
	YIntRect operator*(int32 Scale) const;

	/**
	* Gets the result of division on this rectangle.
	*
	* @param Div What to divide this rectangle by.
	* @return New divided rectangle.
	*/
	YIntRect operator/(int32 Div) const;

	/**
	* Gets the result of adding a point to this rectangle.
	*
	* @param Point The point to add to both points in the rectangle.
	* @return New rectangle with point added to it.
	*/
	YIntRect operator+(const YIntPoint& Point) const;

	/**
	* Gets the result of dividing a point with this rectangle.
	*
	* @param Point The point to divide with.
	* @return New rectangle with point divided.
	*/
	YIntRect operator/(const YIntPoint& Point) const;

	/**
	* Gets the result of subtracting a point from this rectangle.
	*
	* @param Point The point to subtract from both points in the rectangle.
	* @return New rectangle with point subtracted from it.
	*/
	YIntRect operator-(const YIntPoint& Point) const;

	/**
	* Gets the result of adding two rectangles together.
	*
	* @param Other The other rectangle to add to this.
	* @return New rectangle after both are added together.
	*/
	YIntRect operator+(const YIntRect& Other) const;

	/**
	* Gets the result of subtracting a rectangle from this one.
	*
	* @param Other The other rectangle to subtract from this.
	* @return New rectangle after one is subtracted from this.
	*/
	YIntRect operator-(const YIntRect& Other) const;

public:

	/**
	* Calculates the area of this rectangle.
	*
	* @return The area of this rectangle.
	*/
	int32 Area() const;

	/**
	* Creates a rectangle from the bottom part of this rectangle.
	*
	* @param InHeight Height of the new rectangle (<= rectangles original height).
	* @return The new rectangle.
	*/
	YIntRect Bottom(int32 InHeight) const;

	/**
	* Clip a rectangle using the bounds of another rectangle.
	*
	* @param Other The other rectangle to clip against.
	*/
	void Clip(const YIntRect& Other);

	/** Combines the two rectanges. */
	void Union(const YIntRect& Other);

	/**
	* Test whether this rectangle contains a point.
	*
	* @param Point The point to test against.
	* @return true if the rectangle contains the specified point,, false otherwise..
	*/
	bool Contains(YIntPoint Point) const;

	/**
	* Gets the Center and Extents of this rectangle.
	*
	* @param OutCenter Will contain the center point.
	* @param OutExtent Will contain the extent.
	*/
	void GetCenterAndExtents(YIntPoint& OutCenter, YIntPoint& OutExtent) const;

	/**
	* Gets the Height of the rectangle.
	*
	* @return The Height of the rectangle.
	*/
	int32 Height() const;

	/**
	* Inflates or deflates the rectangle.
	*
	* @param Amount The amount to inflate or deflate the rectangle on each side.
	*/
	void InflateRect(int32 Amount);

	/**
	* Adds to this rectangle to include a given point.
	*
	* @param Point The point to increase the rectangle to.
	*/
	void Include(YIntPoint Point);

	/**
	* Gets a new rectangle from the inner of this one.
	*
	* @param Shrink How much to remove from each point of this rectangle.
	* @return New inner Rectangle.
	*/
	YIntRect Inner(YIntPoint Shrink) const;

	/**
	* Creates a rectangle from the right hand side of this rectangle.
	*
	* @param InWidth Width of the new rectangle (<= rectangles original width).
	* @return The new rectangle.
	*/
	YIntRect Right(int32 InWidth) const;

	/**
	* Scales a rectangle using a floating point number.
	*
	* @param Fraction What to scale the rectangle by
	* @return New scaled rectangle.
	*/
	YIntRect Scale(float Fraction) const;

	/**
	* Gets the distance from one corner of the rectangle to the other.
	*
	* @return The distance from one corner of the rectangle to the other.
	*/
	YIntPoint Size() const;

	/**
	* Get a textual representation of this rectangle.
	*
	* @return A string describing the rectangle.
	*/
	YString ToString() const;

	/**
	* Gets the width of the rectangle.
	*
	* @return The width of the rectangle.
	*/
	int32 Width() const;

	/**
	* Returns true if the rectangle is 0 x 0.
	*
	* @return true if the rectangle is 0 x 0.
	*/
	bool IsEmpty() const;

public:

	/**
	* Divides a rectangle and rounds up to the nearest integer.
	*
	* @param lhs The Rectangle to divide.
	* @param Div What to divide by.
	* @return New divided rectangle.
	*/
	static YIntRect DivideAndRoundUp(YIntRect lhs, int32 Div);
	static YIntRect DivideAndRoundUp(YIntRect lhs, YIntPoint Div);

	/**
	* Gets number of points in the Rectangle.
	*
	* @return Number of points in the Rectangle.
	*/
	static int32 Num();

public:

	/**
	* Serializes the Rectangle.
	*
	* @param Ar The archive to serialize into.
	* @param Rect The rectangle to serialize.
	* @return Reference to the Archive after serialization.
	*/
	friend YArchive& operator<<(YArchive& Ar, YIntRect& Rect)
	{
		return Ar << Rect.Min.X << Rect.Min.Y << Rect.Max.X << Rect.Max.Y;
	}
};


FORCEINLINE YIntRect YIntRect::Scale(float Fraction) const
{
	YVector2D Min2D = YVector2D(Min.X, Min.Y) * Fraction;
	YVector2D Max2D = YVector2D(Max.X, Max.Y) * Fraction;

	return YIntRect(YMath::FloorToInt(Min2D.X), YMath::FloorToInt(Min2D.Y), YMath::CeilToInt(Max2D.X), YMath::CeilToInt(Max2D.Y));
}


/* FIntRect inline functions
*****************************************************************************/

FORCEINLINE YIntRect::YIntRect()
	: Min(ForceInit)
	, Max(ForceInit)
{ }


FORCEINLINE YIntRect::YIntRect(int32 X0, int32 Y0, int32 X1, int32 Y1)
	: Min(X0, Y0)
	, Max(X1, Y1)
{ }


FORCEINLINE YIntRect::YIntRect(YIntPoint InMin, YIntPoint InMax)
	: Min(InMin)
	, Max(InMax)
{ }


FORCEINLINE const YIntPoint& YIntRect::operator()(int32 PointIndex) const
{
	return (&Min)[PointIndex];
}


FORCEINLINE YIntPoint& YIntRect::operator()(int32 PointIndex)
{
	return (&Min)[PointIndex];
}


FORCEINLINE bool YIntRect::operator==(const YIntRect& Other) const
{
	return Min == Other.Min && Max == Other.Max;
}


FORCEINLINE bool YIntRect::operator!=(const YIntRect& Other) const
{
	return Min != Other.Min || Max != Other.Max;
}


FORCEINLINE YIntRect& YIntRect::operator*=(int32 Scale)
{
	Min *= Scale;
	Max *= Scale;

	return *this;
}


FORCEINLINE YIntRect& YIntRect::operator+=(const YIntPoint& Point)
{
	Min += Point;
	Max += Point;

	return *this;
}


FORCEINLINE YIntRect& YIntRect::operator-=(const YIntPoint& Point)
{
	Min -= Point;
	Max -= Point;

	return *this;
}


FORCEINLINE YIntRect YIntRect::operator*(int32 Scale) const
{
	return YIntRect(Min * Scale, Max * Scale);
}


FORCEINLINE YIntRect YIntRect::operator/(int32 Div) const
{
	return YIntRect(Min / Div, Max / Div);
}


FORCEINLINE YIntRect YIntRect::operator+(const YIntPoint& Point) const
{
	return YIntRect(Min + Point, Max + Point);
}


FORCEINLINE YIntRect YIntRect::operator/(const YIntPoint& Point) const
{
	return YIntRect(Min / Point, Max / Point);
}


FORCEINLINE YIntRect YIntRect::operator-(const YIntPoint& Point) const
{
	return YIntRect(Min - Point, Max - Point);
}


FORCEINLINE YIntRect YIntRect::operator+(const YIntRect& Other) const
{
	return YIntRect(Min + Other.Min, Max + Other.Max);
}


FORCEINLINE YIntRect YIntRect::operator-(const YIntRect& Other) const
{
	return YIntRect(Min - Other.Min, Max - Other.Max);
}


FORCEINLINE int32 YIntRect::Area() const
{
	return (Max.X - Min.X) * (Max.Y - Min.Y);
}


FORCEINLINE YIntRect YIntRect::Bottom(int32 InHeight) const
{
	return YIntRect(Min.X, YMath::Max(Min.Y, Max.Y - InHeight), Max.X, Max.Y);
}


FORCEINLINE void YIntRect::Clip(const YIntRect& R)
{
	Min.X = YMath::Max<int32>(Min.X, R.Min.X);
	Min.Y = YMath::Max<int32>(Min.Y, R.Min.Y);
	Max.X = YMath::Min<int32>(Max.X, R.Max.X);
	Max.Y = YMath::Min<int32>(Max.Y, R.Max.Y);

	// return zero area if not overlapping
	Max.X = YMath::Max<int32>(Min.X, Max.X);
	Max.Y = YMath::Max<int32>(Min.Y, Max.Y);
}

FORCEINLINE void YIntRect::Union(const YIntRect& R)
{
	Min.X = YMath::Min<int32>(Min.X, R.Min.X);
	Min.Y = YMath::Min<int32>(Min.Y, R.Min.Y);
	Max.X = YMath::Max<int32>(Max.X, R.Max.X);
	Max.Y = YMath::Max<int32>(Max.Y, R.Max.Y);
}

FORCEINLINE bool YIntRect::Contains(YIntPoint P) const
{
	return P.X >= Min.X && P.X < Max.X && P.Y >= Min.Y && P.Y < Max.Y;
}


FORCEINLINE YIntRect YIntRect::DivideAndRoundUp(YIntRect lhs, int32 Div)
{
	return DivideAndRoundUp(lhs, YIntPoint(Div, Div));
}

FORCEINLINE YIntRect YIntRect::DivideAndRoundUp(YIntRect lhs, YIntPoint Div)
{
	return YIntRect(lhs.Min / Div, YIntPoint::DivideAndRoundUp(lhs.Max, Div));
}

FORCEINLINE void YIntRect::GetCenterAndExtents(YIntPoint& OutCenter, YIntPoint& OutExtent) const
{
	OutExtent.X = (Max.X - Min.X) / 2;
	OutExtent.Y = (Max.Y - Min.Y) / 2;

	OutCenter.X = Min.X + OutExtent.X;
	OutCenter.Y = Min.Y + OutExtent.Y;
}


FORCEINLINE int32 YIntRect::Height() const
{
	return (Max.Y - Min.Y);
}


FORCEINLINE void YIntRect::InflateRect(int32 Amount)
{
	Min.X -= Amount;
	Min.Y -= Amount;
	Max.X += Amount;
	Max.Y += Amount;
}


FORCEINLINE void YIntRect::Include(YIntPoint Point)
{
	Min.X = YMath::Min(Min.X, Point.X);
	Min.Y = YMath::Min(Min.Y, Point.Y);
	Max.X = YMath::Max(Max.X, Point.X);
	Max.Y = YMath::Max(Max.Y, Point.Y);
}

FORCEINLINE YIntRect YIntRect::Inner(YIntPoint Shrink) const
{
	return YIntRect(Min + Shrink, Max - Shrink);
}


FORCEINLINE int32 YIntRect::Num()
{
	return 2;
}


FORCEINLINE YIntRect YIntRect::Right(int32 InWidth) const
{
	return YIntRect(YMath::Max(Min.X, Max.X - InWidth), Min.Y, Max.X, Max.Y);
}


FORCEINLINE YIntPoint YIntRect::Size() const
{
	return YIntPoint(Max.X - Min.X, Max.Y - Min.Y);
}


FORCEINLINE YString YIntRect::ToString() const
{
	return YString::Printf(TEXT("Min=(%s) Max=(%s)"), *Min.ToString(), *Max.ToString());
}


FORCEINLINE int32 YIntRect::Width() const
{
	return Max.X - Min.X;
}

FORCEINLINE bool YIntRect::IsEmpty() const
{
	return Width() == 0 && Height() == 0;
}
