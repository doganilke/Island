#pragma once
#include <vector>
#include <array>
struct Point
{
	int x, y;
};

class Island
{
public:
	

	Island();
	int findNumberofClusters(std::vector<std::vector<int>>&matrix);
	std::vector<Point> getBestPath()const;
	void printAllIslands()const;
private:
	
	std::vector<Point> m_points;

	bool neighborExists(std::vector<std::vector<int>>matrix, int i, int j);
	void doDFS(std::vector<std::vector<int>>&matrix, int i, int j, std::vector<std::vector<bool>>&visited);
	const std::array<int, 3>offsets{ -1, 0, +1 };

	std::vector<std::vector<Point>>m_path;
};