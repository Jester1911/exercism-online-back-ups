package airportrobot
import ("fmt")

// Write your code here.
// This exercise does not have tests for each individual task.
// Try to solve all the tasks first before running the tests.
type Greet interface {
    LanguageName() string
    Greet(name string) string
}

func SayHello(name string, greeter Greet) string {
    language := greeter.LanguageName()
    nativeGreeting := greeter.Greet(name)
    result := fmt.Sprintf("I can speak %v: %v!", language, nativeGreeting)
    return result
}

type Italian struct {
}

func (l Italian) LanguageName() string {
    return "Italian"
}

func (l Italian) Greet(name string) string {
    return fmt.Sprintf("Ciao %v", name)
}

type Portuguese struct {
}

func (p Portuguese) LanguageName() string {
    return "Portuguese"
}

func (p Portuguese) Greet(name string) string {
    return fmt.Sprintf("Olá %v", name)
}
