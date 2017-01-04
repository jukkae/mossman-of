#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include <vector>

/* For now, use std::vector<std::vector<bool>> as the container for state.
 * Later on, other containers may be used.
 */

namespace gol {
	using CellContainer = std::vector<std::vector<bool>>;

	void resizeCellContainer(CellContainer& c, int cols, int rows);
	CellContainer buildCellContainer(int cols, int rows);

}
#endif /* CELLCONTAINER_H */
