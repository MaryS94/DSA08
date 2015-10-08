/////////////////////////////////////////////////////////////////////
// File: MyCamera.cpp
// DSA2 A08_CameraClass
// Authors:
// 
// Singleton Camera Class
/////////////////////////////////////////////////////////////////////

#include "MyCamera.h"

MyCamera* MyCamera::inst = nullptr;
//Private Constructor
MyCamera::MyCamera()
{

}

//Get instance of camera
MyCamera* MyCamera::GetInstance()
{
	if (inst == nullptr)
	{
		inst = new MyCamera();
	}
	return inst;
}
//Release the camera singleton instance
void MyCamera::ReleaseInst()
{
	if (inst != nullptr)
	{
		delete inst;
		inst = nullptr;
	}
}

//Retrieve the camera view matrix
matrix4 MyCamera::GetView()
{
	//TODO

	return matrix4(IDENTITY);
}
//Retrieve the projection matrix
matrix4 MyCamera::GetProjection(bool bOrthographic)
{
	//TODO

	return matrix4(IDENTITY);
}

void MyCamera::SetPosition(vector3 v3Position)
{
	//TODO
}
void MyCamera::SetTarget(vector3 v3Target)
{
	//TODO
}
void MyCamera::SetUp(vector3 v3Up)
{
	//TODO
}

void MyCamera::MoveForward(float fIncrement)
{
	//TODO
}
void MyCamera::MoveSideways(float fIncrement)
{
	//TODO
}
void MyCamera::MoveVertical(float fIncrement)
{
	//TODO
}

void MyCamera::ChangePitch(float fIncrement)
{
	//TODO
}
void MyCamera::ChangeRoll(float fIncrement)
{
	//TODO
}
void MyCamera::ChangeYaw(float fIncrement)
{
	//TODO
}


