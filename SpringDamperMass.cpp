#include "SpringDamperMass.h"


// methods inherited from SpringMass


// SpringDamperMass movement
void SpringDamperMass::move_spring() {
	// new position
	double temp = velocities[t]-damping_coeff/MASS*velocities[t]-SPRING_CONST/MASS*(positions[t]-pos_eqm);
	// save new position
	velocities.push_back(temp);
	positions.push_back(positions[t] + temp);
}
