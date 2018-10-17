#include "SpringDamperMass.h"

// TODO
// Define your methods here

void SpringDamperMass::move_spring() {
	double temp = velocities[t]-damping_coeff/MASS*velocities[t]-SPRING_CONST/MASS*(positions[t]-pos_eqm);
	velocities.push_back(temp);
	positions.push_back(positions[t] + temp);
}
