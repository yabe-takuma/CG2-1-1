#include "Object3d.hlsli"

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct Material {
	float32_t4 color;
	int32_t enableLighting;
};
ConstantBuffer<Material> gMaterial : register(b0);

struct DirectionalLight{
float32_t4 color; //ライトの色
float32_t3 direction; //!<ライトの向き
float intensity; //!<輝度
};
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
struct PixelShaderOutput{
float32_t4 color : SV_TARGET0;
};



PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	float32_t4 textureColor=gTexture.Sample(gSampler,input.texcoord);
	if(gMaterial.enableLighting!=0){
	float NdotL=saturate(dot(normalize(input.normal),-gDirectionalLight.direction));
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
	output.color=gMaterial.color*textureColor*gDirectionalLight.color*cos*gDirectionalLight.intensity;
	} else{
	output.color=gMaterial.color*textureColor;
	}
	return output;
}