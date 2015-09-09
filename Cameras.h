#pragma once
#include <stdint.h>
#include <DirectXMath.h>
class BaseCamera
{
public:
	BaseCamera();
	~BaseCamera();

	virtual void Update(){};
	virtual void Reset();

	virtual void SetViewParams( DirectX::FXMVECTOR vEyePt, DirectX::FXMVECTOR vLookatPt, DirectX::FXMVECTOR vUp );
	virtual void SetProjParams( float fFov, float fAspect, float fNearPlane, float fFarPlane );

	DirectX::XMMATRIX GetViewMatrix() const { return DirectX::XMLoadFloat4x4( &m_mView ); }
	DirectX::XMMATRIX GetProjMatrix() const { return DirectX::XMLoadFloat4x4( &m_mProj ); }
	DirectX::XMVECTOR GetEyePt() const { return DirectX::XMLoadFloat3( &m_vEye ); }
	DirectX::XMVECTOR GetLookAtPt() const { return DirectX::XMLoadFloat3( &m_vLookAt ); }
	float GetNearClip() const { return m_fNearPlane; }
	float GetFarClip() const { return m_fFarPlane; }

protected:
	DirectX::XMFLOAT4X4		m_mView;
	DirectX::XMFLOAT4X4		m_mProj;
	DirectX::XMFLOAT3		m_vEye;
	DirectX::XMFLOAT3		m_vLookAt;
	DirectX::XMFLOAT3		m_vUp;
	DirectX::XMFLOAT3		m_vDefaultEye;
	DirectX::XMFLOAT3		m_vDefaultLookAt;
	DirectX::XMFLOAT3		m_vDefaultUp;
	float					m_fFOV;
	float					m_fAspect;
	float					m_fNearPlane;
	float					m_fFarPlane;

};