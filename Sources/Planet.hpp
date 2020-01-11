#include "Renderable.hpp"
#include "Noise.hpp"

class Planet : public Renderable
{
	private:
		uint32_t _resolution;
		Noise _noise;
	public:
		float _roughness;
		float _strength;
		vec3<float> _center;
		Planet( uint32_t resolution );
		~Planet( void );
		void GenerateCube( void );
		void RegenerateCube( void );
		void GenerateFace( uint32_t index, vec3<float> direction );
		float Evaluate( vec3<float> point );
};
