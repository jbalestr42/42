#include "AStar.hpp"

AStar::AStar(void) { }

AStar::AStar(AStar const & aStar)
{
	*this = aStar;
}

AStar::~AStar(void) { }

AStar & AStar::operator=(AStar const & aStar)
{
	(void)aStar;
	return (*this);
}
