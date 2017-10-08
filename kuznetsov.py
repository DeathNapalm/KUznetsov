from itertools import permutations as p

functions = set()
functions_copy= functions.copy()
n = int(input('size of notation scale '))


def make_selectors(n=2):
    left_selector = ' '.join(str(x) for x in range(n) for _ in range(n))
    right_selector = ' '.join(str(x) for _ in range(n) for x in range(n))
    functions_copy.add(left_selector)
    functions_copy.add(right_selector)


def input_into_table():
    while True:
        input_func = input('enter table ')
        if input_func in {'yes', 'y', 'done'}:
            break
        functions.add(input_func)
        functions_copy.add(input_func)


def func_call(funcmain, arg1, arg2, n=2):
    arg1 = [int(x) for x in arg1.split(' ')]
    arg2 = [int(x) for x in arg2.split(' ')]
    funcmain = [int(x) for x in funcmain.split(' ')]
    new_function = [funcmain[arg1[i] * n + arg2[i]] for i in range(n * n)]
    new_function = [str(x) for x in new_function]
    new_function = ' '.join(new_function)
    return new_function


def add_into_functions(newf):
    if newf not in functions:
        functions.add(newf)
        functions_copy.add(newf)


def permutate(functions, functions_copy):
    controle_length = len(functions)
    everything = [[i] + list(j) for i in functions for j in p(functions_copy, 2)]
    for x in everything:
        mainfunc, arg1, arg2 = x
        add_into_functions(func_call(mainfunc,arg1,arg2))

    return len(functions)-controle_length



input_into_table()
make_selectors(n)
while permutate(functions, functions_copy):
    if len(functions) == n**n**n:
        break

print(functions)
