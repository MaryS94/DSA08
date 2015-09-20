
/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/08
----------------------------------------------*/
#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "RE\ReEngAppClass.h"
#include "MyMesh.h"
#include <SFML\Graphics.hpp>
//#include <chrono>

using namespace ReEng; //Using ReEng namespace to use all the classes in the dll

class AppClass : public ReEngAppClass
{
public:
	typedef ReEngAppClass super;

	MyMesh* m_pMesh = nullptr;
	float* m_fMatrixArray = nullptr;
	int m_nObjects = 200;

	/* Constructor */
	AppClass(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow) : super(hInstance, lpCmdLine, nCmdShow) {}

	/*
	InitApplication
	Initialize ReEng variables necessary to create the window
	*/
	virtual void InitApplication(String a_sWindowName);

	/*
	InitUserVariables
	Initializes user specific variables, this is executed right after InitApplicationVariables,
	the purpose of this member function is to initialize member variables specific for this lesson
	*/
	virtual void InitUserVariables(void);

	/*
	Update
	Updates the scene
	*/
	virtual void Update(void);

	/*
	Display
	Displays the scene
	*/
	virtual void Display(void);

	/*
	ProcessKeyboard
	Manage the response of key presses
	*/
	virtual void ProcessKeyboard(void);

	/*
	ProcessMouse
	Manage the response of key presses and mouse position
	*/
	virtual void ProcessMouse(void);

	/*
	Release
	Releases the application
	IF INHERITED AND OVERRIDEN MAKE SURE TO RELEASE BASE POINTERS (OR CALL BASED CLASS RELEASE)
	*/
	virtual void Release(void);
};

#endif //__APPLICATION_H_