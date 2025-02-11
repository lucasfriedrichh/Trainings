from itertools import combinations

def parse_card(card):
    number_str, figure_str = card.split()
    
    if number_str == 'um':
        number = 1
    elif number_str == 'dois':
        number = 2
    elif number_str == 'tres':
        number = 3
    
    if 'circulo' in figure_str:
        figure = 1
    elif 'quadrado' in figure_str:
        figure = 2
    elif 'triangulo' in figure_str:
        figure = 3
    
    return (number, figure)

def is_valid_set(card1, card2, card3):
    for i in range(2):
        if not ((card1[i] == card2[i] == card3[i]) or (len({card1[i], card2[i], card3[i]}) == 3)):
            return False
    return True

while True:
    n = int(input())
    if n == 0:
        break
    
    cards = []
    for _ in range(n):
        card = input().strip()
        cards.append(parse_card(card))
    
    count_sets = 0
    for c1, c2, c3 in combinations(cards, 3):
        if is_valid_set(c1, c2, c3):
            count_sets += 1
    
    print(count_sets)
