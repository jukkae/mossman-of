#ifndef GOLWORLD_H
#define GOLWORLD_H

#include <cstddef>
#include <utility>
#include <vector>

#include "cellContainer.hpp"
#include "ruleSet.hpp"

// TODO place this somewhere else?
namespace mossman {
	int wrapAround(int i, int max);
}

using namespace mossman;
using namespace gol;

class GolWorld {
public:
	GolWorld(int columns, int rows);
	void step();
	void resize(size_t columns, size_t rows) {
		nCols = columns; 
		nRows = rows; 
		gol::resizeCellContainer(cells, nCols, nRows);
	}
	void randomizeState();
	void setRules(RuleSet ruleSet);
	void clear();
	void insertShape(const CellContainer& shape, int x, int y);

	inline bool isAlive(int x, int y) const {
		return cells[x][y];
	}

	inline int colCount() const { return nCols; }
	inline int rowCount() const { return nRows; }

private:
	int countAliveNeighbours(int x, int y) const;
	CellContainer buildCellContainer() const;
	CellContainer buildRandomizedCellContainer() const;

	inline size_t wrapColumn(int x) const {
		return wrapAround(x, colCount());
	}

	inline size_t wrapRow(int y) const {
		return wrapAround(y, rowCount());
	}

	int nCols; // number of columns AFTER NEXT step()
	int nRows; // number of rows AFTER NEXT step()

	RuleSet ruleSet; 	// currently applied ruleset
	CellContainer cells;	// current state
	std::vector<std::pair<int, int>> neighbourhood;
};

#endif /* GOLWORLD_H */
