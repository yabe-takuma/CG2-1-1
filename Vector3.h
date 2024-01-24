#pragma once

struct Vector3
{
	float x;
	float y;
	float z;
};

struct CameraForGPU {
	Vector3 worldPosition;
};