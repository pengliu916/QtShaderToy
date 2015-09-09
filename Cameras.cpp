#include "Cameras.h"
using namespace DirectX;

BaseCamera::BaseCamera()
{
	XMStoreFloat3( &m_vDefaultUp, g_XMIdentityR1 );
	XMStoreFloat3( &m_vUp, g_XMIdentityR1 );
	SetViewParams( g_XMZero, g_XMIdentityR2, g_XMIdentityR1 );
	SetProjParams( XM_PI / 4, 1.0f, 1.0f, 1000.0f );
}

void BaseCamera::Reset()
{
	SetViewParams( g_XMZero, g_XMIdentityR2, g_XMIdentityR1 );
	SetProjParams( XM_PI / 4, 1.0f, 1.0f, 1000.0f );
}

void BaseCamera::SetViewParams( DirectX::FXMVECTOR vEyePt, DirectX::FXMVECTOR vLookatPt, FXMVECTOR vUp )
{
	XMStoreFloat3( &m_vEye, vEyePt );
	XMStoreFloat3( &m_vDefaultEye, vEyePt );

	XMStoreFloat3( &m_vLookAt, vLookatPt );
	XMStoreFloat3( &m_vDefaultLookAt, vLookatPt );
	
	XMStoreFloat3( &m_vUp, vUp );

	XMMATRIX mView = XMMatrixLookAtLH( vEyePt, vLookatPt, XMLoadFloat3( &m_vUp ) );
	XMStoreFloat4x4( &m_mView, mView );
}

void BaseCamera::SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
{
	// Set attributes for the projection matrix
	m_fFOV = fFOV;
	m_fAspect = fAspect;
	m_fNearPlane = fNearPlane;
	m_fFarPlane = fFarPlane;

	XMMATRIX mProj = XMMatrixPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane );
	XMStoreFloat4x4( &m_mProj, mProj );
}