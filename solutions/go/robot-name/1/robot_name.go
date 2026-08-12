package robotname

import (
	"errors"
	"math/rand/v2"
	"strconv"
)

// Robot contains the unique name of each robot instance.
type Robot struct {
	name string
}

var MAX_NAMES = 26 * 26 * 10 * 10 * 10

// RobotManager uses a map[string]struct{} to emulate a set to track and enforce unique
// Robot names.
type RobotManager struct {
	robots map[string]struct{}
	count  int
}

// Manager is a singleton instance of RobotManager
var Manager = &RobotManager{
	robots: map[string]struct{}{}}

// Name gives a unique name to the robot.
func (r *Robot) Name() (string, error) {
	if r == nil {
		return "", errors.New("cannot name nil pointer")
	} else if r.name != "" {
		return r.name, nil
	} else if Manager.count >= MAX_NAMES {
		return "", errors.New("names exhausted")
	}

	// DEBUG
	// if Manager.count%1000 == 0 {
	// 	fmt.Println("Count: ", Manager.count)
	// }

	name := generateUniqueRobotName(Manager)
	r.name = name
	Manager.count++
	Manager.robots[name] = struct{}{} // add entry in Manager set
	return name, nil
}

// Reset clears the stored name of the robot.
func (r *Robot) Reset() {
	// delete(Manager.robots, r.name) // remove entry in Manager set
	// Manager.count--
	r.name = ""
}

// generateUniqueRobotName creates a random 2 letter, 3 numeric (length 5) digit name for a
// robot via comparison of the generated name and all active names in the RobotManager
// instance.
func generateUniqueRobotName(manager *RobotManager) string {
	// alphabetic part
	alpha := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	for {
		s1 := ""
		for len(s1) < 2 {
			s1 += string(alpha[rand.IntN(26)])
		}

		// digit part - generates rand number [0-999]
		s2 := strconv.Itoa(rand.IntN(900) + 100)

		// full name
		name := s1 + s2
		_, ok := manager.robots[name]
		if !ok {
			// success - unique name as not found in set
			return name
		}
		// DEBUG
		// if manager.count > 600000 {
		// 	fmt.Println("Hit a name collision")
		// }
	}
}
