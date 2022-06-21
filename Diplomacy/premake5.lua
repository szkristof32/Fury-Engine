project "Diplomacy"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"%{wks.location}/Fury Engine/src"
	}

	links
	{
		"Fury Engine"
	}

	filter "system:windows"
		systemversion "latest"
		defines "FURY_PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines "FURY_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FURY_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "FURY_DIST"
		runtime "Release"
		optimize "on"