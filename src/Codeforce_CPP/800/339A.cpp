#include <bits/stdc++.h>
#include <algorithm>

/* Начинающий математик Ксения учится в третьем классе. Сейчас в школе она проходит операцию сложения.

Учитель записал на доске сумму нескольких чисел, которую требуется посчитать. Чтобы было проще считать, в сумме используются только числа 1, 2 и 3. Но и этого Ксении мало. Ксения только учится считать, и поэтому она может посчитать сумму, только если слагаемые в сумме идут в порядке неубывания. Например, сумму 1+3+2+1 она посчитать не может, а суммы 1+1+2 и 3+3 может.

Вам задана сумма, которая записана на доске. Переставьте слагаемые и выведите ее в виде, в котором Ксения сможет посчитать сумму.

Входные данные
В первой строке записана непустая строка s — сумма, которую нужно посчитать Ксении. Строка s не содержит пробелов, состоит только из цифр и знаков «+» и является корректной суммой чисел 1, 2 и 3. Длина строки s не более 100 символов.

Выходные данные
Выведите новую сумму, которую сможет посчитать Ксения. */

int main()
{
	std::string str;
	std::vector<std::string> vec;
	std::cin >> str;
	
	size_t pos = 0;
	std::string token, delimiter = "+";
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
		vec.push_back(token);
	}
	vec.push_back(str);

	std::sort(vec.begin(), vec.end());

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (it == vec.end() - 1)
		{
			std::cout << *it << " ";
		}
		else
		{
			std::cout << *it << "+";
		}
	}
	std::cout << std::endl;

	return 0;
}