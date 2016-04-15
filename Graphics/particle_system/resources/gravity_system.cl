typedef struct		s_particle
{
	float			position[3];
	float			color;
}				t_particle;

__constant float MIN_DIST = 8.5f;
__constant float PARTICLE_MASS = 100.f;
__constant float GRAVITY = 250.f * 100.f;

__kernel void animate(__global t_particle * particles, __global float *velocities, float dt, float posx, float posy, float posz)
{
	unsigned int i = get_global_id(0);

	float4 res = (float4)(posx - particles[i].position[0], posy - particles[i].position[1], posz - particles[i].position[2], 0.f);
	float dist = fast_length(res);
	particles[i].color = dist;
	if (dist < MIN_DIST)
		dist = MIN_DIST;
	float4 force = GRAVITY * normalize(res) / (dist * dist);

	velocities[i * 3 + 0] += (force.x / PARTICLE_MASS) * dt;
	velocities[i * 3 + 1] += (force.y / PARTICLE_MASS) * dt;
	velocities[i * 3 + 2] += (force.z / PARTICLE_MASS) * dt;
	particles[i].position[0] += velocities[i * 3 + 0] * dt;
	particles[i].position[1] += velocities[i * 3 + 1] * dt;
	particles[i].position[2] += velocities[i * 3 + 2] * dt;
}
