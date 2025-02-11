def resp(d: dict):
    for chave, valor in d.items():
        print(f"{chave} {valor}")
    print("") 

while True:
    try:
        text = input()
        
        dic = {}
        
        for char in text:
            asc = ord(char)
            dic[asc] = dic.get(asc, 0) + 1

        dic = dict(sorted(dic.items(), key=lambda item: (item[1], -item[0])))

        resp(dic)
        
    except EOFError:
        break
