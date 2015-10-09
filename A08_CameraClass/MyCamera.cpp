/////////////////////////////////////////////////////////////////////
// File: MyCamera.cpp
// DSA2 A08_CameraClass
// Authors:
// 
// Singleton Camera Class
/////////////////////////////////////////////////////////////////////

#include "MyCamera.h"


/*Notes to self delete later.....

glm::perspective( fovy,    //view angle
                  aspect,  //screen ratio
				  near,    //distance to near clip plane
				  far)     //distance to far clip plane

glm::ortho( left,      
            right,
			bottom,
			top,         
			near,        //distance to near clip plane
			far)         //distance to far clip plane

glm::lookAt( v3 eye,    //point in space of camera
             v3 center, //point in space to (lookAt)/(target)
			 v3 up)     //cam_up

*/


MyCamera* MyCamera::inst = nullptr;
//Private Constructor
MyCamera::MyCamera()
{
	//Init camera properties
	fov = 45.0f;
	aspectRatio = 1080.0f / 720.0f;
	clipFront = 0.01f;
	clipBack = 1000.0f;

	//Init camera position looking at origin
	camTarget = vector3(0.0f, 0.0f, 0.0f);
	camPosition = vector3(0.0f, 0.0f, -10.0f);
	camUp = vector3(0.0f, 1.0f, 0.0f);
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
//this should be updated prior to call?
	return glm::lookAt(camPosition,camTarget,camUp);
}
//Retrieve the projection matrix
matrix4 MyCamera::GetProjection(bool bOrthographic)
{
	if (bOrthographic)
	{
//TODO - this should be based on aspectRatio
		return matrix4(IDENTITY);
	}
	
	return glm::perspective(fov,aspectRatio,clipFront,clipBack);
}

void MyCamera::SetPosition(vector3 v3Position)
{
	camPosition = v3Position;
}
void MyCamera::SetTarget(vector3 v3Target)
{
	camTarget = v3Target;
}
void MyCamera::SetUp(vector3 v3Up)
{
	camUp = v3Up;
}

//these need to be along the cam direction/view vector 
//move along (pos -> target)
void MyCamera::MoveForward(float fIncrement)
{
	//get the normalized dirction vector
	vector3 camDir = glm::normalize(camTarget - camPosition);
	//move in this direction
	
	camPosition += (camDir * fIncrement);
	camTarget += (camDir * fIncrement);
}
void MyCamera::MoveSideways(float fIncrement)
{
	vector3 camDir = glm::normalize(camTarget - camPosition);
	
	//Use the cross product to get a perpendicular vector
	//           \|_     ([\]camDir x [|]camUp) = [_]camRight 
	//Then scale & add to pos / target
	vector3 camRight = glm::cross(camDir, camUp);
	
	camPosition += (camRight * fIncrement);
	camTarget += (camRight * fIncrement);
}
void MyCamera::MoveVertical(float fIncrement)
{
	//move along the up vector
	camPosition += (camUp * fIncrement);
	camTarget += (camUp * fIncrement);
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


