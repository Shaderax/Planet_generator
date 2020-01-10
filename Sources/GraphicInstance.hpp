#include "Math/vec4.hpp"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <string>

class GraphicInstance
{
	private:
		static GraphicInstance*				_instance;
		struct WindowAttribute
		{
			uint32_t	_width;
			uint32_t	_height;
			bool		_fullscreen;
			bool		_vsync;
			std::string	_name;

			WindowAttribute( int width = 1280, int height = 720, bool fullscreen = false, bool vsync = false, std::string name = "New Project" ) :
				_width(width),
				_height(height),
				_fullscreen(fullscreen),
				_vsync(vsync),
				_name(name)
			{
			}
		} _windowAttribute;

		GLFWwindow*						_window;
		bool					_initialized;
		vec4<float>				_backgroundColor;
	public:
		static GraphicInstance* GetInstance( void );
		static void ReleaseInstance( void );
		GraphicInstance( void );
		~GraphicInstance( void );
		void Initialize( void );
		GLFWwindow* GetWindow( void );
		WindowAttribute GetWindowAttribute( void );
		void	CreateWindow( void );
		static void FramebufferResizeCallback(GLFWwindow *window, int width, int height);
		void PollEvent( void );
		bool ShouldClose( void );
		void Draw( void );
		void SwapBuffer( void );
		void SetBackgroundColor( vec4<float> color );
};

