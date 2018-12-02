#include <iostream>
#include <chrono>
#include <thread>

#include "rtc.h"

bool clear_interval;

void set_interval(auto cb, int delay) {
	std::thread t([=]() {
		while (true) {
			if (clear_interval) return;
			std::this_thread::sleep_for(
					std::chrono::milliseconds(delay));
			if (clear_interval) return;
			cb();
		}
	});
	t.detach();
}

class projectile {
public:
	tuple position; // point
	tuple velocity; // vector

	projectile(tuple p, tuple v) : position(p), velocity(p) {}
};

class environment {
public:
	tuple gravity; // vector
	tuple wind;    // vector

	environment(tuple g, tuple w) : gravity(g), wind(w) {}
};

projectile tick(environment e, projectile* p) {
	tuple pos = p->position + p->velocity;
	tuple vel = p->velocity + e.gravity + e.wind;
	return projectile(pos, vel);
}

int main() {
	projectile p = projectile(point(0, 1, 0), normalize(vector(1, 1, 0)));
	environment e = environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));


	set_interval([&]() {
		projectile tmp = tick(e, &p);
		p.position = tmp.position;


		std::cout << tmp.position.y << std::endl;

	}, 16/1000);

	while(true) {
		if (p.position.y >= 10.0 || p.position.y <= 0.0) {
			exit(0);
		}
	}

	return 0;
}