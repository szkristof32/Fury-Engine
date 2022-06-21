workspace "Fury Engine"
	architecture "x86_64"
	startproject "Diplomacy"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Fury Engine/vendor/GLFW"
	include "Fury Engine/vendor/Glad"
group ""

include "Fury Engine"
include "Diplomacy"