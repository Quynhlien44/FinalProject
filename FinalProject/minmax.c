#include "appdev.h"
#include <stdlib.h>
#include <time.h>

combo minmax() {
	combo ret;
	srand((unsigned)time(NULL));
	ret.min = rand() % 31 - 20; 
	ret.max = rand() % 31 + 15; 
	return ret;
}