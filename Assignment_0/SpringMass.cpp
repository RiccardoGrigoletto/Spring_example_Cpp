#include "SpringMass.h"

#include <ostream>
#include <fstream>
#include <vector>

using namespace std;

// define gravity constant
const double SpringMass::GRAVITY = 10;
const double SpringMass::SPRING_CONST = 7;
const double SpringMass::MASS = 30;



// TODO SpringMass constructor
  
SpringMass::SpringMass(double pos_init, double vel_init, double pos_eqm, double vel_eqm) :
		pos_eqm(pos_eqm), vel_eqm(vel_eqm), t(0)
{
	positions.push_back(pos_init);
	velocities.push_back(vel_init);
}

SpringMass::~SpringMass() {
  // TODO clean up stuff from HEAP  
}

// TODO SpringMass simulation step
int SpringMass::step() {
	move_spring();
	return ++t;
}

// TODO SpringMass configuration getter
bool SpringMass::getConfiguration(int t, Vec2d& state) const {
	if (t>=0 && t<positions.size()) {
		state.x = (positions[t]);
		state.y = (velocities[t]);
		return true;
	}
	else {
		return false;
	}
}

// TODO SpringMass current simulation t getter
int SpringMass::getCurrentSimulationTime() const {
  return t;
}

void SpringMass::move_spring() {
	double temp = velocities[t]-SPRING_CONST/MASS*(positions[t]-pos_eqm);
	velocities.push_back(temp);
	positions.push_back(positions[t] + temp);

};
