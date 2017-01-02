#ifndef WRAPAROUND_H
#define WRAPAROUND_H

/* Given an index and the size of a container, wraps the index around as if accessing a circular
 * container. Lower boundary of the index is assumed to be 0. */
int wrapAround(int i, int max);

#endif /* WRAPAROUND_H */
