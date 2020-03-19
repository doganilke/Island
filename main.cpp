#include <string>
#include "Island.h"
#include <iostream>


auto main()->int
{
	std::vector<std::vector<int>> arr =
	{	{{ 0, 0, 0 ,1, 0 ,0, 0},
		 { 0 ,1 ,0 ,1 ,1 ,1 ,0},
		 {  1, 1, 0 ,1 ,1, 0 ,0},
		 {   0 ,0, 0, 0, 2 ,0, 1},
		 {  0,0, 0, 0 ,1, 1 ,1}
}	};
	
	Island island;
	try
	{
		std::cout << "Number of island is : " << island.findNumberofClusters(arr) << "\n";
		auto x = island.getBestPath();
		std::cout << "best path is : \n";
		for (auto r : x)
		{
			std::cout << r.x << " " << r.y << "\n";
		}
		std::cout << "-------------\n";
		island.printAllIslands();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
	
	
}