#include "Renderable.hpp"

class Planet : public Renderable
{
	private:
		uint32_t _resolution;
	public:
		Planet( uint32_t resolution );
		~Planet( void );
		void GenerateCube( void );
		void GenerateFace( uint32_t index, vec3<float> direction );
};
