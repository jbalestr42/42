#include "scop.h"

void		init_key(t_env *env)
{
	env->keys[KEY_FORWARD].code = 'z';
	env->keys[KEY_FORWARD].is_active = 0;
	env->keys[KEY_BACKWARD].code = 's';
	env->keys[KEY_BACKWARD].is_active = 0;
	env->keys[KEY_LEFT].code = 'q';
	env->keys[KEY_LEFT].is_active = 0;
	env->keys[KEY_RIGHT].code = 'd';
	env->keys[KEY_RIGHT].is_active = 0;
	env->keys[KEY_UP].code = 'e';
	env->keys[KEY_UP].is_active = 0;
	env->keys[KEY_DOWN].code = 'a';
	env->keys[KEY_DOWN].is_active = 0;
	env->keys[KEY_P].code = 'p';
	env->keys[KEY_P].is_active = 0;
	env->keys[KEY_M].code = 'm';
	env->keys[KEY_M].is_active = 0;
	env->keys[KEY_L].code = 'l';
	env->keys[KEY_L].is_active = 0;
}

void		init_env(t_env * env)
{
	env->frame_count = 0;
	env->wnd_width = 800;
	env->wnd_height = 600;
	env->wnd_handle = 0;
	env->projection = IDENTITY_MATRIX;
	env->mesh = NULL;
	env->shader = NULL;
	env->texture = NULL;
	init_key(env);
	env->camera.fov = 60.f;
	env->camera.near_plane = 1.f;
	env->camera.far_plane = 100.f;
	env->camera.rotation[0] = 0.f;
	env->camera.rotation[1] = 0.f;
	env->camera.translation = IDENTITY_MATRIX;
	env->camera.translation.m[14] = -6;
}

void		init_openGL(int argc, char* argv[])
{
	GLenum	GlewInitResult;

	init_window(argc, argv);
	glewExperimental = GL_TRUE;
	GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		fprintf(stderr, "ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));
	glGetError();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	exit_on_GLerror("ERROR: Could not set OpenGL depth testing options");
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);
	exit_on_GLerror("ERROR: Could not set OpenGL culling options");
}

void		init_window(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(4, 0);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitWindowSize(env.wnd_width, env.wnd_height);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	env.wnd_handle = glutCreateWindow(WINDOW_TITLE_PREFIX);
	if (env.wnd_handle < 1)
	{
		fprintf(stderr, "ERROR: Could not create a new rendering window.\n");
		exit(EXIT_FAILURE);
	}
	glutReshapeFunc(resize_function);
	glutDisplayFunc(render_function);
	glutIdleFunc(idle_function);
	glutTimerFunc(0, timer_function, 0);
	glutKeyboardFunc(keyboard_input_press);
	glutKeyboardUpFunc(keyboard_input_release);
	glutMotionFunc(mouse_move_input);
	glutPassiveMotionFunc(mouse_move_input);
	glutSetCursor(GLUT_CURSOR_NONE);
	//glutSpecialFunc(handleSpecialKeypress);
	//glutSpecialUpFunc(handleSpecialKeyReleased);
	glutCloseFunc(clear);
}

void		exit_on_GLerror(const char *error_message)
{
	GLenum	error;

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		fprintf(stderr, "%s: %s\n", error_message, gluErrorString(error));
		exit(EXIT_FAILURE);
	}
}
