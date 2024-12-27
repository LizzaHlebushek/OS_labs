import random

def generate_number():
    # Сначала выбираем тип числа с равными шансами
    choice = random.randint(1, 5)
    
    if choice == 1:
        # 20% шанс - 0
        return 0
    elif choice == 2:
        # 20% шанс - положительное целое число
        return random.randint(1, 10000)
    elif choice == 3:
        # 20% шанс - отрицательное целое число
        return random.randint(-10000, -1)
    elif choice == 4:
        # 20% шанс - положительное дробное число
        return round(random.uniform(0.0001, 10000), 4)  # Округляем до 4 знаков после запятой
    elif choice == 5:
        # 20% шанс - отрицательное дробное число
        return round(random.uniform(-10000, -0.0001), 4)  # Округляем до 4 знаков после запятой

    
file = open("file", "w")

s = ''   
xs = ''
for i in range(6, 10):
    for j in range(3):
        s += str(i+1)
        s += ' '
        s += str(j+1)
        s += '\n'
        file.write(s)
        s = ''
        for k in range(i+1):
            for m in range (j+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''

        s += str(j+1)
        s += ' '
        s += str(i+1)
        s += '\n'
        file.write(s)
        s = ''
        for k in range(j+1):
            for m in range (i+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''



for j in range(10):
    s += str(j+1)
    s += ' '
    s += str(j+1)
    s += '\n'
    file.write(s)
    s = ''
    for k in range(j+1):
            for m in range (j+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''
    s += str(j+1)
    s += ' '
    s += str(j+1)
    s += '\n'
    file.write(s)
    s = ''
    for k in range(j+1):
            for m in range (j+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''
print( "the hard part" )
for j in range(400, 420):
    s += str(j+1)
    s += ' '
    s += str(j+1)
    s += '\n'
    file.write(s)
    s = ''
    for k in range(j+1):
            for m in range (j+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''
    print( "table", j ,  '*',  j, "is ready" )
    s += str(j+1)
    s += ' '
    s += str(j+1)
    s += '\n'
    file.write(s)
    s = ''
    for k in range(j+1):
            for m in range (j+1):
                xs = ''
                a = generate_number()
                if a!= 0:
                    xs += str(a)
                a = generate_number()
                if a!= 0:
                    if a > 0:
                        if len(xs) != 0: xs += '+'
                        xs += str(a)
                        xs+='i '
                    else:
                        xs += str(a)
                        xs+='i '
                else:
                    if len(xs) == 0:
                        xs = '0 '
                    else:
                        xs += ' '
                s += xs
                
            s = s[:len(s)-1] + '\n'
            file.write(s)
            s = ''
    print( "second table", j,  '*', j, "is ready" )

    