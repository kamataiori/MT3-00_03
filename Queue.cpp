﻿#include "Queue.h"

Matrix4x4 MakeTranslateMatrix(const Vector3& translate)
{
	Matrix4x4 result =
	{
		result.m[0][0] = 1,
		result.m[0][1] = 0,
		result.m[0][2] = 0,
		result.m[0][3] = 0,

		result.m[1][0] = 0,
		result.m[1][1] = 1,
		result.m[1][2] = 0,
		result.m[1][3] = 0,

		result.m[2][0] = 0,
		result.m[2][1] = 0,
		result.m[2][2] = 1,
		result.m[2][3] = 0,

		result.m[3][0] = translate.x,
		result.m[3][1] = translate.y,
		result.m[3][2] = translate.z,
		result.m[3][3] = 1,
	};

	return result;

}

Matrix4x4 MakeScaleMatrix(const Vector3& scale)
{
	Matrix4x4 result =
	{
		result.m[0][0] = scale.x,
		result.m[0][1] = 0,
		result.m[0][2] = 0,
		result.m[0][3] = 0,

		result.m[1][0] = 0,
		result.m[1][1] = scale.y,
		result.m[1][2] = 0,
		result.m[1][3] = 0,

		result.m[2][0] = 0,
		result.m[2][1] = 0,
		result.m[2][2] = scale.z,
		result.m[2][3] = 0,

		result.m[3][0] = 0,
		result.m[3][1] = 0,
		result.m[3][2] = 0,
		result.m[3][3] = 1,
	};

	return result;

}

Vector3 Transform(const Vector3& vector, const Matrix4x4 matrix)
{
	Vector3 result;
	float w;

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];

	w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);

	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}

void VectorScreenPrint(int x, int y, const Vector3& vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

void MatrixScreenPrint(int x, int y, const Matrix4x4& matrix)
{
	for (int row = 1; row < 5; ++row)
	{
		for (int colum = 1; colum < 5; ++colum)
		{
			Novice::ScreenPrintf(x + colum * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][colum]);
		}
	}
}
