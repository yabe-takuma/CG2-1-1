#pragma once
#include"Vector2.h"
#include"Vector3.h"

struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};

struct VertexData{
	Vector4 position;
	Vector2 texcoord;
	Vector3 normal;
};

struct Material {
	Vector4 color;
	int32_t enableLighting;
};

struct DirectionalLight {
	Vector4 color;//!<ライトの色
	Vector3 direction;//!<ライトの向き
	float intensity;//!<輝度
};


Vector3 Normalize(const Vector3& v);