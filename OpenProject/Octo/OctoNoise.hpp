#ifndef OCTONOISE_HPP
# define OCTONOISE_HPP

# define B 0x100
# define BM 0xff

# define N 0x1000
# define NP 12   /* 2^N */
# define NM 0xfff

class OctoNoise
{
private:
	OctoNoise(void);
	virtual ~OctoNoise(void);

	void init(void);
	inline float lerp(float t, float a, float b);
	inline float s_curve(float t);
	inline void normalize2(float vec[2]);
	inline void normalize3(float vec[3]);

	int	p[B + B + 2];
	float	g3[B + B + 2][3];
	float	g2[B + B + 2][2];
	float	g1[B + B + 2];
	bool	start;
	static OctoNoise *msp_current;

public:
	static OctoNoise & getCurrent(void);

	float noise1(float arg);
	float noise2(float vec[2]);
	float noise3(float vec[3]);
	float fbm(float * vec, int octaves = 3, float lacunarity = 2.0, float gain = 0.4);

};

#endif
