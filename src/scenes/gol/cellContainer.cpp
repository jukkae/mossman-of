#include "cellContainer.hpp"

namespace gol {
	void resizeCellContainer(CellContainer& c, int cols, int rows) {
		c.resize(cols);
		for(int col = 0; col < cols; col++) {
			c[col].resize(rows);
		}
	}

	CellContainer buildCellContainer(int cols, int rows) {
		auto c = CellContainer();
		resizeCellContainer(c, cols, rows);
		return c;
	}
}
