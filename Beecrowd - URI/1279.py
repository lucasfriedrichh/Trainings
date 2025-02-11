flag = False
while True:
    try:
        ano = int(input())
        bis = 0
        ordinary = True
        
        if flag:
            print("")
        flag = True

        if (ano % 4 == 0) and (not (ano % 100 == 0) or (ano % 400 == 0)):
            print('This is leap year.')
            bis = 1
            ordinary = False
        
        if (ano % 15 == 0):
            print('This is huluculu festival year.')
            ordinary = False
        if (ano % 55 == 0) and bis:
            print('This is bulukulu festival year.')
        
        if ordinary:
            print('This is an ordinary year.')
    except EOFError:
        break