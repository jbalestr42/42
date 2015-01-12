name=$(echo $1 | tr 'a-z' 'A-Z')
param=$(echo ${1::1} | tr 'A-Z' 'a-z')$(echo ${1:1:100000})

cat <<EOF > includes/$1.hpp
#ifndef ${name}_HPP
# define ${name}_HPP

class $1
{
public:
	$1(void);
	$1($1 const & p_$param);
	virtual ~$1(void);

	$1 &	operator=($1 const & p_$param);

};

#endif /* !${name}_HPP */

EOF



cat <<EOF > sources/$1.cpp
#include "$1.hpp"

$1::$1(void) { /* unused */ }

$1::$1($1 const & p_$param)
{
	*this = p_$param;
}

$1::~$1(void)
{

}

$1 & $1::operator=($1 const & p_$param)
{

	return (*this);
}

EOF
