#include"Vector3.h"

#include <cassert>
#include <cmath>

Vector3 Normalize(const Vector3& v)
{
	Vector3 result;
	float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	assert(length != 0.0f);
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return result;
}