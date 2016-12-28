#ifndef RULESET_H
#define RULESET_H

#include <algorithm>

class RuleSet {
public:
	RuleSet(): birthCounts({ 3 }), survivalCounts({ 2, 3 }) {;}
	RuleSet(std::vector<int> birthCounts, std::vector<int> survivalCounts): birthCounts(birthCounts), survivalCounts(survivalCounts) {;}

	bool birthRulesContain(int i) { return std::find(birthCounts.begin(), birthCounts.end(), i) != birthCounts.end(); }
	bool survivalRulesContain(int i) { return std::find(survivalCounts.begin(), survivalCounts.end(), i) != survivalCounts.end(); }
private:
	std::vector<int> birthCounts;
	std::vector<int> survivalCounts;
};

#endif /* RULESET_H */
