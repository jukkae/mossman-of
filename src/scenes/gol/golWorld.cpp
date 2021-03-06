#include "golWorld.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

GolWorld::GolWorld(int columns, int rows) 
		: nCols(columns), nRows(rows) {
	randomizeState();

	// Build default neighbourhood
	// TODO extract somewhere? need to consider neighbourhood implementations more
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
			int neighbourCount = countAliveNeighbours(x,y);
			buffer[x][y] = (isAlive(x, y) 
				? ruleSet.survivalRulesContain(neighbourCount)
				: ruleSet.birthRulesContain(neighbourCount));
		}
	}
	this->cells = buffer;
}

void GolWorld::resize(size_t columns, size_t rows) {
	nCols = columns;
	nRows = rows;
	gol::resizeCellContainer(cells, nCols, nRows);
}

void GolWorld::randomizeState() {
	this->cells = buildRandomizedCellContainer();
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

int GolWorld::countAliveNeighbours(int x, int y) const {
	int sum = 0;
	int col, row;
	for(auto neighbour : neighbourhood) {
		col = wrapColumn(neighbour.first + x);
		row = wrapRow(neighbour.second + y);
		if(isAlive(col, row)) sum++;
	}
	return sum;
}

CellContainer GolWorld::buildCellContainer() const {
	return gol::buildCellContainer(nCols, nRows);
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
