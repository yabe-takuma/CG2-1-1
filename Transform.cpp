#include "Transform.h"
#include "Vector3.h"

Vector3 scale = { 0.0f,0.0f,0.0f };
Vector3 rotate = { 0.0f,0.0f,0.0f };
Vector3 translate = { 0.0f,0.0f,0.0f };
Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);
