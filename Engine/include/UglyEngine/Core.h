#pragma once

//STL
#include <string>
#include <map>

// Include version header
#include "Version.h"

// Include plog
#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

// Include GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Constants declaration
namespace ugly
{
	static const std::string LOG_FILENAME = "UglyEngine.log";

}//namespace ugly