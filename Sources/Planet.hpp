#include "Renderable.hpp"
#include "Noise.hpp"

class Planet : public Renderable
{
	private:
		Noise _noise;
	public:
		uint32_t _resolution;
		uint32_t _nbLayers;
		float _baseRoughness;
		float _persistence;
		float _roughness;
		float _strength;
		float _minValue;
		vec3<float> _center;
		Planet( uint32_t resolution );
		~Planet( void );
		void GenerateCube( void );
		void RegenerateCube( void );
		void GenerateFace( uint32_t index, vec3<float> direction );
		float Evaluate( vec3<float> point );
};
