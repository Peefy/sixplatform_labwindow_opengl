//==============================================================================
//
// Title:		openGL_helper.h
// Purpose:		A short description of the interface.
//
// Created on:	2017/8/10 at 10:53:44 by dugu.
// Copyright:	Wicrosoft. All Rights Reserved.
//
//==============================================================================

#ifndef __openGL_helper_H__
#define __openGL_helper_H__

#ifdef __cplusplus
    extern "C" {
#endif
		
//头文件
#include "cvidef.h"
#include <windows.h>
#include <stdio.h>
#include <utility.h>
#include <GL\gl.h>
#include <GL\glu.h>

		
//openGL函数宏定义 坐标原点的平移和旋转操作
#define GL_TRANS(x,y,z)  glTranslatef(x,y,z); 
//angle为负数 顺时针转动 正数 逆时针转动
#define GL_ROTATE_X(angle)  glRotatef(angle,1,0,0) 
#define GL_ROTATE_Y(angle)  glRotatef(angle,0,1,0)   
#define GL_ROTATE_Z(angle)  glRotatef(angle,0,0,1) 
//将坐标原点存入堆栈
#define GL_PUSH_DRAW_POINT glPushMatrix()	
#define GL_POP_DRAW_POINT glPopMatrix()
//顶板的欧拉角属性
extern void OpenGL_SetRoll(double angle);  
extern void OpenGL_SetYaw(double angle);  
extern void OpenGL_SetPitch(double angle);  

//函数声明
int OpenGLControlInit(int panelHandle,int pictureBox); 
//画实心正方体
void DrawCubeWithColor(float length,float r,float b,float g);  
//画实心长方体
void DrawSolidBoxWithColor(float a,float b,float c,float red,float blue,float green); 
//画实心球
void DrawBall(float radius,float red,float blue,float green);
//画圆柱
void DrawCylinderWithTwoPoints(float x1,float y1,float z1,float x2,float y2,float z2,float blueHeight,
							   float baseRadius,int isJudgeAngleY);
void DrawBanFormThreePoints(float x1,float y1,float z1,float x2,float y2 ,float z2,
						   float x3,float y3,float z3);

void PointRotatef(float angle,float x,float y,float z,
				  float old_x,float old_y,float old_z,
				  float* new_x,float* new_y,float* new_z);
void PointRotatef_X(float angle,
				  float old_x,float old_y,float old_z,
				  float* new_x,float* new_y,float* new_z);
void PointRotatef_Y(float angle,
				  float old_x,float old_y,float old_z,
				  float* new_x,float* new_y,float* new_z);
void PointRotatef_Z(float angle,
				  float old_x,float old_y,float old_z,
				  float* new_x,float* new_y,float* new_z);
		
void RenderImage(int fastFlag);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __openGL_helper_H__ */
