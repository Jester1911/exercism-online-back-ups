class Operation:

    def __init__(self, operation: str) -> None:
        self._operation: str = operation
        self._a: int = 0
        self._b: int = 0
        self._result: int = 0

    def _multiply(self):
        self._result = self._a * self._b

    def _divide(self):
        try:
            self._result = self._a / self._b
        except ZeroDivisionError:
            raise ZeroDivisionError

    def _add(self):
        self._result = self._a + self._b

    def _subtract(self):
        self._result = self._a - self._b

    def calculate(self, a: int, b: int) -> int:
        self._a = a
        self._b = b

        if self._operation == "multiplied":
            self._multiply()
        elif self._operation == "divided":
            self._divide()
        elif self._operation == "plus":
            self._add()
        elif self._operation == "minus":
            self._subtract()

        return self._result

    def get_operation(self) -> str:
        return self._operation


def is_integer(word: str) -> bool:
    try:
        int(word)
        return True
    except:
        return False


def parse_question(question: str) -> (list, list[Operation]):
    words = question[:len(question) - 1].split(' ')
    operands = []
    operations = []

    for word in words:
        if is_integer(word):
            operands.append(int(word))

        elif word == "multiplied":
            operations.append(Operation(word))

        elif word == "divided":
            operations.append(Operation(word))

        elif word == "minus":
            operations.append(Operation(word))

        elif word == "plus":
            operations.append(Operation(word))

        elif word == "cubed":
            raise ValueError("unknown operation")

        if len(operands) > len(operations) + 1:
            raise ValueError("syntax error")

        if len(operations) > len(operands):
            raise ValueError("syntax error")

    return operands, operations


def answer(question: str) -> int:
    operands, operations = parse_question(question)

    if len(operands) != len(operations) + 1:
        raise ValueError("syntax error")

    elif len(operands) == 0:
        raise ValueError("syntax error")

    if len(operands) == 1:
        return operands[0]

    i = 0
    result = 0
    while (i < len(operands)) and (len(operations) > 0) and (len(operands) > 1):
        if i == 0:
            result = operations[i].calculate(operands[i], operands[i + 1])
            i = 2
        else:
            result = operations[i - 1].calculate(result, operands[i])
            i += 1

    return result
