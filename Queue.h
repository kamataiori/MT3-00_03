#pragma once
#include <struct.h>
#include <assert.h>
#include <math.h>
#include <Novice.h>

//平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

//拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4 matrix);

//数値表示
static const int kColumnWidth = 60;
static const int kRowHeight = 20;

void VectorScreenPrint(int x, int y, const Vector3& vector, const char* label);
void MatrixScreenPrint(int x, int y, const Matrix4x4& matrix);


