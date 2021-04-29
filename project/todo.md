# PROJECT: Planet Orbiting a Binary System (13.)

## TODO:

> 1. analysis

> 2. odient.hpp

> 3. main.cpp

> 4. polishing, refining tesing

> Requirment: ther should be notes, for in order the make the R&D book that follows the development. Orientation: thoughts, ideas, fomulas are allowed, but no code should be present in the report.

## IDEAS:

> The problem with this is how to show the difference in comparing it to a unary system. Thus this is the main problem: show how different is.

> RK4 must be included, or a good integrating method in order to have correct results. This is easily solved by `odeint.hpp`. It should contain the integrating methods and the tools shown through the course could  easily used. The only thing why using a different integrating method could be needed is to use a good result and compared it to that with runtime and error. (this shoots outside the goal)

> Initialisation: initialisation will happen by a file with the planets coordinates and velocities. The output will be different.

> Init_problem: how to choose the correct velocities? (for the orbiting to happen) -> strange solution is that we don't have a good guess, we just need these celestial bodies, but they are alone. Hence any combination is good and will result into an orbit:

> Init_problem: {x1,x2, v1,v2} or {x1, x2, v_abs, theta}? Or something me exotic? Final decision will be written.

> Strangeness: trinary?