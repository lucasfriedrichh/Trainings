# Gera todas as escolhas ordenadas de tres indices distintos e usa um set
# para eliminar numeros repetidos. Tempo: O(n^3). Espaco: O(n^3).
class Solution:
    def totalNumbers(self, digits: list[int]) -> int:
        numbers = {
            100 * digits[first] + 10 * digits[second] + digits[third]
            for first in range(len(digits))
            for second in range(len(digits))
            for third in range(len(digits))
            if first != second
            and first != third
            and second != third
            and digits[first] != 0
            and digits[third] % 2 == 0
        }

        return len(numbers)
