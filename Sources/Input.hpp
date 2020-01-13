#pragma once

class Object;

class Input
{
	public:
		Input( void );
		void Update( void );
		bool isMouseMoved( void );
		void Process( Object* obj );

		struct Mouse
		{
			float   _last_x;
			float   _last_y;
			double  _new_x;
			double  _new_y;
			float   _off_x;
			float   _off_y;
			float   _sensitivity;
			float   _yaw;
			float   _pitch;
		}
		_mouse;
};
