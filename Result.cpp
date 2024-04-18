#include "Result.h"

Result::Result()
{
}

void Result::Updata()
{
}

void Result::Draw()
{
	VectorScreenPrint(0, 0, transformed, ": transformed");
	MatrixScreenPrint(0, 0, translateMatrix);
	MatrixScreenPrint(0, kRowHeight * 5, scaleMatrix);
}
