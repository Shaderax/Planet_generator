#include "Input.hpp"

#include "GraphicInstance.hpp"

Input::Input( void )
{
	//glfwGetCursorPos(GraphicInstance::GetInstance()->GetWindow(), &(_mouse._new_x), &(_mouse._new_y));

        _mouse._last_x = 0;
        _mouse._last_y = 0;
	_mouse._new_x = 0;
	_mouse._new_y = 0;

        _mouse._off_x = 0;
        _mouse._off_y = 0;
        _mouse._sensitivity = 0.1f;
        _mouse._yaw = -90.0f;
        _mouse._pitch = 0.0f;
}

void Input::Update( void )
{
        if (isMouseMoved() == false)
                return ;

        glfwGetCursorPos(GraphicInstance::GetInstance()->GetWindow(), &(_mouse._new_x), &(_mouse._new_y));
        _mouse._off_x = _mouse._new_x - _mouse._last_x;
        _mouse._off_y = _mouse._new_y - _mouse._last_y;
        _mouse._last_x = _mouse._new_x;
        _mouse._last_y = _mouse._new_y;
        _mouse._off_x *= _mouse._sensitivity;
        _mouse._off_y *= _mouse._sensitivity;
        _mouse._yaw += _mouse._off_x;
        _mouse._pitch += _mouse._off_y;
        if (_mouse._pitch > 89.0f)
                _mouse._pitch = 89.0f;
        if (_mouse._pitch < -89.0f)
                _mouse._pitch = -89.0f;
}

bool	Input::isMouseMoved( void )
{
        glfwGetCursorPos(GraphicInstance::GetInstance()->GetWindow(), &(_mouse._new_x), &(_mouse._new_y));
        if (_mouse._new_x != _mouse._last_x || _mouse._new_y != _mouse._last_y)
                return (true);
        return (false);
}
