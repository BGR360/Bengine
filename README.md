# The "Bengine" 3D Game Engine
A cross-platform, homebrewn game engine written in C++ using Qt and OpenGL.

## Blast from the Past: CppGameEngine Parte 1
This project is a complete remake of [my original C++ game engine](https://github.com/bgr360/CppGameEngine3D), which also used Qt and OpenGL. In this version, I aim to focus more on the functionality of the Editor, reworking the Asset system (previously known as the ResourceManager), and experimenting more with rendering. In my previous version, I focused more on creating from scratch. I created my own Matrix/Vector library (ouch), wrote my own OpenGL code and wrapper classes for Shaders and the like, and 

#### Improvements to be Made

* Don't use exceptions. BAD for a high-performance game engine!
* Rely more on Qt's OpenGL wrappers so that I can focus on the actual GLSL shaders and the rendering engine
* Better Material classes
* Cleaner Editor code

## Goals for this Version

* Use Test-Driven Development
* Create an Editor that can create and compile new game projects
* Improve definitions for Materials
* Sharpen use of Data-Driven Design
* Scripting???
