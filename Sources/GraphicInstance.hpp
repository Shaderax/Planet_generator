#include "Math/vec4.hpp"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <string>
#include <vector>

class GraphicInstance
{
	public:
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
		};
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
		void Update( void );
		void SwapBuffer( void );
		void SetBackgroundColor( vec4<float> color );
		void ShowCursor( bool select );
		void GetCursorPosition( double* x, double* y );
		void CreateBuffer( GLuint* vbo, uint32_t size, float* array);
		void CreateVAO( GLuint* vao, GLuint* vboToBind);
		GLuint CompileShader( std::vector<char>& shaderCode, int shaderType );
		uint32_t CreateShaderProgram( std::string vertPath, std::string fragPath );

	private:
		static GraphicInstance*				_instance;

		GLFWwindow*				_window;
		bool					_initialized;
		vec4<float>				_backgroundColor;
		WindowAttribute				_windowAttribute;
};
