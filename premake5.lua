workspace "rpg_engine"
	architecture 'x86'

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "rpg_engine"
	location "src"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.location}/**.h",
		"%{prj.location}/**.cpp",
	}

	includedirs
	{
		"dep/include/**"
	}

	links
	{
		"glfw3",
		"opengl32",
		"glew32s",
		"FreeImage"
	}

	libdirs
	{
		"dep/src/**",
	}

	filter "system:windows"
		cppdialect "C++17"
		-- staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLEW_STATIC"
		}

		postbuildcommands
		{
			-- ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/"),
			-- "copy dep/src/freeImage/FreeImage.dll /bin/" .. outputdir .. "/%{prj.name}/"
			-- "copy dep\\src\\freeImage\\FreeImage.dll bin\\Debug-windows-x86\\rpg_engine\\"
		}
	
	filter "configurations:Debug"
		defines "BUILD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BUILD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BUILD_DIST"
		optimize "On"
	
		











