#pragma once
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define MAP_X1  4
#define MAP_Y1  4
#define STAGE 10

int stage = 0;
int tempMap[STAGE][MAP_HEIGHT][MAP_WIDTH];

//int map1[MAP_HEIGHT][MAP_WIDTH] = {
//   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//   { 1, 1, 4, 1, 1, 0, 0, 0, 0, 1 },
//   { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
//   { 1, 0, 2, 0, 0, 0, 0, 0, 0, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 5, 0, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 0, 0 ,1 },
//   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
//};

int map[2][MAP_HEIGHT][MAP_WIDTH] = {
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 4, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 2, 0, 2, 4, 1, 0 },
		{ 0, 1, 4, 0, 2, 5, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 4, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	},

	//int map2[MAP_HEIGHT][MAP_WIDTH] =
	{
		{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 1, 5, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 1, 0, 2, 2, 1, 0, 1, 1, 1 },
		{ 0, 1, 0, 2, 0, 1, 0, 1, 4, 1 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 4, 1 },
		{ 0, 0, 1, 1, 0, 0, 0, 0, 4, 1 },
		{ 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	}
};