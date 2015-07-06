nom de fichier = nom de la classe

VARIABLES
    Dans une classe:
        - Variables membres: m_
        - Static membres: ms_
        - Globales: g_
        - Parametres de fonction: p_
        - Variables local: rien
        - Enume: e_
        EScreen
        {
            e_screen_game
            e_screen_options
        };
        
PREFIX
    float:
        float mf_float;
    int:
        int mn_int;
    enum:
        EScreen me_enum;
    char:
        char mc_char;
    pointer: (separer par des espaces) 
        non: char *mpc_pointer; /!\
        char * mpc_pointer;
        char ** mppc_pointer;

class AAbstract 
{
    float   mf_size;
};

class IInterface { };

class Basic
{
};

struct SStruct
{
};

bad: void space :: between();
good: void space::between();

//////////////////////////////////////////////
//////////////////FILE////////////////////////
//////////////////////////////////////////////

Example.hpp

class Example
{
    float   mf_setters;

    void Example();
    void ~Example();

    void setSetters(float pf_setters);

    void draw(float pf_XWidth, float pf_YWidth);
};


Example.cpp

/* ---------------------------------------------------------------------- */
/*                                Base                                    */
/* ---------------------------------------------------------------------- */
void Example::Example() { };
void Example::~Example() { };

/* ---------------------------------------------------------------------- */
/*                              Accessors                                 */
/* ---------------------------------------------------------------------- */
void Example::setSetters(float pf_setters)
{
    mf_setters = pf_setters;
}

/* ---------------------------------------------------------------------- */
/*                              Methods                                   */
/* ---------------------------------------------------------------------- */
void    Example::draw(float pf_XWidth, float pf_YWidth) { };



