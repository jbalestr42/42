name=$(echo $1 | tr 'a-z' 'A-Z')

cat <<EOF > $1.hpp
#ifndef ${name}_HPP
# define ${name}_HPP

class $1
{
public:
	$1(void);
	$1($1 const & p_$1);
	~$1(void);

	$1 &	operator=($1 const & p_$1);

}

#endif /* !${name}_HPP */

EOF



cat <<EOF > $1.cpp
#include "$1.hpp"

$1::$1(void)
{

}

$1::$1($1 const & p_$1)
{

}

$1::~$1(void)
{

}

$1 &	$1::operator=($1 const & p_$1)
{

}

EOF
