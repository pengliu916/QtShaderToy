#pragma once
#include <DirectXMath.h>
using namespace DirectX; 

class MouseInteractiveMovement
{
public:
	MouseInteractiveMovement();
	~MouseInteractiveMovement();
	virtual void update( float, float, unsigned char );
	virtual void reset();
};