#pragma once

#ifndef __INCLUDES__
#define __INCLUDES__
//Standard-Libs
    //Data-Structs
#include <iostream>
#include <vector>
#include <map>
#include <set>

    //Utils
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <ostream>
#include <unistd.h>


//Graphics
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

//Math
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Asset-Loading
#include <assimp/material.h>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// #include <freetype2/freetype/freetype.h>
// #include <freetype2/ft2build.h>

//Ant-Headers
#include "debug_logger.h"
#endif