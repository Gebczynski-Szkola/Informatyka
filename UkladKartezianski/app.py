class startPoint:
    x = 0
    y = 0


p1 = startPoint()

with open('punkty.txt', encoding='utf8') as tekst:
    ilosc = tekst.readline()
    ilosc = int(ilosc)
    lines = []

    print(lines)

    for x in range(ilosc):
        lines[[x]].append(tekst.readline().replace(
            "\t", " ").replace("\n", ""))


tekst.close()
print(lines)

print(lines[0])
