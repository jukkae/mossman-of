#ifndef GOLWORLD_H
#define GOLWORLD_H

#include <cstddef>
#include <utility>
#include <vector>

#include "cellContainer.hpp"
#include "ruleSet.hpp"
#include "util/wrapAround.hpp"

//using namespace mossman;
using namespace gol;

/* GolWorld encapsulates the state of cellular automata, providing methods for modifying the
 * applied rules and manipulating the state.
 */
class GolWorld {
public:
	/* Construct a new instance of given size. */
	GolWorld(int columns, int rows);

	/* Advance the simulation by one step, modifying the state. */
	void step();

	/* Change the amount of cells. */
	void resize(size_t columns, size_t rows);

	/* Randomize the state. */
	void randomizeState();

	/* Change the applied ruleset. */
	void setRules(RuleSet ruleSet);

	/* Clear the state of all cells. */
	void clear();

	/* Insert given shape, with top-left corner at given coordinates. */
	void insertShape(const CellContainer& shape, int x, int y);

	/* Return true if cell at given coordinates is alive. */
	inline bool isAlive(int x, int y) const { return cells[x][y]; }

	/* Return the current number of columns in the simulation. */
	inline int colCount() const { return nCols; }

	/* Return the current number of rows int the simulation. */
	inline int rowCount() const { return nRows; }

private:
	/* Given coordinates, returns the number of cells alive in the current neighbourhood around
	 * the coordinates. */
	int countAliveNeighbours(int x, int y) const;

	/* Build a new, empty cell container with size equal to the currently used. */
	CellContainer buildCellContainer() const;

	/* Build a new cell container with size equal to the currently used and with all cell
	 * states randomized. */
	CellContainer buildRandomizedCellContainer() const;

	/* Wrap a column coordinate around the edge of the current cell container. */
	inline size_t wrapColumn(int x) const { return wrapAround(x, colCount()); }

	/* Wrap a row coordinate around the edge of the current cell container. */
	inline size_t wrapRow(int y) const { return wrapAround(y, rowCount()); }

	int nCols; // Number of columns
	int nRows; // Number of rows

	RuleSet ruleSet; 	// Currently applied ruleset
	CellContainer cells;	// Current state

	std::vector<std::pair<int, int>> neighbourhood; // Currently applied neighbourhood
};

#endif /* GOLWORLD_H */
