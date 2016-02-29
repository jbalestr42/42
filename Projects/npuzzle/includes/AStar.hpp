#ifndef ASTAR_HPP
# define ASTAR_HPP

# include <iostream>
# include <vector>
# include <list>
# include <map>

class AStar
{
public:
	struct PuzzleState
	{
		std::vector<int>	state;
		int					g;
		int					h;
	};

	AStar(void);
	AStar(AStar const & aStar);
	virtual ~AStar(void);

	AStar & operator=(AStar const & aStar);

	int cost(PuzzleState const & state, PuzzleState const & goal)
	{
		int cost = 0;
		for (std::size_t i = 0u; i < state.state.size(); i++)
		{
			if (state.state[i] != goal.state[i])
				cost++;
		}
		return (cost);
	}

	void addList(std::list<PuzzleState> & list, PuzzleState & state, PuzzleState const & goal)
	{
		state.g = cost(state, goal); // only in open list
		auto it = list.begin();
		for (; it != list.end(); it++)
		{
			if (state.g < it->g)
				break;
		}
		list.insert(it, state);
	}

	void dump(std::vector<int> const & state)
	{
		std::cout << "---------------------" << std::endl;
		//std::cout << " -- " << state.g << std::endl;
		for (std::size_t i = 0; i < m_size; i++)
		{
			for (std::size_t j = 0; j < m_size; j++)
			{
				std::cout << state[i * m_size + j];
				if (j != m_size - 1)
					std::cout << " | ";
			}
			std::cout << std::endl;
		}
	}

	bool isEqual(std::vector<int> const & current, std::vector<int> const & goal)
	{
		for (std::size_t i = 0u; i < m_totalSize; i++)
		{
			if (current[i] != goal[i])
				return (false);
		}
		return (true);
	}

	bool isEqual(PuzzleState const & current, PuzzleState const & goal)
	{
		return (isEqual(current.state, goal.state));
	}

	void emplace(std::vector<PuzzleState> & successors, PuzzleState const & current, int p1, int p2)
	{
		PuzzleState n = current;
		std::swap(n.state[p1], n.state[p2]);
		successors.emplace_back(std::move(n));
	}

	bool inBounds(int i, int j)
	{
		if (i >= 0 && i < static_cast<int>(m_size) && j >= 0 && j < static_cast<int>(m_size))
			return (true);
		return (false);
	}

	void getSuccessors(std::vector<PuzzleState> & successors, PuzzleState const & current)
	{
		std::pair<int, int> pos;
		for (std::size_t i = 0u; i < m_size; i++)
		{
			for (std::size_t j = 0u; j < m_size; j++)
			{
				if (current.state[i * m_size + j] == 0u)
				{
					pos.first = i;
					pos.second = j;
					break;
				}
			}
		}
		if (inBounds(pos.first - 1, pos.second))
			emplace(successors, current, pos.first * m_size + pos.second , (pos.first - 1) * m_size + pos.second);
		if (inBounds(pos.first + 1, pos.second))
			emplace(successors, current, pos.first * m_size + pos.second , (pos.first + 1) * m_size + pos.second);
		if (inBounds(pos.first, pos.second - 1))
			emplace(successors, current, pos.first * m_size + pos.second , pos.first * m_size + pos.second - 1);
		if (inBounds(pos.first, pos.second + 1))
			emplace(successors, current, pos.first * m_size + pos.second , pos.first * m_size + pos.second + 1);
	}

	std::list<PuzzleState>::const_iterator isInList(std::list<PuzzleState> const & list, PuzzleState const & state)
	{
		auto it = list.begin();
		for (; it != list.end(); it++)
		{
			if (isEqual(*it, state))
			{
				//if (it->g < state.g)
					break;
			}
		}
		return it;
	}

	void solve(PuzzleState & start, PuzzleState const & goal)
	{
		addList(m_open, start, goal);
		m_parent[start.state] = start.state;
		int i = 0;
		while (m_open.size())
		{
			PuzzleState current = m_open.front();
			m_open.pop_front();
			i++;

			if (isEqual(current, goal))
			{
				std::cout << "found " << i << std::endl;
				std::cout << m_parent.size() << std::endl;
				dump(current.state);
				dump(m_parent.find(current.state)->second);
				dump(m_parent.find(m_parent.find(current.state)->second)->second);
				dump(m_parent.find(m_parent.find(m_parent.find(current.state)->second)->second)->second);
				std::cout << "**************" << std::endl;
				//auto it = m_parent.find(current.state);
				//while (it != m_parent.end() && !isEqual(it->first, start.state))
				//{
				//	it = m_parent.find(it->second);
				//	dump(it->first);
				//}
				break;
			}

			//std::cout << m_parent.size() << " " << current.g << std::endl;
			std::vector<PuzzleState> successors;
			getSuccessors(successors, current);
			for (auto & successor : successors)
			{
				successor.g++;
				auto itOpen = isInList(m_open, successor);
				if (itOpen != m_open.end() && successor.g >= itOpen->g)
					continue;
				auto itClosed = isInList(m_closed, successor);
				if (itClosed != m_closed.end() && successor.g >= itClosed->g)
					continue;

				if (itOpen != m_open.end())
					m_open.erase(itOpen);
				if (itClosed != m_closed.end())
					m_closed.erase(itClosed);
				m_parent[successor.state] = current.state;
				addList(m_open, successor, goal);
			}
			m_closed.push_back(current);
		}
	}

private:
	std::list<PuzzleState>		m_open;
	std::list<PuzzleState>		m_closed;
	std::size_t					m_size = 3;
	std::size_t					m_totalSize = m_size * m_size;
	std::map<std::vector<int>, std::vector<int>>			m_parent;

};

#endif
