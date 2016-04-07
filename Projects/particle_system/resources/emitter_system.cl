typedef struct		s_particle
{
	float			position[3];
	float			color;
}				t_particle;

__constant float MAX_LIFE = 2.f;

__kernel void animate(__global t_particle * particles, __global float *velocities, __global float *life_times, float dt)
{
	unsigned int i = get_global_id(0);

	life_times[i * 2] += dt;
	particles[i].color = life_times[i * 2] / life_times[i * 2 + 1];
	if (life_times[i * 2] >= life_times[i * 2 + 1])
	{
		life_times[i * 2] = 0.f;
		particles[i].position[0] = 0.f;
		particles[i].position[1] = 0.f;
		particles[i].position[2] = 0.f;
		velocities[i * 6 + 0] = velocities[i * 6 + 3];
		velocities[i * 6 + 1] = velocities[i * 6 + 4];
		velocities[i * 6 + 2] = velocities[i * 6 + 5];
	}

	velocities[i * 6 + 1] += -9.8 * dt;
	particles[i].position[0] += velocities[i * 6 + 0] * dt;
	particles[i].position[1] += velocities[i * 6 + 1] * dt;
	particles[i].position[2] += velocities[i * 6 + 2] * dt;
}
