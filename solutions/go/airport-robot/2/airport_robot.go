package airportrobot
import ("fmt")

// Write your code here.
// This exercise does not have tests for each individual task.
// Try to solve all the tasks first before running the tests.
type Greet interface {
    Language() string
    Greet(name string) string
}

func SayHello(name string, g Greet) string {
    result := fmt.Sprintf("I can speak %s: %s!", g.Language(), g.Greet(name))
    return result
}

type Italian struct {
}

func (l Italian) Language() string {
    return "Italian"
}

func (l Italian) Greet(name string) string {
    return fmt.Sprintf("Ciao %s", name)
}

type Portuguese struct {
}

func (p Portuguese) Language() string {
    return "Portuguese"
}

func (p Portuguese) Greet(name string) string {
    return fmt.Sprintf("Olá %s", name)
}
