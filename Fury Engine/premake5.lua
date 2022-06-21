project "Fury Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	includedirs
	{
		"src",
		"vendor/glm",
		"vendor/GLFW/include",
		"vendor/Glad/include",
		"vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FURY_PLATFORM_WINDOWS",
			"FURY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Diplomacy\"")
		}

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