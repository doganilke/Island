#include "Island.h"
#include <iostream>
#include <exception>
Island::Island()
{

}

int Island::findNumberofClusters(std::vector<std::vector<int>>& matrix)
{
	int size = matrix.at(0).size();
	for (auto r : matrix)
	{
		if (r.size() != size)
		{
			throw std::exception{ "Dimension Error" };
		}
		for (auto x : r)
		{
			if (x !=0 && x!=1)
			{
				throw std::exception{ "All elements must be 1 or 0" };
			}
		}
	}
	std::vector<std::vector<bool>>visited{ matrix.size(),std::vector<bool>(matrix.at(0).size(),false) };

	int count = 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if ((matrix[i][j] == 1) && (!visited[i][j]))
			{
				count += 1;
				doDFS(matrix, i, j, visited);
				m_path.push_back(m_points);
				m_points.clear();
			}
		}
	}
	return count;
}

bool Island::neighborExists(std::vector<std::vector<int>> matrix, int i, int j)
{
	if ((i >= 0) && (i < matrix.size()) && (j >= 0) && (j < matrix[0].size()))
	{
		if (matrix[i][j] == 1)
		{
			return true;
		}
	}

	return false;
}

void Island::doDFS(std::vector<std::vector<int>>& matrix, int i, int j, std::vector<std::vector<bool>>& visited)
{
	if (visited[i][j])
	{
		return;
	}


	visited[i][j] = true;

	int xOffset, yOffset;
	for (int l = 0; l < offsets.size(); l++)
	{
		xOffset = offsets[l];
		for (int m = 0; m < offsets.size(); ++m)
		{
			yOffset = offsets[m];


			if (xOffset == 0 && yOffset == 0)
			{
				
				m_points.push_back(Point{ i,j });
				continue;
			}


			if (neighborExists(matrix, i + xOffset, j + yOffset))
			{
				//std::cout << "i : " << i<< " j : " << j << "\n";
				doDFS(matrix, i + xOffset, j + yOffset, visited);

			}

		}
	}
}

std::vector<Point> Island::getBestPath() const
{
	int size = 0;
	std::vector<Point> temp;
	for (auto r : m_path)
	{
		if (size < r.size())
		{
			size = r.size();
			temp = r;
		}
			
	}
	return temp;
}

void Island::printAllIslands() const
{
	int i = 1;
	for (auto r : m_path)
	{
		std::cout << "Path number :"<<i<<" \n";
		for (auto t : r)
		{
			std::cout << t.x << " " << t.y << "\n";
		}
		++i;
		std::cout << "--------------\n";
	}
}
