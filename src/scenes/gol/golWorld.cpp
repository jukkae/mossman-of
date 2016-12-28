#include "golWorld.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

// TODO organize/reorder

// TODO move this somewhere else?
namespace mossman {
	int wrapAround(int i, int max) {
		auto mod = i % max;
		return mod < 0 ? max + mod : mod;
	}
}

GolWorld::GolWorld(int columns, int rows) 
		: nCols(columns), nRows(rows) {
	randomizeState();

	// Build default neighbourhood
	neighbourhood.reserve(8);
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			if(i == 0 && j == 0) continue;
			neighbourhood.push_back(std::make_pair(i,j));
		}
	}
}

void GolWorld::step() {
	auto buffer = buildCellContainer();
	for(int x = 0; x < colCount(); x++) {
		for(int y = 0; y < rowCount(); y++) {
			if(x >= nCols || y >= nRows) continue;
			int neighbourCount = countAliveNeighbours(x,y);
			buffer[x][y] = (isAlive(x, y) 
				? ruleSet.survivalRulesContain(neighbourCount)
				: ruleSet.birthRulesContain(neighbourCount));
		}
	}
	this->cells = buffer;
}

int GolWorld::countAliveNeighbours(int x, int y) const {
	int sum = 0;
	int col, row;
	for(auto neighbour : neighbourhood) {
		col = wrapColumn(neighbour.first + x);
		row = wrapColumn(neighbour.second + y);
		if(isAlive(col, row)) sum++;
	}
	return sum;
}

CellContainer GolWorld::buildCellContainer() const {
	return gol::buildCellContainer(nCols, nRows);
}

void GolWorld::randomizeState() {
	this->cells = buildRandomizedCellContainer();
}

CellContainer GolWorld::buildRandomizedCellContainer() const {
	auto buffer = buildCellContainer();
	for(int x = 0; x < nCols; x++) {
		for(int y = 0; y < nRows; y++) {
			buffer[x][y] = (rand() % 2 == 0) ? true : false;
		}
	}
	return buffer;
}

void GolWorld::setRules(RuleSet rules) {
	this->ruleSet = rules;
}

void GolWorld::clear() {
	this->cells = buildCellContainer();
}

void GolWorld::insertShape(const CellContainer& shape, int x, int y) {
	for(size_t i = 0; i < shape.size(); i++) {
		for(size_t j = 0; j < shape[0].size(); j++) {
			cells[x+i][y+j] = shape[i][j];
		}
	}
}
